// TITLE	Mergesort Algorithm		mergeSort.cpp
// COMMENT
//			Objective: Sort a vector by recursivelly dividing it to basic elements, followed by merging them in order.
//				Input: Unsorted vector.
//		       Output: Sorted vector
//		   Complexity: Linearithmic: N.logN 
#include "stdafx.h"
using namespace std;


// both declarations are not in completed form
// copy part of the vector into new vector 
vector<int> Copy(vector<int>& v,int beg_index, int size);
// merge, sorting the divided vectors
void merge (vector<int>& v, vector<int>& left, vector<int>& right);

void mergeSort(Vector<int> &v)
{
	if (v.size() > 1)
	{
		int n1= v.size()/2;
		int n2 = v.size() - n1;
		vector<int> left = Copy(v, 0, n1);
		vector<int> right = Copy(v, n1, n2);
		mergeSort(left);
		mergeSort(right);
		merge(v, left, right);
	}	
}



