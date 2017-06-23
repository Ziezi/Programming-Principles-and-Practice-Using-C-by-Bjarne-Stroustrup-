/*
	TITLE		    Vectors                     Chapter18TryDriil2.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Drill 2
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 23.12.2015
*/
#include <iostream>
#include <vector>

// 1. Defina a global vector and initialize it with 10 ints: 1,2,4,8,16 etc;
std::vector<int> gv(10);  

// 2. Define f(), taking vector<int> argument
void f(const std::vector<int>& v);

unsigned int factorial (unsigned int i);

//---------------------------------------------------------------------------------------

int main () {

	try
	{
		for (size_t i = 0; i < gv.size(); ++i)
		{
			gv[i] = (int) pow(2.0, double (i));
		}

		// 4 In main:

		// a. call f() with gv 
		f(gv);

		// b. define a vector vv and initialize its values to the 10 first factorials
		std::vector<int> vv;
		for (int i = 0; i < 10; ++i) 
		{
			vv.push_back(factorial(i));
		}

		// c. call f with vv
		f(vv);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	catch (...)
	{
		std::cerr << "Unhandled exception!\n";
	}

	getchar();
}

//---------------------------------------------------------------------------------------

// 3. In f();
void f(const std::vector<int>& v)
{
	// a. define a local vector with same number of elements as v

	// b. copy the values from gv to lv
	std::vector<int> lv(gv);

	// c. print out the values of lv
	for (auto it = lv.begin(); it != lv.end(); ++it) 
	{
		std::cout << *it <<" ";
	}
	std::cout <<"\n";

	// d. define a local vector lv2 and initialize it to be copy of the argument 
	std::vector<int> lv2(v);

	// e. print out the elements of lv2
	for (auto it = lv2.begin(); it != lv2.end(); ++it)
	{
		std::cout << *it <<" ";
	}
	std::cout <<"\n";
}

//---------------------------------------------------------------------------------------

unsigned int factorial (unsigned int i) 
{
	if (i <= 1)
	{
		return 1;
	}

	return i * factorial(--i);
}