/*
	TITLE		   Words with hex 	     Chapter25Exercise2.cpp
	COMMENT
		Objective: Make a list of words that can be spelled with
				   hexadecimal notation. Read o as 0, read 1 as l
				   read 2 as to, etc. For example, F001 and Beef. 

				   0FF1CE - office
				   B10C - block
				   BAD - bad
				   F00D - food
				   CAFE - caffe
				   C001 - cool
				   DEAD - dead
				   BABE - babe
				   FA11 - fall
				   FACE - face
				   B00C - book
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 12.05.2017
*/
#include <iostream>
#include <string> 
#include <algorithm>
#include <set>

void generate_char_permutations(const std::string& s)
{
	for (auto itb = s.begin(); itb != s.end(); ++itb)
	{
		for (auto ite = itb + 1; ite != s.end(); ++ite)
		{
			// all possible substrings from 1 to s.size()
			std::string substr(itb, ite);

			do
			{
				std::cout << substr <<'\n';
			} 
			while (std::next_permutation(substr.begin(), substr.end()));

			getchar();
		}
	} 
}

//-----------------------------------------------------------------------------------------------------------
 
int main()
{
	try
	{ 
		std::string alphabet("abcdefol "); 

		// There are 46233 (= Sum_{1}^{8}n!) combinations of 1, 2,..,8 letters that could possibly generate a word.
		generate_char_permutations(alphabet);

		// collect them in a set, test against a dictionary
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}