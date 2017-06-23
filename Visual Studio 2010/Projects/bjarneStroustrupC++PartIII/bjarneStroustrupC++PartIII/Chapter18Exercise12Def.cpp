/*
	TITLE		    "Hunt the Lumpus"       Chapter18Exercise12.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Implement the game: "Hunt the Lumpus".
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 12.1.2016
*/

// class Cave implementations

// Helper functions
/*
	Function: random_number()
	Use: Implicitly in generate_labyrinth()
	     and wumpus_move().

	It generate a pseudo-random number
	within [min, max].
*/
int Labyrinth::random_number (unsigned int min, unsigned int max) 
{
	static bool seed_initialized = false;
	
	if (!seed_initialized) 
	{
		seed_initialized = true;
		srand((unsigned int) time(NULL));
	}

	return rand() % (max - min + 1) + min; 
}

//-----------------------------------------------------------------------------------------------------

/*
	Function: random_number_without_i ();
	Use: Implicitly in generate_labyrinth()
	     and wumpus_move().

	It generates a pseudo-random number
	within [min, max] except i, where
	min < i < max.

	It either returns number within
	the interval or makes a iterative
	calls till it generates the needed
	result;

	Avoids rooms connecting with 
	themselves (loops).
*/
int Labyrinth::random_number_without_i (int min, int max, unsigned int i)
{
	int res = random_number(min, max);

	while (res == i)
	{
		res = random_number(min, max);
	}

	return res;
} 

//-----------------------------------------------------------------------------------------------------

/*
	Function: random_number_without_those ()
	Use: Implicit in populate_labyrinth ()

    It generate random numbers within the
	interval [min, max], except the numbers
	passed in the form of set<int>& s, where
	min < set_values < max.

	To avoid populating same rooms with
	multiple artefacts.
*/
int Labyrinth::random_number_without_these (int min, int max, std::set<int>& s) 
{
	int res = random_number (min, max);

	while (s.find(res) != s.end()) 
	{
		res = random_number (min, max);
	}

	return res;
}

//-----------------------------------------------------------------------------------------------------

/*
	Function: generate_cave()
	Use: Implicit in the class constructor

	It creates array of Rooms and
	it connects each of their doors 
	randomly to one of the other rooms.
*/
void Labyrinth::generate_labyrinth() 
{
	entrance =  new Room [size];

	int first_room = 0;
	int last_room = size - 1;

	// traverse the rooms and conect each with three other
	for (int i = 0; i < size; ++i) 
	{
		int left_goes_to = random_number_without_i (first_room, last_room, i);
		int center_goes_to = random_number_without_i (first_room, last_room, i);
		int right_goes_to = random_number_without_i (first_room, last_room, i);

		entrance[i].set_left (&entrance[left_goes_to]);
		entrance[i].set_center (&entrance [center_goes_to]);
		entrance[i].set_right (&entrance [right_goes_to]);;
	}
}

//-----------------------------------------------------------------------------------------------------

/*
	Function: populate_labyrinth()
	Use: Implicitly in Labyrinth constructor

	It populates the rooms of the labyrinth
	with artefacts: bats, bottomless pits
	depending on the level: (1)left_hands, (2)hunter, (3)serial_killer. 
*/
void Labyrinth::populate_labyrinth () 
{
	// check input validity
	const int easy = 1;
	const int hard = 3;
	if (level < easy || level > hard) 
	{
		std::cerr <<"\nNo such level of difficulty!\n";
	}

	// assign a number to the rooms
	for (int i = 0; i < size; ++i)
	{
		entrance[i].set_number(i);
	}

	// populate DIFFERENT rooms with bats or bottomless pits
	const int first_room = 1;
	const int last_room = size - 1;
	size_t populated = level * 3;

	// determine the number of arrows depending on the level of difficulty 
	arrows = 9 / level;

	std::set<int> already_populated;

	for (size_t i = 1; i < populated; ++i)
	{
		// ensure different rooms
		int room_number = random_number_without_these(first_room, last_room, already_populated);
		already_populated.insert(room_number);

		// populate with bats or pits
		if (i % 2 == 0) 
		{
			entrance[room_number].set_pit(true);
		} 
		else 
		{
			entrance[room_number].set_bat(true);
		}
	}	 
}

