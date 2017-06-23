/* 
   TITLE  		  I/O parsing 	     			    Chapter4Drill.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
       Objective: Test each step.
           Input: - 
          Output: -
		  Author: Chris B, Kirov
            Date: 01. 04. 2015

*/
#include "../std_lib_facilities.h"
 
// 1. while loop reading and printing two int values;
// exit by typing '|' as sentinel value
void input_check(string&, string&);

// 2. find smaller / larger between the two input values
void find_extrema(int a, int b);

// 3. print whether the tho input integers are equal
void are_equal(int a, int b);

// 4 read doubles until sentinel is typed
void input_check_doubles(string&, string&);

// 5. compare floating point numbers; down to a minimal value
// differentiating two consequtive numbers
void almost_equal(double, double, double);

// 6. read a double at a time and keep track of the extrema; 
// print min/max at exit
void input_extrema(string&, string&);

// 7. read lenght value as double and units as string;
// define legth convertion factors
struct My_pair
{
	double length;
	string unit;

	My_pair(double l,const string& u)
		: length(l), unit(u) 
	{
	
	}
};

void length_input(string&, string&);
My_pair parse_length_unit(string&);
double convert_to_meters(double, string&);

// 8. reject invalid values or lengths without units
bool is_valid_unit(string&);

// 9. accumulate all input lenghts and units till "|"; 
// calculate sum (in meters), min, max, total number
void print_stats(const vector<My_pair>&);

// 10. & 11. sort and print the lenghts
void sort_lenghts(const vector<My_pair>&);

//===========================================================================
int main() 
{
	
	string prompt = "Type two ints; '|' to end:\n>>";
	string sentinel = "|";
	input_check(prompt, sentinel);

	string prompt2 = "Type two doubles; '|' to end:\n>>";
	string sentinel2 = "|";
	input_check_doubles(prompt2, sentinel2);

	string prompt3 = "Type a double:\n>>";
	string sentinel3 = "|";
	input_extrema(prompt3, sentinel3);

	length_input();
}

//===========================================================================


//---------------------------------------------------------------------------
// 1.
/*
	Function: input_check()
	Use: input_check(prompt_message, sentinel_character)

	It reads a pair of intergers from standard input, 
	while displaying the result of their comparison;
	till sentinel typed.
*/
void input_check(string& prompt, string& sentinel)
{
	cout << prompt;

	string line;
	while (getline(cin, line) && line != sentinel)
	{
		stringstream ss(line);

		int num1= 0, num2 = 0;
		
		if (ss >> num1 >> num2)
		{
			cout << num1 <<" "<< num2 <<'\n';

			find_extrema(num1, num2);

			are_equal(num1, num2);
		}
		else 
		{
			cout <<"Not supported input value!\n";
		}
	}
	cout <<"Exit\n";	
}

//---------------------------------------------------------------------------
// 2.
/*
	Function: find_extrema()
	Use: find_extrema(int_val1, int_val2)

	It prints the result of the comparison
	between the two parameters.
*/
void find_extrema(int a, int b)
{
	cout <<"the smaller value is: ";
	if (a < b)
	{
		 cout << a <<'\n';
	} 
	else
	{
		cout << b <<'\n';
	}

	cout <<"the larger value is: ";
	if (b > a)
	{
		cout << b <<'\n';
	}
	else
	{
		cout << a <<'\n';
	}
}

//---------------------------------------------------------------------------
// 3.
/*
	Function: are_equal()
	Use: are_equal(int_val1, int_val2);

	It prints whether the two parameters
	are equal; otherwise it prints nothing.
*/
void are_equal(int a, int b)
{
	if (a == b)
	{
		cout << "the numbers are equal\n";

	}
}

