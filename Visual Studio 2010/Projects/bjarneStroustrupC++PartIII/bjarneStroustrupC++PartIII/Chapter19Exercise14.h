/*
	TITLE		    GUI to "Hunt the wumpus" Chapter19Exercise14.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Provide a simple GUI interface output to the 
					"Hunt the Wumpus" from Chapter 18.
					Take the input from an input box and display a
					map of of the part of the cave currently known 
					to the player in a window.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 06. 2. 2016
*/

#ifndef Chapter19Exercise14_h
#define Chapter19Exercise14_h

class Hunt_the_Wumpus: public Window
{
public:
	Hunt_the_Wumpus()
		: Window(700, 700, "Chapter 19 Exercise 15"),
		command_box(Point(x_max() / 2 - 75, 100), 150, 30, "Type command: "),
		move(Point(x_max() / 2 - 35, 150), 70, 30, "Move", cb_move),
		restart(Point(x_max() / 2 - 70, 150), 70, 30, "Restart", cb_restart),
		quit(Point(x_max() / 2, 150), 70, 30, "Quit", cb_quit),
		arrows_left(new Text(Point(x_max()/2 - 225, 15), "Arrows: ")),
		current_room(new Text(Point(x_max()/2 - 225, 35), "Player in: ")),
		adj_rooms(new Text(Point(x_max()/2 - 225, 55), "Move to: ")), 
		my_hunch(new Text(Point(x_max()/2 - 225, 75), "My hunch: ")),
		result(new Text(Point(x_max()/2 - 25, 200), "Start")),
		cave(new Labyrinth(10, 1)),
		visited_rooms(24, false), rooms(24, nullptr), pits(24, nullptr),
		bats(24, nullptr), doors(24, nullptr)
	{
		attach(command_box);
		attach(move);
		result->set_font_size(20);
		result->set_color(Color::red);

		attach(restart);
		attach(quit);
		quit.hide();
		restart.hide();

		start_game();
	}

private:
	// controls
	In_box command_box;
	Button move, restart, quit;

	// callbacks
	static void cb_move(Address, Address pw) { reference_to<Hunt_the_Wumpus>(pw).move_pushed(); }
	static void cb_restart(Address, Address pw) { reference_to<Hunt_the_Wumpus>(pw).restart_pushed(); }
	static void cb_quit(Address, Address pw) { reference_to<Hunt_the_Wumpus>(pw).quit_pushed(); }

	// actions
	void move_pushed();
	void restart_pushed() { restart.hide(); quit.hide(); start_game(); move.show(); }
	void quit_pushed() { hide(); }

	// helper
	void start_game();
	void draw_labyrinth();
	void show_options() { restart.show(); quit.show(); }
	void reset_containers();

	// data member
	Labyrinth* cave;

	Text* arrows_left;
	Text* current_room;
	Text* adj_rooms; 
	Text* my_hunch;
	
	Text* result;

	std::vector<bool> visited_rooms;
	std::vector<Graph_lib::Rectangle*> rooms;
	std::vector<Graph_lib::Circle*> pits;
	std::vector<Graph_lib::Mark*> bats;
	std::vector<Graph_lib::Text*> doors;
};

//--------------------------------------------------------------------------------------------------------------------

void Hunt_the_Wumpus::start_game()
{
	delete cave;

	int size = 24;
	int difficulty = 3;
	cave = new Labyrinth(size, difficulty);	

	std::stringstream ss;
	ss << "Arrows: "<< cave->get_arrows_number();
	arrows_left = new Text(Point(x_max()/2 - 225, 15), ss.str());
	attach(*arrows_left);

	std::stringstream ss1;
	ss1 <<"Player in: " << cave->get_player()->get_number() <<'\n';
	current_room = new Text(Point(x_max()/2 - 225, 35), ss1.str());
	attach(*current_room);

	std::stringstream ss2;
	ss2 << cave->disp_room_door_numbers() <<'\n';
	adj_rooms = new Text(Point(x_max()/2 - 225, 55), ss2.str());
	attach(*adj_rooms);

	std::stringstream ss3;
	ss3 << cave->disp_adj_room_presence() <<'\n';
	my_hunch = new Text(Point(x_max()/2 - 225, 75), ss3.str());
	attach(*my_hunch);

	detach(*result);
	delete result;

	result = new Text(Point(x_max()/2 - 25, 200), "Start");
	result->set_font_size(20);
	result->set_color(Color::red);
	attach(*result);

	draw_labyrinth();
}

//--------------------------------------------------------------------------------------------------------------------

