/*	
    TITLE			   Expand calculator		  Chapter6TryThis3.cpp
    Bjarne Stroustrup "Programming: Principles and Practice Using C++"
 	COMMENT
 			Objective: Add class Token_stream and modify main and all
					   the functions as indicated in 6.7 - 6.9. 

					   Add end of expression (evaluate) symbol ';'.

					   File organization: separation of declarations
					   and implementations
 				Input: -
 			   Output: -
			   Author: Chris B. Kirov
		         Date: 1.2.2015
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/*
	class: Token

	Used for the conversion
	of raw input to interprted
	data used for algebraic
	calculations.
*/
class Token {
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
class Token_stream{
public:
	// constructor
	Token_stream();			

	// member functions
	Token get();					 
	void putback(Token t);			 

private:
	// data members
	bool full;						 
	Token buffer;					 
};
// Object instantiated to be used on main
Token_stream ts;	

// forward declaration due to circular dependacy between the functions implementing the grammar
double expression();

//================================================================================================
int main()
try
{
	double val = 0;
	while (std::cin)
	{
		Token t = ts.get();

		// 'q' for quit
		if (t.kind == 'q')
		{
			break;		
		}

		// ';' signifies end of expression
		if (t.kind == ';')	
		{
			std::cout << "=" << val << '\n';
		}
		else
		{
			ts.putback(t);
			val = expression();
		}
	}
	std::cout << "=" << expression() << '\n';
	getchar();
}
catch (std::exception& e)
{
	std::cerr << e.what() << std::endl;
	getchar();
	return 1;
}
catch (...)
{
	std::cerr << "exception \n";
	getchar();
	return 2;
}
//================================================================================================

// class Token_stream member implementations
Token_stream::Token_stream()		 
	:full(false), buffer(0)	
{

}			 

void Token_stream::putback(Token t)	 
{
	if (full) std::cerr <<"putback() into full buffer";
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
		case'(': case')': case'+': case'-': case'*':
		case'/': case'%': case';': case'q':
			return Token(ch);
		case'.':
		case'0': case'1': case'2': case'3': case'4':
		case'5': case'6': case'7': case'8': case'9':
		{
			 std::cin.putback(ch);			 
			 double val;
			 std::cin >> val;				 
			 return Token('8', val);	 
		}
		default:
			std::cerr <<"Bad token!";
	}
}

//-----------------------------------------------------------------------------------------------
/*
	Function: primary();

	It
*/
double primary()						 
{
	Token t = ts.get();
	switch (t.kind)
	{
		case '(':						 
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')') std::cerr <<"')' expected";
			return d;
		}
		case '8':						 
			return t.value;				 
		default:
			std::cerr <<"primary expected";
	}
}

//-----------------------------------------------------------------------------------------------
/*
	Function: term()

	Deals with *,/.
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
				break;
			case '/':
			{
				double d = primary();
				if (d == 0) std::cerr <<"zero division\n";
				left /= d;
				t = ts.get();
				break;
			}
			default:
				ts.putback(t);		// put t back into the Token stream
				return left;
		}
	}
}

//-----------------------------------------------------------------------------------------------
 
/*
	Function: expression()

	// Deals with '+' and '-'.
*/
double expression()
{
	double left = term();					 
	Token t = ts.get();						 
	while (true)
	{
		switch (t.kind)
		{
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);				 
			return left;				 
		}
	}
}

