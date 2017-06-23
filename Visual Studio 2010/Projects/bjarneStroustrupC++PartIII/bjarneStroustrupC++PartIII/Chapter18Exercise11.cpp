/*
	TITLE		    Skip List	            Chapter18Exercise11.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Research and implement the data structure:
					Skip List. 
		           
					References to the papers by W. Pugh:
					http://epaperpress.com/sortsearch/download/skiplist.pdf

					http://cglab.ca/~morin/teaching/5408/refs/p90b.pdf
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 27.12.2015
*/
#include <iostream>
#include <time.h>
#include <string>
#include <vector>

#include "Chapter18Exercise11.h"

 
//==================================================
int main () {
	 
	 // Initialize a skip list
	
	 // 1. Create last NIL element of with level = maxLevel and key = maxKey
	 int nilLevel = 16;
	 // last element key is the largest
	 int nilKey = std::numeric_limits<int>::max();
	 std::string  nilValue = "a";
	 Node* NIL = new Node (nilLevel, nilKey, nilValue);


	 // 2. Create first header elemenent with level = maxLevel and connect with the last
	 int headLevel = nilLevel;
	 // first element key is the smallest (not ever checked)
	 int headKey = -1;
	 std::string headValue = "a";
	 Node* head = new Node (headLevel, headKey, headValue);

	 // connect all the levels/ forward pointers of the header to NIL
	 for (size_t i = 0; i < head->frd_ptr.size(); ++i) {
		 head->frd_ptr[i] = NIL;
	 }




	 // Test skip list functions

	 // 3. Insert new node
	 int firstKey = 1;
	 std::string firstVal = "b";
	 insert_node (head, firstKey, firstVal);

	 int key = 2;
	 std::string val;
	 for (int i = 2; i < 20; ++i) { 

		 val = (i + '0');
		 insert_node (head, i, val);
	 }

	 print_skip_list(head);
	 
	 std::cout <<"\n\n\n";


	 // 3a. Find a node
	 for (int i = 0; i < 20; ++i) {
		
		Node* found = nullptr;
		found = search_node(head, i);
		if (found) std::cout <<"Node Found! Value: "<< found->value <<'\n';
		else std::cout <<"No node with key: "<< i <<"\n";
	 }


	 // 4. Reassing a new value to an already existing node
	 int secondKey = 5;
	 std::string secondVal = "HRISTO";
	 insert_node (head, secondKey, secondVal);
	 print_skip_list(head);
	 

	 // 4a. Find reassigned node
	 Node* found2 = nullptr;
	 found2 = search_node(head, secondKey);
	 if (found2) std::cout <<"Found!\nreassigned value: "<< found2->value <<'\n';


	 // 5. Delete a node
	 // delete the above node
	 delete_node (head, secondKey);
	 print_skip_list(head);


	 // 5a. Find a deleted node
	 Node* found3 = nullptr;
	 found3 = search_node(head, secondKey);
	 if (found3) std::cout <<"Found!\nreassigned value: "<< found3->value <<'\n';
	 else std::cout <<"Node not found!\n";

	 // MEMORY NOT FREED!

	 std::cout << "\nDone!\n";
	 getchar();	 
}
//==================================================
 