//-----------------------------------------------------------------------------------------------------

/*
	Function: summon_wumpus()
	Use: Implicitly in labyrinth constructor

	It gives initial position to wumpus.
*/
void Labyrinth::summon_wumpus() 
{
	// player at node with index 0 (avoid eating player at start)
	current_wumpus = &entrance[random_number(1, size - 1)]; 
	current_wumpus->set_wumpus(true);
}

//-----------------------------------------------------------------------------------------------------

/*
	Function: insert_player()
	Use: Implictly in labyrinth constructor.

	It puts the player in the first room of the
	labyrinth.
*/
void Labyrinth::insert_player () 
{
	// first room always empty  
	current_player = &entrance[0];
	current_player->set_player(true);
	arrow = nullptr;
}

//-----------------------------------------------------------------------------------------------------

/*
	Function: disp_room_door_numbers () 
	Use: Implicitly in function rum_game()

	It displays the currently available 
	options for movement, i.e. adjoint 
	rooms numbers.
*/
std::string Labyrinth::disp_room_door_numbers () const
{
	std::stringstream ss;
	ss <<"Move to: ";
	ss << current_player->get_left()->get_number() <<'\n'
	   << " or: "<< current_player->get_center()->get_number() <<'\n'
	   << " or: "<< current_player->get_right()->get_number() <<'\n';

	return ss.str();
}

//-----------------------------------------------------------------------------------------------------

/*
	Function: disp_adj_room_presence () 
	Use: Implicitly in function rum_game()

	It displays whether there is an
	artefact (pit or bat) in some of the
	adjoint rooms.
*/
std::string Labyrinth::disp_adj_room_presence () const 
{
	std::stringstream ss;
	ss << "Hunch: ";
	if (current_player->get_left()->is_wumpus() ||
		current_player->get_center()->is_wumpus() ||
		current_player->get_right()->is_wumpus()
		) 
	{
		ss <<"\n I smell the wumpus.\n";
	}
		
	if (current_player->get_left()->is_pit() ||
		current_player->get_center()->is_pit() ||
		current_player->get_right()->is_pit()
		)
	{
		ss <<"\n I feel breeze.\n";
	}

	if (current_player->get_left()->is_bat() ||
		current_player->get_center()->is_bat() ||
		current_player->get_right()->is_bat()
		)
	{
		ss <<"\n I hear a bat.\n";
	}

	return ss.str();
}

//-----------------------------------------------------------------------------------------------------

/*
	Function: test_nodes()
	Use: Implicitly in the class's constructor body

	It tests the expected values of the data members
	after the calls to the initialization functions.
*/
void Labyrinth::test_nodes () 
{

	// test generate_labyrinth ()
	for (auto i = 0; i < size; ++i) 
	{
		if (entrance[i].get_left() == nullptr ||
			entrance[i].get_center() == nullptr ||
            entrance[i].get_right() == nullptr  )
		{
                 std::cerr <<"\nUninitialized pointer value\n";
				 getchar();
        }
    }
   
	// test populated_labyrinth ()
	for (auto i = 0; i < size; ++i) 
	{
		if (i != entrance[i].get_number()) 
		{
			std::cerr <<"\nUnexpected room number: " << entrance[i].get_number()	      
					  << '\n';
			getchar();
		}
	}

	int number_of_rooms_with_artefacts = level * 3 - 1;
	int artefacts_counter = 0;
	for (auto i = 0; i < size; ++i) 
	{
		if (entrance[i].is_pit() || entrance[i].is_bat()) 
		{

			++artefacts_counter;
		}
	}

	if (number_of_rooms_with_artefacts != artefacts_counter)
	{
		std::cerr <<"\nUnexpected number of artefacts\n";
		getchar();
	}
	

	// test summon_wumpus();
	bool summoned = false;
	for (auto i = 0; i < size; ++i)
	{
		if (entrance[i].is_wumpus())
		{
			summoned = true;
		}	  
	}

	if (!summoned)
	{
		std::cerr <<"\nWumpus not summoned!\n";
		getchar();
	}
	
	// test insert_player()
	if (!entrance[0].is_player())
	{
		std::cerr <<"\nPlayer not inserted!\n";
		getchar();
	}
}

