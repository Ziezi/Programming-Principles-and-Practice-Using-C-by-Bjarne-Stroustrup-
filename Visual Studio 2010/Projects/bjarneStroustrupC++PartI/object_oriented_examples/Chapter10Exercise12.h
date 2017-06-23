/*
	TITLE			   Word in a file   	    Chapter10Exercise12.h
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: It prints the line containing a specific word in a file.
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Date: 07.05.2015
*/ 
 

/*
	Function: find_word_in_file();
	 
	It reads the file line by line,
	extracting each whitespace separated
	word; if a word from the line matches
	the second argument the whole line is 
	printed.
*/
void find_word_in_file(std::string& filename, std::string& word)
{
	std::ifstream ifs(filename.c_str());
	if(!ifs)
	{
		std::cerr <<"Can't open input file!\n";
	}

	int line_number = 0;
	std::string line;
	while (getline(ifs, line))
	{
		++line_number;
		std::stringstream ss(line);
		std::string word_from_line;

		while (ss >> word_from_line)
		{
			 if (word_from_line == word)
			 {
				std::cout << line_number <<"  "<< line <<'\n';
			 }
		}
	}
}

