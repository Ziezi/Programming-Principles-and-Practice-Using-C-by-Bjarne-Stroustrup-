/*
	TITLE		    Text statistics GUI		 Chapter21Exercise15.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Provide GUI for exercise 14
					"How many occurrences of ship are there in a file?"
					"Which word occurs most frequently?" 
					"Which is the longest word in the file?" 
					"Which is the shortest?" 
					"List all words starting with s."
					"List all four-letter words." 

					Test commands:
					How many occurrences of make are there in a Chapter21Exercise15.txt?
					Which word occurs most frequently in Chapter21Exercise15.txt?
					Which is the longest word in the Chapter21Exercise15.txt?
					Which is the shortest in Chapter21Exercise15.txt?
					List all words starting with s in Chapter21Exercise15.txt.
					List all three-letter words in Chapter21Exercise15.txt.

		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 06. 03. 2017
*/

#ifndef Chapter21Exercise15_h
#define Chapter21Exercise15_h

class Text_Statistics_GUI: public Window
{
public:
	Text_Statistics_GUI()
		: Window(700, 700, "Text Query"),
		command_ibox(Point(100, 0), 500, 20, "Command:"),
		results_obox(Point(100, 50), 500, 150, "Result:"),
		execute_button(Point(600, 0), 70, 20, "Execute", cb_execute)
	{
		attach(command_ibox);
		attach(results_obox);
		attach(execute_button);
	}
	
private:
	// controls
	In_box command_ibox;
	Out_box results_obox;
	Button execute_button;

	// callbacks
	static void cb_execute (Address, Address pw) { reference_to<Text_Statistics_GUI>(pw).execute_pressed(); }

	// action
	void execute_pressed();

	// helpers
	void occurrences(const std::string& target);
	void mode(const std::string& command);
	void longest(const std::string& command);
	void shortest(const std::string& command);
	void word_starting_with(const std::string& command);
	void word_of_length(const std::string& command);

	// data
	std::vector<std::string> modified_text;
	std::map<std::string, int> dictionary;
};

//-------------------------------------------------------------------------------------

void Text_Statistics_GUI::execute_pressed()
{
	std::string command = command_ibox.get_string();

	// interpret command
	if (command.find("occurrences") != std::string::npos)
	{
		occurrences(command);
	}
	else if (command.find("most frequently") != std::string::npos)
	{
		mode(command);
	}
	else if (command.find("the longest word") != std::string::npos)
	{ 
		longest(command);
	}
	else if (command.find("the shortest") != std::string::npos)
	{ 
		shortest(command);
	}
	else if (command.find("words starting with") != std::string::npos)
	{ 
		word_starting_with(command);
	}
	else if (command.find("-letter words") != std::string::npos)
	{ 
		word_of_length(command);
	}
	else 
	{
		results_obox.put("No such command!\n");
	}

	// empty containers
	modified_text.clear();
	dictionary.clear();
}

//-------------------------------------------------------------------------------------

void Text_Statistics_GUI::occurrences(const std::string& command)
{
	// find word after "of", i.e. target
	size_t s_pos = command.find("of") + 3;
	size_t e_pos = command.find(" ", s_pos);
	size_t length = e_pos - s_pos;
	std::string target = command.substr(s_pos, length);

	// find file name, i.e. last word
	size_t pos1 = command.find_last_of(" ");
	size_t pos2 = command.find_last_of("?");
	size_t length2 = pos2 - pos1 - 1;

	std::string file_name; 
	if (pos1 != std::string::npos)
	{
		file_name = command.substr(pos1 + 1, length2); 
	}

	// execute command
	cleaup_text_file(file_name,  modified_text, file_name);
	populate_map(modified_text, dictionary);
	int freq = find_occurrences_of(target, dictionary);

	// display result
	std::stringstream ss;
	ss << freq;
	results_obox.put(ss.str());
}

//-------------------------------------------------------------------------------------

void Text_Statistics_GUI::mode(const std::string& command)
{
	// find file name, i.e. last word
	size_t pos1 = command.find_last_of(" ");
	size_t pos2 = command.find_last_of("?");
	size_t length2 = pos2 - pos1 - 1;

	std::string file_name; 
	if (pos1 != std::string::npos)
	{
		file_name = command.substr(pos1 + 1, length2); 
	}

	// find mode
	cleaup_text_file(file_name,  modified_text, file_name);
	populate_map(modified_text, dictionary);
	std::string mode = find_mode(dictionary);

	// display result
	results_obox.put(mode);
}

