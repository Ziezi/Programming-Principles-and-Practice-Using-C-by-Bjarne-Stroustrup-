/*
	TITLE		   Simple Encryption - Bit Twiddling 		Chapter25TryThis6.h
	COMMENT
		Objective: Write "the Tiny Encryption Algorithm" by D. Wheeler,
				   presented in §25.5.6, copy the encrypted text in a file
				   and decrypt it. The key is: bs.
				   https://en.wikipedia.org/wiki/Tiny_Encryption_Algorithm
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 11.05.2017
*/

#ifndef Chapter25TryThis6_h
#define Chapter25TryThis6_h

/*
	Function: encipher(src, dest, key)

	src - eight (2 words or 2*4 bytes) characters to be enciphered.
	dest- enciphtered output.
	key - array of 4 words.
	Applies "Tiny Encryption Algorithm".

	Assumes sizeof(long) == 4 bytes.
*/
void encipher(const unsigned long* const v,
			  unsigned long* const w, 
			  const unsigned long* const k)
{
	unsigned long y = v[0];
	unsigned long z = v[1];
	unsigned long sum = 0;
	unsigned long delta = 0x9E3779B9;	// derived from the Golden Number = (sqrt(5) - 1) * 2^{31}
	unsigned long n = 32;

	while (n-- > 0)
	{
		y += (z<<4 ^ z>>5) + z^sum + k[sum&3];

		sum += delta;

		z += (y<<4 ^ y>>5) + y^sum + k[sum>>11 & 3];
	}

	w[0] = y;
	w[1] = z;
}

//---------------------------------------------------------------------------

/*
	Function: decipher(src, dest, key)

	src - 2 encrypted words
	dest - 2 decrypted words
	key 
	Applies reverse "Tiny Encryption Algorithm".

	Assumes sizeof(long) == 4 bytes.
*/
void decipher(const unsigned long *const v,
			  unsigned long *const w,
			  const unsigned long *const k)
{
    unsigned long y = v[0];
    unsigned long z = v[1];
    unsigned long sum = 0xC6EF3720;
    unsigned long delta = 0x9E3779B9;
    unsigned long n = 32;

    while (n-- > 0) 
	{
        z -= (y<<4 ^ y>>5) + y ^ sum + k[sum>>11 & 3];
        sum -= delta;
        y -= (z<<4 ^ z>>5) + z ^ sum + k[sum&3];
    }

    w[0] = y;
    w[1] = z;
}

//---------------------------------------------------------------------------

/*
	Sends the clear text from: src_file as
	encrypted text to: dest_file, using TEA
	with key: the last argument.
*/
void send_msg(std::string& src_file, 
			  std::string& dest_file,
			  std::string key)
{
	const int nchar = 2 * sizeof(long);		// size of I/O chunk: 8 bytes = 64 bits
	const int kchar = 2 * nchar;			// size of key: 16 bytes = 128 bits

	// pad key with 0's to match en-/de- cipher argument input size
	while (key.size() < kchar)
	{
		key += '0';
	}

	// prepare files
	std::ifstream ifs(src_file.c_str());
	std::ofstream ofs(dest_file.c_str());

	if (!ifs || !ofs)
	{
		throw std::runtime_error("File can't open!\n");
	}

	// key: extract raw string data interpreted as pointer to const unsigned long 
	const unsigned long* k = reinterpret_cast<const unsigned long*>(key.data());

	// define C-compatible way to read & write from / to file 128 bits (two unsigned longs) at a time
	unsigned long outptr[2]; 

	char inbuf[nchar];
	//inbuf[nchar] = 0;
	unsigned long* inptr = reinterpret_cast<unsigned long*>(inbuf);

	int count = 0;

	while (ifs.get(inbuf[count]))
	{
		ofs << std::hex; // write output in hex 

		if (++count == nchar) // 8 characters in the input buffer: ready to encode
		{
			encipher(inptr, outptr, k);

			// pad with leading 0's
			ofs << std::setw(8)	<< std::setfill('0') << outptr[0] <<' '
			    << std::setw(8)	<< std::setfill('0') << outptr[1] <<' ';
			
			count = 0;
		}
	}

	if (count) // pad at the end
	{
		while (count != nchar)
		{
			inbuf[count++] = '0';
		}

		encipher(inptr, outptr, k);
		ofs << outptr[0] <<' '<< outptr[1] <<' '; 
	}
}

//---------------------------------------------------------------------------

/*
	Receives encrypted text from: src_file and
	writes it as clear text in: dest_file, using
	the reverse TEA and key: the last argument.
*/
void receive_msg(std::string& src_file, 
			     std::string& dest_file,
			     std::string key)
{
	const int nchar = 2 * sizeof(long);		// size of I/O chunk: 8 bytes = 64 bits
	const int kchar = 2 * nchar;			// size of key: 16 bytes = 128 bits

	// pad key with 0's to match en-/de- cipher argument input size
	while (key.size() < kchar)
	{
		key += '0';
	}

	// prepare files
	std::ifstream ifs(src_file.c_str());
	std::ofstream ofs(dest_file.c_str());

	if (!ifs || !ofs)
	{
		throw std::runtime_error("File can't open!\n");
	}

	const unsigned long* k = reinterpret_cast<const unsigned long*>(key.data());

    unsigned long inptr[2];
    char outbuf[nchar+1];
    outbuf[nchar] = 0;  // terminator
    unsigned long* outptr = reinterpret_cast<unsigned long*>(outbuf);
    ifs.setf(std::ios_base::hex, std::ios_base::basefield);

    while (ifs >> inptr[0] >> inptr[1]) 
	{
        decipher(inptr,outptr,k);
        ofs << outbuf;
    }
}

#endif