/* 
	TITLE		   Check for unwanted effects	Chapter26Exercise5.cpp
	COMMENT
		Objective: Add a test to the set of binary_search tests 
				   to try to catch the (unlikely) error of a 
				   binary_search modifying the sequence.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 01.06.2017
*/
#include <iostream>
#include <vector>
#include <algorithm>	// std::binary_search
#include <functional>	// std::hash

/*
	To check whether the data had been modified after the use of std::binary_search, 
	a hash function could be used in the following order:
		- apply hash on the data before applying tested algorithm: generate a hash value 1.
		- apply hash on the data after applying tested algorithm: generate a hash value 2.
		- compare hash value 1 and value 2; 
	If value 1 and value 2 identical : data not modified during application of the tested algorithm.
*/
template <typename T>
struct Hash_Vector
{
	std::size_t operator() (const std::vector<T>& v) const 
	{
		std::size_t result = 0;

		std::size_t size = v.size();
		for (std::size_t i = 0; i < size; ++i)
		{
			hash_combine(result, v[i]);
		}

		return result;
	}
};

//----------------------------------------------------------------------------------------------------

template<typename T>
inline void hash_combine(std::size_t& result, const T& element)
{
	result ^= std::hash<T>()(element) + 0x9e3779b9 + (result << 6) + (result >> 2);
}

//----------------------------------------------------------------------------------------------------

int main()
{
	try
	{
		std::vector<int> data(10);
		for (std::size_t i = 0; i < 10; ++i)
		{
			data[i] = i;
		}

		Hash_Vector<int> hv;
		std::size_t value_1 = hv(data);

		if (std::binary_search(data.begin(), data.end(), data[0]))
		{
			std::cout <<"Value found.\n";
		}
		else
		{
			std::cout <<"Value NOT found!\n";
		}

		// data[0] = 1;
		// std::swap(data[0], data[1]);
		std::size_t value_2 = hv(data);

		if (value_1 == value_2)
		{
			std::cout <<"Data unaltered by std::binary_search.\n";
		}
		else
		{	
			std::cout <<"Data altered by std::binary_search!\n";
			std::cout <<"Hash 1: "<< value_1 <<" Hash 2: " << value_2 <<'\n';
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}