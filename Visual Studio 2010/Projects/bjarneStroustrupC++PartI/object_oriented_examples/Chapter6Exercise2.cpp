/* 
   TITLE		   Add expressions in brackets  Chapter6Exercise2.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
 		Objective: Add the ability to use {} as well as (), 
		           so that {(expression)+ term}, can be evaluated.
			Input: -
		  Outptut: -
		   Author: Chris B. Kirov.
			 Data: 09.02.2015.
*/		 
#include <iostream>

//------------------------------------------------------------------------------
/*
	class: Token
	Used for the conversion
	of raw input to interprted
	data used for algebraic
	calculations.
*/
class Token {
public:
    char kind;						 // what kind of token
    double value;					 // for numbers: a value 

    Token(char ch)					 // make a Token from a char
        :kind(ch), value(0) 
	{ 
	
	}    

    Token(char ch, double val)		 // make a Token from a char and a double
        :kind(ch), value(val) 
	{

	}
};

//------------------------------------------------------------------------------
/*
	class Token_stream
	Used as a buffer for
	tokenized input.
*/ 
class Token_stream {
public: 
    Token_stream();					 // make a Token_stream that reads from cin

    Token get();					 // get a Token (get() is defined elsewhere)
    void putback(Token t);			 // put a Token back

private:

    bool full;						 // is there a Token in the buffer?
    Token buffer;					 // here is where we keep a Token put back using putback()
} ts;							     // object instantiated to be used in miain

//------------------------------------------------------------------------------
// forward declaration due to circular dependacy between the functions implementing the grammar
double expression();    

//================================================================================================

int main()
try
{
	std::cout << "\t\tWelcome to our simple calculator 5.0.\n";
	std::cout << "Supported operations: +,-,*,/, compound expressions using { } and ( ).\n";
	std::cout << "Type: '=' to evaluate and: 'x' to exit.\n";
	std::cout << "\nEnter expression using floating-point numbers:\n>>";

	double val;
    while (std::cin)
	{
        Token t = ts.get();

        if (t.kind == 'x')
		{	
			break; 
		}

        if (t.kind == '=')
		{	
            std::cout << "=" << val << '\n';
		}
        else
		{
            ts.putback(t);
			val = expression();
		}
    }
	getchar();
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
    return 1;
}
//================================================================================================

// Class Token_stream member implementations
Token_stream::Token_stream()
	:full(false), buffer(0)			 // no Token in buffer
{

}
//------------------------------------------------------------------------------
// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) std::cerr <<"putback() into a full buffer\n";

    buffer = t;						 // copy t to buffer
    full = true;					 // buffer is now full
}	

//------------------------------------------------------------------------------
Token Token_stream::get()
{
    if (full)
	{       
		full = false;                // do we already have a Token ready?
        return buffer;               // remove token from buffer
    } 

    char ch;
	std::cin >> ch;					 // note that >> skips whitespace (space, newline, tab, etc.)
		
    switch (ch)
	{
		case'{': case'}': case'(': case')': case'+': case'-':
		case'*': case'/': case'=': case'x':
		{
			return Token(ch);		 // let each character represent itself
		}
		case'.':				     // digits start either with a dot or digit
		case'0': case'1': case'2': case'3': case'4':
		case'5': case'6': case'7': case'8': case'9':
		{    
			std::cin.putback(ch);    // put digit back into the input stream
			double val;
			std::cin >> val;         // read a floating-point number
			return Token('8',val);   // let '8' represent "a number"
		}
		default:
		{
			std::cerr <<"Bad token";
		}
    }
}




//------------------------------------------------------------------------------
 /*
	Function: primary();
	Deals with +, - operations;
    ( Expression ) and { Expression }.
*/
double primary()
{
    Token t = ts.get();
    switch (t.kind)
	{
		case '{':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != '}') std::cerr <<"'}' expected\n";
			return d;
		}
		case '(':
		{    
			double d = expression();
			t = ts.get();
			if (t.kind != ')') std::cerr <<"')' expected\n";
			return d;
		}
		case '8':					 // we use '8' to represent a number
		{
			return t.value;		  	 // return the number's value
		}
		default:
		{
			std::cerr <<"primary expected\n";
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
    Token t = ts.get();              // get the next token from token stream

    while(true) 
	{
        switch (t.kind)
		{
			case '*':
			{
				left *= primary();
				t = ts.get();
				break;
			}
			case '/':
			{    
				double d = primary();
				if (d == 0) std::cerr <<"divide by zero\n";
				left /= d; 
				t = ts.get();
				break;
			}
			default: 
			{
				ts.putback(t);       // put t back into the token stream
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
    double left = term();            // read and evaluate a Term
    Token t = ts.get();              // get the next token from token stream

    while(true)
	{    
        switch(t.kind)
		{
			case '+':
			{
				left += term();		 // evaluate Term and add
				t = ts.get();
				break;
			}
			case '-':
			{
				left -= term();      // evaluate Term and subtract
				t = ts.get();
				break;
			}
			default: 
			{
				ts.putback(t);       // put t back into the token stream
				return left;         // finally: no more + or -: return the answer
			}
        }
    }
}
