/*
	TITLE		    Input buffers and strings  Chapter17Exercise8.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Write characters from std::cin into std::string. 
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 07.12.2015
*/
#include <iostream>
#include <string>

int main ()
{
	try 
	{
		std::string s;
		char c, sentinel = '!';
		
		while (true)
		{
			std::cout <<"Type input\n>>";
			std::cin >> c;

			if (c == sentinel)
			{
				break;
			}

			s.push_back(c);
		}

		getchar();

		std::cout <<"Buffer content: \n";
		std::cout << s;
	} 
	catch (std::exception &e) 
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	getchar();
}