/*
	TITLE		   Bitwise logical operators      Chapter25Exercise4Def.cpp
	COMMENT
		Objective: Add the bitwise logical operators &, |, ^ , and ~ 
				   to the calculator from Chapter 7. 
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 13.05.2017
*/

/*
	Calculator Grammar:
	Calculation:
			Redirect Input
			Redirect Output
			Print
			Quit
			Statement
			Calculation Statement
			 
	Statement:
			Declaration ----------------------------> Declaration: "let" name "=" Expression
					        constant variable Declaration: "let" "const" name "=" Expression
			Expression
	Expression:
			Term
			Expression +, -, Term
	Term:
			Bitwise
			Term *; / ; % Bitwise
	Bitwise:
			Primary
			Bitwise & (AND), ^ (XOR), | (OR) Primary
	Primary:
			Floating point Numbers / Roman numerals
			'(' Expressions ')'
			sqrt-----------------------------------> sqrt: "sqrt" "(" Expression ")"
			pow------------------------------------> pow: "pow" "("double, integer ")"
			factorial------------------------------> factorial: integer"!"
			+; -;  ~(Bitwise NOT), primary
			name-----------------------------------> returns the value of a defined variable previously introduced by "let" command
			sin------------------------------------> returns the sinus of the an angle within [0,360] degrees.
*/


// Class Token_stream member implementations
/*
	Function: get()
	 
	It extracts raw data from "input_stream" and returns:
	number, operator, name of user defined variable
	or bad token.
*/
Token Token_stream::get()
{
	if (full) 
	{ 
		full=false; 
		return buffer; 
	}
	 
	// if (input_stream.eof()) return Token(printIdentifier); 

	char ch; 
	input_stream.get(ch);

	while (isspace(ch))
	{
		// print when: press enter, i.e. newline, '\n' or '='
		if (ch == '\n' || ch == printKeyword) return Token(printIdentifier); 

		input_stream.get(ch);
    }

	switch (ch)
	{
		case '(': case ')': case '+': case '-': case ',':
		case '*': case '/': case '%': case '=': case '!':  
		case '~': case '&': case '|': case '^': 
		{
			return Token(ch);
		}
		case '.':
		case '0': case '1': case '2': case '3': case '4': 
		case '5': case '6': case '7': case '8': case '9':
		{	
			input_stream.putback(ch);

			double val;
			input_stream >> val;

			return Token(numberIdentifier, val);
		}
		case 'I': case 'V': case 'X': case 'L': case 'C':
		case 'D': case 'M':
		{
			std::string roman_numeral(1, ch);

			while (input_stream.get(ch) && is_roman_digit(ch))
			{
				roman_numeral += ch;
			}

			input_stream.putback(ch);

			if (is_roman_number(roman_numeral))
			{
				return Token(romanNumeralIdentifier, (double) to_arab(roman_numeral));
			}
			else
			{
				throw std::runtime_error("Token_stream::get: invalid Roman numeral!\n");
			}
		}
		default:
		{
			if (isalpha(ch) || ch == '_' || ch == '#') 
			{
				std::string s;  
				s += ch;

				while(input_stream.get(ch) && !input_stream.eof() && (isalpha(ch) || isdigit(ch) || ch == '_' || ch == '.' || ch == ':'))
				{
					s += ch;
				}

				input_stream.putback(ch);
				
				if (s == sinFunctionKeyword) return Token(sinFunctionIdentifier);  
				if (s == squareRootKeyword) return Token(mysqrtIdentifier);
				if (s == powerKeyword) return Token(mypowIdentifier);
				if (s == quitKeyword) return Token(quitIdentifier);
				if (s == declarationKeyword) return Token(declarationIdentifier);
				if (s == helpKeyword) return Token(helpIdentifier);  
				if (s == redirectInputKeyword) return Token(redirectedInputIdentifier);
				if (s == redirectOutputKeyword) return Token(redirectedOutputIdentifier);
				if(is_file_name(s)) return Token(fileNameIdentifier, s);

				return Token(nameIdentifier, s);
			}

			throw std::runtime_error("Token_stream::get: bad input token!\n");
		}
	}
}
//--------------------------------------------------------------------------------------------------------
/*
	Function: unget()
	 
	Extracts the token in the argument from the Token_strem_Object
	back to its buffer, if the buffer is empty.
*/
void Token_stream::unget(Token t)
{
	if(full)
	{
		throw std::runtime_error("Token_stream::unget: unget into full buffer!\n");
	}
	buffer = t; 
	full = true; 
}
//--------------------------------------------------------------------------------------------------------
/*
	Function: ignore()
	 
	It searches the character in the argument 
	in the Token_stream buffer and in the 
	input_stream and skips it.
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
	while (input_stream >> ch)
	{
		if (ch == c) return;
	}
}
//========================================================================================================

// Class Table member implementations
/*
	Function: get_value();
	 
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
	throw std::runtime_error("Table::get_value: undefined name!\n");
	return 0;
}
//--------------------------------------------------------------------------------------------------------
/*
	Function: set_value();
	 
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
	throw std::runtime_error("Table::set: undefined name!\n");
}
//--------------------------------------------------------------------------------------------------------
/*
	Function: is_declared();
	 
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
	 
	Assigns a new value on already defined 
	(user-defined) variable. Called from st.set() in primary().
*/
double Table::reAssign(std::string n, double newValue)
{
	for (unsigned int i = 0; i < symbol_table.size(); ++i)
	{
		if (symbol_table[i].name == n)
		{
			if (symbol_table[i].identifier == constantVariableIdentifier) 
			{
				throw std::runtime_error("Table::reassign: can not assign to constant expression!\n");
				return get_value(symbol_table[i].name);
			}

			symbol_table[i].value = newValue;
			return newValue;
		}
	}

	throw std::runtime_error("Table::reassign: non existing variable can not be reassigned!\n");	
	return 0;
}
//========================================================================================================

