 /* 
	TITLE			    				      Chapter16Exercise9Calc.h
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			    Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Data:  
*/

#ifndef _Chapter16Exercise9Calc_h_
#define _Chapter16Exercise9Calc_h_

// symbolic constants used in the code
// "keyword" is a read via input
// "identifier" is an internal semaphore for function communication

const char sinFunctionIdentifier = 't';
const std::string sinFunctionKeyword = "sin";
#define PI 3.14159

const char factorialIdentifier = '!';

const std::string helpKeyword = "H";
const char helpIdentifier = 'h';

const char printKeyword = '=';			
const char printIdentifier = 'r'; 

const char numberIdentifier = '8';	

const char romanNumeralIdentifier = 'o';

const char nameIdentifier = 'a';	 

const std::string quitKeyword = "Q";		
const char quitIdentifier = 'q';	 

const std::string declarationKeyword = "let";
const char declarationIdentifier = 'L';	 

const std::string squareRootKeyword = "sqrt";
const char mysqrtIdentifier = 's';	 

const std::string powerKeyword = "pow";
const char mypowIdentifier = 'p';	 

const std::string redirectInputKeyword = "from";
const char redirectedInputIdentifier = 'i';

const std::string redirectOutputKeyword = "to";
const char redirectedOutputIdentifier = 'e';

const char fileNameIdentifier = 'f';

const char assignmentIdentifier = '=';

#define k 1000;				

const std::string constantVariableKeyword = "const";
const char constantVariableIdentifier = 'c';

const char variableIdentifier = 'v';

const std::string prompt = "> ";	// symbol used to prompt the user for input
const std::string result = "= ";	// symbol after which the result is printed
//==============================================================================

/*
	class: Token

	Used for the conversion
	of raw input to interpreted
	data used for algebraic
	calculations.
*/
class Token 
{
public:
	char kind;
	double value;
	std::string name;

	Token(char ch)
		: kind(ch), value(0)
	{
	
	}

	Token(char ch, double val)
		:kind(ch), value(val) 
	{
	
	}

	Token(char ch, std::string n) 
		:kind(ch), name(n)
	{
	
	}
};
//==============================================================================

/*
	class Token_stream
	Used as a buffer for
	tokenized input.
*/ 
class Token_stream 
{
public:
	Token_stream() 
		:full(false), buffer(0), input_stream(std::cin) 
	{

	}

	Token_stream(std::istream& is) 
		:full(false), buffer(0), input_stream(is) 
	{

	}

	Token get();
	void unget(Token t); 
	void ignore(char s);

private:

	bool full;
	Token buffer;

	// input streams are not copyable, that is why we need a reference to the stream
	std::istream& input_stream;
} ts;  // <----- to redirect input stream initialise constructor with the appropriate stream

//==============================================================================
/*
	class Table
	
	Used to store/recover user-defined variables.
*/
class Table  
{
public:
	inline double get(std::string n)
	{
		return get_value(n);
	}

	inline double set(std::string n, double newValue)
	{
		return reAssign(n, newValue);
	}

	inline void declare(char i, std::string n)
	{
		set_value(i,n,0);
	}

	inline bool is_declared(std::string name)
	{
		return is_Declared(name);
	}

	inline bool is_constvar(std::string name)
	{
		return is_constantVar(name);
	}

	inline void add(char i, std::string n, double v)
	{
		symbol_table.push_back(Variable(i, n, v));
	}
	
private:
	/*
		class Variable
		Defining data structure used 
		for user defined variables.
	*/
	class Variable
	{
	public:
		char identifier;
		std::string name;
		double value;	

		Variable(char i, std::string n, double v)
			: identifier(i), name(n), value(v) 
		{
		
		}
	};

	// container holding the user defined variables; 
	std::vector<Variable> symbol_table;	 

	double get_value(std::string s);
	void set_value(char i ,std::string s, double d);
	bool is_Declared(std::string s);
	double reAssign(std::string n, double newValue);
	bool is_constantVar(std::string name);
} st; // object of type Symbol_table used in the program  
//==============================================================================

// forward declarations
double expression(Token_stream& ts);
bool is_roman_digit(char& r);
bool is_roman_number(std::string& roman);
int to_arab(std::string& s);
std::string to_roman(int value);
bool is_file_name(std::string&);

//==============================================================================
#include "Chapter16Exercise9CalcDef.cpp"

#endif