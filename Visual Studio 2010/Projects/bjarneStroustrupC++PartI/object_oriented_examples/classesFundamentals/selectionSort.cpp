// TITLE	Selection sort algorhitm		selectionSort.cpp
// COMMENT
//			Objective: Sort a set of values by checking for the Minimum value
//					   each time and putting it in front of the set.
//				Input: A vector by reference.
//			   Output: A sorted vector.
//		   Complexity: Quadratic: N^2
#include "stdafx.h"
using namespace std;

void Swap(int& i_th, int& curr_min);

int selectionSort(Vector<int> &v)
{
	for(int i=0; i<v.size()-1; i++)
	{
		int minIndex = i;	// find index of min in range from i to end
		for(int j = i+1; j<v.size(); j++)
		{
			if(v[j]< v[minIndex]) 
			{
				minIndex = j;
			}
		}
		Swap(v[i], v[minIndex]);	// swap min to front	
	}
}

// swap funtion for two vector values 
void Swap(int& i_th, int& curr_min)
{
	int temp = i_th;
	i_th = curr_min;
	curr_min = temp;
}

