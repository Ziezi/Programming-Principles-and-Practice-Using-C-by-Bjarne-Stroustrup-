/*
	TITLE		    Skip List	            Chapter18Exercise11v2.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Research and implement the data structure:
					Skip List. 
		       
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 27.12.2015
*/
#ifndef CHAPTER18EXERCISE11V2_H
#define CHAPTER18EXERCISE11V2_H 
//====================================================================================================================
struct Skip_Node {
	// node data members
	int key;
	std::string value;

	// pointers to successor nodes
	std::vector<Skip_Node*> forward;

	// constructor
	Skip_Node (int k, const std::string& v, int level); 
};

//====================================================================================================================
class Skip_list {
public:
	// constructors
	Skip_list ();

	// destructor
	~Skip_list ();

	// non - modifying members 
	void print ();
	Skip_Node* find (int searchKey);

	// modifying members
	void insert (int searchKey, std::string newValue);
	void erase (int searchKey); 
	
private:
	// pointer to first node
	Skip_Node* head;
	// last node
	Skip_Node* NIL;

	// implicitly used members
	int randomLevel (); 
	int nodeLevel(const std::vector<Skip_Node*>& v);
	Skip_Node* makeNode (int key, std::string val, int level);

	/*
		Data Member: probability
		It determines the fraction,
		p, or (probability) of the nodes
		with level i that also have 
		level i + 1 pointers.
		In our case p = 0.5 (or 50%).
	*/
	float probability;

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
		lists with elements up to 2^16.
	*/
	int maxLevel;
};

#include "Chapter18Exercise11v2Def.cpp"

#endif