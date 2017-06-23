 /*
   TITLE	           Linking, Run-time & Logical errors  Chapter5TryThis3.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
 			Objective: Observe the response from the linking, run-time & logical errors.
					   Print the calculated areas;
					   Insert tests until all errors caught (result as expected).
 				Input: -
 			   Output: IntelliSense, compiler (and you) responds with error messages.
			   Author: Chris B. Kirov
		         Data: 1.2.2015
*/
#include <iostream>
 
int area (int, int);
int framed_area(int, int);

//=============================================================================================
int main()
{
	 int x = -1;
	 int y = 2;
	 int z = 4;

	 int area1 = 0, area2 = 0, area3 = 0;
	 double ratio = 0;

	 // caller test
	 if (x <= 0 || y <= 0)
	 {
		std::cerr << "Invalid parameters!\n";
	 }
	 else
	 {
		area1 = area(x, y);
	 }

	 // caller test
	 if (y <= 0 || z <= 0)
	 {
		std::cerr <<"Invalid paremeters!\n";
	 }
	 else
	 {
		area2 = framed_area(1, z);
		area3 = framed_area(y, z);
	 }

	 // caller test
	 if (area3 == 0)
	 {
		std::cerr <<"Division by 0!\n";
	 }
	 else
	 {
		ratio = double (area1) / area3;
	 }

	 std::cout <<"area1: "<< area1 <<'\n';
	 std::cout <<"area2: "<< area2 <<'\n';
	 std::cout <<"area3: "<< area3 <<'\n';
	 std::cout <<"ratio: "<< ratio <<'\n';

	 getchar();
}
//=============================================================================================

int area (int length, int width)
{
	// callee test
	if (length <= 0 || width <= 0)
	{
		std::cerr <<"area: Invalid parameter!\n";
		return 0;
	}
	return length * width;
}

int framed_area(int x, int y)
{
	int frame = 2;
	if (x <= frame || y <= frame)
	{
		std::cerr << "framed_area: Invalid parameter!\n";
		return 0;
	}
	return area(x - frame, y - frame);
}