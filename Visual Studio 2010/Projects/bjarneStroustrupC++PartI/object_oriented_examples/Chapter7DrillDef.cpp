/*
	TITLE			   Debug and run       		     Chapter7DrillDef.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
					   calculator08buggy.cpp
	COMMENT
			Objective: 
					   1.Download : http://www.stroustrup.com/Programming/calculator08buggy.cpp
			             Remove the 3 inserted bugs that the compiler will catch and 3 that it won't.
					   2. Add helpful comments.
					   3. -
					   4. Test for different value and epxressions.
					   5. -
					   6. define k 1000.
					   7. Add sqrt();
					   8. Handle negative square roots with appropriate error message.
					   9. Add pow(x, n), where x^n.
					   10. Declare new variable with: #.
					   11. Exit with 'q'.
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Date: 19.02.2015
*/

/*
	Function: clean_up_mess();
	Use: clean_up_mess();

	It ignores the sybmol used for
	print command. Used for error handling, 
	to skip the error code and resume 
	execution. Called from catch runtime error
	block.
*/
void clean_up_mess()
{
	ts.ignore(print);
}

//-------------------------------------------------------------------------------
/*
	Function: calculate();
	Use: calculate();

	Prompts the user for input
	and performs one of three operations:
	exit program, print result or feed input
	in statement() and display the result.
	Contains try-catch block and runtime error 
	handling. Called from main().
*/
void calculate()
{
	while(true)
	{
		try 
		{
			std::cout << prompt;
			Token t = ts.get();
			while (t.kind == print) 
			{
				t = ts.get();
			}

			if (t.kind == quitKeyword) 
			{
				return;
			}

			/*
			if (t.kind == test) 
			{
				cinReadsTestFile();
			}
			*/

			ts.unget(t);
			std::cout << result << statement() << std::endl;
		}			
		catch(std::runtime_error& e)
		{
			std::cerr << e.what() << std::endl;
			clean_up_mess();
		}
		catch(...)
		{
			std::cerr << "unknown exception!" << std::endl;
			getchar();
		}
	}
}

