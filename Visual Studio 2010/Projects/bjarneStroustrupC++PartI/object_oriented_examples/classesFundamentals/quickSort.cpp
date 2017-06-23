/*
   TITLE	           Quick-sort algorithm		quickSort.cpp
   COMMENT
 			Objective: 
 				Input: Unsorted vector by reference.
 			   Output: Sorted vector.
 		   Complexity: Linearithmic: NlogN.
		       Author: Chris B. Kirov
 			     Date: 01.01.2015
*/
#include "stdafx.h"
using namespace std;

void Swap(int& lh_element, int& rh_element);

int Partition (vector<int>& arr, int start, int stop){
	int lh = start + 1, rh = stop, pivot;

	pivot = arr[start];
	while(true){
		while (lh < rh && arr[rh] >= pivot) { rh--; }
		while (lh < rh && arr[lh] < pivot) { lh++; }
		if(lh == rh) break;
		Swap(arr[lh], arr[rh]);
		// invariant: arr[start+1...lh] < pivot && arr[rh...stop] >= pivot
	}
	if (arr[lh] >= pivot) { return start; }
	Swap(arr[start], arr[lh]);
	return lh;
}

void quickSort (vector<int>& arr, int start, int stop){
	if (stop > start){
		int pivot = Partition(arr, start, stop);
		quickSort(arr, start, pivot -1);
		quickSort(arr, pivot + 1, stop);
	}
}