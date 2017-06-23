 /*
	TITLE			   Propose 3 & Implement 1 feature Chapter7exercise10Def.cpp
	"Software - Principles and Practice using C++" by Bjarne Stroustrup"
	COMMENT
			Objective: Propose three possible improvements and implement
					   one.
				Input: - 
			   Output: -
			   Author: Chris B. Kirov
			     Date: 25.02.2015
*/
// Definition of member functions of the tokenization classes
/*
	Function: get()
	Use: Token t = Token_Stream_object.get();

	It extracts raw data from std::cin and returns:
	number or operator or name of user defined variable
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
	std::cin.get(ch);

	while (isspace(ch))
	{
        if (ch == '\n')
		{
			return Token(printIdentifier); 
		}

        std::cin.get(ch);
    }

	switch (ch)
	{
		case '(': case ')': case '+': case '-': case ',':
		case '*': case '/': case '%': case '=': case '!':  
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

			return Token(numberIdentifier , val);
		}
		default:
		{
			if (isalpha(ch) || ch == '_' || ch == '#') 
			{
				std::string s;  
				s += ch;

				while(std::cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
				{
					s += ch;
				}

				std::cin.putback(ch);
				
				if (s == sinFunctionKeyword) return Token(sinFunctionIdentifier); // New code
				if (s == squareRootKeyword) return Token(mysqrtIdentifier);
				if (s == powerKeyword) return Token(mypowIdentifier);
				if (s == quitKeyword) return Token(quitIdentifier);
				if (s == declarationKeyword) return Token(declarationIdentifier);
				if (s == helpKeyword) return Token(helpIdentifier);  

				return Token(nameIdentifier, s);
			}

			std::cerr <<"bad input token!\n";
		}
	}
}
//--------------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------------
/*
	Function: ignore()
	Use: Token_stream ts.ignore(char c)

	It searches the character in the argument 
	in the Token_stream buffer and in the std::cin 
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
	while (std::cin >> ch)
	{
		if (ch == c) return;
	}
}
//--------------------------------------------------------------------------------------------------------
// Definition of member functions of the class used for user defined variables
/*
	Function: get_value();
	Use: double d = get_value(string name)

	Searches for user defined variable 
	using the name in the argument to find and return its value.
	Returns error if variable not defined.
*/
double Table::get_value(std::string s)
{
	for (unsigned int i = 0; i < symbol_table.size(); ++i)
	{
		if (symbol_table[i].name == s)
		{
			return symbol_table[i].value;
		}
	}
	std::cerr <<"get_value: undefined name!\n";
	return 0;
}
//--------------------------------------------------------------------------------------------------------
/*
	Function: set_value();
	Use: set_value(string name, double value)

	Searches for user defined variable 
	using the name in the argument to find and
	sets the value in the second argument.
	Returns error if variable not defined.
*/
void Table::set_value(char i, std::string s, double d)
{
	for (unsigned int i = 0; i < symbol_table.size(); ++i)
	{
		if (symbol_table[i].name == s)
		{
			symbol_table[i].identifier = i;
			symbol_table[i].value = d;
			return;
		}
	}
	std::cerr <<"set: undefined name!\n";
}
//--------------------------------------------------------------------------------------------------------
/*
	Function: is_declared();
	Use: bool var_decl = is_declared(string name)

	Uses the argument to search whether a variable 
	with such name is declared by the user.
*/
bool Table::is_Declared(std::string s)
{
	for (unsigned int i = 0; i < symbol_table.size(); ++i)
	{
		if (symbol_table[i].name == s)
		{
			return true;
		}
	}
	return false;
}
//--------------------------------------------------------------------------------------------------------
/*
	Function: reAssign(string name);
	Use: double reAssign(string n);

	Assigns a new value on already defined 
	(user-defined) variable. Called from primary().
*/
double Table::reAssign(std::string n)
{
	double newValue = expression();
	for (unsigned int i = 0; i < symbol_table.size(); ++i)
	{
		if (symbol_table[i].name == n)
		{
			if (symbol_table[i].identifier == constantVariableIdentifier) 
			{
				std::cout <<"can not assign to constant expression!" << symbol_table[i].name << std::endl;
				return get_value(symbol_table[i].name);
			}

			symbol_table[i].value = newValue;
			return newValue;
		}
	}

	std::cerr <<"Non existing variable can not be reassigned!\n";	
	return 0;
}
//--------------------------------------------------------------------------------------------------------
// Definition of non-member functions
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
//--------------------------------------------------------------------------------------------------------
/*
	Function: power(double base, int pow);
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
		return base * power(base, pow - 1);
	}
}
//--------------------------------------------------------------------------------------------------------
/*
	Function: factorial();
	Use: double fact = factorial(double (int) number)

	It returns the factorial of the number in the argument.
	Tests if argument integer, casts it into integer.
*/
double factorial(double number)
{
	int isInteger = int(number);

	if (isInteger != number) 
	{
		std::cerr <<"factorial: number must be integers!\n";
	}

	if(number < 2)
	{
		return 1;
	}

	return number * factorial(number - 1);
}
//--------------------------------------------------------------------------------------------------------
/*
	Function: helpFunction();
	Use: void helpFunction(void);

	It returns a brief use instruction
	message. Called from calculate().
	Using keyword: 'H' in std input.
*/
void helpFunction(void)
{
	std::cout << "\nCalculator 10.0\t Author: Chris B. Kirov\t Date: 26.02.2015\n";
	std::cout << "\nSupported operations (in decreasing order of precedence):\n";
	std::cout << "1.'('Expression')'; '{'Expression'}';\n pow(base,exp); sqrt(Expression), , Expression! ; sin(Expression)\n";
	std::cout << "2. *; \'; % (using integers)\n";
	std::cout << "3. / +; -\n";
	std::cout << "4. User defined variables. Syntax:\n let [const] name = value.\n";
	std::cout << "5. Reassignment of non-constant variables. Syntax:\n declared_name = new_value.\n";
	std::cout << "6. Evaluate expression / Print result with: CR.\n";
	std::cout << "7. Exit with: ""exit""." << std::endl;
}

