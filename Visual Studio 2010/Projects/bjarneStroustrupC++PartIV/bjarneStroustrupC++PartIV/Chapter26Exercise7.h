/* 
	TITLE		   Test Text Editor     Chapter26Exercise7.h
	COMMENT
		Objective: Test the "simple text editor" from §20.6. 
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 01.06.2017
*/

#ifndef Chapter26Exercise7_h
#define Chapter26Exercise7_h

struct Measurements
{
	std::string label;
	std::string command;
	std::string arg1;
	std::string arg2; 
	int result;
};

//------------------------------------------------------------------------------------------------

/*
	Test file format:
		{ command arg expected_result }
		{ command arg1 arg2 expected_result }
*/
std::istream& operator>> (std::istream& is, Measurements& m);
 
//------------------------------------------------------------------------------------------------

/* switch values */
enum CMD 
{
	FIND = 1, FIND_TEXT, ERASE, INSERT, REPLACE, CHAR_NUM, WORD_NUM
};

//------------------------------------------------------------------------------------------------

std::map<std::string, int> command_numbers;

//------------------------------------------------------------------------------------------------

static void init_command_numbers(std::map<std::string, int>& m);

//------------------------------------------------------------------------------------------------

int get_command_number(const std::string& command_name);
 
//------------------------------------------------------------------------------------------------

// text interface for class Document with redirectable I/O.
class Test_Document
{
	std::vector<Measurements> tests;
	Document text;

	void set_document_text(std::istream& is) { is >> text; }
	void set_measurements(std::istream& is);

	int call_find (std::string& arg);
	int call_find_text (std::string& arg);
	int call_erase (std::string& arg);
	int call_insert (std::string& arg1, std::string& arg2);
	int call_replace (std::string& arg1, std::string& arg2);
	int call_get_char_number ();
	int call_get_word_number ();

	void run_tests();

public:
	Test_Document(std::istream& measurements, std::istream& text);

	void print_document_text() { text.print(); };
};

#include "Chapter26Exercise7Def.cpp"

#endif
