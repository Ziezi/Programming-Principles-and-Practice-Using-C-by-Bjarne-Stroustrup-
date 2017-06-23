/*
	TITLE			Accumulate sum		     Chapter19Exercise1.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: A function that that adds a vector elements
		            of an object of any type to which elements 
					can be added.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 21.1.2016
*/
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

// function handling all built-in types
template <typename T>
T accumulate_sum (const std::vector<T>& v, T sum = T()) 
{
	// terminate if vector empty 
	assert(v.size());

	// additional argument with a default values is provided
	// T sum = v[0];
	for (size_t i = 0; i < v.size(); ++i) 
	{
		sum += v[i];
	}

	return sum;
}

//--------------------------------------------------------------------

int main ()
{
	try
	{
		std::vector<int> v(5,5);
		int sum;
		sum = accumulate_sum(v);
		std::cout <<"sum: "<< sum <<'\n';

		std::vector<std::string> v1;
		v1.push_back("ab");
		v1.push_back("cd");

		std::string sum1;
		sum1 = accumulate_sum(v1);
		std::cout <<"sum: "<< sum1 <<'\n';
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	catch (...)
	{
		std::cerr << "Unhandled Exception!\n";
	}
	getchar();
}

//--------------------------------------------------------------------

/*
    // To check if the type supports addition  

	#include <utility>
	#include <experimental/type_traits>

	template<class T>
	using add_inc_t = decltype(std::declval<T&>() += std::declval<T>());

	template<class T>
	constexpr auto is_additive_v = std::experimental::is_detected_v<add_inc_t, T>;

	template <typename T>
	T accumulate_sum (const std::vector<T>& v) 
	{
		// terminate if vector empty 
		assert(v.size());

		static_assert(is_additive_v<T>, "the type T needs to be additive by providing operator+");

		T sum = v[0];
		for (size_t i = 1; i < v.size(); ++i) sum += v[i];
		return sum;
	}
*/

// Function that handles objects with specific addition operators
// could be reduced to its data members which need to be built-in types