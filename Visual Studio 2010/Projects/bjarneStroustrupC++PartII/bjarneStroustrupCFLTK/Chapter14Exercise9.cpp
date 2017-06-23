/*
	TITLE		   Group container                Chapter14Exercise9.cpp
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
#include <iostream> 
#include <vector>
#include "Graph.h"
#include "Simple_window.h"
#include "Chapter14Exercise9.h"

int main()
{
	Point tl(x_max()/2,0);
	int width = 700;
	int height = 700;
	string label = "Chapter 14 Exercise 9";

	Simple_window sw(tl, width, height, label);

	try
	{ 
		// checkers board parameters
		Point topLeft(0, 0);
		int gridWidth = 70;
		int gridHeight = 70;
		int gridRows = 8;
		int gridColumns = 8;

		// instantiate class Group object
		Group game(topLeft, gridWidth , gridHeight, gridRows, gridColumns);

		// load the grid
		for (size_t i = 0; i < game.grid_size(); ++i) 
		{
			sw.attach(game.get_grid(i));
		}

		// create pawns
		Pawn p1(Point(35,35), 20), p2(Point(35,105), 20);
		p1.set_color(Color::red);

		p1.set_style(Line_style(Line_style::solid, 10));
		p2.set_color(Color::blue);

		p2.set_style(Line_style(Line_style::solid, 10));

		// add pieces to the game
		game.add(p1);
		game.add(p2);

		// load the pieces
		for (size_t i = 0; i < game.pieces_size(); ++i) 
		{
			sw.attach(game.get_pieces(i));
		}

		// show the checkers board before the command prompt
		sw.wait_for_button();

		// inroduction to the game
		string prompt("Type next move in the format: index command:\n>>");
		cout <<"Valid indexes: [0," << game.pieces_size() - 1 <<"]\n";
		cout <<"Valid commands: up, down, left, right.\n";

		// input loop
		string line;
		string exit("end");

		while(true)
		{
			cout << prompt;

			// read input
			getline(cin, line);

			// check termination condition
			if (line == exit)
			{
				break;
			}

			// extract input
			stringstream ss(line);
			int index = 0;
			string command;
			ss >> index >> command;

			// read move command
			if (command == "up")
			{
				sw.attach(game.move_up(index));
				sw.wait_for_button(); 
			}
			else if (command == "down")
			{
				sw.attach(game.move_down(index));
				sw.wait_for_button(); 
			}
			else if (command == "left")
			{ 
				sw.attach(game.move_left(index));
				sw.wait_for_button(); 
			}
			else if(command == "right")
			{
				sw.attach(game.move_right(index));
				sw.wait_for_button(); 
			}
			else 
			{	
				std::cout <<"Command not supported!";
			}
		}
		
		sw.wait_for_button();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	catch(...)
	{
		std::cerr <<"Default exception!"<< std::endl;
		getchar();
	}
}

