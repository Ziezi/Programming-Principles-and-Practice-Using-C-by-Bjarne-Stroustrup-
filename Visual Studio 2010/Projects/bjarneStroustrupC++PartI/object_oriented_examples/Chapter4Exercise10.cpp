/* 
	TITLE 		   "Rock, Paper, Scissors"      Chapter4Exercise10.cpp
	 Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Write a  "Rock, Paper, Scissors" game.
			Input: Requests either one of three possible moves;
				   sentinel to exit. 
		   Output: Prints game state (win/ loss) message.
		   Author: Chris B. Kirov
			 Date: 5. 1 . 2015	
*/
#include "../../std_lib_facilities.h"

void game();
int simulate_move(int, int);
void check_result(int, int);

//=====================================================================

int main()
{
	cout <<"Play Rock, Paper, Scissors; Type""|"" to exit\n";
	game();
}

//=====================================================================

/*
	Function: game()
	Use: game();

	It runs the game of "Rock, paper, scissors".
	Prompts the user to select a move by typing 
	numbers [1,3]. Generates random number to
	simulate opponent move. Displays result.
	Exit by typing "|".
*/
void game()
{
	 string prompt = "Select a move by typing a number:\n1. Paper.\n2. Scissors.\n3. Rock.\n";
	
	 int move = 0;

	 string sentinel = "|";
	 string input;

	 cout << prompt;
	 while (getline(cin, input) && input != sentinel)
	 {
		stringstream ss(input);
		// check input format validity
		if (ss >> move)
		{
			// check move validity
			if (move < 1 || move > 3)
			{
				cout <<"Non existent move!";
				continue;
			}
			// generate move
			int opponent_move = simulate_move(1, 3);

			check_result(move, opponent_move);

			cout << prompt; 
		}
		else
		{
			cout <<"Wrong input format!";
		}
	 }
}

/*
	Function: simulate_move()
	Use: int pseudorandom_num = simulate_move(min, max);

	It generates a pseudorandom number withing the
	interval [min, max].
*/
int simulate_move(int min, int max)
{
	static bool initialized = false;

	if (!initialized)
	{
		srand(time(NULL));
		initialized = true;
	}

	return rand() % max + min;
}

/*
	Function: check_result();
	Use: Implicitly used in game().

	It displays the made moves 
	and determines/prints the winner.

	rock > scissors 
	scissors > paper
	paper > rock
*/
void check_result(int move, int opponent_move)
{
	// display moves
	string display_move[] = {"none", "paper", "scissors", "rock"};
	cout <<"You: "<< display_move[move] <<" opponent: "<< display_move[opponent_move] <<'\n';

	// display result
	if (move == opponent_move)
	{
		cout <<"Draw!\n";
	}
	else if (move == opponent_move + 1 || move == opponent_move - 2)
	{
		cout <<"You Win!\n";
	}
	else
	{
		cout <<"You Lose!\n";
	}
}