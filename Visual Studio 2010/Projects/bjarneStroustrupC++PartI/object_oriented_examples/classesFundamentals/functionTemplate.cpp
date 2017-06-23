/* 
   TITLE	           Use swap function with any primitive type		funtionTemplate.cpp
   COMMENT
 			Objective: Generalise function input types.
 				Input: Elements of any primitive type.
 		       Output: - (swapped elements not printed).
			   Author: Chris B. Kirov
			     Date: 01.01.2015
*/
#include "stdafx.h"
using namespace std;

// definition of swap function template.
template <typename Type>
void SwapPrimType (Type a, Type b){
	Type temp = a;
	a = b;
	b = temp;
}

// definition of selection sort function template.
template <typename T>
void selectionSortPrimType (vector<T>& v){
	for(int i = 0; v.size() -1; i++){
		int minIndex = i;
		for (int j = i+1; j < v.size(); j++){
			if(v[j] < v[minIndex]) { minIndex = j; }
		}
		swapAnyType(v[i],v[minIndex]);
	}
}

// To use the above functions with any type: primitive or class/struct defined
// we need a callback function (comparison function "cmp" specifically for the constructed type)
// provided by the type class, as parameter in the sort algorithm function.
template <typename T>
void sortAnyType (vector<T>& v, int (cmp)(T, T)){
	for (int i = 0; i < v.size()-1; i++){
		int minIndex = i;
		for (int j= i+1; j < v.size(); j++){
			if (cmp(v[j],v[minIndex]) < 0 )	{ minIndex = j; }
		}
		SwapPrimType(v[i],v[minIndex]);
	}
}

// Class defining Coordinates for comparison.
class Coord{
public:
	double x, y;
	Coord(): x(0),y(0) { }
	Coord(double a, double b): x(a), y(b) { }
};

// Supplying callback function for Coord class data member comparison.
int CoordComp(Coord a, Coord b){
	if (a.x < b.x) return (-1);				// If the compared coordinates have same x-values, brake the tie by
	else if (a.x > b.x) return (1);									
	else if (a.y < b.y) return (-1);		// comparing the y-coordinates.
	else if (a.y > b.y) return (1);
}

// default compare fucntion
template <typename T>
int compareDefault (T one, T two){
	if (one == two) { return 0;}
	return (one < two ? -1 : 1)
}

// to invoke sort algorithm in the main()
// sortAnyType(vector_object<class_type>, callback_funcion)
// in our example
// sortAnyType(vector_object<Coord>, CoordComp)

// to initialize the default comparison function 
// we equate it in the parameter list of the sort algorithm
// sortAnyType(vector_object<class_type> callback_function = default)
// sortAnyType(vector_object<Coord>,retun_type CoordComp(par1,par2) = comapreDefault)

// To sort in reverse orded we use Reverse comparison function when calling the sorting algorithm

int ReverseCmp(int a, int b){
	if (a < b) return 1;
	else if(a > b) return -1;
	return 0;
}