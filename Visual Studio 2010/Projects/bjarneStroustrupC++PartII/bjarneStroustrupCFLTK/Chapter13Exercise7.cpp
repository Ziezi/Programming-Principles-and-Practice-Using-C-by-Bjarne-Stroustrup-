/*
	TITLE		   RGB chart		  Chapter13Exercise7.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Create a RGB color chart.
		   Output: 
		   Author: 19.09.2015
		     Date: Chris B. Kirov
*/

#include "GUI.h"
#include "Simple_window.h"
#include <iostream>
#include <iomanip>
#include "Chapter13Exercise6.h"

// class LabeledBox
class LabeledBox: public Rectangle
{
public:
	LabeledBox(Point ul, int w, int h, string t);
	Text* add_text() const;
private:
	Point topLeft;
	int width;
	int height;
	string label;
};
// member implementations
LabeledBox::LabeledBox(Point ul, int w, int h, string t)
	: Rectangle(ul, w, h), topLeft(ul), width(w), height(h), label(t)
{ }

Text* LabeledBox::add_text() const
{
	ConnectionPoints cp(topLeft, width, height);
	Text* t = new Text(Point(cp.w().x + 10, cp.w().y +7), label);
	t->set_font(Font::courier);
	t->set_color(Color::white);
	t->set_font_size(15);
	return t;
}

// Helper function
/*
	Function: colorCode()
	Use: string numberOfColorInHEXAsSrting = colorCode(int colorNumber);
	This function converts an int (in hex) notation
	into a string, to be displayed as color code.
*/
string colorCode(int n)
{
	 stringstream ss;
	 //ss << hex << uppercase << fixed << std::setprecision(4) << n;
	 ss << n;
	 return ss.str();
}

//---------------------------------------------------------------------------------------------------------------------
int main()
{
	 // window parameters
	 int winWidth = 800;
	 int winHeight = 600;
	 Point centerPoint((x_max() - winWidth) / 2., (y_max() - winHeight) / 2.);
	 Simple_window* siw = new Simple_window(centerPoint, winWidth, winHeight, "Chapter 13 Exercise 7");

	 try
	 {
		 // LabeledBox garbage collector
		 vector<LabeledBox*> RGBColorChart;
		 // chart parameters
		 int boxWidth = 30;
		 int boxHeight = 30;
		 int numRows = 16;
		 int numColumns = 16;

		 // create chart
		 unsigned int colorAsNum = 0;
		 for (size_t i = 0; i < numRows; ++i)
		 {
			for (size_t j = 0; j < numColumns; ++j)
			{
				// increment color
				colorAsNum ++;
				// create object
				LabeledBox* lb = new LabeledBox(Point(j * boxWidth, i * boxHeight), boxWidth, boxHeight, colorCode(colorAsNum));
				lb->set_fill_color(colorAsNum);
				// store the object 
				RGBColorChart.push_back(lb);
				// attach object
				siw->attach(*lb);
				siw->attach(*lb->add_text());
			}
		 }
		 siw->wait_for_button();
		 // free heap memory
		 for (auto it = RGBColorChart.begin(); it != RGBColorChart.end(); ++it) delete *it;
	 }
	 catch(std::exception& e)
	 {
		std::cerr << e.what() << std::endl;
	 }
	 catch(...)
	 {
		std::cerr <<"Defaul exception!"<< std::endl;
	 }
}