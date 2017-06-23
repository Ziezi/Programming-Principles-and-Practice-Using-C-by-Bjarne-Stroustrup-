/* 
	TITLE		   Test Binary_search	  Chapter26Exercise1.h
	COMMENT
		Objective: Run your binary search algorithm from §26.1 
				   wilh the tests presented in §26.3.2.1. 
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 31.05.2017
*/

#ifndef Chapter26Exercise1_h
#define Chapter26Exercise1_h

//------------------------------------------------------------------------------------------------

/*
	Asssumes sorted containers.

	Parameters: 
		target - wanted value.
		begin - pointer/iterator to begining of container.
		end- pointer/iterator to end of container.
	Returns:
		- pointer/iterator to found element 
		- parameter: end, if element not found.
	Complexity: 
		O(logN)
	Exception Safety:
		- Basic exception safety.
	Tested:
		- for elements at all positions: [0, size - 1].
		- for targets larger and smaller than the elements in the container.  
		- with pointers and iterators.
		- with array and std::vector of type int, float and std::string; with empty containers.
*/
template<typename T, typename it>
bool binary_search(it begin, it end, const T& target)
{
	 while (begin != end)
	 {
		auto offset = std::distance(begin, end);
		it middle = begin;
		std::advance(middle, offset / 2);

		if (target == *middle)
		{
			return true;
		}
		else if (target < *middle)
		{
			end = middle;
			// std::advance(end, -1); // forward iterators
		}
		else 
		{
			begin = middle;
			std::advance(begin, 1);
		}
	 }

	 return false;
}

//------------------------------------------------------------------------------------------------

template <typename T>
struct Test
{
	std::string label;
	T val;
	std::vector<T> seq;
	bool res;
};

//------------------------------------------------------------------------------------------------

/*
	Input format: T , T , T
*/
template <typename T>
std::istream& operator>> (std::istream& is, std::vector<T>& v)
{
	if (!is || is.peek() == '}') // empty sequence
	{
		return is;
	}

	T val;

	while (is >> val)
	{
		v.push_back(val);

		while (is.peek() == ' ')
		{
			is.ignore();
		}

		if (is.peek() == ',')
		{
			is.ignore();
		}

		if (is.peek() == '}')
		{
			break;
		}
	}

	return is;
}

//------------------------------------------------------------------------------------------------

/*
	Input format: { string T { T , T , ..., TN } bool }
	{ Test_name target_val { T1 , T2, T3 , ... , TN } expected_res }
*/
template <typename T>
std::istream& operator>> (std::istream& is, Test<T>& t)
{
	if (!is)
	{
		return is;
	}

	char op1, cp1, op2, cp2;
	std::string test_name;
	T target_value;
	
	is >> op1 >> test_name >> target_value >> op2;

	if (!is || op1 != '{' || op2 != '{')
	{
		is.setf(std::ios_base::failbit);
		return is;
	}

	std::vector<T> sequence;
	bool expected_result;
	
	is >> sequence >> cp1 >> expected_result >> cp2;
	
	if (!is || cp1 != '}' || cp2 != '}')
	{
		is.setf(std::ios_base::failbit);
		return is;
	}

	t.label = test_name;
	t.val = target_value;
	t.seq = sequence;
	t.res = expected_result;

	return is;
}

//------------------------------------------------------------------------------------------------

template <typename T>
bool test_all(std::istream& is, std::ostream& os)
{
	int error_count = 0;
	int tests_passed = 0;
	Test<T> t;

	while (is >> t)
	{
		bool r = binary_search(t.seq.begin(), t.seq.end(), t.val);

		if (r != t.res)
		{
			os <<"failure: test "<< t.label 
			   <<" binary_search: "<< t.seq.size() <<" elements"
			   <<" , target value: "<< t.val <<"->"<< t.res <<'\n';

			++error_count;
		}
		++tests_passed;
	}

	os <<"Tests passed: "<< tests_passed <<'\n';
	os <<"Errors: "<< error_count <<'\n';

	return (error_count == 0);
}

#endif