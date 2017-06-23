/*
	TITLE		    Skip List	            Chapter18Exercise11.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Research and implement the data structure:
					Skip List. 
		       
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 27.12.2015
*/
#ifndef CHAPTER18EXERCISE11_H
#define CHAPTER18EXERCISE11_H

struct Node {
	int key;
	std::string value;
	// pointers to next nodes in the Skip List
	std::vector<Node*> frd_ptr;

	Node (int level, int k, const std::string& v); 
};

Node::Node (int level, int k, const std::string& v)
	: key(k), value(v) 
{
	// initialize all elements to nullptr 
	for (int i = 0; i < level; ++i) frd_ptr.emplace_back(nullptr);
}

//-------------------------------------------------------------------------------------------------------------------

// implicitly used members
/*
	Data Member: probability
	It determines the fraction
	p or (probability) of the nodes
	with with level i pointers that
	also have level i+1 pointers.
	In our case p = 0.5 (or 50%).
*/
double probability = 0.5;

/*
	Data Member: maxLevel
	It detemines the maximum level
	a node can have based on the 
	upper bound of the total elements
	of the list, N.

	maxLevel = L(N), where
	L(N) = log1/p(N).

	The maxLevel = 16 is determined 
	by the fact that the probablilty
	of 0.5 is appropriate for skip 
	lists with elements up to 2^32.
*/
int maxLevel = 16;

//-------------------------------------------------------------------------------------------------------------------
// Helper functuions

/*
	Function: randomLevel()
	Use: int num = randomLevel(int maxLevel, double probability);
	It generates node levels in the range
	[1, maxLevel]. 

	It uses rand() scaled by its maximum 
	value: RAND_MAX, so that the randomly 
	generated numbers are within [0,1).

	Based on the above the returnig values
	of the function are within [1,16).

	Tested for 10000 elements, with results:
	level 1: 2561  level 6: 70   level 11: 4
	level 2: 1225  level 7: 44   level 12: 1
 	level 3: 607   level 8: 17   level 13: 0
	level 4: 312   level 9: 9    level 14: 0
	level 5: 147   level 10: 3   level 15: 0

*/
int randomLevel (int maxLevel = 16, double probability = 0.5) {
	int l = 1;

	while ((((double)std::rand() / RAND_MAX)) < probability && 
		   std::abs(l) < maxLevel) {
		 
		l += 1;
	}

	return abs(l);
}

/*
	Function: nodeLevel()
	Use: int level = nodeLevel(list->frd_ptr);

	It returns the number of non-null pointers
	corresponding to the level of the current node.
	(the node that contains the checked vector of 
	forward pointers)

	If list empty it returns 1.
*/
int nodeLevel (const std::vector<Node*>& ptrs) {
	int currentLevel = 1;
	int nilKey = std::numeric_limits<int>::max();

	if (ptrs[0]->key == nilKey) {
		return currentLevel;
	}

	for (size_t i = 0; i < ptrs.size(); ++i) {

		if (ptrs[i] != nullptr && ptrs[i]->key != nilKey) {
			++currentLevel;
		} else { 
			break;
		}
	}
	return currentLevel;
}

//-------------------------------------------------------------------------------------------------------------------
// non - modifying functions

/*
	Function: print_skip_list ()
	Use: print_skip_list (ptr_to_head);

	It prints the skip list's value and
	key by traversing its first level.
*/
void print_skip_list (Node* head) {
	Node* list = head;
	int lineLenght = 1;

	std::cout <<"{";

	while (list->frd_ptr[0] != nullptr) {
		std::cout <<"value: "<< list->frd_ptr[0]->value
			      <<", key: "<< list->frd_ptr[0]->key
				  <<", level: "<< nodeLevel(list->frd_ptr); 

		list = list->frd_ptr[0];

		if (list->frd_ptr[0] != nullptr) std::cout <<" : ";

		if (++lineLenght % 2 == 0) std::cout <<"\n";
	}
	std::cout <<"}\n";
}