//---------------------------------------------------------------------------
// 4.
/*
	Function: input_check_doubles()
	Use: input_check_doubles(prompt_message, termination_character)

	It reads a pair of doubles from standard input and 
	performs comparison between them down to a precision
	determined by the parameter: epsilon;
*/
void input_check_doubles(string& prompt, string& sentinel)
{
	cout << prompt;

	string line;
	while (getline(cin, line) && line != sentinel)
	{
		stringstream ss(line);

		double num1= .0, num2 = .0;
		
		if (ss >> num1 >> num2)
		{
			cout << num1 <<" "<< num2 <<'\n';

			double eps = 1.0 / 10000000;
			almost_equal(num1, num2, eps);
		}
		else 
		{
			cout <<"Not supported input value!\n";
		}
	}
	cout <<"Exit\n";	
}

//---------------------------------------------------------------------------
// 5.
/*
	Function: almost_equal()
	Use: almost_equal(double_val1, double_val2);

	It performs a comparison between double values
	of the two first parameters, down to a precision
	determined by the third parameter.
*/
void almost_equal (double a, double b, double epsilon)
{ 
	 double res = a - b;
	 if (abs(res) < epsilon) 
	 {
		cout <<"the numbers are almost equal\n";
		return;
	 }

	 cout <<"the smaller value is: ";
	 if (res < 0) 
	 {
		cout << a <<'\n';
	 }
	 else
	 {
		cout << b <<'\n';
	 }

	 cout <<"the larger value is: ";
	 if (res > 0)
	 {
		cout << a <<'\n';
	 }
	 else
	 {
		cout << b <<'\n';
	 }
}

//---------------------------------------------------------------------------
// 6.
/*
	Function: input_extrema()
	Use: input_extrema(prompt, termination);

	It reads a pair of doubles till a sentinel
	is typed, while keeping current input min and max
	value.
*/
void input_extrema(string& prompt, string& sentinel)
{
	double min = 1000000;
	double max = -1000000;

	cout << prompt;
	string line;
	while (getline(cin, line) && line != sentinel)
	{
		stringstream ss(line);

		double num1= .0;
		
		if (ss >> num1)
		{
			cout << num1;
			if (num1 > max)
			{
				max = num1;
				cout <<" the largest so far.";
			}
			if (num1 < min)
			{
				min = num1;
				cout <<" the smallest so far.";
			}
			cout <<"\n";
		}
		else 
		{
			cout <<"Not supported input value!\n";
		}
	}
	cout <<"Exit\n";	
}

//---------------------------------------------------------------------------
// 7
/*
	Function: length_input()
	Use: length_input();

	It reads a pair of lenght (double) and unit (string), till sentinel is types;

	It converts all the lengths to meters and it prints:
	sum, min, max, and it prints them in ascending order.
*/
void length_input(string prompt = "Type length and unit:\n>>", string sentinel = "|")
{
	cout << prompt;
	string line;

	vector<My_pair> raw_lengths;

	// read a line of  input 
	while(getline(cin,line) && line != sentinel)
	{
		My_pair mp = parse_length_unit(line);

		const int invalid_value = -1;
		if (mp.length != invalid_value) 
		{
			raw_lengths.push_back(mp);
		}
	}

	print_stats(raw_lengths);

	sort_lenghts(raw_lengths);
}

/*
	Function: parse_length_unit()
	Use: parse_length_unit(input_line);

	It parses the input line consisted 
	of a string in the format of concatenated
	floating point number and string, constucting
	an object consisted of the same values separated.
	It performs unit check and returns invalid
	value (-1, 0), in case of false check.
*/
My_pair parse_length_unit(string& line)
{

	// input variables
	double length = 0;
	string unit;

	stringstream ss(line);
	 
	// parse input character by character
	char ch;
    while(ss.get(ch))
    {
	    // differentiate between digit and alphabetic value
        if (isdigit(ch) || ch == '.')
        {
            string s;
            s += ch;
        
            while (ss.get(ch) && (isdigit(ch) || ch == '.'))
            {
               s += ch;    
            }
        
            ss.putback(ch);
        
            stringstream numeric_input(s);
            numeric_input >> length;
        }
        else if (isalpha(ch))
        {
	    	unit = ch;
		    while(ss.get(ch) && isalpha(ch))
 		    {
			    unit += ch; 
		    }
		
		    ss.putback(ch); 
        }
	    else 
	    {
	        cout <<"Not supported value!\n";
	    }
    }	

	// check units
	if (is_valid_unit(unit))
	{
		return My_pair(length, unit);
		
	} 
	else
	{
		return My_pair(-1, 0);
		cout <<"Unit not supported!\n";		
	}
}

