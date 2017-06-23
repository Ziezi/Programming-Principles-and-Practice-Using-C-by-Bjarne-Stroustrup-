/*
	TITLE		    Containers comparison        Chapter20Drill.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: 1. Define an arrray of integers to:
					   { 0, 1, 2, 3, 4, 5, 6, 7, 8 , 9, }. 
					2. Define a vector with the same elements.
					3. Define a list with the same elements.
					4. Define second array, vector and list 
					   initialized as a copy from the first.
					5. Increase each value in the array by 2,
					   in the vector by 3 and by 5 int the list.
					6. Write a copy() function.
					7. Copy the array into the vector and 
					   the list into the array.
					8. Use the standart library find() to see
					   if the vector contains the value 3 and
					   print out its position if it does; 
					   do the same with value 27 in the list.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 17. 02. 2017
*/
#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm>

//-----------------------------------------------------------------------------------

int factor = 2;

//-----------------------------------------------------------------------------------

int increase(int i) 
{
	return i + factor;
}

//-----------------------------------------------------------------------------------

void print(int i)
{
	std::cout << i <<" ";
}

//-----------------------------------------------------------------------------------

// 6.
template<class Iter1, class Iter2>
void m_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	if (f1 == e1)
	{
		return;
	}

	while (f1 != e1)
	{
		*f2 = *f1;

		++f2;
		++f1;
	}
}

//-----------------------------------------------------------------------------------

int main()
{
	try 
	{
		// 1. 
		std::array<int, 10> a = { 0, 1, 2, 3, 4, 5, 6, 7, 8 , 9, };

		// 2. 
		std::vector<int> v(a.begin(), a.end());

		// 3. 
		std::list<int> l(a.begin(), a.end());

		// 4.
		std::array<int, 10> a2 = a;
		std::vector<int> v2 = v; 
		std::list<int> l2 = l;

		// 5.
		std::transform(a2.begin(), a2.end(), a2.begin(), increase);
		std::for_each(a2.begin(), a2.end(), print);

		std::cout <<"\n";

		factor = 3;
		std::transform(v2.begin(), v2.end(), v2.begin(), increase);
		std::for_each(v2.begin(), v2.end(), print); 

		std::cout <<"\n";

		factor = 5;
		std::transform(l2.begin(), l2.end(), l2.begin(), increase);
		std::for_each(l2.begin(), l2.end(), print); 

		std::cout <<"\n";

		// 7.
		m_copy(a.begin(), a.end(), v2.begin());
		std::for_each(v2.begin(), v2.end(), print); 

		std::cout <<"\n";

		m_copy(l2.begin(), l2.end(), a.begin());
		std::for_each(a.begin(), a.end(), print);

		std::cout <<"\n";

		// 8.
		int target_val = 3;
		std::vector<int>::iterator v_iter = std::find(v2.begin(), v2.end(), target_val); 

		if (v_iter != v2.end())
		{
			std::vector<int>::difference_type diff = v_iter - v2.begin();
			std::cout <<"position of value: "<< *v_iter <<" is: "<< diff <<'\n';
		}

		target_val = 27; // 14
		std::list<int>::iterator l_iter = std::find(l2.begin(), l2.end(), target_val);

		if (l_iter != l2.end())
		{
			std::list<int>::iterator temp = l2.begin();
			int position = 0;

			while (temp != l_iter)
			{
				++position;
				++temp;
			}

			std::cout <<"position of value: "<< *l_iter <<" is: "<< position <<'\n';
		}
		else
		{
			std::cout <<"Element not found!\n";
		}
	} 
	catch (std::exception& e) 
	{
		std::cerr << e.what();
	}
	getchar ();
}