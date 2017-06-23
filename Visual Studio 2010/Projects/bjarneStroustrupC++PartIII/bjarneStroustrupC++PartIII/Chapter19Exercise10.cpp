/*
	TITLE			Auto_ptr               Chapter19Exercise10.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Implement a simple auto_ptr supporting:
					constructor, destructor, ->, *, and release();
		     Input: -
			Output: - 
			Author: Chris B. Kirov
			  Date: 24.1.2016
*/
#include <iostream>
#include "Chapter19Exercise10.h"
#include "assert.h"

void test1 () 
{
	std::cout <<"\nTest constructor and get() member.\n";
	Auto_ptr<int> p(new int);
	*p.get() = 5;
	std::cout <<"p points to: "<< *p << "\n";

	assert(*p, 5);
	std::cout <<"TEST 1 DONE\n";
}

//--------------------------------------------------------------------------------------------------------------------------

void test2 () 
{
	std::cout <<"\nTest release() members.\n";
	Auto_ptr<int> p(new int(5));

	int* raw_ptr = nullptr;
	raw_ptr = p.release();

	std::cout <<"released to raw pointer: "<< *raw_ptr <<'\n'; 

	Auto_ptr<char> p1(new char('a'));
	p1.reset();

	std::cout <<"TEST 2 DONE\n";
}

//--------------------------------------------------------------------------------------------------------------------------

void test3 ()
{
	std::cout <<"\nTest copy constructor and copy assignment.\n";
	Auto_ptr<int> p1(new int(10));
	// Auto_ptr<int> p2(p1);
	
	std::cout <<"can't copy be constructed\n";

	Auto_ptr<int> p3(new int(20));
	// p1 = p3;
	std::cout <<"can't be copy assigned\n";

	std::cout <<"TEST 3 DONE\n";
}

//--------------------------------------------------------------------------------------------------------------------------

class Base
{
    public:
        virtual ~Base() {}
        virtual void doAction() = 0;
};

class Derived1: public Base
{
    public:
        virtual void doAction() override
		{
			std::cout << "Derived 1\n";
		}
};

class Derived2: public Base
{
    public:
        virtual void doAction() override
		{
			std::cout << "Derived 2\n";
		}
};

void test4 (bool c)
{
	std::cout <<"\nTest use with types derived from T.\n";

	Derived1* action1 = new Derived1;
    Derived2* action2 = new Derived2;

	Base* action = nullptr;

	if (c)
	{
		action = action1;
	}
	else
	{
		action = action2;
	}

    if (action)
	{
		action->doAction();
	}

	std::cout <<"TEST 4 DONE\n";
}

//--------------------------------------------------------------------------------------------------------------------------

int main ()
{
	test1 ();
	test2 ();
	test3 ();
	test4 (true);
	test4 (false);

	getchar();
}