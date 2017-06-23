/* 
  TITLE			   String Manipulation            Chapter3Drill.cpp
  Bjarne Stroustrup "Programming: Principles and Practice Using C++"
  COMMENT
 		Objective: I/O interaction and basic string manipulation. 
 			Input: Reqeusts information (name, age, sex)
 		   Output: It prints standard text depending on the input information.
		   Author: Chris B. Kirov
		     Data: 1.2.2015
*/
#include "../../std_lib_facilities.h"

 

int main()
{
	// comparison variables; avoiding "magical" literals 
	const char male ='m';
	const char female ='f';
	const char other = 'o';

	cout << "Please enter your first name (followed by CR-(Enter)):\n";
	string first_name;
	cin >> first_name;

	cout << "Dear," << first_name << "!\n";															 
	cout << "\t" << "greetings from Greece, here it is mildly hot summer, perfect for vacation.\n";	 
	cout << "\t" << "I hope you are great, can not wait to see you!\n";

	cout << "What was our common friend name?\n";
	string friend_name;
	cout << "Have you seen" << friend_name << "lately?\n";											 

	cout << "What is" << friend_name << "'s gender (m/f/o)?\n";
	char friend_sex = 0;

	while (friend_sex != male || friend_sex != female || friend_sex != other)
	{ 
			cout << "Select from the three (char) options: ""m"" for: male, ""f"" for: female, ""o"" for: other" << endl;
			cin >> friend_sex; 
	}

	if (friend_sex == male)
	{ 
		cout << "If you see" << friend_name << ", please ask him to call me.\n";
	}	 
	else if (friend_sex == female)
	{ 
		cout << "If you see" << friend_name << ", please ask her to call me.\n";
	}
	else if (friend_sex == other) 
	{ 
		cout << "If you see" << friend_name << ", please tell that I asked for a phonecall. \n";
	}

	cout << "How old were you?\n";																	 
	int age = 0;
	cin >> age;

	if (age < 0 || age > 100)
	{
		error("You are kidding!?"); 
	}										 
	if (age = 12)
	{
		cout << "I heard that you are turning" << age + 1 << "next month.\n"; 
	}
	if (age = 17)
	{ 
		cout << "Next year you will able to vote.\n"; 
	}
	if (age > 70)
	{ 
		cout << "I hope you are enjoing retirement.\n";
	}

	cout << "Yours sincerely," << "\v\v" << "Chris\n";												 
}