//-----------------------------------------------------------------------------------------------------

// Modifying member functions
/*
	Function: wumpus ();
	Use: Implicitly in run_game().

	It advances the node traversing
	function to a random node.

	It returns a value corresponding 
	to the game status after the movement.

	It takes a randomly generated number
	that corresponds to movenent in one 
	of the three possible directions:
	1 -left, 2 - center and three - right.
*/
int Labyrinth::wumpus ()
{
	int move = random_number(1,3);
	const int go_left = 1;
	const int go_center= 2;
	const int go_right= 3;

	int kill_player = 1;
	int alive = 0;
	int dead = -1;

	switch (move)
	{
		case go_left: 
		{
	        // no longer present in this room
			current_wumpus->set_wumpus(false);
			// advance to next room
			current_wumpus = current_wumpus->get_left();
			// present in next room
			current_wumpus->set_wumpus(true);
			break;
		}
		case go_center: 
		{
			current_wumpus->set_wumpus(false);
			current_wumpus = current_wumpus->get_center();
			current_wumpus->set_wumpus(true);
			break;
		}
		case go_right: 
		{
			current_wumpus->set_wumpus(false);
			current_wumpus = current_wumpus->get_right();
			current_wumpus->set_wumpus(true);
			break;
		}
		default: 
		{
			std::cerr <<"\nWumpus can't move in this direction!\n";
			break;
		}
	}
	
	// wumpus enters players's room, it wins
	if (current_wumpus->is_player())
	{
		std::cout <<"\nWumpus bumped into the player and ate him!\n";
		return kill_player;
	}

	// wumpus enters a room with an arrow, it dies
	if (current_wumpus->is_arrow())
	{
		std::cout << "\nWumpus have been hit by an arrow!\n";
		return dead;
	}  
	return alive;
}

//-----------------------------------------------------------------------------------------------------

