/*
	TITLE		    "Hunt the Lumpus"       Chapter18Exercise12.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Implement the game: "Hunt the Lumpus".
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 12.1.2016
*/

#ifndef CHAPTER18EXERCISE12_H
#define CHAPTER18EXERCISE12_H

class Room 
{
public:
	Room ()																	// constructor
	{
		room_number = 0;

		wumpus = false;
		bat = false;
		pit = false;
	
		player = false;
		arrow = false;

		left_door = nullptr;
		center_door = nullptr;
		right_door = nullptr;
	}

	// Non-modifying functions
	// check what is in the room 
	bool is_wumpus () const { return wumpus; }
	bool is_bat () const { return bat; }
	bool is_pit () const { return pit; }
	bool is_player () const { return player; }
	bool is_arrow () const { return arrow; }

	// Modifying functions
	// set what is in the room
	void set_wumpus (bool here) { wumpus = here; }
	void set_bat (bool here) { bat = here; }
	void set_pit (bool here) { pit = here; }
	void set_player (bool here) { player = here; }
	void set_arrow (bool here) { arrow = here; }

	// room setters (used to connect to an adjoint room)
	void set_left (Room* l) { left_door = l; }
	void set_center (Room* c) { center_door = c; }
	void set_right (Room* r) { right_door = r; }
	void set_number (unsigned int n) { room_number = n; }

	// room getters (used to check what is in the adjoint rooms)
	Room* get_left () const { return left_door; }
	Room* get_center () const { return center_door; }
	Room* get_right () const { return right_door; }

	unsigned int get_number () const { return room_number; }

private:
	unsigned int room_number;

	bool wumpus;
	bool bat;
	bool pit;
	
	bool player;
	bool arrow;

	Room* left_door;
	Room* center_door;
	Room* right_door;
};

//-----------------------------------------------------------------------------------------------------

class Labyrinth 
{
public:
	Labyrinth (int s, int l)													// constructor
		: size(s), level(l)
	{
		if (size < 0 || level < 0) 
		{
			std::cerr <<"\nSize and level of labyrinth must be positive!\n";
		}

		generate_labyrinth ();
		populate_labyrinth();
		summon_wumpus ();
		insert_player ();

		test_nodes ();
	}

	~Labyrinth () { delete[] entrance; }										// destructor

	std::string disp_room_door_numbers () const;
	std::string disp_adj_room_presence () const;

	int shoot_arrow(int door1, int door2, int door3);
	int player (const std::string& command);
	
	int wumpus ();

	// methods used for GUI implementation
	Room* get_enrtance() { return entrance; }
	Room* get_player() { return current_player; }
	Room* get_wumpus() { return current_wumpus; }
	Room* get_arrow() { return arrow; }
	int get_size() { return size; }
	int get_arrows_number() { return arrows; }

private:
	Room* entrance;																// head(root) node
	Room* current_wumpus;
	Room* current_player;
	Room* arrow; 

	int size;																	// number of Rooms (nodes)
	int level;																	// number of rooms with pits and bats
	int arrows;

	int random_number (unsigned int from, unsigned int to);
	int random_number_without_i (int min, int max, unsigned int i);
	int random_number_without_these (int min, int max, std::set<int>& these);

	void generate_labyrinth ();
	void populate_labyrinth ();
	void summon_wumpus();
	void insert_player();
	
	void test_nodes ();
};

#include "Chapter18Exercise12Def.cpp"
#endif


 

  

