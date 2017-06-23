/*
	TITLE			   Checkers Board	        Chapter12Exercise4.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Draw a checkers board 8-by-8
					   alternating white and red.
				Input: -
			   Output: Graph on screen.
			   Author: Chris B. Kirov
			     Date: 17. 08. 2015
*/

/*
	Class: checkersBoard

	It initializes a checkers board object 
	with the following properties: 
	number of columns, rows, size of side of
	the squares, and two colors drawn by
	member function drawBoard().
*/
class checkersBoard
{
public:
	// default constructor
	checkersBoard();

	// constructor
	checkersBoard(int nC, int nR, int sS, Color a, Color b);

	// destuctor
	~checkersBoard();

	// function member
	void drawBoard();

private:
	// data members
	int numberOfColumns;
	int numberOfRows;

	// size of a square
	int sqrSize;

	// saves rectangles of the checkers board
	vector<Graph_lib::Rectangle*> rects;

	// the two colors of the board
	Color firstColor;
	Color secondColor;
};
//------------------------------------------------------------------------------------------------------------------------------
// class checkersBoard member implementations

// default constructor
checkersBoard::checkersBoard()
	: numberOfColumns(8), numberOfRows(8), sqrSize(20), firstColor(Graph_lib::Color::white), secondColor(Graph_lib::Color::black)
{ 
		rects.reserve(numberOfColumns * numberOfRows); 
		drawBoard();
}
//------------------------------------------------------------------------------------------------------------------------------

// constuctor
checkersBoard::checkersBoard(int nC, int nR, int sS, Color a, Color b)
	: numberOfColumns(nC), numberOfRows(nR), sqrSize(sS), firstColor(a), secondColor(b)
{ 
		rects.reserve(numberOfColumns * numberOfRows); 
}

//------------------------------------------------------------------------------------------------------------------------------
// destructor
checkersBoard::~checkersBoard()
{
	// release the dinamically allocated memory
	for(size_t l = 0; l < rects.size(); ++l)
	{
		delete rects[l];
	}
}

//------------------------------------------------------------------------------------------------------------------------------
/*
	Function: drawBoard()

	It create a window and
	attaches the checkersboard
	to it.

	Checkers board created from colored
	squares (ectangle with width = height).
*/
void checkersBoard::drawBoard()
{
	// create a window in the center of the screen wiht size: 600x600
	const int wWidth = 660;
	const int wHeight = 660;
	Point centerScreen(x_max()/2 - wWidth/2, y_max()/2 - wHeight/2);
	Simple_window sw(centerScreen,  wWidth, wHeight, "Chapter 12 Exercise 4");

	// starting upper left coordinates of the window 
	const int frameSize = 10;
	int tlx = sw.x_max() - wWidth + frameSize;
	int tly = sw.y_max() - wHeight + frameSize;

	// create the board's squares
	for(size_t i = 0; i < numberOfColumns; ++i)
	{
		for(size_t j = 0; j < numberOfRows; ++j)
		{
			// create a n x n conjugate squares 
			Graph_lib::Rectangle* r = new Graph_lib::Rectangle(Point(tlx + sqrSize * i, tly + sqrSize * j), sqrSize, sqrSize);

			// fill the consecutive squares with alternate color
			r->set_fill_color(((i + j)  % 2 == 0) ? firstColor : secondColor);

			// save square (rectangle with width = height) in vector
			rects.push_back(r);
		}
	}

	// attach all the rectangle objects to the window object
	for(size_t k = 0; k < rects.size(); ++k)
	{
		sw.attach(*rects[k]);
	}

	sw.wait_for_button();
}