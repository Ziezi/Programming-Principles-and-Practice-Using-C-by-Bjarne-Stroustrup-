/*
	TITLE		    Text statistics 		 Chapter21Exercise14.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Write a program (using the output from the previous exercise) to answer
					questions such as:
					"How many occurrences of ship are ther in a file?"
					"Which word occurs most frequently?" 
					"Which is the longest word in the file?" 
					"Which is the shortest?" 
					"List all words starting with s."
					"List all four-letter words." 
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 06. 03. 2017
*/

#ifndef Chapter21Exercise14_h
#define Chapter21Exercise14_h

void populate_map(const std::vector<std::string>& modified_text, std::map<std::string, int>& dictionary)
{
	for (size_t i = 0; i < modified_text.size(); ++i)
	{
		std::string line = modified_text[i];

		std::stringstream ss(line);

		std::string word;
		while (ss >> word)
		{
			++dictionary[word];
			word = std::string();
		}
	}
}

//------------------------------------------------------------------------

int find_occurrences_of(const std::string& target, std::map<std::string, int>& dictionary)
{
	std::map<std::string, int>::iterator found = dictionary.find(target);

	if (found != dictionary.end())
	{
		return found->second;
	}
	return 0;
}

//------------------------------------------------------------------------

std::string find_mode(std::map<std::string, int>& dictionary) 
{
	auto mode = std::max_element(dictionary.begin(), dictionary.end(),
		 [](const std::pair<std::string, int>& lhs, const std::pair<std::string, int>& rhs)
		 { return lhs.second < rhs.second; } );

	return mode->first;
}

//------------------------------------------------------------------------

std::string find_longest_word(std::map<std::string, int>& dictionary) 
{
	auto longest = std::max_element(dictionary.begin(), dictionary.end(),
		 [](const std::pair<std::string, int>& lhs, const std::pair<std::string, int>& rhs)
		 { return lhs.first.size() < rhs.first.size(); } );

	return longest->first;
}

//------------------------------------------------------------------------

std::string find_shortest_word(std::map<std::string, int>& dictionary) 
{
	auto shortest = std::min_element(dictionary.begin(), dictionary.end(),
		 [](const std::pair<std::string, int>& lhs, const std::pair<std::string, int>& rhs)
		 { return lhs.first.size() < rhs.first.size(); } );

	return shortest->first;
}

//------------------------------------------------------------------------

struct Starts_with 
{    
    Starts_with(char c) : target(c) { }
    bool operator()(const std::pair<std::string, int>& src) const { return src.first[0] == target; }
	char target;
};

//------------------------------------------------------------------------

std::vector<std::string> find_words_starting_with(std::map<std::string, int>& dictionary, char target)
{
	size_t size = std::count_if(dictionary.begin(), dictionary.end(), Starts_with(target));
	std::vector<std::pair<std::string, int>> s_pairs(size);
	std::copy_if(dictionary.begin(), dictionary.end(), s_pairs.begin(), Starts_with(target));
	 
	std::vector<std::string> s_words;
	for (auto it = s_pairs.begin(); it != s_pairs.end(); ++it)
	{
		s_words.push_back(it->first);
	}

	return s_words;
}

//------------------------------------------------------------------------

struct Length_of
{    
    Length_of(size_t l) : target(l) { }
    bool operator()(const std::pair<std::string, int>& src) const { return src.first.size() == target; }
	size_t target;
};

//------------------------------------------------------------------------

/* template <class Container, class Predicate, class T> could be used for the last 2 functions */
std::vector<std::string> find_words_of_length (std::map<std::string, int>& dictionary, size_t target)
{
	size_t size = std::count_if(dictionary.begin(), dictionary.end(), Length_of(target));
	std::vector<std::pair<std::string, int>> l_pairs(size);
	std::copy_if(dictionary.begin(), dictionary.end(), l_pairs.begin(), Length_of(target));
	 
	std::vector<std::string> l_words;
	for (auto it = l_pairs.begin(); it != l_pairs.end(); ++it)
	{
		l_words.push_back(it->first);
	}

	return l_words;
}

#endif