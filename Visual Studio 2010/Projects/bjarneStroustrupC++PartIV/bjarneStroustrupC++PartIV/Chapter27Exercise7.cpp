/* 
	TITLE	       Intrusive vs non-intrusive      Chapter27Exercise7.cpp
	COMMENT
		Objective: What are the advantages and disadvantages of intrusive 
				   containers compared to C++ standard (non-intrusive) 
				   containers? Make lists of pros and cons. 
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 13.06.2017
*/

/*
	I. Intrusive containers 
		1. Pros:
			- stores the objects themselves.  
			- doesn't involve memory management. (less dynamic memory overhead.)
			- iteration is faster. 
			- better exception guarantees.
			- predictability in insertion and deletion of objects. 
			  (no additional (non-predictable) memory management is required.)
			- better memory locality.
			- 
		2. Cons:
			- contains additional data for container integration. 
			  (every store type must be adapted (modified) to the container requirements.)
			- caution with possible side effects when changing the contents of the stored object.
			  (especially for associative containers.)
			- lifetime management of the inserted object, independently from the container.
			- object can be possibly disposed before erased from the container leading to iterator invalidation.
			- intrusive containers are NON-copyable and NON-assignable.


	II. Non-instrusive containers (C++ standard containers)
		 1. Pros:
			- does not containe additional information regarding the container integration.
			- object's lifetime managed by the container. (less complex.)
		 2. Cons:
			- store copies of values passed by the user.
			- an object can belong only to one container. (or the contaier should store pointers to objects.)
			- overhead on storing copies. (bookkeeping on each allocation.)
			- non-copyable or non-movable objects CAN'T be stored in non-intrusive containers.
			- can't store derived object and still maintain its original type. (slicing - looses polymorphism.)


*/