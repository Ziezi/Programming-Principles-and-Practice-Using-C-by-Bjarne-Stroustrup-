/*
	TITLE			   Expand calculator    	 Chapter7Exercise1.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Allow user defined variables with names involving underscores.

			           Enter an epxresion and end it with '=' and CR, 
					   to evaluate.

				Input: -
			   Output: -.
			   Author: Chris B. Kirov
			     Date: 23.02.2015
*/
#include <iostream>
#include <string>
#include <vector>
#include "Chapter7Exercise1.h"

int main()
{
	std::cout << "\t\tWelcome to our calculator!" << std::endl;
	calculate();
}