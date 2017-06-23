/*
	TITLE		   Group container                Chapter14Exercise9.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define a class Group to be container of shapes;
				   with suitable operations applied to the members
				   of Group (Vector_ref).
				   Use Group to define checkers (draughts) board
				   where pieces can be moved under program control.
		    Input: - 
		   Output: -
		   Author: 13.10.2015
		     Date: Chris B. Kirov
*/

#ifndef _Chapter14Exercise9_h_
#define _Chapter14Exercise9_h_

// class Group is a container of Shapes
class Group
{
public:
	// constructors
	Group();
	Group(Point ul, int gridx, int gridy, int numrow, int numcolumn);

	// grid member functions
	Shape& get_grid(int i) { return grid[i]; }
	int grid_size() const { return grid.size(); }

	//  pieces member functions
	void add(Shape& s) { pieces.push_back(s); }
	void add(Shape* s) { pieces.push_back(s); }
	Shape& get_pieces(int i) { return pieces[i]; }
	int pieces_size() const { return pieces.size(); }

	Shape& move_up(int i);
	Shape& move_right(int i);
	Shape& move_left(int i);
	Shape& move_down(int i);

private:
	Point upperLeft;
	int gridSideX;
	int gridSideY;
	int gridRowNumber;
	int gridColumnNumber;

	Graph_lib::Vector_ref<Shape> grid;
	Graph_lib::Vector_ref<Shape> pieces;
};

//--------------------------------------------------------------------------------------------------------------------------------
// class member implementation

// default constructor
Group::Group()	
	: upperLeft(0, 0), gridSideX(50), gridSideY(50), gridRowNumber(5), gridColumnNumber(5) 
{
	// create grid
	for (size_t i = 0; i <= gridRowNumber; ++i)
	{ 
		for (size_t j = 0; j <= gridColumnNumber; ++j)
		{
			Graph_lib::Rectangle* rec = new Graph_lib::Rectangle(Point(upperLeft.x + gridSideX * j,
				                                                       upperLeft.y + gridSideY * i), gridSideX, gridSideY);
			rec->set_fill_color(((i + j) % 2 == 0) ? Color::black : Color::white); 
			grid.push_back(rec);
		}
	}	 
} 

// constructror
Group::Group(Point ul, int gridx, int gridy, int numrow, int numcolumn)
	: upperLeft(ul.x, ul.y), gridSideX(gridx), gridSideY(gridy), gridRowNumber(numrow), gridColumnNumber(numcolumn) 
{
	// create grid
	for (size_t i = 0; i <= gridRowNumber; ++i)
	{ 
		for (size_t j = 0; j <= gridColumnNumber; ++j)
		{
			Graph_lib::Rectangle* rec= new Graph_lib::Rectangle(Point(upperLeft.x + gridSideX * j, 
				                                                      upperLeft.y + gridSideY * i), gridSideX, gridSideY);
			rec->set_fill_color(((i + j) % 2 == 0) ? Color::black : Color::white); 
			grid.push_back(rec);
		}
	}	
} 

// member functions
Shape& Group::move_up(int i)
{
	pieces[i].move(0, -gridSideY); 
	return pieces[i];
}

Shape& Group::move_right(int i)
{
	pieces[i].move(gridSideX, 0); 
	return pieces[i];
}

Shape& Group::move_left(int i)
{
	pieces[i].move(-gridSideX, 0); 
	return pieces[i];
}

Shape& Group::move_down(int i)
{
	pieces[i].move(0, gridSideY); 
	return pieces[i];
}

//--------------------------------------------------------------------------------------------------------------------------------
// class Pawn reprsenint a moving object on the checkers board
class Pawn: public Circle{
public:
	Pawn(Point c, int r)
		: Circle(c,r) 
	{ 
		Graph_lib::Mark m(c, 'p');
	}
};
 
//--------------------------------------------------------------------------------------------------------------------------------
/*
// Objective 4
		size_t numOfPics = 3;
		vector<Image*> allPics;
		// add images and cut them in the same size
		for (size_t n = 0; n < numOfPics; ++n){
			allPics.emplace_back(new Image (Point(0, 90), "prof_pic.jpg"));
			allPics[n]->set_mask(Point(0,200),gridSideX * 2, gridSideY * 2);
		}
		// move them away from the diagonal	
        allPics[0]->move(0, gridSideY * 5);
		allPics[1]->move(gridSideX * 6, -gridSideY);
		allPics[2]->move(gridSideX * 6, gridSideY * 2);
		// attach the to the window
		for(auto it = allPics.begin(); it != allPics.end(); ++it){
			sw.attach(**it);
		}

		// Objective 5
		// random number generator
		mt19937 rng;
		rng.seed(random_device());
		uniform_int_distribution<int> dist0to7(0, 6);
		// loop to make a number of random moves
		int numOfMove = 5;
		for (size_t p = 0; p < numOfMove; ++p){
			Image movingPic(Point(gridSideX * dist0to7(rng), gridSideY* dist0to7(rng)), "Chess_king90x90.jpg");
			sw.attach(movingPic);
			sw.wait_for_button();
		}
*/

#endif