// Definition of non-member functions
/*
	Function: squareRoot(double d);
	 
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
	 
	It returns the factorial of the number in the argument.
	Tests if argument integer, casts it into integer.
*/
double factorial(double number)
{
	int isInteger = int(number);

	if (isInteger != number) 
	{
		throw std::runtime_error("factorial: number must be integers!\n");
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
	 
	It returns a brief use instruction
	message. Called from calculate().
	Using keyword: 'H' in std input.
*/
void helpFunction(std::ostream& os)
{
	std::cout << "\nCalculator 11.0\t Author: Chris B. Kirov \t Date: 14.04.2016\n";
	std::cout << "\nSupported operations (in decreasing order of precedence):\n";
	std::cout << "Accepts Arabic and Roman numerals.\n";
	std::cout << "1.'('Expression')'; '{'Expression'}';\n pow(base,exp); sqrt(Expression), , Expression! ; sin(Expression)\n";
	std::cout << "2. *; % (using integers)\n";
	std::cout << "3. /; +; -\n";
	std::cout << "4. User defined variables. Syntax:\n let [const] name = value.\n";
	std::cout << "5. Reassignment of non-constant variables. Syntax:\n declared_name = new_value.\n";
	std::cout << "6. Evaluate expression / Print result with: CR.\n";
	std::cout << "7. Exit with: ""Q""." << std::endl;
}
//--------------------------------------------------------------------------------------------------------

/*
	Function: initialize_digits()
*/
static void initialize_digits(std::vector<char>& romans)
{
	 romans.push_back('I');
	 romans.push_back('V');
	 romans.push_back('X');
	 romans.push_back('L');
	 romans.push_back('C');
	 romans.push_back('D');
	 romans.push_back('M');
}
//--------------------------------------------------------------------------------------------------------

/*
	Function: is_roman_digit();
	 
	It checks if a token is 
	a valid Roman digit.
*/
bool is_roman_digit(char& r)
{
	 std::vector<char> roman_digits;
	 initialize_digits(roman_digits);

	 for(size_t i = 0; i < roman_digits.size(); ++i)
	 {
		 if(roman_digits[i] == r)
		 {
			 return true;
		 }
	 }
	 return false;
}
//--------------------------------------------------------------------------------------------------------

/*
	Function: is_roman_number();
	 
	It checks for the validity of a Roman numeral.
	
	Asserts that each MSD is either larger
	or equal to the adjacent LSD or 5/10 
	times smaller than it (IV, IX; XL, XC, CD, CM). 
*/
bool is_roman_number(std::string& roman)
{
	if (roman.size() == 1 && is_roman_digit(roman[0]))
	{
		return true;
	}

	// check if all digits are valid Roman digits
	for (size_t i = 0; i < roman.size(); ++i)
	{
		if (!is_roman_digit(roman[i]))
		{
			return false;
		}
	}

	// check for correspondence between digits value and position
	for(size_t i = 0; i < roman.size() - 1; i++)
	{
		if(to_arab(std::string(1, roman[i])) >= to_arab(std::string(1, roman[i + 1])) ||
		      5 * to_arab(std::string(1, roman[i])) == to_arab(std::string(1, roman[i + 1])) ||
		      10 * to_arab(std::string(1, roman[i])) == to_arab(std::string(1, roman[i + 1])) 
		  )
		{
			
		}
		else
		{
			return false;
		}
	}
	return true;
}

//--------------------------------------------------------------------------------------------------------

/*
	Function: initialize_roman_to_arab();
*/
static void initialize_roman_to_arab(std::map<char, int>& roman)
{
	 roman['M'] = 1000;
	 roman['D'] = 500;
	 roman['C'] = 100;
	 roman['L'] = 50;
	 roman['X'] = 10;
	 roman['V'] = 5;
	 roman['I'] = 1;
}
//--------------------------------------------------------------------------------------------------------

/*
	Function: to_arab();
	 
	It changes a number representation 
	from Roman (numbers < 4000) to Arab. 
	Applies the rules for calculating 
	the value of a Roman numeral.
*/
int to_arab(std::string& s)
{ 
	 std::map<char, int> roman;
	 initialize_roman_to_arab(roman);

	 int result = 0;
	 for(size_t i = 0; i < s.size() - 1; ++i)
	 {
		if(roman[s[i]] < roman[s[i + 1]])
		{
			result -= roman[s[i + 1]];
		}
		else 
		{
			result += roman[s[i]];
		}
	 }

	 result += roman[s[s.size() - 1]];

	 return result;
}
//--------------------------------------------------------------------------------------------------------

/*
	Function: initialize_arab_to_roman();
*/
static void initialize_arab_to_roman(std::forward_list< std::pair<int, std::string> >& roman)
{
	roman.emplace_front(std::pair<int, std::string>(1, "I"));
	roman.emplace_front(std::pair<int, std::string>(4, "IV"));
	roman.emplace_front(std::pair<int, std::string>(5, "V"));
	roman.emplace_front(std::pair<int, std::string>(9, "IX"));
	roman.emplace_front(std::pair<int, std::string>(10, "X"));
	roman.emplace_front(std::pair<int, std::string>(40, "XL"));
	roman.emplace_front(std::pair<int, std::string>(50, "L"));
	roman.emplace_front(std::pair<int, std::string>(90, "XC"));
	roman.emplace_front(std::pair<int, std::string>(100, "C"));
	roman.emplace_front(std::pair<int, std::string>(400, "CD"));
	roman.emplace_front(std::pair<int, std::string>(500, "D"));
	roman.emplace_front(std::pair<int, std::string>(900, "CM"));
	roman.emplace_front(std::pair<int, std::string>(1000, "M"));
}
//--------------------------------------------------------------------------------------------------------

/*
	Function: to_roman();
	
	It changes a number representation 
	from  Arab(numbers < 4000) to Roman. 
*/
std::string to_roman(int value)
{
	if (value == 0)
	{
		return " ";
	}

	std::forward_list< std::pair<int, std::string> > roman;
	initialize_arab_to_roman(roman);

	std::string roman_number;
	for(auto it = roman.begin(); it != roman.end(); ++it)
	{
		while (value >= it->first)
		{
			roman_number += it->second;

			value -= it->first;
		}
	}
	return roman_number;
}

//--------------------------------------------------------------------------------------------------------

/*
	Function: initialize_file_extensions();


*/
static void initialize_file_extensions(std::vector<std::string>& v)
{
	v.emplace_back(".txt");
	v.emplace_back(".bin");
}

//--------------------------------------------------------------------------------------------------------
/*
	Function: is_file_name();

	It checks if a token
	is a valid file name.
*/
bool is_file_name(std::string& s)
{
	if (s == "std::cout" || s == "std::cin")
	{
		return true;
	}

	std::size_t pos = s.find(".");
	std::string file_extension = s.substr(pos);

	std::vector<std::string> supported_file_extensions;
	initialize_file_extensions(supported_file_extensions);

	for (size_t i = 0; i < supported_file_extensions.size(); ++i)
	{
		if (file_extension == supported_file_extensions[i])
		{
			return true;
		}
	}
	return false;
}

//===========================================================================================================

// Functions Implementing the Calculator Grammar
/*
	Function: primary()
 
	Lowest in the grammar hierarchy, first 
	to extract a token from the Token_stream 
	and to return: (+/-)number, number in parentheses,
	name of user defined variable or error, if neither
	of the above found. Called by term().
*/
double primary(Token_stream& ts)
{
	Token t = ts.get();
	switch (t.kind) 
	{
		case '(': 
		{	
			double d = expression(ts);

			t = ts.get();

			if (t.kind != ')')
			{
				throw std::runtime_error("primary: ')' expected!\n");
			}

			return d;
		}
		case '{':  
		{	
			double d = expression(ts);

			t = ts.get();

			if (t.kind != '}')
			{
				throw std::runtime_error("primary:'}' expected!\n");
			}

			return d;
		}
		case mysqrtIdentifier:
		{
			t = ts.get();

			if(t.kind != '(') 
			{
				throw std::runtime_error("primary::sqrt: '(' expected!\n");
			}

			double value = expression(ts);

			if (value < 0)
			{
				throw std::runtime_error("primary::sqrt: Complex numbers not supported!\n");
			}

			t = ts.get();

			if (t.kind != ')')
			{
				throw std::runtime_error("primary::sqrt: ')' expected!\n");
			}

			return squareRoot(value);
		}
		case mypowIdentifier: 
		{
			t = ts.get();

			if(t.kind != '(')
			{
				throw std::runtime_error("primary::pow: '(' expected\n");
			}

			double base = expression(ts);

			t = ts.get();

			if (t.kind != ',')
			{
				throw std::runtime_error("primary::pow: ',' expected\n");
			}

			double d = expression(ts);

			int pow = int(d);

			if (pow != d)
			{
				throw std::runtime_error("primary::pow: integer expected\n");
			}

			t = ts.get();

			if (t.kind != ')')
			{
				throw std::runtime_error("primary::pow: ')' expected\n");
			}

			return power(base, pow);
		}
		case sinFunctionIdentifier:
		{
			t = ts.get();

			if(t.kind != '(')
			{
				throw std::runtime_error("primary::sin: '(' expected\n");
			}

			double angleInDegrees = expression(ts);

			t = ts.get();

			if (t.kind != ')')
			{
				throw std::runtime_error("primary::sin: ')' expected\n");
			}

			return std::sin(angleInDegrees * (PI / 180.));
		}
		case '~':
		{
			unsigned int lhs = (unsigned int)primary(ts);
			return ~lhs;
		}
		case '-':
		{
			return -primary(ts);
		}
		case '+':
		{
			return primary(ts);
		}
		case numberIdentifier: case romanNumeralIdentifier:
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
				double newValue = expression(ts);

				return st.set(t.name, newValue);
			}

			ts.unget(t2);

			// this line possibly causes the redundant print line when user defined variable is added with literal
			return st.get(t.name);
	    }
		default:
		{
			std::cout <<"T kind: " << t.kind <<" T value: " << t.value <<" T name: " << t.name <<'\n';
			getchar();
			throw std::runtime_error("primary: primary expected!\n");
		}
	}
}
//--------------------------------------------------------------------------------------------------------
/*
	Function: bitwise()

	Ugly attempt (though successful)
	to implement bitwise logical operations
	using the already existing functions that
	return double.
*/
double bitwise(Token_stream& ts)
{
	double left = primary(ts);
	Token t = ts.get();

	while (true)
	{
		switch (t.kind)
		{
			case '&':
			{
				unsigned int lhs = (unsigned int) left;
				lhs &= (unsigned int)primary(ts);
				left = lhs;
				t = ts.get();
				break;
			}
			case '^':
			{
				unsigned int lhs = (unsigned int) left;
				lhs ^= (unsigned int)primary(ts);
				left = lhs;
				t = ts.get();
				break;
			}
			case '|':
			{	
				unsigned int lhs = (unsigned int) left;
				lhs |= (unsigned int)primary(ts);
				left = lhs;
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
	Function: term()
	 
	Extracts two bitwise()'s(operand)  and a token(operation),
	and performs one of three operations: multiplication,
	division or integer division; returns primary if token
	does not match any of the operations. Called by expression().
*/
double term(Token_stream& ts)
{
	double left = bitwise(ts);
	Token t = ts.get();

	while(true) 
	{
		switch(t.kind)
		{
			case '*':
			{
				left *= bitwise(ts);
				t = ts.get();
				break;
			}
			case '/':
			{	
				double d = bitwise(ts);

				if (d == 0)
				{
					throw std::runtime_error("term: division by zero!\n");
				}

				left /= d;
				t = ts.get();

				break;
			}
			case '%':
			{
				double d = bitwise(ts);

				int denom = int(d);

				if (denom != d)
				{
					throw std::runtime_error("primary::modulo: left hand term is not integer!\n");
				}

				if (denom == 0)
				{
					throw std::runtime_error("primary::modulo: division by zero!\n");
				}

				int numer = int(left);

				if (numer != left) 
				{
					throw std::runtime_error("primary::modulo: right hand term is not integer!\n");
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
	 
	Extracts two term()'s and a token(operation)
	and performs on of two operations: addition
	or subtraction; returns term if token does
	not match any of the operations. Called by
	declaration().
*/
double expression(Token_stream& ts)
{
	double left = term(ts);
	Token t = ts.get();

	while(true)
	{
		switch(t.kind) 
		{
			case '+':
			{
				left += term(ts);
				t = ts.get();

				break;
			}
			case '-':
			{
				left -= term(ts);
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
	 
	Extracts a token and checks if it is of type: name
	of user variable, then extracts a second token to 
	check the syntax of definition (if the name is followed
	by equal sign), if so declares a variable with that name.
	Called by statement().
*/
double declaration(Token_stream& ts)
{
	Token t = ts.get();

	if (t.kind != nameIdentifier)
	{
		throw std::runtime_error("declaration: name expected in declaration\n");
	}

	std::string newVariableName = t.name;

	if (t.name == constantVariableKeyword)
	{
		Token t3 = ts.get();

		if (t3.kind != nameIdentifier)
		{
			throw std::runtime_error("declaration: name expected in declaration\n");
		}

		std::string newConstantVarriableName = t3.name;

		if (st.is_declared(newConstantVarriableName))
		{
			throw std::runtime_error("declaration:declaration: variable already declared!\n");
		}

		Token t4 = ts.get();

		if (t4.kind != assignmentIdentifier)
		{
			throw std::runtime_error("declaration:declaration: = missing in declaration\n");
		}

		double constantVariableValue = expression(ts);

		st.add(constantVariableIdentifier, newConstantVarriableName, constantVariableValue);

		return constantVariableValue;
	}
	else
	{
		if (st.is_declared(newVariableName))
		{
			throw std::runtime_error("declaration: variable already declared!\n");
		}

		Token t2 = ts.get();

		if (t2.kind != assignmentIdentifier)
		{
			throw std::runtime_error("declaration: = missing in declaration\n");
		}

		double newVariableValue = expression(ts);

		st.add(variableIdentifier, newVariableName, newVariableValue);

		return newVariableValue;
	}
}

//--------------------------------------------------------------------------------------------------------

/*
	Function: statement();
	 
	Extracts a token and if that token is of
	kind keyword for user defined variable: 
	calls definition; otherwise it ungets the 
	token and calls expression().
*/
double statement(Token_stream& ts)
{
	Token t = ts.get();
	switch(t.kind) 
	{
		case declarationIdentifier:
		{
			return declaration(ts);
		}
		default:
		{
			ts.unget(t);
			return expression(ts);
		}
	}
}

//--------------------------------------------------------------------------------------------------------

/*
	Function: clean_up_mess();
	 
	It ignores the symbol used for
	print command. Used for error handling, 
	to skip the error code and resume 
	execution. Called from catch runtime error
	block.
*/
void clean_up_mess(Token_stream& ts)
{
	ts.ignore(printKeyword);
}

//--------------------------------------------------------------------------------------------------------

/*
	Function: calculate();
 
	Prompts the user for input
	and performs one of three operations:
	exit program, print result or feed input
	in statement() and display the result.
	Contains try-catch block and runtime error 
	handling. Called from main().
*/
void calculate(Token_stream& ts, std::ostream& os = std::cout, std::ostream& es = std::cerr)
{
	while(true)
	{
		try 
		{
			os << prompt;
			Token t = ts.get();

			while(t.kind == printIdentifier)
			{
				t = ts.get();
			}

			if (t.kind == quitIdentifier)
			{
				return;
			}

			if (t.kind == helpIdentifier)
			{
				helpFunction(os);
			}
			 
			if (t.kind == romanNumeralIdentifier)
			{
				ts.unget(t);
				std::cout << result << to_roman((int) statement(ts)) << std::endl;
			}
			else
			{
				ts.unget(t);
				std::cout << result << statement(ts) << std::endl;
			}
		}
		catch(std::runtime_error& e)
		{
			es << e.what() << std::endl;
			clean_up_mess(ts);
		}
		catch(...)
		{
			es <<"unknown exception!"<< std::endl;
		}
	}
}
