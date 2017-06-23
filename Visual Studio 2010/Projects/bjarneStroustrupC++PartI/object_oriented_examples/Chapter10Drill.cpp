/*
	TITLE			   Implement Class Point         	Chapter10Drill.h
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: 1. Write a class Point representing a point in 2D plane.
					      Data members: coordinate x, coordinate y
					   2. Input 7 points.
					   3. Print the 7 points.
					   4. Open a .txt file and write the points to it.
					   5. Close the output file stream, open a input file
					      stream and read and store the points in vector processed_points.
					   6. Print the poins from vectors processed_points and original_points.
					   7. Print error message if the elements of the vectors or their values are different.
				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 03.04.2015
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include"Chapter10Drill.h"

void fill_vector(std::istream& is, std::vector<MyPoint::Point>& v);
void print_vector(std::string& label, std::vector<MyPoint::Point>& v);
void write_to_file(std::string& file_name, std::vector<MyPoint::Point>& v);

//======================================================================================================
int main()
{
	try
	{
		// 2. Input 7 points
		std::vector<MyPoint::Point> original_points;
		std::cout <<"Please type points using the format (x,y); to quit: Ctrl + Z.\n>>";
		fill_vector(std::cin, original_points);
		
		// 3. Print the 7 points.
		std::string input_points = "Input points";
		print_vector(input_points, original_points);

		// 4. Open a .txt file and write the points to it.
		std::string outputFileName = "Chapter10Drill.txt";
		write_to_file(outputFileName, original_points);	
		
		//  5. Close the output file stream, open a input file stream and read and store the points in vector processed_points.
		std::vector<MyPoint::Point> processed_points;
		std::ifstream ifs(outputFileName.c_str());
		fill_vector(ifs, processed_points);

		// 6. Print the poins from vectors processed_points and original_points
		std::string original = "Original Points:";
		print_vector(original, original_points);

		std::string processed = "Processed Points:";
		print_vector(processed, processed_points);

		// 7. Print error message if the elements of the vectors or their values are different.
		if (processed_points != original_points)
		{
			std::cout <<"Something is wrong!\n";
		}
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
//======================================================================================================

/*
	Function: fill_vector();

*/ 
void fill_vector(std::istream& is, std::vector<MyPoint::Point>& v)
{
		if(!is)
		{
			std::cerr <<"Can't open input stream!\n";
		}

		std::string line;
		while(getline(is, line))
		{
			std::stringstream ss(line);
			MyPoint::Point p;

			if (ss >> p)
			{
				v.emplace_back(p);
			}
			else
			{
				std::cerr <<"Wrong input format!\n";
			}
		}
}
//------------------------------------------------------------------------------------------------------

/*
	Function: print_vector();

*/
void print_vector(std::string& label, std::vector<MyPoint::Point>& v)
{
	std::cout << label <<"\n";
	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] <<"\n"; 
	}
}
//------------------------------------------------------------------------------------------------------

/*
	Function: write_to_file();

*/
void write_to_file(std::string& file_name, std::vector<MyPoint::Point>& v)
{
	std::ofstream ofs(file_name.c_str());

	if(!ofs)
	{
		std::cerr <<"Can't open output file!\n";
	}

	for(size_t i = 0; i < v.size(); ++i)
	{
		ofs << v[i] <<"\n";
	}
}


