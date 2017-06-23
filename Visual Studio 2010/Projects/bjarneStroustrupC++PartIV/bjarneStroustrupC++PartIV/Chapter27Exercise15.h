/* 
	TITLE	       Simulate single inheritance in C.        				    Chapter27Exercise15.h 
	COMMENT
		Objective: Let each "base class" contain a pointer to an array of pointers to functions 
				   (to simulate virtual functions as free standing functions taking a pointer to 
				   a "base class" object as their first argument see §27.2.3. 
				   Implement "derivation" by making the "base class" the type of the first member 
				   of the derived class. For each class, initialize the array of "virtual functions" 
				   appropriately. 
				   To test the ideas, implement a version of "the old Shape example" with the base and 
				   derived draw() just printing out the name of their class. Use only language features 
				   and library facilities available in standard C.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 20.06.2017
*/
#ifndef Chapter27Exercise15_h
#define Chapter27Exercise15_h

struct Base_class;	// forward declaration; to be used in Base_function_table

//--------------------------------------------------------------------------------------------------

// instead of array of function pointers
typedef struct 
{
	void (*Base_class) (struct Base_class*);		// consrtuctor-like
	void (*print_base) (struct Base_class*);		// print data members 
} Base_function_table;

//--------------------------------------------------------------------------------------------------

typedef struct Base_class
{
	char* name;
	Base_function_table* virtual_tbl;				// pointer to function pointers: (class (virtual) member functions in C)
} Base_class;

//--------------------------------------------------------------------------------------------------

// forward declarations of functions to initialize the pointers to functions in Base_function_table
void initialize_base(Base_class* tthis);
void print_base(Base_class* tthis);

//--------------------------------------------------------------------------------------------------

// initialize the function pointers 
Base_function_table Base_tbl = { initialize_base, print_base };

//--------------------------------------------------------------------------------------------------

// enumerator representing the type of the derived class; used in (member) functions to discriminate object types.
typedef enum Type { derived1, derived2, derived3 } Type;

//--------------------------------------------------------------------------------------------------

struct Derived_1; // forward declaration; to be used in Derivesd_function_table

//--------------------------------------------------------------------------------------------------

// instead of array of function pointers
typedef struct 
{
	void (*Derived_1) (struct Derived_1*);
	void (*print_derived) (struct Derived_1*);
} Derived_function_table;

//--------------------------------------------------------------------------------------------------

// derived class
/*
	Assumes the offset of the member base is 0. 
	(i.e. there is NOT an additional (run-time, vtable (in C++))
	information stored implicitly by the compiler before base).
	An extra pointer, before base, could be added to work around 
	this issue.
*/
typedef struct Derived_1
{
	Base_class base;	// placing the base class as the first data member indicates "inheritance" from base class
	int value;			// additional data member
} Derived_1;

//--------------------------------------------------------------------------------------------------

// forward declarations of functions to initialize the pointers to functions in Derived_function_table
void initialize_derived (Derived_1*  tthis);
void print_derived (Derived_1* tthis);
 
//--------------------------------------------------------------------------------------------------

Derived_function_table Derived_tbl = { initialize_derived, print_derived };

#include "Chapter27Exercise15Def.c"

#endif

