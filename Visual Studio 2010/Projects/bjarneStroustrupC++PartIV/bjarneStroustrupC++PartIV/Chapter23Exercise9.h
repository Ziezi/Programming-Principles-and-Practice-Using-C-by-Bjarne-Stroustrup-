/*
	TITLE		   Table checking using eof()					     Chapter23Exercise9.h
	COMMENT
		Objective: Using eof() (§B.7.2), it is possible to detcnninc which line of a table
				   is the last. Use that to (try to) simplify the table-checking program from §23.9.
				   Be sure to test your program with files that end with empty 
				   lines after the table and with files that don't end with a newline at all.  

				   Chapter23Exercise9a.txt   - ends with \n on the last line
				   Chapter23Exercise9b.txt   - empty lines after the table
				   Chapter23Exercise9c.txt   - empty line in the middle
				   Chapter23Exercise9c.txt  - without \n on the last line
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 27.04.2017
*/
#ifndef Chapter23Exercise9_h
#define Chapter23Exercise9_h

template <class T>
T from_string(const std::string& src)
{
	std::stringstream interpreter(src);

	T dest = T();

	if(!(interpreter >> dest))
	{
		throw std::runtime_error("from_string::No operator>> for returning type!\n");
	}
	 
	return dest;
}

//-------------------------------------------------------------------------------------------------------------------

bool is_valid_table(const std::string& header_pattern, const std::string& rows_pattern, const std::string& file_name)
{
	std::ifstream ifs(file_name.c_str());
	if (!ifs)
	{
		throw std::runtime_error("is_valid_table::Can't open input file!\n");
	}

	std::regex header;
	std::regex rows;

	try
	{
		header = header_pattern;
		rows = rows_pattern;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() <<'\n';
		throw std::runtime_error("is_valid_table::invalid regex assignment!\n");
	}

	std::string line;
	int line_number = 0;

	if (getline(ifs, line))
	{
		std::smatch match;

		// header format
		if (!std::regex_match(line, match, header))
		{
			throw std::runtime_error("is_valid_table::Wrong header format!\n");
		}
	}

	int boys = 0;
	int girls = 0;

	while(getline(ifs, line))
	{
		++line_number;
		std::smatch match;

		// row format
		
		if (!std::regex_match(line, match, rows))
		{
			throw std::runtime_error("is_valid_table::Wrong row format!\n");
		}

		if (ifs.eof())
		{
			std::cout <<"At eof!\n";
			return true;
		}

		// row values
		int curr_boy = from_string<int>(match[1]);
		int curr_girl = from_string<int>(match[2]);
		int curr_total = from_string<int>(match[3]);

		if (curr_boy + curr_girl != curr_total)
		{
			throw std::runtime_error("is_valid_table::row sum doesn't check!\n");
		}
		
		// last line
		std::regex ll("Alle klasser"); 
		if (std::regex_search(line, match, ll))
		{
			std::cout << "\nIf there is an additional line under the table this whole block is needed!\n";
			if (curr_boy != boys)
			{
				throw std::runtime_error("is_valid_table::total sum of boys doesn't check");
			}

			if (curr_girl != girls)
			{
				throw std::runtime_error("is_valid_table::total sum of girls doesn't check");
			}

			if (!(ifs >> std::ws).eof())
			{
				throw std::runtime_error("is_valid_table::characters left after total line!\n");
			}

			return true;
		}

		boys += curr_boy;
		girls += curr_girl;
	}

	throw std::runtime_error("is_valid_table::last line missing!\n");
	return false;
}

#endif