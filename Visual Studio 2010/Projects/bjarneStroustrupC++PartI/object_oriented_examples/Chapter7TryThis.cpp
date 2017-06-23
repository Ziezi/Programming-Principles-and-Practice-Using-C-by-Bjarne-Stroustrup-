/*
	TITLE			   Test the calculator input    Chapter7TryThis.cpp
	 Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Test the input and stability of the program.
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Date: 17.02.2015
*/
#include <iostream>
#include <string>

//------------------------------------------------------------------------------
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
	char kind;
	double value;

	Token(char k)
		: kind(k), value(0) 
	{
	
	}

	Token(char k, double v)
		: kind(k), value(v) 
	{

	}
};

//------------------------------------------------------------------------------
/*
	class Token_stream
	Used as a buffer for
	tokenized input.
*/ 
class Token_stream
{
public:
	Token_stream();

	Token get();
	void putback(Token t);
	void ignore(char c);

private:
	bool full;
	Token buffer;
} ts;

//------------------------------------------------------------------------------
// forward declaration due to circular dependacy between the functions implementing the grammar
double expression();

//------------------------------------------------------------------------------
void clean_up_mess();
void calculate();

//===============================================================================

int main()
{
	calculate();
}

//===============================================================================

// Class Token_stream member implementation 
Token_stream::Token_stream()
	:full(false), buffer(0)
{

}

//-----------------------------------------------------------------------
void Token_stream::putback(Token t)
{
	if(full) 
	{
		std::cerr <<"putback() into a full buffer!\n";
	}
	buffer = t;
	full = true;
}

//-----------------------------------------------------------------------
Token Token_stream::get()
{
	const char number = '8';			 // t.kind = number, means that t is a number Token

	if (full)
	{
		full = false;
		return buffer;
	}

	char ch;
	std::cin >> ch;
	switch (ch)
	{
		case'=': case'x': case'!': case'%': case'{': case'}':
		case'(': case')': case'+': case'-': case'*': case'/':
		{
			return Token(ch);
		}
		case '.':
		case '0': case '1' :case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{
			std::cin.putback(ch);
			double val;
			std::cin >> val;
			return Token(number,val);
		}	
		default:
		{
			std::cerr <<"Bad input token!\n";
		}
	}
}

//-----------------------------------------------------------------------
void Token_stream::ignore(char c)
{
	if(full && c == buffer.kind)
	{
		full = false;
		return;
	}
	full = false;

	char ch = 0;
	while(std::cin >> ch)
	{
		if(ch == c) return;
	}
}


//-----------------------------------------------------------------------
/*
	Non-member method: is_factorial.
	Use: bool fact = is_factorial(void);

	This funnction returns true if a number
	is followed by factorial opertor. 
	Tests if number preceeding the factorial
	is integer and positive, returns error if not.
*/
bool is_factorial()
{
	Token t = ts.get();
	if (t.kind == '!')	
	{
		if (t.value < 0 || t.value != int(t.value))
		{
			std::cerr <<"Factorial must be positive integer!\n";
		}
		ts.putback(t);
		return true;
	}
	ts.putback(t);
	return false;
}
//-----------------------------------------------------------------------
/*
	Non-member method: factorial.
	Use: double fact = factorial(double);
	This funnction provides factorial operator.
*/
double factorial(double num)
{
	if(num <= 1)
	{
		return 1;
	}
    return num * factorial(num - 1);
}

//------------------------------------------------------------------------------
/*
	Function: primary();
	Deals with +, - operations;
    ( Expression ) and { Expression }.
*/
double primary()
{
	const char number = '8';			 // t.kind = number, means that t is a number Token

	Token t = ts.get();
	switch (t.kind) 
	{
		case '{':
		{
			double d  = expression();
			t = ts.get();
			if(t.kind != '}')
			{
				std::cerr <<"'}' expected!\n";
			}
			return d;
		}
		case '(':
		{
			double d = expression();
			t = ts.get();
			if(t.kind != ')') 
			{
				std::cerr <<"')' expected!\n";
			}
			return d;
		}
		case number: case '!':
		{
			if(is_factorial())
			{
				double d = factorial(t.value);
				t = ts.get();
				return d;
			}
			else return t.value;
		}
		case '-':
			return -primary();
		case '+':
			return primary();
		default:
		{
			std::cerr <<"primary expected!\n";
			getchar();
		}
	}
}

//------------------------------------------------------------------------------
 /*
	Function: term()
	Deals with *,/ and % 
*/
double term()
{
	double left = primary();
	Token t = ts.get();
	while(true) 
	{
		switch (t.kind) 
		{
			case'*':
			{
				left *= primary();
				t = ts.get();
				break;
			}
			case'/':
			{
				double d = primary();
				if (d == 0)	
				{
					std::cerr <<"division by zero!\n";
				}

				left /= d;
				t = ts.get();
				break;
			}
			case '!':
			{
				left = factorial (primary());
				t = ts.get();
				break;
			}
			case '%':
			{
				double d = primary();

				int numtor = int(left);
				if (numtor != left)
				{
					std::cerr <<"left hand value of % not integer!\n";
				}

				int denomtor = int(d);
				if (denomtor != d)
				{
					std::cerr <<"right hand value of % not integer!\n";
				}
				if (denomtor == 0) 
				{
					std::cerr <<"division by zero!\n";
				}

				left = numtor % denomtor;
				t = ts.get();
				break;
			}
			default:
			{
				ts.putback(t);
				return left;
			}
		}
	}
}

//------------------------------------------------------------------------------
/*
	Function: expression()
	Deals with '+' and '-'.
*/
double expression()
{
	double left = term();
	Token t = ts.get();
	while(true) 
	{
		switch (t.kind) 
		{
			case'+':
			{
				left +=term();
				t = ts.get();
				break;
			}
			case'-':
			{
				left -=term();
				t = ts.get();
				break;
			}
			default:
			{
				ts.putback(t);
				return left;
			}
		}
	}
}

//-----------------------------------------------------------------------
/*
	Non-member funcion: clean_up_mess()

	It ignores the token causing exception
	and facilitates smooth transition back
	to normal functionality.
*/
void clean_up_mess()
{
	const char print = '=';			     // print (result) token
	ts.ignore(print);
}

//-----------------------------------------------------------------------
/*
	Non-member function: calculate();

	Runs input loop.
*/
void calculate()
{
	std::cout <<"\t\tWelcome to our simple calculator.\n";
	std::cout <<"\tPrint result: '='.\n";
	std::cout <<"\tExit: 'x'.\n";

	const std::string prompt = ">>"; 
	const std::string result = "=";

	const char quit = 'x';				 // quit (program) token
	const char print = '=';			     // print (result) token

	while(std::cin)
	{
		try
		{
			std::cout << prompt;
			Token t = ts.get();

			while (t.kind == print)
			{
				t = ts.get();
			}

			if (t.kind == quit) 
			{
				return;
			}
			ts.putback(t);

			std::cout << result << expression() << '\n';
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			clean_up_mess();
			getchar();
		}
		catch(...)
		{
			std::cerr << "default exception" << std::endl;
			getchar();
		}
	}
}