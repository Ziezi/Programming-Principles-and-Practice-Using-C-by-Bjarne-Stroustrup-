/* 
	TITLE		   Test      				    Chapter26Drill1.cpp
	COMMENT
		Objective: Implement the input operator Test from §26.3.2.2.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 30.05.2017
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
		- for targets larger and smaller than the elemens in the container.  
		- with pointers and iterators.
		- with array and std::vector of type int; with empty containers.
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

//--------------------------------------------------------------------

struct Test
{
	std::string label;
	int val;
	std::vector<int> seq;
	bool res;
};

//--------------------------------------------------------------------

/*
	Input format: int, int, int 
*/
std::istream& operator>> (std::istream& is, std::vector<int>& v)
{
	if (!is)
	{
		return is;
	}

	int val;

	while (is >> val)
	{
		v.push_back(val);

		if (is.peek() == ',' || is.peek() == ' ')
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

//--------------------------------------------------------------------

/*
	Input format: { string int { int, int,... } bool }
	{ Test_name target_val { int_seq } expected_res }
*/
std::istream& operator>> (std::istream& is, Test& t)
{
	if (!is)
	{
		return is;
	}

	char op1, cp1, op2, cp2;
	std::string test_name;
	int target_value;
	
	is >> op1 >> test_name >> target_value >> op2;

	if (!is || op1 != '{' || op2 != '{')
	{
		is.setf(std::ios_base::failbit);
		return is;
	}

	std::vector<int> sequence;
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

//--------------------------------------------------------------------

int test_all(std::istream& is, std::ostream& os)
{
	int error_count = 0;
	Test t;

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
	}

	return error_count;
}

//--------------------------------------------------------------------

int main()
{
	try
	{
		std::string ifile("Chapter26Drill1Tests.txt");
		std::string ofile("Chapter26Drill1Results.txt");

		std::ifstream ifs(ifile.c_str());
		std::ofstream ofs(ofile.c_str());

		if (!ifs || !ofs)
		{
			throw std::runtime_error("Can't open file!\n");
		}

		std::cout <<"Errors: " << test_all(ifs, std::cout) <<'\n';
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}
