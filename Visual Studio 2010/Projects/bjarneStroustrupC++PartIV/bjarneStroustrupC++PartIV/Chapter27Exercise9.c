/* 
	TITLE	       Ordered Linked List								     Chapter27Exercise9.c 
	COMMENT
		Objective: Using only C facilities, including lhe C standard library, read a sequence 
				   of words from stdin and write them to stdout in lexicographical order.
				   Hint: The C sort function is called qsort(); look it up somewhere.

				   Alternatively, insert the words into an ordered list as you read them. 
				   Theere is no C standard library list.  
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 15.06.2017
*/
#include <stdio.h>
#include <stdlib.h>					// qsort(), 
#include <string.h>					// strcmp()
#include <assert.h>
#include "Chapter27Exercise2.h"
#include "Chapter27Exercise9.h"

#define SIZE 10

int main()
{
	// via_building_ordered_list();
	// via_array_qsort();

	// char* arr[SIZE];
	// populate_array(arr, SIZE);
	// print_str_array(arr, SIZE);
	// clear_array(arr, SIZE);

	getchar();
	getchar();
}