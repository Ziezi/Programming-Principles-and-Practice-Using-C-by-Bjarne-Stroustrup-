/*	
    TITLE			   Debug Calculator		  Chapter6TryThis2.cpp
    Bjarne Stroustrup "Programming: Principles and Practice Using C++"
 	COMMENT
 			Objective: Dowload and debug calculator00.cpp
			           Example code from Chapter 6.6
					   "Trying the first version" of.
					   http://www.stroustrup.com/Programming/calculator00.cpp
					   Explore and analyze the code.

					   Grammar:
					   Expression:
							Term
							Term + or - Expression
					   Term:
							Primary
							Primary * or / Number
					   Number:
					        Floating point literal
							'(' Expression ')'
					   
 				Input: - part of the input is discarted.
				       - result printed when next expression typed.
				       - no way to discern where expression ends.
 			   Output: -
			   Author: Chris B. Kirov
		         Date: 1.2.2015
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) 
	{
	
	}

    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) 
	{
	
	}
};

//------------------------------------------------------------------------------

Token get_token()    // read a token from cin
{
    char ch;
    std::cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) 
	{
		//not yet   case ';':    // for "print"
		//not yet   case 'q':    // for "quit"
		case '(': case ')': case '+': case '-': case '*': case '/': 
			return Token(ch);        // let each character represent itself
		case '.':
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{    
            std::cin.putback(ch);         // put digit back into the input stream
            double val;
            std::cin >> val;              // read a floating-point number
            return Token('8',val);   // let '8' represent "a number"
        }
		default:
			std::cerr <<"Bad token";
    }
}

//------------------------------------------------------------------------------

double expression();  // read and evaluate a Expression

//------------------------------------------------------------------------------

double term();        // read and evaluate a Term

//------------------------------------------------------------------------------

double primary()     // read and evaluate a Primary
{
    Token t = get_token();
    switch (t.kind)
	{
		case '(':    // handle '(' expression ')'
        {    
            double d = expression();
            t = get_token();
            if (t.kind != ')') std::cerr <<"')' expected";
            return d;
        }
		case '8':            // we use '8' to represent a number
		    return t.value;  // return the number's value
		default:
		    std::cerr <<"primary expected";
    }
}


//===============================================================================

int main()
try 
{
    while (std::cin)
	{
        std::cout << "=" << expression() << '\n';
		getchar();
	}
}
catch (std::exception& e)
{
    std::cerr << e.what() << std::endl;
    getchar();
    return 1;
}
catch (...) {
    std::cerr << "exception \n";
    getchar();
    return 2;
}

//===============================================================================


double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = get_token();     // get the next token
    while(true) 
	{    
        switch(t.kind) 
		{
			case '+':
				left += term();    // evaluate Term and add
				t = get_token();
				break;
			case '-':
			    left -= term();    // evaluate Term and subtract
			    t = get_token();
			   break;
			default:
				return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double term()
{
    double left = primary();
    Token t = get_token();     // get the next token

    while(true) 
	{
        switch (t.kind) 
		{
			case '*':
				left *= primary();
				t = get_token();
				break;
			case '/':
            {    
                double d = primary();
                if (d == 0) std::cerr <<"divide by zero";
                left /= d; 
                t = get_token();
                break;
            }
			default: 
				return left;
        }
    }
}

//------------------------------------------------------------------------------