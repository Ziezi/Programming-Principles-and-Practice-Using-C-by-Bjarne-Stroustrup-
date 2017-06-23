/* 
	TITLE	       Simulate single inheritance in C.        				    Chapter27Exercise15Def.c 
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
//--------------------------------------------------------------------------------------------------

// define the functions for the base class
void initialize_base(Base_class* tthis) 
{
	tthis->virtual_tbl = &Base_tbl;	
	tthis->name = "Base Class";
}

//--------------------------------------------------------------------------------------------------

void print_base(Base_class* tthis )
{
	printf("Base::name -> %s\n", tthis->name);
}

//--------------------------------------------------------------------------------------------------

/* override member functions */
// define the functions for the derived class
void initialize_derived(Derived_1*  tthis)
{
	tthis->base.name = "Derived class";
	tthis->value = 10;
	tthis->base.virtual_tbl = (Base_function_table*) &Derived_tbl;
}

//--------------------------------------------------------------------------------------------------

void print_derived(Derived_1* tthis)
{
	printf("Derived::name -> %s\nDerived::value -> %d\n", tthis->base.name, tthis->value);
}

//--------------------------------------------------------------------------------------------------