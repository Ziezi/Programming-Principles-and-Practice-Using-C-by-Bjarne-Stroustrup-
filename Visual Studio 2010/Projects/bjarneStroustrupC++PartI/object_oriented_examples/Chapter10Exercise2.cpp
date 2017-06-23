/*
	TITLE			   Create a file with 50 hour, temperature pairs    Chapter10Exercise2.cpp
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Write a function that creates a file of data in 
					   the form of temperature Reading.
					   Output format: 
					   (hour of the day [1,24], temperature in Celsius)

					   It creates a file named: Chapter10Exercise2raw_temps.txt,
					   filled with 50 temperature readings. 
				Input: - 
			   Output: -
			   Author: Chris B. Kirov
			     Date: 08.04.2015
*/
#include <iostream>
#include <fstream>
#include <string>
#include <time.h> // time

void populate_file(std::string& file_name);

//===========================================================================================================
int main()
{
	std::string file_name("Chapter10Exercise2raw_temps.txt");

	populate_file(file_name);

	std::cout <<"Done.\n";
}
//===========================================================================================================

/*
	Funtion: random();
	 
	It generates a random
	number in the range [min, max).
*/
int random(int min, int max)
{
	static bool first = true;
	if (first)
	{
		srand((unsigned int)time(NULL));   
		first = false;
	}
	return min + rand() % (max - min);
}
//-----------------------------------------------------------------------------------------------------------

/*
	Function: populate_file(file_name);
	 
	It creates a file: 
	and populates it with 50 random 
	temperature values in the interval 
	[-230,200), in Celsius.

	Output format: (hours, temperatures).
*/
void populate_file(std::string& file_name)
{
	std::ofstream ofs(file_name.c_str());

	if(!ofs)
	{
		std::cerr <<"Can't open output file: " << file_name <<"\n";
	}

	for (int i = 0; i < 50; ++i)
	{
		ofs <<'('<< random(0, 24) <<','<< random(-230, 200) <<')'<<'\n';   
	}
}