//---------------------------------------------------------------------------
// 8
/*
	Function: is_valid_unit()
	Use: bool valid = is_valid_unit(unit);

	It compares the parameter to a list 
	of predefined vector elements, if there
	is a match it returns true; otherwise
	it retunrs false.
*/
bool is_valid_unit(string& test_unit)
{
	vector<string> valid_units;
	valid_units.push_back("cm");
	valid_units.push_back("m");
	valid_units.push_back("in");
	valid_units.push_back("ft");

	for (unsigned int i = 0; i < valid_units.size(); ++i)
	{
		if (test_unit == valid_units[i]) return true;
	}
	return false;
}

//---------------------------------------------------------------------------
// 9
/*
	Function: convert_to_meters()
	Use: double meter = convert_to_meters(lenght, unit);

	It returns a converted lenght in meters multiplying it 
	by a factor depending on the second parameter.
*/
double convert_to_meters(double length, string unit)
{
	vector<string> valid_units;
	valid_units.push_back("cm");
	valid_units.push_back("m");
	valid_units.push_back("in");
	valid_units.push_back("ft");

	// correspond to the above units
	vector<double> conversion_factors;
	conversion_factors.push_back(0.0100);
	conversion_factors.push_back(1.0000);
	conversion_factors.push_back(0.0254);
	conversion_factors.push_back(0.3048);

	for (unsigned int i = 0; i < valid_units.size(); ++i)
	{
		if (unit == valid_units[i]) 
		{
			return length * conversion_factors[i];
		}
	}
	return 0;
}

/*
	Function: print_stats()
	Use: print_stats(raw_lengths)

	It prints the number, sum, min and max
	of the, converted in meters, lengths.
*/
void print_stats(const vector<My_pair>& raw_lengths)
{
	// print total number
	cout << "Number of lengths: "<< raw_lengths.size() <<'\n';

	// convert to meters and sum
	double total_sum = 0;
	double min = 1000000, max = -1000000;
	for (unsigned int i = 0; i < raw_lengths.size(); ++i)
	{
		double meters = convert_to_meters(raw_lengths[i].length, raw_lengths[i].unit);

		if (meters > max)
		{
			max = meters;
		}
		if (meters < min)
		{
			min = meters;
		}

		total_sum += meters;
	}
	cout <<"Total sum: "<< total_sum <<'\n';
	cout <<"Max: "<< max <<'\n';
	cout <<"Min: "<< min <<'\n';
}

//---------------------------------------------------------------------------
// 10 & 11
/*
	Function: sort_lenghts()
	Use: sort_lenghts(raw_lengths)

	It sorts and prints the converted
	in meters lenghts in ascending order. 
*/
void sort_lenghts(const vector<My_pair>& raw_lengths)
{
	vector<double> lenghts_in_meters;

	for (unsigned int i = 0; i < raw_lengths.size(); ++i)
	{
		double meters = convert_to_meters(raw_lengths[i].length, raw_lengths[i].unit);

		if (meters)
		{
			lenghts_in_meters.push_back(meters);
		}
	}

	sort(lenghts_in_meters.begin(), lenghts_in_meters.end());

	for (unsigned int i = 0; i < lenghts_in_meters.size(); ++i)
	{
		cout << lenghts_in_meters[i] <<"\n";
	}
}