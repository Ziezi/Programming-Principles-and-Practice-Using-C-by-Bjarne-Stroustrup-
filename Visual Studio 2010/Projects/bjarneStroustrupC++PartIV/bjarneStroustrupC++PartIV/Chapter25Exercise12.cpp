/*
	TITLE		   Decriyption using TEA		Chapter25Exercise12.cpp
	COMMENT
		Objective: Write out the clear text of the example from §25.5.6. 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 15.05.2017
*/
#include <iostream>
#include <fstream>
#include <string>

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


//------------------------------------------------------------------------------------------------------------------

/*
	Receives encrypted text from: src_file and
	writes it as clear text in: std::cout, using
	the reverse TEA and key: the last argument.
*/
void receive_msg(std::string& src_file, 
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

	if (!ifs )
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
        std::cout << outbuf;
    }
}

//------------------------------------------------------------------------------------------------------------------

int main()
{
	try
	{ 
		 std::string file("Chapter25Exercise12.txt");
		 std::string key("bs");

		 receive_msg(file, key);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}