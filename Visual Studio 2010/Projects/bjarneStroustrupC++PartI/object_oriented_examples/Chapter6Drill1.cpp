/*
   TITLE	       Compile and run the code       Chapter6Drill1.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
 		Objective: 1. Debug calculator02buggy.cpp 
		              from http://www.stroustrup.com/Programming/calculator02buggy.cpp
 			Input: -
 		   Output: -
		   Author: Chris B. Kirov
		     Data: 1.2.2015
*/
#include <iostream>

/*
	class: Token

	Used for the conversion
	of raw input to interprted
	data used for algebraic
	calculations.
*/
class Token
{
public:
	// data members
	char kind;
	double value;

	// constructors
	Token(char ch)
		: kind(ch), value(0) 
	{
	
	}

	Token(char ch, double val)
		: kind(ch), value(val)
	{
	
	} 
};

//-----------------------------------------------------------------------------------------------
/*
	class Token_stream

	Used as a buffer for
	tokenized input.
*/ 
class Token_stream
{
public:
	// constructor
	Token_stream();

	// function members
	Token get();
	void putback(Token t);
private:
	// data members
	bool full;
	Token buffer;
} ts; // instantiate Token_stream object providing functions: get() and putback() in main()

// forward declaration due to circular dependacy between the functions implementing the grammar
double expression();

//================================================================================================
int main()
{
	std::cout << "Welcome to out simple calculator 4.0.\n";
	std::cout << "Available operations: '+', '-', '*', '/', '%'\n";
	std::cout << "Press 'x' to quit and '=' to print.\n";

	try
	{
		while (true)
		{
			std::cout << "Type expression using floating-point numbers:\n>>";
			Token t = ts.get();

			if (t.value = 'x') 
			{ 
				break;
			}
			if (t.value = '_')
			{ 
				std::cout << "=" << expression() << '\n';
			}
			else
			{
				ts.putback(t);
				t.value = expression();
			}
		}
	}
	catch (std::exception& e)
	{
		std::cerr << "error: " << e.what() << '\n';
		getchar();
		return 1;
	}
	catch (...)
	{
		std::cerr << "Oops: unknown exception!\n";
		getchar();
		return 2;
	}
}
//================================================================================================

// Class Token_stream member implementations
Token_stream::Token_stream()
	: full(false), buffer(0)		 
{

}							 
 
void Token_stream::putback(Token t)
{
	if (full) std::cerr <<"putback() into full buffer\n";
	buffer = t;						 
	full = true;					 
}

Token Token_stream::get()		
{
	if (full)
	{
		full = false;
		return buffer;
	}
	char ch;
	std::cin >> ch;

	switch (ch)
	{
		case'_': case'x':
		case'(': case')': case'+': case'-': case'*': case'/':
		{
			return Token(ch);
		}
		case'.': case'0': case'1': case'2': case'3': case'4':
		case'5': case'6': case'7': case'8': case'9':
		{
			std::cin.putback(ch);
			double val;
			std::cin >> val;
			return Token('8', val);
		}
		default:
		{
			std::cerr <<"Bad token!\n";
		}
			
	}

}

//-----------------------------------------------------------------------------------------------
/*
	Function: primary();

	Deals with +, - operations. 
*/
double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
		case'(':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')') std::cerr <<"')' expected\n";
			return d;
		}
		case '8':
		{
			return t.value;
		}	
		default:
		{
			std::cerr <<"primary expected\n";
		}
			
	}

}

//-----------------------------------------------------------------------------------------------
/*
	Function: term()

	Deals with *,/ and % 
*/
double term()
{
	double left = primary();
	Token t = ts.get();

	while (true)
	{
		switch (t.kind)
		{
			case '*':
				left *= primary();
				t = ts.get();
			case '/':
			{
				double d = primary();
				if (d == 0) std::cerr <<"division with zero!\n";
				left /= d;
				t = ts.get();
				break;
			}
			default:
				ts.putback(t);
				return left;
		}


	}


}

//-----------------------------------------------------------------------------------------------
/*
	Function: expression()

	Deals with '+' and '-'.
*/
double expression()
{
	double left = term();
	Token t = ts.get();

	while (true)
	{
		switch (t.kind)
		{
			case'+':
			{
				left += term();
				t = ts.get();
				break;
			}
			case'-':
			{
				left -= term();
				t = ts.get();
				break;
			}
			default:
			{	    
				t = ts.get();
				return left;
			}
		}
	}
}