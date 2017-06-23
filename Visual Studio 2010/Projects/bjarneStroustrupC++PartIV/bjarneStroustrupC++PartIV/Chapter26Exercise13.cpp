/* 
	TITLE		   Random length string sorting		    Chapter26Exercise13.cpp
	COMMENT
		Objective: Write a program that generates random length [0,100) strings 
				   and sorts them using std::sort. 
				   Measure the time used to sort 500,000 and 5,000,000 strings.  
			Input: -
		   Output: Size: 50			Time: 0
				   Size: 500		Time: 0.009
				   Size: 5000		Time: 0.096
				   Size: 50000		Time: 1.127
				   Size: 500000		Time: 13.697
				   Size: 5000000	Time: 13.697
				   Size: 50000000	Time: 168.081  
		   Author: Chris B. Kirov
			 Date: 08.06.2017
*/
#include <iostream>
#include <algorithm>	// std::generate, std::copy
#include <string>
#include <vector>
#include <ctime>		// std::time
#include <time.h>		// std::clock

int random(int min, int max) 
{ 
	return min + (rand()) / (RAND_MAX / (max - min)); 
}

//---------------------------------------------------------------------------------------
 
std::string get_random_string()
{
	 static const char alphanum[] =
		"0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

	 int size = random(0, 100);
	 std::string rand_str(size, '0');

	 for (int i = 0; i < size; ++i)
	 {
		rand_str[i] = alphanum[ rand() % (sizeof(alphanum) - 1) ];
	 }
	 
	 return rand_str;
}

//---------------------------------------------------------------------------------------

void populate_vector(std::vector<std::string>& v)
{
	srand((unsigned int)time(0));
	std::generate(v.data(), v.data() + v.size(), get_random_string); 
}

//---------------------------------------------------------------------------------------

void test_sort()
{
	int max = 5000000;
	for (auto i = 50; i <= max; i *= 10)
	{
		std::vector<std::string> v(i);
		populate_vector(v);

		std::clock_t t = clock();

		std::sort(v.begin(), v.end());

		t = clock() - t;

		double time = double(t) / CLOCKS_PER_SEC;

		std::cout <<"Size: "<< v.size() <<"\tTime: "<< time <<'\n';
	}
}

//---------------------------------------------------------------------------------------

int main()
{
	try
	{
		test_sort();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}