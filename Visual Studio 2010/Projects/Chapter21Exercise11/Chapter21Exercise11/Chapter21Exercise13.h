/*
	TITLE		    Clean up text file		 Chapter21Exercise13.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: "clean up" a text file for use in a word query program; 
					that is, replace punctuation with whitespace,
					put words into lower case, 
					replace "don't" with "do not" (etc.), 
					and remove plurals (e.g., ships becomes ship).
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 04. 03. 2017
*/

#ifndef Chapter21Exercise13_h
#define Chapter21Exercise13_h

void to_lowercase (std::string& src)
{
	std::transform(src.begin(), src.end(), src.begin(), ::tolower);
}

//------------------------------------------------------------------------

 
void remove_punctuation (std::string& src)
{
	std::replace_if(src.begin(), src.end(), [] (const char& c) { return ::ispunct(c); }, ' ');
}

//------------------------------------------------------------------------

void remove_plurals (std::string& src)
{
	if (src.back() == 's')
	{
		src.pop_back();
	}
}

//------------------------------------------------------------------------

void replace_word_if (std::string& src, const std::string& target, const std::string& dest)
{
	if (!src.compare(target))
	{
		src.assign(dest); 
	}
}

//------------------------------------------------------------------------

void cleaup_text_file(const std::string& input_file_name, 
					  std::vector<std::string>& modified_text,
					  const std::string& output_file_name)
{
	std::ifstream ifs(input_file_name.c_str());

	if (!ifs)
	{
		throw std::runtime_error("Can't open input file!\n");
	}

	std::string initial_line;
	while (getline(ifs, initial_line))
	{
		
		std::stringstream ss(initial_line);
		std::string modified_line;
		std::string word;

		while (ss >> word)
		{
			// apply modifications
			to_lowercase(word);
			replace_word_if(word, "can't", "can not");
			replace_word_if(word, "don't", "do not");
			remove_plurals(word);
			remove_punctuation(word);

			// contruct modified line
			modified_line.append(" ");
			modified_line.append(word);

			// avoid accumulation
			word = std::string();
		}

		modified_text.push_back(modified_line);

		// avoid accumulation
		ss = std::stringstream();
		initial_line = std::string();
	}

	ifs.clear();
	ifs.close();

	// write modified text back to same file 
	std::ofstream ofs(output_file_name.c_str());

	if (!ofs)
	{
		throw std::runtime_error("Can't open output file!\n");
	}
	
	for (size_t i = 0; i < modified_text.size(); ++i)
	{
		ofs << modified_text[i] <<'\n';
	}
}


#endif 