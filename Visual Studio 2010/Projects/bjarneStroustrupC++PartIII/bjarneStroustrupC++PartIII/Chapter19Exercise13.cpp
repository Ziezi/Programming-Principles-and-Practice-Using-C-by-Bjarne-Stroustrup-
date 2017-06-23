/*
	TITLE			Tracer	                Chapter19Exercise13.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objective: Write a Tracer class where its constructor and 
				   destructor prints a string.
				   Give the strings as constructor arguments.
				   Experiment with Tracers as: local objects,
				   global, objects allocated by new.
				   Add copy constructor and copy assignment
				   and observe where copying is done.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 06. 2. 2016
*/
#include <iostream>
#include <string>

class Tracer
{
public:
	Tracer (const std::string& c, const std::string& d)
		: constructor(c), destructor(d)
	{
		std::cout <<"Constuctor: "<< constructor <<'\n';
	}

	Tracer (const Tracer& t)
		: constructor(t.constructor), destructor(t.destructor)
	{
		std::cout <<"Copy constructor: " << constructor <<'\n';
	}

	Tracer& operator= (const Tracer& t)
	{
		std::cout <<"Copy assignment: " << constructor <<'\n';

		if (this == &t)
		{
			return *this;
		}

		constructor = t.constructor;
		destructor = t.destructor;

		return *this;
	}

	~Tracer()
	{
		std::cout <<"Destructor: " << destructor << '\n';
	}

private:
	std::string constructor;
	std::string destructor;
};

//---------------------------------------------------------------------------

std::string s = "Global";
Tracer t_global(s, s);

//---------------------------------------------------------------------------

void test ()
{
	std::string s = "Local";
	Tracer t_local(s, s);

	s = "Pointer";
	Tracer* t = new Tracer(s, s);

	Tracer t2(*t);

	Tracer t3 = t2;
}

//---------------------------------------------------------------------------

int main ()
{
	test();

	getchar();
}