//-------------------------------------------------------------------------------------

void Text_Statistics_GUI::longest(const std::string& command)
{
	// find file name, i.e. last word
	size_t pos1 = command.find_last_of(" ");
	size_t pos2 = command.find_last_of("?");
	size_t length2 = pos2 - pos1 - 1;

	std::string file_name; 
	if (pos1 != std::string::npos)
	{
		file_name = command.substr(pos1 + 1, length2); 
	}

	// find longest word
	cleaup_text_file(file_name,  modified_text, file_name);
	populate_map(modified_text, dictionary);
	std::string longest_word = find_longest_word(dictionary);

	// display result
	results_obox.put(longest_word);
}

//-------------------------------------------------------------------------------------

void Text_Statistics_GUI::shortest(const std::string& command)
{
	// find file name, i.e. last word
	size_t pos1 = command.find_last_of(" ");
	size_t pos2 = command.find_last_of("?");
	size_t length2 = pos2 - pos1 - 1;

	std::string file_name; 
	if (pos1 != std::string::npos)
	{
		file_name = command.substr(pos1 + 1, length2); 
	}

	// find shortest word
	cleaup_text_file(file_name,  modified_text, file_name);
	populate_map(modified_text, dictionary);
	std::string shortest_word = find_shortest_word(dictionary);

	// display result
	results_obox.put(shortest_word);
}

//-------------------------------------------------------------------------------------

void Text_Statistics_GUI::word_starting_with(const std::string& command)
{
	// find character after "with", i.e. target char
	size_t s_pos = command.find("with") + 5;
	size_t e_pos = command.find(" ", s_pos);
	size_t length = e_pos - s_pos;
	
	std::string target_char; 
	if (s_pos != std::string::npos)
	{
		target_char = command.substr(s_pos, length); 
	}

	// find file name, i.e. last word
	size_t pos1 = command.find_last_of(" ");
	size_t pos2 = command.find_last_of(".");
	size_t length2 = pos2 - pos1 - 1;

	std::string file_name; 
	if (pos1 != std::string::npos)
	{
		file_name = command.substr(pos1 + 1, length2); 
	}

	// find word starting with specific char
	cleaup_text_file(file_name,  modified_text, file_name);
	populate_map(modified_text, dictionary);
	std::vector<std::string> s_words = find_words_starting_with(dictionary, target_char[0]);

	// display result
	std::stringstream ss;
	for (auto it = s_words.begin(); it != s_words.end(); ++it)
	{
		ss << *it <<" ";
	}
	
	results_obox.put(ss.str());
}

//-------------------------------------------------------------------------------------

void Text_Statistics_GUI::word_of_length(const std::string& command)
{
	// find word before "-letter"
	size_t s_pos = command.find("all") + 4;
	size_t e_pos = command.find("-", s_pos);
	size_t length = e_pos - s_pos;

	std::string target_length; 
	if (s_pos != std::string::npos)
	{
		target_length = command.substr(s_pos, length); 
	}

	// length: word to int 
	std::map<std::string, int> word_to_number;
	word_to_number["zero"] = 0;
	word_to_number["one"] = 1;
	word_to_number["two"] = 2;
	word_to_number["three"] = 3;
	word_to_number["four"] = 4;
	word_to_number["five"] = 5;
	word_to_number["six"] = 6;
	word_to_number["seven"] = 7;
	word_to_number["eight"] = 8;
	word_to_number["nine"] = 9;
	
	size_t target = 0;
	target = word_to_number[target_length];

	// find file name, i.e. last word
	size_t pos1 = command.find_last_of(" ");
	size_t pos2 = command.find_last_of(".");
	size_t length2 = pos2 - pos1 - 1;

	std::string file_name; 
	if (pos1 != std::string::npos)
	{
		file_name = command.substr(pos1 + 1, length2); 
	}

	// find words with specific length
	cleaup_text_file(file_name,  modified_text, file_name);
	populate_map(modified_text, dictionary);
	std::vector<std::string> l_words = find_words_of_length(dictionary, target);

	// display result
	std::stringstream ss;
	for (auto it = l_words.begin(); it != l_words.end(); ++it)
	{
		ss << *it <<" ";
	}
	
	results_obox.put(ss.str());
}

#endif