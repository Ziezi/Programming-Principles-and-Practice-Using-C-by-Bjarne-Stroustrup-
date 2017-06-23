/*
	TITLE		   Merge rows of table  			     Chapter23Exercise10.h
	COMMENT
		Objective: Modify the table-checking program from §23.9 to write a new
				   table where the rows with the same initial digit are merged.
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 27.04.2017
*/
#ifndef Chapter23Exercise10_h
#define Chapter23Exercise10_h

/* Represents rows of the table containing digits. */
struct table_data
{
	int boys;
	int girls;
	int total;
};

//----------------------------------------------------------------------------------------------

/* Reads src file, merges rows with same 1st digit and writes to dest file. */
void merge_rows(const std::string& src, const std::string& dest, std::map<char, table_data>& m)
{
	std::ifstream ifs(src.c_str());						// read initial data from file
	if (!ifs) 
	{
		throw std::runtime_error("Can't open input file!\n");
	}

	std::regex row_pattern("^[\\w\\s]+(\\t[\\d]+)(\\t[\\d]+)(\\t[\\d]+)$"), h("KLASSE"), l("Alle klasser"); 
	std::string line, header_line, last_line;
	std::smatch match;

	while(getline(ifs, line))
	{
		if (std::regex_search(line, match, h))			// store header
		{
			header_line = line;
		}

		if (std::regex_match(line, match, row_pattern)) // merge rows starting with same digit
		{
			char grade_digit = match[0].str()[0];
			int curr_boys = from_string<int>(match[1]);
			int curr_girls = from_string<int>(match[2]);
			int curr_total = from_string<int>(match[3]);
			
			if (isdigit(grade_digit) || grade_digit == 'R')
			{
				m[grade_digit].boys += curr_boys;		// store merged rows with same first digit
				m[grade_digit].girls += curr_girls;
				m[grade_digit].total += curr_total;
			}
		}

		if (std::regex_search(line, match, l))			// store last line
		{
			last_line = line;
		}
	}
		
	std::ofstream ofs(dest.c_str());					// write merged data to file
	if (!ofs)
	{
		throw std::runtime_error("Can't open output file!\n");
	}

	ofs << header_line <<"\n";
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		ofs << it->first <<"\t"<< it->second.boys <<"\t"<< it->second.girls <<"\t"<< it->second.total <<"\n";
	}
	ofs << last_line <<"\n";
	std::cout <<"merge_rows::Done!\n";
}

#endif
