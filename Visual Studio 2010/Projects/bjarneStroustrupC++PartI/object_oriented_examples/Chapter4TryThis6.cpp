/* 
   TITLE  		  I/O check 	     			 Chapter4TryThis6.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
       Objective: Read in words using cin, 
			      compare input word with existing list of words
				  if words already exist print "BLEEP" instead of them.
           Input: - 
          Output: -
		  Author: Chris B, Kirov
            Date: 01. 04. 2015

*/
#include "../std_lib_facilities.h"
void check_input(string&);
bool is_defined(string&);

//=========================================================================
int main() 
{	
	 cout <<"Type a sentence:\n>>";
	 string line;
	 getline(cin, line);

	 check_input(line);
}
//=========================================================================

/*
	Function: check_input();
	Use: check_input(a_line_of_input);

	It traverses through the words 
	(passed as parameter) separated by
	whitespace and prints every word
	except the ones matching a list of 
	predefined words.
*/
void check_input(string& input)
{
	stringstream ss(input);

	string word;
	while (ss >> word) 
	{
		if (is_defined(word))
		{
			cout <<" BLEEP";
		}
		else
		{
			cout <<" "<< word;
		}
	}
}

/*
	Function: is_defined()
	Use: bool defined = is_defined(word)

	It compares the parameter to the 
	elements of a vector and if there
	is a match it returns true; otherwise
	it returns false.
*/
bool is_defined(string& word) 
{
	vector<string> defined_words;
	defined_words.push_back("first");	

	for (int i = 0; i < defined_words.size(); ++i) 
	{
		if (defined_words[i] == word) 
		{
			return true;
		}
	}
	return false;
}
 