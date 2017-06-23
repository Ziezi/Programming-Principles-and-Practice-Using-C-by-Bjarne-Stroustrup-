/*
	TITLE			   Code Indentation			 Chapter9Exercise4.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Indent the code. 
				Input:  
			   Output:  
			   Author: Chris B. Kirov
			     Date: 16.03.2015
*/
#include <iostream>

struct X
{
	void f(int x)
	{
		struct Y
		{
			int f(){return 1;} 
			int m;
		};

		int m;
		m=x; 
		Y m2;
		return f(m2.f()); //returns 1
	}

	int m; 

	void g(int m)
	{
		if(m)f(m+2); 
		else{g(m+2);}
	}

	X(){}

	void m3() 
	{
	}

	void main() 
	{
		X a;
		a.f(2); //returns 1
	}
};