/* 
	TITLE	       Machine Lexicographical Order 	       Chapter27Exercise8.cpp
	COMMENT
		Objective: What is the lexicographical order on your machine? 
				   Write out every character on your keyboard together with its 
				   integer value; 
				   then, write the characters out in the order determined 
				   by their integer value. 
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 15.06.2017
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

void read_key_values(std::vector<std::string>& keys, std::vector<int>& key_values)
{
	std::cout <<"Type the key you see:\n";
	for (std::size_t i = 0; i < keys.size(); ++i)
	{
		std::cout <<"Type: "<< keys[i] <<": ";
		
		std::string line;
		getline(std::cin, line);

		std::stringstream ss(line);
		char key;
		ss >> key;
		std::cout <<"integer value: "<< int(key) <<'\n';
		key_values.emplace_back(int(key));
	}
	std::cout <<"Done.\n";
}

//--------------------------------------------------------------------------------

void write_to_stream(std::vector<std::string>& keys, std::vector<int>& key_values, std::ostream& os)
{
	std::map<int, std::string> value_name;

	for (std::size_t i = 0; i < keys.size(); ++i)
	{
		value_name.emplace(std::make_pair(key_values[i], keys[i]));
	}

	os <<"integer value\tkeyboard character name\n";
	for (auto it = value_name.begin(); it != value_name.end(); ++it)
	{
		os << it->first <<"\t"<< it->second <<'\n';
	}
}

//--------------------------------------------------------------------------------

void populate_keys(std::vector<std::string>& keys)
{
	// keyboard except (windows) control keys
	keys.emplace_back("`"); keys.emplace_back("1"); keys.emplace_back("2"); keys.emplace_back("3"); keys.emplace_back("4");
	keys.emplace_back("5"); keys.emplace_back("6"); keys.emplace_back("7"); keys.emplace_back("8"); keys.emplace_back("9");
	keys.emplace_back("0"); keys.emplace_back("-"); keys.emplace_back("="); keys.emplace_back("q"); keys.emplace_back("w");
	keys.emplace_back("e"); keys.emplace_back("r"); keys.emplace_back("t"); keys.emplace_back("y"); keys.emplace_back("u");
	keys.emplace_back("i"); keys.emplace_back("o"); keys.emplace_back("p"); keys.emplace_back("["); keys.emplace_back("]");
	keys.emplace_back("\\");keys.emplace_back("a"); keys.emplace_back("s"); keys.emplace_back("d"); keys.emplace_back("f");
	keys.emplace_back("g"); keys.emplace_back("h"); keys.emplace_back("j"); keys.emplace_back("k"); keys.emplace_back("l");
	keys.emplace_back(";"); keys.emplace_back("'"); keys.emplace_back("z"); keys.emplace_back("x"); keys.emplace_back("c");
	keys.emplace_back("v"); keys.emplace_back("b"); keys.emplace_back("n"); keys.emplace_back("m"); keys.emplace_back(",");
	keys.emplace_back("."); keys.emplace_back("/"); keys.emplace_back("/"); keys.emplace_back("*"); keys.emplace_back(".");
	keys.emplace_back("+"); keys.emplace_back("-"); keys.emplace_back("7"); keys.emplace_back("8"); keys.emplace_back("9");
	keys.emplace_back("4"); keys.emplace_back("5"); keys.emplace_back("6"); keys.emplace_back("1"); keys.emplace_back("2");
	keys.emplace_back("3"); keys.emplace_back("0");
}

//--------------------------------------------------------------------------------

int main()
{
	std::vector<std::string> keys;
	std::vector<int> key_values;

	populate_keys(keys);
	read_key_values(keys, key_values);

	std::string n("Chapter27Exercise8.txt");
	std::ofstream ofs(n.c_str());

	if (!ofs)
	{
		throw std::runtime_error("Can't open file!\n");
	}

	write_to_stream(keys, key_values, ofs);

	ofs.close();
}