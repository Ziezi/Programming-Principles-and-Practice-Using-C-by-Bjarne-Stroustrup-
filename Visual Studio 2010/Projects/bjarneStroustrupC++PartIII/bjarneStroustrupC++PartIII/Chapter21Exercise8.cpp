/*
	TITLE		    Word frequency   		 Chapter21Exercise8.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Take the word frequency example from §21.6.1 and
					and modify it to to output its lines in order of 
					frequency.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 28. 02. 2017
*/
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	try
	{
		std::string file("Chapter21Exercise8.txt");
		std::ifstream ifs(file.c_str());

		if (!ifs)
		{
			throw std::runtime_error("Can't open input file!\n");
		}

		std::map<std::string, int> word_frequency;

		std::string word;
		while (ifs >> word)
		{
			++word_frequency[word];
		}

		std::vector<std::pair<int, std::string>> v;
		for (auto it = word_frequency.begin(); it != word_frequency.end(); ++it)
		{
			v.emplace_back(make_pair(it->second, it->first));
		}

		std::sort(v.begin(), v.end());
		for (auto it = v.begin(); it != v.end(); ++it)
		{
			std::cout << it->first <<": "<< it->second <<'\n';
		}

	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}