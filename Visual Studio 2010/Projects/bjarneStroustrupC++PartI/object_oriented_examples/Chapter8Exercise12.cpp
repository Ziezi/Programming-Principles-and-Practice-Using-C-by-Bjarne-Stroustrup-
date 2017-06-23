/*
	TITLE			   Find statisics      		  Chapter8Exercise12.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++
	COMMENT
			Objective: Write a function that returns
			           the min, max, mean, median and mode
					   of data stored in a vector.
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Date: 11.03.2015
*/
#include <iostream>
#include <string>
#include <vector>
#include <limits>    // std::numeric_limits<_type_>::max() / min()
#include <algorithm> // sort; count
#include <time.h>    // time()
#include <iomanip>   // setprecision(), fixed

/*
	Class: Statistics

	Data structure holding all the wanted
	statistical data.
*/
class Statistics
{
public:
	 Statistics()
		 :  min(0), max(0), mean(0), median(0) 
	 {
	 
	 }

	 void print() const 
	 {
		std::cout <<"Min: "<< std::setprecision(2) << std::fixed << min <<'\n';
		std::cout <<"Max: "<< std::setprecision(2) << std::fixed <<  max <<'\n';
		std::cout <<"Mean: "<< std::setprecision(2) << std::fixed <<  mean <<'\n';
		std::cout <<"Median: "<< std::setprecision(2) << std::fixed <<  median <<'\n';
		std::cout <<"Mode: "<< std::setprecision(2) << std::fixed <<  mode <<'\n';
	 }

	 double min;
	 double max;
	 double mean;
	 double median;
	 double mode;
};

void generateRandomElements(std::vector<double>&, size_t);
void find_statistics(const std::vector<double>&, Statistics&);
double findMax(const std::vector<double>&);
double findMin(const std::vector<double>&);
double findMean(const std::vector<double>&);
double findMedian(const std::vector<double>&);
double findMode(const std::vector<double>&);

//==================================================================================================
int main()
{
	try
	{
		std::cout << "\t\tFind minimum, maximum, mean and median in vector contents.\n";

		// generate a set of random data
		size_t size = 1000;
		std::vector<double> numbers;
		generateRandomElements(numbers, size);

		// find statistics
		Statistics statistics;
		find_statistics(numbers, statistics);

		// print result
		statistics.print();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

//==================================================================================================

/*
	Function: find_statistics(container, statistics)

	It finds min, max, mean,
	mode, median within an object
	Statistics.
*/
void find_statistics(const std::vector<double>& v, Statistics& s)
{
	s.min = findMin(v);
	s.max = findMax(v);
	s.mean = findMean(v);
	s.median = findMedian(v);
	s.mode = findMode(v);
}

/*
	Function: vectorInit(container, n);

	This function initializes the first n elements of
	a vector to a random number.
*/
void generateRandomElements(std::vector<double>& v, size_t n)
{
	srand((unsigned int)time(NULL));

	int lower_bound = 50;
	int upper_bound = 100;
	int range = upper_bound - lower_bound;

	for (size_t i = 0; i < n; ++i)
	{
		v.push_back(rand() % range + lower_bound);
		// std::cout << v[i] <<'\n';
	}
}

/*
	Function: double min = findMax(container);

	It returns the element with the smallest value. 
*/
double findMin(const std::vector<double>& v)
{
	double min = std::numeric_limits<double>::max();
	for (size_t i = 0; i < v.size(); ++i)
	{
		min = (v[i] < min) ? v[i] : min;
	}
	return min;
}

/*
	Function:  double maxElem = findMax(container);

	It returns the element with the greatest value.
*/
double findMax(const std::vector<double>& v)
{
	double max = std::numeric_limits<double>::min();
	for (size_t i = 0; i < v.size(); ++i)
	{
		 max = (v[i] > max) ? v[i] : max;
	}
	return max;
}

/*
	Function: double mean = findMean(container)

	It returns the arithmetic mean.
*/
double findMean(const std::vector<double>& v)
{
	double sum = 0;
	for (size_t i = 0; i < v.size(); ++i)
	{
		sum += v[i];
	}
	return sum / v.size();
}

/*
	Function: double media n= findMode(container);

	It returns the (LAST) element with most frequently
	occuring value.
*/
double findMode(const std::vector<double>& v)
{
	int frequency = std::numeric_limits<int>::min();
	double mode = 0;
	for (size_t i = 0; i < v.size() - 1; ++i)
	{
		 double candidate_mode = v[i];
		 int candidate_frequency = std::count(v.begin(), v.end(), candidate_mode);

		 if (candidate_frequency > frequency)
		 {
			frequency = candidate_frequency;
			mode = candidate_mode;
		 }
	}
	return mode;
}

/*
	Function: double median= findMedian(container);

	It returns the element at the middle of the 
	sorted elements.
*/
double findMedian(const std::vector<double>& v)
{
	std::vector<double> temp(v);
	if (temp.size() % 2 ==0)
	{
		return temp[temp.size() / 2];
	}
	else
	{
		return temp[(temp.size() + 1) / 2];
	}
}