/*
	Function: shoot_arrow()
	Use: Implicitly in function player()

	If some of the first three 
	arguments non-zero shoot in the
	door number which holds.

	Return 
*/
int Labyrinth::shoot_arrow(int door_num1, int door_num2, int door_num3)
{
	int kill_wumpus = 1;
	int alive = 0;

	// shoot: move wumpus and check if wumpus in some of the 3 rooms in front
	size_t arrow_range = 3; // three rooms

	// find which direction corresponds to this number and shoot an arrow 
	if (door_num1 > 0 && arrows > 0)
	{
		// match room number with a door  
		if (current_player->get_left()->get_number() == door_num1)
		{
			// the arrow traversed through three rooms straight 
			for (size_t i = 0; i < arrow_range; ++i) 
			{
				if (i == 0)
				{ 
					arrow = arrow->get_left();
				} 
				else 
				{
					arrow = arrow->get_center();
				}

				// check if the arrow passes through a room in which is the monster
				if (arrow->is_wumpus())
				{
					arrow = nullptr;
					return kill_wumpus;
				}
			}
		} 
		else if (current_player->get_center()->get_number() == door_num1)
		{
			for (size_t i = 0; i < arrow_range; ++i) 
			{
				if (i == 0) 
				{ 
					arrow = arrow->get_center();
				} 
				else 
				{
					arrow = arrow->get_center();
				}

				if (arrow->is_wumpus())
				{
					arrow = nullptr;
					return kill_wumpus;
				}
			}
		} 
		else if (current_player->get_right()->get_number() == door_num1) 
		{
			for (size_t i = 0; i < arrow_range; ++i) 
			{
				if (i == 0) 
				{ 
					arrow = arrow->get_right();
				} 
				else 
				{
					arrow = arrow->get_center();
				}

				if (arrow->is_wumpus())
				{
					arrow = nullptr;
					return kill_wumpus;
				}
			}
		} 
		else 
		{
			std::cerr <<"\nNo such door number in this room!\n";
		}
	}

	// second arrow shot 
	if (door_num2 > 0 && arrows > 0)
	{
		if (current_player->get_left()->get_number() == door_num2) 
		{
			for (size_t i = 0; i < arrow_range; ++i) 
			{
				if (i == 0)
				{ 
					arrow = arrow->get_left();
				} 
				else 
				{
					arrow = arrow->get_center();
				}

				if (arrow->is_wumpus()) 
				{	
					arrow = nullptr;
					return kill_wumpus;
				}
			}
		} 
		else if (current_player->get_center()->get_number() == door_num2)
		{
			for (size_t i = 0; i < arrow_range; ++i)
			{
				if (i == 0) 
				{ 
					arrow = arrow->get_center();
				} 
				else 
				{
					arrow = arrow->get_center();
				}

				if (arrow->is_wumpus())
				{	
					arrow = nullptr;
					return kill_wumpus;
				}
			}
		} 
		else if (current_player->get_right()->get_number() == door_num2)
		{
			for (size_t i = 0; i < arrow_range; ++i) 
			{
				if (i == 0) 
				{ 
					arrow = arrow->get_right();
				} 
				else
				{
					arrow = arrow->get_center();
				}

				if (arrow->is_wumpus())
				{	
					arrow = nullptr;
					return kill_wumpus;
				}
			}
		} 
		else 
		{
			std::cerr <<"\nNo such door number in this room!\n";
		}
	}

	// third arrow shot
	if (door_num3 > 0  && arrows > 0)
	{
		if (current_player->get_left()->get_number() == door_num3) 
		{
			for (size_t i = 0; i < arrow_range; ++i)
			{
				if (i == 0) 
				{ 
					arrow = arrow->get_left();
				} 
				else 
				{
					arrow = arrow->get_center();
				}

				if (arrow->is_wumpus()) 
				{	
					arrow = nullptr;
					return kill_wumpus;
				}
			}
		} 
		else if (current_player->get_center()->get_number() == door_num3) 
		{
			for (size_t i = 0; i < arrow_range; ++i)
			{
				if (i == 0)
				{ 
					arrow = arrow->get_center();
				}
				else
				{
					arrow = arrow->get_center();
				}

				if (arrow->is_wumpus())
				{	
					arrow = nullptr;
					return kill_wumpus;
				}
			}
		} 
		else if (current_player->get_right()->get_number() == door_num3)
		{
			for (size_t i = 0; i < arrow_range; ++i)
			{
				if (i == 0) 
				{ 
					arrow = arrow->get_right();
				} 
				else 
				{
					arrow = arrow->get_center();
				}

				if (arrow->is_wumpus())
				{	
					arrow = nullptr;
					return kill_wumpus;
				}
			}
		} 
		else 
		{
			std::cerr <<"\nNo such door number in this room!\n";
		}
	}
	arrow = nullptr;
	return alive;
}

//-----------------------------------------------------------------------------------------------------

