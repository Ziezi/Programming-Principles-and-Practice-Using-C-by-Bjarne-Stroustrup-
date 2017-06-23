// TITLE		Insertion sort algorithm	insertionSort.cpp
// COMMENT
//			Objective: Sort a set of values by checking each element and 
//					   swapping two neighboring elements if the one with
//					   greater index is smaller than the previous.
//				Input: A Vector by reference.
//			   Output: Sorted vector.

#include "stdafx.h"
using namespace std;

void insertionSort(Vector<int>& arr)
{
	for(int i = 0; i < arr.size(); i++)
	{
		int j, current = arr[i];
		for (j = i-1; j >= 0 && arr[j] > current; j--)
		{
			arr[j+1] = arr[j];	// slide the "current" element back so that there is no smaller element before it
		}
		arr[j+1] = current;		// go on next element
	}
}