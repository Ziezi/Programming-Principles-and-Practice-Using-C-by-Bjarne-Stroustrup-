/*
	TITLE			   Draw a diagram  	       Chapter12Exercise10.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Draw the FLTK and helper GUI headers and 
			           source files hierarchical diagram, 
					   from Chapter 12.8.
			    Input: -
			   Output: Graph on screen.
			   Author: Chris B. Kirov
			     Date: 31. 08. 2015
*/
#include <iostream>
#include "Simple_window.h"

/*
Simple_window& boxWithText(Simple_window& sw, 
	                       int topLeftX, int topLeftY, 
				           const string& upLine, const string& line1, 
						   const string& line2, const string& line3);
 */
//--------------------------------------------------------------------------------------------------------------------

int main()
{
	try
	{
		 // create a centered window
		 const int windowWidth = 800;
		 const int windowHeight = 600;
		 Point centerScreen(x_max() / 2.- windowWidth / 2., y_max() / 2. - windowHeight / 2.);
		 Simple_window sw(centerScreen, windowWidth, windowHeight, "Chapter 12 Exercise 10");
		 
		 // create all text boxes
		 const int frameSize = 1;
		 const int heightSeparator = 200;
		 const int widthSeparator = 150; 

		 // Line 1
		 // center box
		 const int l1b1Width = 200;
		 const int l1b1Height = 75;
		 Graph_lib::Rectangle line1Box1(Point(sw.x_max() / 2. - l1b1Width / 2. - 4 * frameSize,
			                                  sw.y_max() - frameSize - l1b1Height), 
									    l1b1Width, 
										l1b1Height);
		 line1Box1.set_fill_color(Color::yellow);
		 sw.attach(line1Box1);

		 // center box text
		 const int textHeight = 20;
		 Text l1b1Text(Point(sw.x_max() / 2. - l1b1Width / 2. + frameSize,
			                  sw.y_max() - 2 * frameSize - l1b1Height), 
					    "#include Chapter12.cpp");
		 sw.attach(l1b1Text);

		 Text l1b1Text1(Point(sw.x_max() / 2. - l1b1Width / 2. + frameSize,
			                  sw.y_max() - (2 * frameSize) - l1b1Height + textHeight), 
					    "#include \"Graph.h\"");
		 sw.attach(l1b1Text1);

		 Text l1b1Text2(Point(sw.x_max() / 2. - l1b1Width / 2. + frameSize,
							   sw.y_max() - (2 * frameSize) - l1b1Height + 2 * textHeight), 
					     "#include \"Simple_window.h\"");
		 sw.attach(l1b1Text2);
		
		 Text l1b1Text3(Point(sw.x_max() / 2. - l1b1Width / 2. + frameSize,
							  sw.y_max() - (2 * frameSize) - l1b1Height + 3 * textHeight), 
					    "#include \int main() { ... }");
		 sw.attach(l1b1Text3);
		
		 // Line 2 (from bottom):
		 // left box
		 const int l2b1Width = 100;
		 const int l2b1Height = 20;
		 Graph_lib::Rectangle line2Box1(Point(frameSize,
			                                  sw.y_max() - heightSeparator), 
									    l2b1Width, 
										l2b1Height);
		 line2Box1.set_fill_color(Color::yellow);
		 sw.attach(line2Box1);
		 // left box text
		 Text l2b1Text(Point(frameSize,
			                 sw.y_max() - heightSeparator - 2 * frameSize),
					    "#include Graph.cpp");
		 sw.attach(l2b1Text);

		 Text l2b1Text1(Point(frameSize,
                              sw.y_max() - heightSeparator + textHeight - 2 * frameSize), 
					    "Graph code");
		 sw.attach(l2b1Text1);
		 // center box
		 const int l2b2Width = 200;
		 const int l2b2Height = 60;
		 Graph_lib::Rectangle line2Box2(Point(sw.x_max() / 2. - l2b2Width / 2. - 4 * frameSize,
			                                  sw.y_max() - heightSeparator), 
									    l2b2Width, 
										l2b2Height);
		 line2Box2.set_fill_color(Color::yellow);
		 sw.attach(line2Box2);
		 // center box text
		 Text l2b2Text(Point(sw.x_max() / 2. - l2b2Width / 2. - 4 * frameSize,
			                 sw.y_max() - heightSeparator - 2 * frameSize),
					    "Simple_window.h");
		 sw.attach(l2b2Text);
		 Text l2b2Text1(Point(sw.x_max() / 2. - l2b2Width / 2. - 4 * frameSize,
                              sw.y_max() - heightSeparator + textHeight + frameSize), 
					    "// window interface");
		 sw.attach(l2b2Text1);
		 Text l2b2Text2(Point(sw.x_max() / 2. - l2b2Width / 2. - 4 * frameSize,
                              sw.y_max() - heightSeparator + 2 * textHeight + frameSize), 
					    "Class Simple_window { ... };");
		 sw.attach(l2b2Text2);
		 Text l2b2Text3(Point(sw.x_max() / 2. - l2b2Width / 2. - 4 * frameSize,
                              sw.y_max() - heightSeparator + 3 * textHeight - 2 * frameSize), 
					    "...");
		 sw.attach(l2b2Text3);
		 // right box
		 const int l2b3Width = 100;
		 const int l2b3Height = 20;
		 Graph_lib::Rectangle line2Box3(Point(sw.x_max() - l2b3Width - frameSize,
			                                  sw.y_max() - heightSeparator), 
									    l2b3Width, 
										l2b3Height);
		 line2Box3.set_fill_color(Color::yellow);
		 sw.attach(line2Box3);
		 // right box text
		 Text l2b3Text(Point(sw.x_max() - l2b3Width - frameSize,
			                 sw.y_max() - heightSeparator - 2 * frameSize), 
					    "GUI.cpp");
		 sw.attach(l2b3Text);
		 Text l2b3Text1(Point(sw.x_max() - l2b3Width - frameSize,
                              sw.y_max() - heightSeparator + textHeight - 2 * frameSize), 
					    "GUI code");
		 sw.attach(l2b3Text1);
		 // Line 3 
		 // center box
		 const int l3b1Width = 100;
		 const int l3b1Height = 20;
		 Graph_lib::Rectangle line3Box1(Point(sw.x_max() / 2. - l3b1Width - 6 * frameSize,
			                                  sw.y_max() - 1.5 * heightSeparator), 
									    l3b1Width, 
										l3b1Height);
		 line3Box1.set_fill_color(Color::yellow);
		 sw.attach(line3Box1);
		 // center box text
		 Text l3b1Text(Point(sw.x_max() / 2. - l3b1Width - 6 * frameSize,
			                 sw.y_max() - 1.5 * heightSeparator - 2 * frameSize),
					    "window.cpp");
		 sw.attach(l3b1Text);
		 Text l3b1Text1(Point(sw.x_max() / 2. - l3b1Width - 6 * frameSize,
                              sw.y_max() - 1.5 * heightSeparator + textHeight - 2 * frameSize), 
					    "Window code");
		 sw.attach(l3b1Text1);

		 // Line 4
		 // left box
		 const int l4b1Width = 200;
		 const int l4b1Height = 60;
		 Graph_lib::Rectangle line4Box1(Point(frameSize,
			                                  sw.y_max() - 2 * heightSeparator), 
									    l4b1Width, 
										l4b1Height);
		 line4Box1.set_fill_color(Color::yellow);
		 sw.attach(line4Box1);
		 // left box text
		 Text l4b1Text(Point(frameSize,
			                 sw.y_max() - 2 * heightSeparator - 2 * frameSize),
					    "Graph.h");
		 sw.attach(l4b1Text);
		 Text l4b1Text1(Point(frameSize,
                              sw.y_max() - 2 * heightSeparator + textHeight - frameSize), 
					    "// graphical interface");
		 sw.attach(l4b1Text1);
		 Text l4b1Text2(Point(frameSize,
                              sw.y_max() - 2 * heightSeparator + 2 * textHeight - 2 * frameSize), 
					    "Graph code");
		 sw.attach(l4b1Text2);
		 Text l4b1Text3(Point(frameSize,
                              sw.y_max() - 2 * heightSeparator + 3 * textHeight - 3 * frameSize), 
						"Struct Shape { ... };");
		 sw.attach(l4b1Text3);
		 // center box
		 const int l4b2Width = 200;
		 const int l4b2Height = 60;
		 Graph_lib::Rectangle line4Box2(Point(sw.x_max() / 2. - l4b2Width / 2. - 4 * frameSize,
			                                  sw.y_max() - 2 * heightSeparator), 
									    l4b2Width, 
										l4b2Height);
		 line4Box2.set_fill_color(Color::yellow);
		 sw.attach(line4Box2);
		 // center box text
		 Text l4b2Text(Point(sw.x_max() / 2. - l4b2Width / 2. - 4 * frameSize,
			                 sw.y_max() - 2 * heightSeparator - 2 * frameSize),
					    "Window.h");
		 sw.attach(l4b2Text);
		 Text l4b2Text1(Point(sw.x_max() / 2. - l4b2Width / 2. - 4 * frameSize,
                              sw.y_max() - 2 * heightSeparator + textHeight - frameSize), 
					    "// window interface");
		 sw.attach(l4b2Text1);
		 Text l4b2Text2(Point(sw.x_max() / 2. - l4b2Width / 2. - 4 * frameSize,
                              sw.y_max() - 2 * heightSeparator + 2 * textHeight - 2 * frameSize), 
					    "class Window {...};");
		 sw.attach(l4b2Text2);
		 Text l4b2Text3(Point(sw.x_max() / 2. - l4b2Width / 2. - 4 * frameSize,
                              sw.y_max() - 2 * heightSeparator + 3 * textHeight - 3 * frameSize), 
						"...");
		 sw.attach(l4b2Text3);
		 // right box
		 const int l4b3Width = 200;
		 const int l4b3Height = 60;
		 Graph_lib::Rectangle line4Box3(Point(sw.x_max() - l4b3Width - frameSize,
			                                  sw.y_max() - 2 * heightSeparator), 
									    l4b3Width, 
										l4b3Height);
		 line4Box3.set_fill_color(Color::yellow);
		 sw.attach(line4Box3);
		 // center box text
		 Text l4b3Text(Point(sw.x_max() - l4b3Width - frameSize,
			                 sw.y_max() - 2 * heightSeparator - 2 * frameSize),
					    "GUI.h");
		 sw.attach(l4b3Text);
		 Text l4b3Text1(Point(sw.x_max() - l4b3Width - frameSize,
                              sw.y_max() - 2 * heightSeparator + textHeight - frameSize), 
					    "// GUI interface");
		 sw.attach(l4b3Text1);
		 Text l4b3Text2(Point(sw.x_max() - l4b3Width - frameSize,
                              sw.y_max() - 2 * heightSeparator + 2 * textHeight - 2 * frameSize), 
					    "struct In_box {...};");
		 sw.attach(l4b3Text2);
		 Text l4b3Text3(Point(sw.x_max() - l4b3Width - frameSize,
                              sw.y_max() - 2 * heightSeparator + 3 * textHeight - 3 * frameSize), 
						"...");
		 sw.attach(l4b3Text3);

		 // Line 5
		 const int l5b1Width = 200;
		 const int l5b1Height = 40;
		 Graph_lib::Rectangle line5Box1(Point(frameSize,
			                                  sw.y_max() - 2.5 * heightSeparator), 
									    l5b1Width, 
										l5b1Height);
		 line5Box1.set_fill_color(Color::yellow);
		 sw.attach(line5Box1);
		 // left box text
		 Text l5b1Text(Point(frameSize,
			                 sw.y_max() - 2.5 * heightSeparator - 2 * frameSize),
					    "Point.h");
		 sw.attach(l5b1Text);
		 Text l5b1Text1(Point(frameSize,
                              sw.y_max() - 2.5 * heightSeparator + textHeight - frameSize), 
					    "struct Point {...};");
		 sw.attach(l5b1Text1);
		 // center box
		 const int l5b2Width = 200;
		 const int l5b2Height = 40;
		 // two background empty polygons
		 Graph_lib::Rectangle b1line5Box2(Point(sw.x_max() / 2. - l5b2Width / 2. - 4 * frameSize - - 6 * frameSize,
			                                    sw.y_max() - 2.5 * heightSeparator - - 6 * frameSize), 
									    l5b2Width, 
										l5b2Height);
		 b1line5Box2.set_fill_color(Color::yellow);
		 sw.attach(b1line5Box2);
		 Graph_lib::Rectangle b2line5Box2(Point(sw.x_max() / 2. - l5b2Width / 2. - 4 * frameSize - - 3 * frameSize,
			                                  sw.y_max() - 2.5 * heightSeparator - - 3 * frameSize), 
									    l5b2Width, 
										l5b2Height);
		 b2line5Box2.set_fill_color(Color::yellow);
		 sw.attach(b2line5Box2);

		 Graph_lib::Rectangle line5Box2(Point(sw.x_max() / 2. - l5b2Width / 2. - 4 * frameSize,
			                                  sw.y_max() - 2.5 * heightSeparator), 
									    l5b2Width, 
										l5b2Height);
		 line5Box2.set_fill_color(Color::yellow);
		 sw.attach(line5Box2);
		 // center box text
		 Text l5b2Text1(Point(sw.x_max() / 2. - l5b2Width / 2. - 4 * frameSize,
                              sw.y_max() - 2.5 * heightSeparator + textHeight - frameSize), 
					    "FLTK headers");
		 sw.attach(l5b2Text1);
		 // right box
		 const int l5b3Width = 200;
		 const int l5b3Height = 40;
		 // two background empty polygons
		 Graph_lib::Rectangle b1line5Box3(Point(sw.x_max() - l5b3Width - 6 * frameSize,
			                                  sw.y_max() - 2.5 * heightSeparator - 6 * frameSize), 
									    l5b3Width, 
										l5b3Height);
		 b1line5Box3.set_fill_color(Color::yellow);
		 sw.attach(b1line5Box3);
		 Graph_lib::Rectangle b2line5Box3(Point(sw.x_max() - l5b3Width - 3 * frameSize,
			                                  sw.y_max() - 2.5 * heightSeparator - 3 * frameSize), 
									    l5b3Width, 
										l5b3Height);
		 b2line5Box3.set_fill_color(Color::yellow);
		 sw.attach(b2line5Box3);
		
		 Graph_lib::Rectangle line5Box3(Point(sw.x_max() - l5b3Width - frameSize,
			                                  sw.y_max() - 2.5 * heightSeparator), 
									    l5b3Width, 
										l5b3Height);
		 line5Box3.set_fill_color(Color::yellow);
		 sw.attach(line5Box3);
		 // right box text
		 Text l5b3Text1(Point(sw.x_max() - l5b3Width - frameSize,
                              sw.y_max() - 2.5 * heightSeparator + textHeight - frameSize), 
					    "FLTK code");
		 sw.attach(l5b3Text1);

		 // Arrows connecting the boxes
		 // Line 1: box center -> Line 2: box center
		 Graph_lib::Marked_polyline l1bc_l2bc("^");
		 l1bc_l2bc.add(Point(sw.x_max() / 2. - l1b1Width / 2.,
			                 sw.y_max() - frameSize - l1b1Height));
		 l1bc_l2bc.add(Point(sw.x_max() / 2. - 4 * frameSize,
			                 sw.y_max() - heightSeparator + l2b2Height + 2 * frameSize));
		 sw.attach(l1bc_l2bc);
		 // Line 1: box center -> Line 4: box left
		 Graph_lib::Marked_polyline l1bc_l4bl("^");
		 l1bc_l4bl.add(Point(sw.x_max() / 2. - l1b1Width / 2.,
			                 sw.y_max() - frameSize - l1b1Height));
		 l1bc_l4bl.add(Point(frameSize + l4b1Width / 2.,
			                 sw.y_max() - 2 * heightSeparator + l4b1Height + 2 * frameSize));
		 sw.attach(l1bc_l4bl);
		 // Line 2: box left -> Line 4: box left
		 Graph_lib::Marked_polyline l2bl_l4bl("^");
		 l2bl_l4bl.add(Point(frameSize + l2b1Width / 2.,
			                 sw.y_max() - heightSeparator));
		 l2bl_l4bl.add(Point(frameSize + l4b1Width / 2.,
			                 sw.y_max() - 2 * heightSeparator + l4b1Height + 2 * frameSize));
		 sw.attach(l2bl_l4bl);
		 // Line 2: box center -> Line 4: box center
		 Graph_lib::Marked_polyline l2bc_l4bc("^");
		 l2bc_l4bc.add(Point(sw.x_max() / 2. - 4 * frameSize,
			                 sw.y_max() - heightSeparator));
		 l2bc_l4bc.add(Point(sw.x_max() / 2. - 4 * frameSize,
			                 sw.y_max() - 2 * heightSeparator + l4b2Height));
		 sw.attach(l2bc_l4bc);
		 // Line 2: box center -> Line 4: box right
		 Graph_lib::Marked_polyline l2bc_l4br("^");
		 l2bc_l4br.add(Point(sw.x_max() / 2. - 4 * frameSize,
			                 sw.y_max() - heightSeparator));
		 l2bc_l4br.add(Point(sw.x_max() - l4b3Width / 2. - frameSize,
			                 sw.y_max() - 2 * heightSeparator + l4b3Height));
		 sw.attach(l2bc_l4br);
		 // Line 2: box right -> Line 4: box right
		 Graph_lib::Marked_polyline l2br_l4br("^");
		 l2br_l4br.add(Point(sw.x_max() - l2b3Width / 2. - frameSize,
			                 sw.y_max() - heightSeparator));
		 l2br_l4br.add(Point(sw.x_max() - l4b3Width / 2. - frameSize,
			                 sw.y_max() - 2 * heightSeparator + l4b3Height));
		 sw.attach(l2br_l4br);
		 // Line 3 : box center -> Line 4: box center
		 Graph_lib::Marked_polyline l3bc_l4bc("^");
		 l3bc_l4bc.add(Point(sw.x_max() / 2. - l3b1Width / 2. - 6 * frameSize,
			                 sw.y_max() - 1.5 * heightSeparator));
		 l3bc_l4bc.add(Point(sw.x_max() / 2. - 4 * frameSize,
			                 sw.y_max() - 2 * heightSeparator + l4b2Height));
		 sw.attach(l3bc_l4bc);
		 // Line 4: box left -> Line 5: box left
		 Graph_lib::Marked_polyline l4bl_l5bl("^");
		 l4bl_l5bl.add(Point(frameSize + l4b1Width / 2.,
			                 sw.y_max() - 2 * heightSeparator));
		 l4bl_l5bl.add(Point(frameSize + l5b1Width / 2.,
			                 sw.y_max() - 2.5 * heightSeparator + l5b1Height));
		 sw.attach(l4bl_l5bl);
		 // Line 4: box left -> Line 5: box center
		 Graph_lib::Marked_polyline l4bl_l5bc("^");
		 l4bl_l5bc.add(Point(frameSize + l4b1Width / 2.,
			                 sw.y_max() - 2 * heightSeparator));
		 l4bl_l5bc.add(Point(sw.x_max() / 2. - 4 * frameSize,
			                 sw.y_max() - 2.5 * heightSeparator + l5b2Height));
		 sw.attach(l4bl_l5bc);
		 // Line 4: box center -> Line 5: box center
		 Graph_lib::Marked_polyline l4bc_l5bc("^");
		 l4bc_l5bc.add(Point(sw.x_max() / 2. - 4 * frameSize,
			                 sw.y_max() - 2 * heightSeparator));
		 l4bc_l5bc.add(Point(sw.x_max() / 2. - 4 * frameSize,
			                 sw.y_max() - 2.5 * heightSeparator + l5b2Height));
		 sw.attach(l4bc_l5bc);
		 // Line 4: box center -> Line 5: box left
		 Graph_lib::Marked_polyline l4bc_l5bl("^");
		 l4bc_l5bl.add(Point(sw.x_max() / 2. - 4 * frameSize,
			                 sw.y_max() - 2 * heightSeparator));
		 l4bc_l5bl.add(Point(frameSize + l5b1Width / 2.,
			                 sw.y_max() - 2.5 * heightSeparator + l5b1Height));
		 sw.attach(l4bc_l5bl);
		 // Line 4: box right -> Line 5: box center
		 Graph_lib::Marked_polyline l4br_l5bc("^");
		 l4br_l5bc.add(Point(sw.x_max() - l4b3Width / 2. - frameSize,
	            			 sw.y_max() - 2 * heightSeparator));
		 l4br_l5bc.add(Point(sw.x_max() / 2. - 4 * frameSize,
			                 sw.y_max() - 2.5 * heightSeparator + l5b2Height));
		 sw.attach(l4br_l5bc);
		 // Line 4: box right -> Line 4: box center
		 Graph_lib::Marked_polyline l4br_l4bc("<");
		 l4br_l4bc.add(Point(sw.x_max() - l4b3Width / 2. - frameSize,
	            			 sw.y_max() - 2 * heightSeparator));
		 l4br_l4bc.add(Point(sw.x_max() - l4b3Width - frameSize,
	            			 sw.y_max() - 2.1 * heightSeparator));
		 l4br_l4bc.add(Point(sw.x_max() / 2. - 4 * frameSize,
			                 sw.y_max() - 2 * heightSeparator));
		 sw.attach(l4br_l4bc);
		 // Line 5: box right -> Line 5: box center
		 Graph_lib::Marked_polyline l5br_l5bc("<");
		 l5br_l5bc.add(Point(sw.x_max() - l5b3Width / 2. - frameSize,
			                 sw.y_max() - 2.5 * heightSeparator));
		 l5br_l5bc.add(Point(sw.x_max() - l5b3Width - frameSize,
			                 sw.y_max() - 2.6 * heightSeparator));
		 l5br_l5bc.add(Point(sw.x_max() / 2. - 4 * frameSize,
			                 sw.y_max() - 2.5 * heightSeparator));
		 sw.attach(l5br_l5bc);

		 sw.wait_for_button();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(...)
	{
		std::cerr <<"Default exception!"<< std::endl;
	}	
}

//--------------------------------------------------------------------------------------------------------------------
 

/*
	Function: max_line_length()
	 
	This function finds the length of the longest string in a vector and
	returns it.

static size_t max_line_length(std::vector<std::string> &lines)
{
    size_t max = 0;

    for (auto it = lines.begin(); it != lines.end(); it++)
	{
        if (it->length() > max)
		{
            max = it->length();
        }
    }
    return max;
}
*/

//--------------------------------------------------------------------------------------------------------------------
/*
	Function:  boxWithText()
	Use: void boxWithText(Simple_window& sw,
						  int topLeftX, int topLeftY, 
						  const string& upLine, const string& line1, 
						  const string& line2 , const string& line3)

	This function draws a box with text either on top and/or
	three line in it, depending on the value of the last 4 pararameters.
	The first parameter passes the simple_window object to which the box
	and text will be attached. The second and third parameters are the 
	top left coordinates of the box.


Simple_window& boxWithText(Simple_window& sw,
						   int topLeftX, int topLeftY, 
						   const string& upLine = "0", const string& line1 = "0", 
						   const string& line2 = "0", const string& line3 = "0")
{
	const int frameSize = 1;
	const int textHeight = 20;

	// create box
	// boxWidth depends on the lengthiest string 
	int boxWidth = 0;

	// boxHeight depends on how much of the strings have value != 0
	int boxHeight = 0;

	vector<string> lines(3);
	lines[0] = line1;
	lines[1] = line2;
	lines[2] = line3;

	// box width determined from the longest string multiplied by a scaling factor
	const int scalingFactor = 1;
	boxWidth =  max_line_length(lines) * scalingFactor;

	// box height determined on how many of the strings are != 0 
	for(size_t i = 0; i < lines.size(); ++i)
	{
		if (lines[i] != "0")
		{
			boxHeight +=  textHeight + frameSize;
		}
	}

	// frame between the last line and the bottom line of the box
	boxHeight += frameSize;
	cout << "box w: "<< boxWidth <<" boxh: "<< boxHeight;

	Graph_lib::Rectangle box(Point(topLeftX, topLeftY), boxWidth, boxHeight);
	box.set_fill_color(Color::yellow);
	sw.attach(box);

	// create text
	// case upLine: topLeftY - textHeight - frameSize 
	if (upLine != "0")
	{
		Text l0(Point(topLeftX + frameSize, topLeftY - textHeight - frameSize), upLine);
		sw.attach(l0);
	}

	// case line1: topLeftY + texrHeight + frameSize
	if (line1 != "0")
	{
		Text l1(Point(topLeftX + frameSize, topLeftY + textHeight + frameSize), line1);
		sw.attach(l1);
	}

	// case line2: topLeftY + 2 * textHeight + 2 * frameSize
	if (line2 != "0")
	{
		Text l2(Point(topLeftX + frameSize, topLeftY + 2 * textHeight + 2 * frameSize), line2);
		sw.attach(l2);
	}

	// case line3: topLeftY + 3 * textHeight + 3 * frameSize
	if (line3 != "0")
	{
		Text l3(Point(topLeftX + frameSize, topLeftY + 3 * textHeight + 3 * frameSize), line3);
		sw.attach(l3);
	}
}

*/