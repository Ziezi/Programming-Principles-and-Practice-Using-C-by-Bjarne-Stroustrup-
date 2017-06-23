/* 
	TITLE          String comparison              Chapter3Exercise7.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
     COMMENT
		Objective: Put in order three strings; 
		           Next to each other if they are equal. 
				   Useful terms: Hamming distance. ASCII char values.

			Input: Requests 3 strings.
		   Output: Prints the ordered strings.
		   Author: Chris B. Kirov
		     Date: 01.02.2014
*/
 
#include "../../std_lib_facilities.h"
 
int main()
{
	// prompt message  
	cout << "Please enter three words." << endl;
	cout << "The first word:\t" << endl;
	string str1;
	cin >> str1;
	cout << "The second word:\t" << endl;
	string str2;
	cin >> str2;
	cout << "The third word:\t" << endl;
	string str3;
	cin >> str3; 

	// input confirmation
	cout << "\n\n\n" << endl;
	cout << str1 << "," << str2 << "," << str3 << endl;
	cout << "\n" << endl;
	
	// string comparison; strings are sequence of characters; characters are int types (ASCII code puts them in order)
	if (str1 <= str2 && str2 <= str3)
	{ 
		cout << "The words in ascending order are: " << str1 << ',' << str2 << ',' << str3 << endl;
	}
	else if (str1 >= str2 && str1 <= str3)
	{ 
		cout << "The words in ascending order are: " << str2 << ',' << str1 << ',' << str3 << endl; 
	}
	else if (str1 > str2 && str1 >= str3 && str2 <= str3)
	{ 
		cout << "The words in ascending order are: " << str2 << ',' << str3 << ',' << str1 << endl;
	}
	else if (str1 >= str2 && str2 >= str3)
	{ 
		cout << "The words in ascending order are: " << str3 << ',' << str2 << ',' << str1 << endl; 
	}
	else if (str1 >= str3 && str1 >= str2)
	{ 
		cout << "The words in ascending order are: " << str3 << ',' << str1 << ',' << str3 << endl;
	}
	else if (str1 <= str3 && str3 <= str2)
	{ 
		cout << "The words in ascending order are: " << str1 << ',' << str3 << ',' << str2 << endl; 
	}

	return 0;
}
 