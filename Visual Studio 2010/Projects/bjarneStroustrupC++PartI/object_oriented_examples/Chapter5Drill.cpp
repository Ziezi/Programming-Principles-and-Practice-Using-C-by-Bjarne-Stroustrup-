/* 
   TITLE			   Debug using exception handler  Chapter5Drill.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
 			Objective: Remove all errors in the following lines.
 				Input: -
 			   Output: Prints "Success" if no errors present.
			   Author: Chris B. Kirov
		         Data: 1.2.2015
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	try
	{
		cout <<"1.Success!\n";
		cout <<"2.Success!\n";
		cout <<"3.Success" << "!\n";
		cout <<"4.Success!" << endl;

		int res = 7; 
		vector<int> v1(10); 
		v1[5] = res; 
		cout << "5.Success!\n";

		vector<int> v2(10); 
		v2[5] = 5; 

		if (v2[5] == 5) cout <<"6.Success!\n";
		if (v2[5] == 5) cout <<"7.Success!\n";				// Value accessed and compared to literal (immediate value)
		else cout <<"7.Fail\n";

		bool c = false; 
		if (!c) cout <<"8.Success!\n"; 
		else cout <<"8.Fail!\n";

		string s = "ape"; 
		c = "fool";											// bool is 8-bit memory location assigned a 4-bit string 
		if (c) cout << "9.Success!\n";						// (everything different than 'false' is true)?

		s = "fool";											// passed by value: s is a new copy of string s with new value  
		if (s == "fool") cout <<"10.Success!\n";

		s = "ape";
		if (s != "fool") cout <<"11.Success!\n";			// passed by value: s is a new copy of string s with new value  

		bool s1 = "ape";									// bool is 8-bit memory location assigned a 3-bit string
		if (s1 + "fool") cout <<"12.Success!\n"; 

		vector<char> v(5); 
		for (int i = 0; i < v.size(); ++i); 
		cout <<"13.Success!\n";								// Always prints, regardless of thrown out-of-range exception 

		vector<char> v3(5);
		for (int i = 0; i <  v.size(); ++i); 
		cout <<"14.Success!\n";								// Always prints, regardless of thrown out-of-range exception 		

		string ss = "15.Success!\n"; 
		for (int i = 0; i < 12; ++i) cout << ss[i];			// successful loop over the index of the vector(no out of range exception)
		if (true) cout << "16.Success!\n";					// Always prints, as set to true
		else cout <<"Fail!\n";

		int x = 2000; 
		char ch = x; 
		if (ch = 2000) cout <<"17.Success!\n";				// ASCII representation of the char 'x' matches the int representation of 2000

		string sss = "18.Success!\n"; 
		for (int i = 0; i < 12; ++i) cout << sss[i];		// successful loop over the index of the vector(no out of range exception)

		vector<string> v4(5); 
		for (int i = 0; i < v.size(); ++i);					// successful loop over the index of the vector(no out of range exception)
		cout <<"19.Success!\n";							

		int i = 0; 
		int j = 9; 
		while (i < 10) ++i; 
		if (j < i) cout <<"20.Success!\n";				    // post condition incrementing: while loop i broken, then i is incremented

		int x1 = 4; 
		double d = 5 / double(x1 - 2); 
		if (d == 2.5) cout <<"21.Success!\n";				// int to double cast

		string ssss = "22.Success!\n"; 
		for (int i = 0; i < 12; ++i) cout << ssss[i];		// loop over the index of the string

		int ii = 0;
		while (ii < 10) ++ii; 
		if (j > ii) cout <<"22.Success !\n";				// false, not dispalying as j=9

		int i2 = 0; 
		while (i2 < 10) ++i2; 
		if (j < i2) cout <<"23.Success!\n";					// same as: 20.Success, i is incremented to 10 

		int x2 = 4; 
		double d2 = 5 / (x2 - 2); 
		if (d2 = 2 * x2 + 0.5) cout <<"24.Success!\n";		// fail: integer division
		cout <<"25.Success!\n";

		return 0;
	}
	catch (exception& e)
	{
		cerr <<"error: "<< e.what() <<'\n'; 
		getchar();
		return 1;
	}
	catch (...)
	{
		cerr << "Oops: uknown exception!\n";
		getchar();
		return 2;
	}
}