/*
	Function: search_node (Node* list, int searchKey)
	Use: Node* found = search_node (ptr_to_list_head, searchKey);

	Element is searched by traversing forward pointers that
	do not overshoot the node containing the element being
	searched for.

	When no more progress could be made on the current level
	of forward pointers, the search moves down to the next level.

	When further progress couldn't be made, at level 1, we
	must be infront of the desired node or it doesn't exist.
*/
Node* search_node (Node* head, int searchKey) {
	Node* x = head;
	unsigned int currentMaximum = nodeLevel(head->frd_ptr);
	 
	for (unsigned int i = currentMaximum; i-- > 0;) {
		std::cout <<"level: "<< i <<'\n';
		while (x->frd_ptr[i] != nullptr && x->frd_ptr[i]->key < searchKey) {
			std::cout <<"horizontal translation to node: "<< x->value <<'\n'; 
			x = x->frd_ptr[i];
		}	
	}
	x = x->frd_ptr[0];

	if (x->key == searchKey) {
		return x;
	} else {
		return nullptr;
	}
}

//-------------------------------------------------------------------------------------------------------------------
// modifying functions
/*
	Function: makeNode()
	Use: Node* Node_ptr = makeNode(level, key, value);

	It wraps the node constructor which creates
	a node on the heap. 
	
	It returns a pointer 
	to a dynamically allocated node.
*/
Node* makeNode(int level, int key, std::string value) {
	return new Node(level, key, value);
}

/*
	Function: insert_node ()
	Use: insert_node (ptr_to_list_head, searchKey, newValue);

	The insertion is performed though search and splice.

	A vector: update[] is maintained so that when the search
	is complete, update[] contains a pointer to the rightmost
	node of level i or higher, that is to the left of the 
	location of insertion.

	If an insertion generates a node with a level greater than
	the previous maximum level of the list, the maximum level
	of the list is updated and the appropriate portions of 
	update[] are initialized.
*/
void insert_node (Node* head, int searchKey, std::string newValue) {
	// if node exists reassign
	Node* x = nullptr;
	x = search_node(head, searchKey);
	if (x) {
		x->value = newValue;
		return;
	}

	// vector of pointer that need to be updated to account for the new node
	std::vector<Node*> update(head->frd_ptr);
	x = head;
	unsigned int currentMaximum = nodeLevel(head->frd_ptr);

	// search the list till new node's key < n-th successor key && > (n + 1)-th 
	for (unsigned int i = currentMaximum; i-- > 0;) {

		while (x->frd_ptr[i] != nullptr && x->frd_ptr[i]->key < searchKey) {

			x = x->frd_ptr[i];
		}
		update[i] = x;
	}
	x = x->frd_ptr[0];
	
	// create new node
	int newNodeLevel = 1;
	if (x->key != searchKey) {
	
		newNodeLevel = randomLevel();
		int currentLevel = nodeLevel(update);

		if (newNodeLevel > currentLevel) {

			for (int i = currentLevel + 1; i < newNodeLevel; ++i) {

				update[i] = head;
			}	
		}
		x = makeNode(newNodeLevel, searchKey, newValue);
	}
	
	// connect pointers of predecessors and new node
	for (int i = 0; i < newNodeLevel; ++i) {

		x->frd_ptr[i] = update[i]->frd_ptr[i];
		update[i]->frd_ptr[i] = x;
	}
}

/*
	Function: delete_node ()
	Use: delete_node(ptr_to_list_head, searchKey);

	The deletion is performed though search and splice.

	A vector: update[] is maintained so that when the search
	is complete, update[] contains a pointer to the rightmost
	node of level i or higher, that is to the left of the 
	location of insertion.

	After each deletion, a check is performed of whether the
	node with maximum level has been deleted and if so, the
	maximum level of the list is decreased, (by deleting 
	(assigning nullptr) to the appropriate portion of update[]).
*/
void delete_node (Node* head, int searchKey) {
	// vector of pointer that need to be updated to account for the deleted node
	std::vector<Node*> update(head->frd_ptr);
	Node* x = head;
	unsigned int currentMaximum = nodeLevel(head->frd_ptr);

	for (unsigned int i = currentMaximum; i-- > 0;) {

		while (x->frd_ptr[i] != nullptr && x->frd_ptr[i]->key < searchKey) {

			x = x->frd_ptr[i];
		}
		update[i] = x;
	}
	x = x->frd_ptr[0];

	if (x->key == searchKey) {
		for (size_t i = 0; i < update.size(); ++i) {

			if (update[i]->frd_ptr[i] != x) {

				break;
			}
			update[i]->frd_ptr[i] = x->frd_ptr[i];
		}
		delete x;		 
	}	 
}
	
#endif