// Class Token_stream member implementations
//-------------------------------------------------------------------------------
/*
	Function: get()
	Use: Token t = Token_Stream_object.get();

	It extracts raw data from cin and returns:
	number or operatro or name of user defined variable
	or bad token.
*/
Token Token_stream::get()
{
	if (full) 
	{ 
		full=false; 
		return buffer; 
	}

	char ch; 
	std::cin >> ch;
	switch (ch)
	{
		case '(': case ')': case '+': case '-': case ',':
		case '*': case '/': case '%': case 'Q': case '=':
		{
			return Token(ch);
		}
		case '.':
		case '0': case '1': case '2': case '3': case '4': 
		case '5': case '6': case '7': case '8': case '9':
		{	
			std::cin.putback(ch);
			double val;
			std::cin >> val;
			return Token(number,val);
		}
		default:
		{
			if (isalpha(ch)) 
			{
				std::string s;
				s += ch;
				while(std::cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
				std::cin.putback(ch);

				if (s == StdInReadsTestFile) return Token(test);
				if (s == squareRootKeyword) return Token(mysqrt);
				if (s == powerKeyword) return Token(mypow);
				if (s == quit) return Token(quitKeyword);
				return Token(name,s);
			}
			else if ('#')
			{
				return Token(declKey);
			}
			std::cerr <<"bad input token!\n";
		}
	}
}

//-------------------------------------------------------------------------------
/*
	Function: unget()
	Use: Token_stream ts.unget(Token t);

	Extracts the token in the argument from the Token_strem_Object
	back to its buffer, if the buffer is empty.
*/
void Token_stream::unget(Token t)
{
	if(full) 
	{
		std::cerr <<"unget into bull buffer!\n";
	}
	buffer = t; 
	full = true; 
}

//-------------------------------------------------------------------------------
/*
	Function: ignore()
	Use: Token_stream ts.ignore(char c)

	It searches the character in the argument 
	in the Token_stream buffer and in the cin 
	and skips it.
*/
void Token_stream::ignore(char c)
{
	if (full && c  ==  buffer.kind) 
	{
		full = false;
		return;
	}
	full = false;

	char ch = 0;
	while (std::cin>>ch)
	{
		if (ch == c) return;
	}
}

// Functions implementing the calculator grammar
//-------------------------------------------------------------------------------
/*
	Function: get_value();
	Use: double d = get_value(string name);

	Searches for user defined variable 
	using the name in the argument to find and return its value.
	Returns error if variable not defined.
*/
double get_value(std::string s)
{
	for (unsigned int i = 0; i < names.size(); ++i)
	{
		if (names[i].name == s) return names[i].value;
	}
	std::cerr <<"get: undefined name\n";
	return 0;
}

//-------------------------------------------------------------------------------
/*
	Function: set_value();
	Use: set_value(string name, double value);

	Searches for user defined variable 
	using the name in the argument to find and
	sets the value in the second argument.
	Returns error if variable not defined.
*/
void set_value(std::string s, double d)
{
	for (unsigned int i = 0; i <= names.size(); ++i)
	{
		if (names[i].name == s)
		{
			names[i].value = d;
			return;
		}
	}
	std::cerr <<"set: undefined name\n";
}

//-------------------------------------------------------------------------------
/*
	Function: is_declared();
	Use: bool var_decl = is_declared(string name);

	Uses the argument to search whether a variable 
	with such name is declared by the user.
*/
bool is_declared(std::string s)
{
	for (unsigned int i = 0; i < names.size(); ++i)
	{
		if (names[i].name == s) return true;
	}
	return false;
}

//-------------------------------------------------------------------------------
/*
	Function: squareRoot(double d);
	Use: double res = squareRoot(double d);

	It calculates the square root of the 
	number in the argument. Wrapping function.
	Called from primary(). 
*/
double squareRoot(double d)
{
	return sqrt(d);
}

//-------------------------------------------------------------------------------
/*
	Funtion: power(double base, int pow);
	Use: double res = power(double b, int p);

	It calculates the p-th power of number b.
	Called from primary(). 
*/
double power(double base,int pow)
{
	if (pow == 1) 
	{
		return base;
	}
	else
	{
		return (base * power(base, pow-1));
	}
}

//-------------------------------------------------------------------------------
/*
	Function: primary()
	Use: double num = primary();

	Lowest in the grammar hierarchy, first 
	to extract a token from the Token_stream 
	and to return: (+/-)number, number in parenthesses,
	name of user defined variable or error, if neither
	of the above found. Called by term().
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
			if (t.kind != ')')
			{
				std::cerr <<"')' expected\n";
			}
			return d;
		}
		case 's':
		{
			t = ts.get();
			if(t.kind != '(') 
			{
				std::cerr <<"'(' exprected\n";
			}

			double d = expression();
			if (d < 0)
			{
				std::cerr <<"Complex numbers still not supported!\n";
			}

			t = ts.get();
			if (t.kind != ')') 
			{
				std::cerr <<"')' expected\n";
			}
			return squareRoot(d);
		}
		case 'p': 
		{
			t = ts.get();
			if(t.kind != '(')
			{
				std::cerr <<"'(' expected\n";
			}

			double base = expression();

			t = ts.get();
			if (t.kind != ',')
			{
				std::cerr <<"',' expected\n";
			}

			double d = expression();
			int pow = (int)d;

			if (pow != d)
			{
				std::cerr <<"exponent: integer expected\n";
			}

			t = ts.get();
			if (t.kind != ')')
			{ 
				std::cerr <<"')' expected\n";
			}
			return power(base,pow);
		}
		case '-':
		{
			return -primary();
		}
		case '+':
		{
			return primary();
		}
		case number:
		{
			return t.value;
		}
		case name:
		{
			return get_value(t.name);
		}
		default:
		{
			std::cerr <<"primary expected\n";
		}
	}
}

//-------------------------------------------------------------------------------
/*
	Function: term()
	Use: double te = term();

	Extracts two primary()'s(operand)  and a token(operation),
	and performs one of three operations: multiplication,
	divisio or integer division; returns primary if token
	does not match any of the operations. Called by expression().
*/
double term()
{
	double left = primary();
	Token t = ts.get();
	while(true) 
	{
		switch(t.kind)
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
				if (d == 0)
				{
					std::cerr <<"divide by zero\n";
				}
				left /= d;
				t = ts.get();
				break;
			}
			case '%':
			{
				double d = primary();
				int denom = int(d);
				if (denom != d) 
				{
					std::cerr <<"left hand term is not integer!\n";
				}

				if (denom == 0)
				{
					std::cerr <<"zero division!";
				}

				int numer = int(left);
				if (numer != left) 
				{
					std::cerr <<"right hand term is not integer!\n";
				}

				left = numer % denom;
				t = ts.get();
				break;
			}
			default:
			{
				ts.unget(t);
				return left;
			}
		}
	}
}

//-------------------------------------------------------------------------------
/*
	Function: expression();
	Use: double expre = expression();

	Extracts two term()'s and a token(operation)
	and performs on of two operations: addition
	or subtraction; returns term if token does
	not match any of the operations. Called by
	declaration().
*/
double expression()
{
	double left = term();
	Token t = ts.get();

	while(true)
	{
		switch(t.kind) 
		{
			case '+':
			{
				left += term();
				t = ts.get();
				break;
			}
			case '-':
			{
				left -= term();
				t = ts.get();
				break;
			}
			default:
			{
				ts.unget(t);
				return left;
			}
		}
	}
}

//-------------------------------------------------------------------------------
/*
	Function: declaration();
	Use: double decl = declaration();

	Extracts a token and checks if it is of type: name
	of user variable, then extracts a second token to 
	check the syntax of definition (if the name is followed
	by equal sign), if so declares a variable with that name.
	Called by statement().
*/
double declaration()
{
	Token t = ts.get();
	
	if (t.kind != name)
	{ 
		std::cerr <<"name expected in declaration\n";
	}

	std::string name = t.name;
	if (is_declared(name))
	{ 
		std::cerr << name <<"declared twice\n";
	}

	Token t2 = ts.get();
	if (t2.kind != print) 
	{
		std::cerr <<"= missing in declaration of "<< name <<"\n";
	}

	double declared = expression();
	names.push_back(Variable(name, declared));
	return declared;
}

//-------------------------------------------------------------------------------
/*
	Function: statement();
	Use: double sta = statement();

	Extracts a token and if that token is of
	kind keyword for user defined valriable: 
	calls definition; otherwise it ungets the 
	token and calls expession().
*/
double statement()
{
	Token t = ts.get();
	switch(t.kind) 
	{
		case declKey:
		{
			return declaration();
		}
		default:
		{
			ts.unget(t);
			return expression();
		}
	}
}
