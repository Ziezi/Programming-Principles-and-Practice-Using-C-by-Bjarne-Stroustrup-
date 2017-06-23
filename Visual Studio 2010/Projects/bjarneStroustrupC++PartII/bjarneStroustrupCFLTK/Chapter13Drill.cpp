/*
	TITLE		Get a grip with Graph_lib members     Chapter13Drill.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Utilize the facilities provided by Graph_lib 
		           to create graphical objects.
				   1. Create an Simple_window with size 800 x 1000
				   2. Draw a 8 x 8 grid on the leftmost 800 x 800,
				      with size 100 x 100.
				   3. Color the diagonal bixes in red using Rectangle.
				   4. Find image and place 3 copies on such that covers
				      4 boxes (use mask() if needed).
				   5. Add an image that moves from box to box when the 
				      button "Next" is pressed.
		    Input: -
		   Output: prints graphical objects
		   Author: 10.09.2015
		     Date: Chris B. Kirov
*/
#include "GUI.h"
#include "Simple_window.h"
#include <iostream>
#include <random>

int main()
{
     // Objective 1
	 int winWidth = 800;
	 int winHeight = 1000;
	 Point center((x_max() - winWidth) / 2., (y_max() - winHeight) / 2.);
	 Simple_window sw(center, winWidth, winHeight, "Chapter 13 Drill");

	try
	{
		// Objective 2
		vector<Graph_lib::Line*> gridLines;
		size_t gridSideX = 90;
		size_t gridSideY = 90;
		size_t gridRowNumber = 8;
		size_t gridColumnNumber  = 8;

		// add horizonatal lines
		for (size_t i = 0; i <= gridRowNumber; ++i)
		{ 
			gridLines.emplace_back(new Graph_lib::Line(Point(0, gridSideX * i), Point(gridSideX * gridColumnNumber, gridSideX * i)));
		}
	    // add vertical lines 
		for (size_t j = 0; j <= gridColumnNumber; ++j)
		{
			gridLines.emplace_back(new Graph_lib::Line(Point(gridSideY * j, 0), Point( gridSideY * j, gridSideY * gridRowNumber)));
		}
		// attach lines to window
		for (auto it = gridLines.begin(); it != gridLines.end(); ++it) sw.attach(**it);
	
		// Objective 3
		vector<Graph_lib::Rectangle*> diagonalBoxes;
		for (size_t m = 0; m < gridRowNumber; ++m)
		{
			diagonalBoxes.emplace_back(new Graph_lib::Rectangle(Point(gridSideX * m, gridSideY * m), gridSideX, gridSideY));
		}
		// attach rectangles to window
		for (auto it = 0; it < diagonalBoxes.size(); ++it)
		{
			diagonalBoxes[it]->set_fill_color(Color::red);
			diagonalBoxes[it]->set_color(Color::invisible);
			sw.attach(*diagonalBoxes[it]);
		}

		// Objective 4
		size_t numOfPics = 3;
		vector<Image*> allPics;
		// add images and cut them in the same size
		for (size_t n = 0; n < numOfPics; ++n)
		{
			allPics.emplace_back(new Image (Point(0, 90), "prof_pic.jpg"));
			allPics[n]->set_mask(Point(0,200),gridSideX * 2, gridSideY * 2);
		}
		// move them away from the diagonal	
        allPics[0]->move(0, gridSideY * 5);
		allPics[1]->move(gridSideX * 6, -gridSideY);
		allPics[2]->move(gridSideX * 6, gridSideY * 2);
		// attach the to the window
		for(auto it = allPics.begin(); it != allPics.end(); ++it) sw.attach(**it);
			
		// Objective 5
		// random number generator
		mt19937 rng;
		rng.seed(random_device());
		uniform_int_distribution<int> dist0to7(0, 6);

		// loop to make a number of random moves
		int numOfMoves = 5;
		for (size_t p = 0; p < numOfMoves; ++p)
		{
			Image movingPic(Point(gridSideX * dist0to7(rng), gridSideY * dist0to7(rng)), "Chess_king90x90.jpg");
			sw.attach(movingPic);
			sw.wait_for_button();
		}

		sw.wait_for_button();
		// gridLines: free heap memory 
		for (auto it = gridLines.begin(); it != gridLines.end(); ++it) delete *it;
		// diagonalBoxes: free heap memory
		for (auto it = diagonalBoxes.begin(); it != diagonalBoxes.end(); ++it) delete *it;
		// allPics: free heap memory
		for (auto it = allPics.begin(); it != allPics.end(); ++it) delete *it;
	}
	catch(exception& e)
	{
		cerr << e.what() << endl;
		getchar();
	}
	catch(...)
	{
		cerr <<"Default exception!"<< endl;
		getchar();
	}
	return 0;
}