/*
	Function: player()
	Use: Imlicitly in run_game()

	It reads input command from the 
	console and it translates it 
	to either movement in one of three
	possible directions: left, center, right
	and/or shooting an arrow in one or all
	of three directions.

	Command format: s13 - s: move to; room number: 13
	-2-3 -:shoot; in room: 2 and: 3.
	
	The numbers must be valid room numbers.
*/
int Labyrinth::player (const std::string& command)
{
	// status of game
	int alive = 0;
	int dead = -1;
	int kill_wumpus = 1;

	if (!(arrows > 0)) 
	{
		std::cout <<"\nYou ran out of arrows!\n";
		return dead;
	}

	arrow = current_player;

	// check current room presence and determine player status
	// if bat in same room: "the bat pick you up and lands you in another room"
	if (current_player->is_bat()) 
	{
		    // player no longer in this room
		    current_player->set_player(false);

			// move player to a random room (avoiding same room)
			current_player = &entrance[random_number_without_i(1, size-1, current_player->get_number())];

			// display which is the number of the new room
			std::cout <<"\nA bat transported you to room number: "<< current_player->get_number() <<'\n';

			// indicate presence in current room
			current_player->set_player(true);
	}

	// if pit in same room: game over
	if (current_player->is_pit())
	{
		std::cout <<"\nYou have fallen into a bottomless pit!\n";
		return dead;
	}

	// if player walks into a room that wumpus is in: game over
	if (current_player->is_wumpus())
	{
		std::cout <<"\nYou have been eaten by wumpus!\n";
		return dead;
	}

	// extract shooting and moving instructions
	char move = 's';
	int door_num = -1;
	char shoot1 = '-', shoot2 = '-', shoot3 = '-' ;
	int door_num1 = -1, door_num2 = -1, door_num3 = -1;

	std::stringstream ss(command);
	ss >> move >> door_num 
	   >> shoot1 >> door_num1  // one shot
       >> shoot2 >> door_num2// two shots                        
	   >> shoot3 >> door_num3; // three shots
  
	// ugly shit!
	if (door_num1 != -1) arrows--; if (door_num2 != -1) arrows--; if (door_num3 != -1) arrows--; 

	// shoot arrow if any of the arguments != -1
	alive = shoot_arrow(door_num1, door_num2, door_num3);

	// if wumpus killed alive becomes +1, indicating Win
	if (alive == 1) 
	{
		return kill_wumpus;
	}

	// move player  
	// find the side with the door matching the room number
	if (current_player->get_left()->get_number() == door_num)
	{
		current_player->set_player(false);
		current_player = current_player->get_left();
		current_player->set_player(true);
	} 
	else if (current_player->get_center()->get_number() == door_num) 
	{
		current_player->set_player(false);
		current_player = current_player->get_center(); 
		current_player->set_player(true);
	} 
	else if (current_player->get_right()->get_number() == door_num) 
	{
		current_player->set_player(false);
		current_player = current_player->get_right(); 
		current_player->set_player(true);
	} 
	else 
	{
		std::cerr <<"\nNo such door number in this room!\n";
	}
	std::cout << "arrows left: "<< arrows <<'\n';
	return alive;
}

//-----------------------------------------------------------------------------------------------------

// Non-member function
void clear_screen(int skipped_lines) 
{
    std::cout << std::string(skipped_lines, '\n');
}

//-----------------------------------------------------------------------------------------------------

/*
	Function: run_game()
	Use: In main()
	
	It runs the game with 
	the use of an infinite loop,
	terminated only if wumpus or 
	player are dead.

	It calls the node traversing functions
	and checks their returning values
	indicating the game status.
*/  
void run_game ()
{
	int size = 20;
	int difficulty_level = 3;
	Labyrinth cave(size, difficulty_level); 

	int player_status = 0;   // -1 dead, 0 alive, 1 killed wumpus
	int wumpus_status = 0;	 // -1 dead, 0 alive, 1 killed player

	// loop till player || wumpus are alive
	int skipped_lines = 2;
	while (true)
	{	
		std::cout <<"Wumpus in room: " << cave.get_wumpus()->get_number() <<'\n';
		std::cout <<"Player in room: " << cave.get_player()->get_number() <<'\n';

		// display room door numbers
		std::cout << cave.disp_room_door_numbers ();

		// display adjoint room content
		std::cout << cave.disp_adj_room_presence ();

		// prompt user to type command to player: move, shoot
		std::string command;

		std::cout << "\nType a command:\n>> ";
		std::cin >> command;

		player_status = cave.player(command);
		if (player_status == -1) 
		{
			std::cout <<"\nGame Over!\n";
			break;
		}
		if (player_status == 1) 
		{
			std::cout <<"\nYou win!\n";
			break;
		}
		 
		// wumpus moves to random room 
		wumpus_status = cave.wumpus();
		if (wumpus_status == -1) 
		{
			std::cout <<"\nYou win!\n";
			break;
		}
		if (wumpus_status == 1)
		{
			std::cout <<"\nGame Over!\n";
			break;
		}
		clear_screen(skipped_lines);
	}
	getchar();
}