void Hunt_the_Wumpus::draw_labyrinth()
{
	reset_containers();

	Room* e = cave->get_enrtance();
	
	int width = 80;
	int height = 80;
	int row = 80;

	int index = 0;

	for (size_t j = 0; j < 4; ++j)
	{
		for (size_t i = 0; i < 6; ++i)
		{
			Point a(row * i, 220 + j * row);
			Point b(row * i + width, 220 + height + j * row);

			std::stringstream ss;
			ss <<"N:"<< e[index].get_number();
			ss <<",L:"<< e[index].get_left()->get_number();
			ss <<",C:"<< e[index].get_center()->get_number();
			ss <<",R:"<< e[index].get_right()->get_number();

			rooms[index] = new Graph_lib::Rectangle(a, b);
		
			Point c(a.x + width / 2, a.y + height / 2);

			doors[index] = new Text(Point(c.x- width/2, c.y), ss.str());
			doors[index]->set_font_size(9);

			if (e[index].is_bat())
			{
				bats[index] = new Mark(Point(c.x, c.y + 10), 'b');
			}

			if (e[index].is_pit())
			{
				pits[index] = new Circle(c, 20);
			}

			++index;
		}
	}

	for (size_t i = 0; i < cave->get_size(); ++i)
	{
		attach(*rooms[i]);
	}
}

//--------------------------------------------------------------------------------------------------------------------

void Hunt_the_Wumpus::move_pushed()
{
	detach(*arrows_left);
	delete arrows_left;

	detach(*current_room);
	delete current_room;

	detach(*adj_rooms);
	delete adj_rooms;

	detach(*my_hunch);
	delete my_hunch;

	detach(*result);
	delete result;

	int player_status = 0;   // -1 dead, 0 alive, 1 killed wumpus
	int wumpus_status = 0;	 // -1 dead, 0 alive, 1 killed player

	std::cout <<"Wumpus in room: " << cave->get_wumpus()->get_number() <<'\n';

	// update map
	int n = cave->get_player()->get_number();
	std::cout << "n: " << n<<'\n';
	if (!visited_rooms[n])
	{
		visited_rooms[n] = true;
		attach(*doors[n]);
		rooms[n]->set_fill_color(Color::red);
		if (bats[n]) attach(*bats[n]); 
	}

	std::string command = command_box.get_string();
	player_status = cave->player(command);

	// update map if bat in room transported you in other room
	n = cave->get_player()->get_number();
	if (!visited_rooms[n])
	{
		visited_rooms[n] = true;
		attach(*doors[n]);
		rooms[n]->set_fill_color(Color::red);
		if (bats[n]) attach(*bats[n]); 
	}

	if (player_status == -1) 
	{
		move.hide();
		show_options();

		result = new Text(Point(x_max()/2 - 25, 200), "\nGame Over!\n");
		result->set_font_size(20);
		result->set_color(Color::red);
		attach(*result);
		redraw();

		return;
	}
	if (player_status == 1) 
	{
		move.hide();
		show_options();

		result = new Text(Point(x_max()/2 - 25, 200), "\nYou win!\n");
		result->set_font_size(20);
		result->set_color(Color::red);
		attach(*result);
		redraw();

		return;
	}
		 
	// wumpus moves to random room 
	wumpus_status = cave->wumpus();
	if (wumpus_status == -1) 
	{
		move.hide();
		show_options();

		result = new Text(Point(x_max()/2 - 25, 200), "\nYou win!\n");
		result->set_font_size(20);
		result->set_color(Color::red);
		attach(*result);
		redraw();

		return;
	}
	if (wumpus_status == 1)
	{
		move.hide();
		show_options();

		result = new Text(Point(x_max()/2 - 25, 200), "\nGame Over!\n");
		result->set_font_size(20);
		result->set_color(Color::red);
		attach(*result);
		redraw();

		return;
	}

	std::stringstream ss;
	ss << "Arrows: "<< cave->get_arrows_number();
	arrows_left = new Text(Point(x_max()/2 - 225, 15), ss.str());
	attach(*arrows_left);

	std::stringstream ss1;
	ss1 <<"Player in: " << cave->get_player()->get_number() <<'\n';
	current_room = new Text(Point(x_max()/2 - 225, 35), ss1.str());
	attach(*current_room);

	std::stringstream ss2;
	ss2 << cave->disp_room_door_numbers() <<'\n';
	adj_rooms = new Text(Point(x_max()/2 - 225, 55), ss2.str());
	attach(*adj_rooms);

	std::stringstream ss3;
	ss3 << cave->disp_adj_room_presence() <<'\n';
	my_hunch = new Text(Point(x_max()/2 - 225, 75), ss3.str());
	attach(*my_hunch);

	result = new Text(Point(x_max()/2 - 25, 200), "Play");
	result->set_font_size(20);
	result->set_color(Color::red);
	attach(*result);

	redraw();
}

//--------------------------------------------------------------------------------------------------------------------

void Hunt_the_Wumpus::reset_containers()
{
	for (size_t i = 0; i < cave->get_size(); ++i)
	{
		detach(*rooms[i]); 
		detach(*pits[i]);  
		detach(*bats[i]); 
		detach(*doors[i]);  
	}

	visited_rooms = std::vector<bool>(24, false);
	rooms = std::vector<Graph_lib::Rectangle*>(24, nullptr);
	pits = std::vector<Graph_lib::Circle*>(24, nullptr);
	bats = std::vector<Graph_lib::Mark*>(24, nullptr);
	doors = std::vector<Graph_lib::Text*>(24, nullptr);
}

#endif