//===========================================================================================================
// Functions Implementing the Calculator Grammar

/*
	Function: primary()
	Use: double num = primary();

	Lowest in the grammar hierarchy, first 
	to extract a token from the Token_stream 
	and to return: (+/-)number, number in parentheses,
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
				std::cerr <<"')' expected!\n";
			}

			return d;
		}
		case '{': // New code
		{	
			double d = expression();

			t = ts.get();

			if (t.kind != '}')
			{
				std::cerr <<"'}' expected!\n";
			}

			return d;
		}
		case mysqrtIdentifier:
		{
			t = ts.get();

			if(t.kind != '(') 
			{
				std::cerr <<"sqrt: '(' expected!\n";
			}

			double value = expression();

			if (value < 0)
			{
				std::cerr <<"sqrt: Complex numbers not supported!\n";
			}

			t = ts.get();

			if (t.kind != ')')
			{
				std::cerr <<"sqrt: ')' expected!\n";
			}

			return squareRoot(value);
		}
		case mypowIdentifier: 
		{
			t = ts.get();

			if(t.kind != '(')
			{
				std::cerr <<"pow: '(' expected\n";
			}

			double base = expression();

			t = ts.get();

			if (t.kind != ',')
			{
				std::cerr <<"pow: ',' expected\n";
			}

			double d = expression();

			int pow = int(d);

			if (pow != d)
			{
				std::cerr <<"pow: integer expected\n";
			}

			t = ts.get();

			if (t.kind != ')')
			{
				std::cerr <<"pow: ')' expected\n";
			}

			return power(base,pow);
		}
		case sinFunctionIdentifier:
		{
			t = ts.get();

			if(t.kind != '(')
			{
				std::cerr <<"sin: '(' expected\n";
			}

			double angleInDegrees = expression();

			t = ts.get();

			if (t.kind != ')')
			{
				std::cerr <<"sin: ')' expected\n";
			}

			return std::sin(angleInDegrees * (PI / 180.));
		}
		case '-':
		{
			return -primary();
		}
		case '+':
		{
			return primary();
		}
		case numberIdentifier: 
		{	
			Token t2 = ts.get();

			if(t2.kind == factorialIdentifier)
			{
				return factorial(t.value);
			}

			ts.unget(t2);

			return t.value;
		}
		case nameIdentifier:
		{
			Token t2 = ts.get();

			if (t2.kind == assignmentIdentifier)
			{
				return st.set(t.name);
			}

			ts.unget(t2);

			// this line possibly causes the redundant print line when user defined variable is added with literal
			return st.get(t.name);
	    }
		default:
		{
			std::cerr <<"primary expected!\n";
		}
	}
}
//--------------------------------------------------------------------------------------------------------
/*
	Function: term()
	Use: double te = term();

	Extracts two primary()'s(operand)  and a token(operation),
	and performs one of three operations: multiplication,
	division or integer division; returns primary if token
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
					std::cerr <<"division by zero!\n";
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
					std::cerr <<"modulo: left hand term is not integer!\n";
				}

				if (denom == 0)
				{
					std::cerr <<"modulo: division by zero!\n";
				}

				int numer = int(left);

				if (numer != left) 
				{
					std::cerr <<"modulo: right hand term is not integer!\n";
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
//--------------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------------
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

	if (t.kind != nameIdentifier)
	{
		std::cerr <<"declaration: name expected in declaration\n";
	}

	std::string newVariableName = t.name;

	if (t.name == constantVariableKeyword)
	{
		Token t3 = ts.get();

		if (t3.kind != nameIdentifier)
		{
			std::cerr <<"declaration: name expected in declaration\n";
		}

		std::string newConstantVarriableName = t3.name;

		if (st.is_declared(newConstantVarriableName))
		{
			std::cerr <<"declaration: variable already declared!\n";
		}

		Token t4 = ts.get();

		if (t4.kind != assignmentIdentifier)
		{
			std::cerr <<"declaration: = missing in declaration\n";
		}

		double constantVariableValue = expression();

		st.add(constantVariableIdentifier, newConstantVarriableName, constantVariableValue);

		return constantVariableValue;
	}
	else
	{
		if (st.is_declared(newVariableName))
		{
			std::cerr <<"declaration: variable already declared!\n";
		}

		Token t2 = ts.get();

		if (t2.kind != assignmentIdentifier)
		{
			std::cerr <<"declaration: = missing in declaration\n";
		}

		double newVariableValue = expression();

		st.add(variableIdentifier, newVariableName, newVariableValue);

		return newVariableValue;
	}
}
//--------------------------------------------------------------------------------------------------------
/*
	Function: statement();
	Use: double sta = statement();

	Extracts a token and if that token is of
	kind keyword for user defined variable: 
	calls definition; otherwise it ungets the 
	token and calls expression().
*/
double statement()
{
	Token t = ts.get();
	switch(t.kind) 
	{
		case declarationIdentifier:
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
//--------------------------------------------------------------------------------------------------------
/*
	Function: clean_up_mess();
	Use: clean_up_mess();

	It ignores the symbol used for
	print command. Used for error handling, 
	to skip the error code and resume 
	execution. Called from catch runtime error
	block.
*/
void clean_up_mess()
{
	ts.ignore(printKeyword);
}

//--------------------------------------------------------------------------------------------------------
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

			while (t.kind == printIdentifier) 
			{
				t = ts.get();
			}

			if (t.kind == quitIdentifier) 
			{
				return;
			}

			if (t.kind == helpIdentifier)
			{ 
				helpFunction();
			}

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
			std::cerr <<"unknown exception!"<< std::endl;
			getchar();
		}
	}
}
 