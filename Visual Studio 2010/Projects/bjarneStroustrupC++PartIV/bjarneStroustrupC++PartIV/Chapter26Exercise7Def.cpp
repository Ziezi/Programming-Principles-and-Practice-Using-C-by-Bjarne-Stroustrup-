/* 
	TITLE		   Test Text Editor     Chapter26Exercise7Def.cpp
	COMMENT
		Objective: Test the "simple text editor" from §20.6. 
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 01.06.2017
*/

//------------------------------------------------------------------------------------------------

std::istream& operator>> (std::istream& is, Measurements& m)
{
	if (!is)
	{
		return is;
	}

	char op, cp;
	is >> op;

	if (op != '{')
	{
		is.setf(std::ios_base::failbit);
		return is;
	}

	std::string label;
	std::string command;
	std::string arg1;
	std::string arg2; 
	int result;

	is >> label >> command >> arg1 >> arg2 >> result >> cp;
	
	if (cp != '}' || !is)
	{
		is.setf(std::ios_base::failbit);
		return is;
	}

	m.label = label;
	m.command = command;
	m.arg1 = arg1;
	m.arg2 = arg2;
	m.result = result;

	return is;
}

//------------------------------------------------------------------------------------------------

static void init_command_numbers(std::map<std::string, int>& m)
{
	m.emplace(std::make_pair("find", 1));
	m.emplace(std::make_pair("find_text", 2));
	m.emplace(std::make_pair("erase", 3));
	m.emplace(std::make_pair("insert", 4));
	m.emplace(std::make_pair("replace", 5));
	m.emplace(std::make_pair("get_char_number", 6));
	m.emplace(std::make_pair("get_word_number", 7));
}

//------------------------------------------------------------------------------------------------

int get_command_number(const std::string& command_name)
{
	if (command_numbers.end() == command_numbers.find(command_name))
	{
		throw std::runtime_error("get_command_number()::Invalid command name!\n");
	}

	return command_numbers[command_name];
}

//------------------------------------------------------------------------------------------------

Test_Document::Test_Document(std::istream& measurements, std::istream& text)
{
	init_command_numbers(command_numbers);
	set_document_text(text);
	set_measurements(measurements);
	run_tests();
}

//------------------------------------------------------------------------------------------------

void Test_Document::set_measurements(std::istream& is)
{
	Measurements m;
	while (is >> m)
	{
		tests.emplace_back(m);	
	}
}

//------------------------------------------------------------------------------------------------

int Test_Document::call_find(std::string& arg)
{
	Document::iterator it = text.find(text.begin(), arg[0]);

	return (it != text.end()) ? 1 : 0;
}

//------------------------------------------------------------------------------------------------

int Test_Document::call_find_text(std::string& arg)
{
	Document::iterator it = text.find_txt(arg);

	return (it != text.end()) ? 1 : 0;
}

//------------------------------------------------------------------------------------------------

int Test_Document::call_erase (std::string& arg)
{
	std::stringstream ss(arg);
	int pos = 0;
	ss >> pos;

	Document::iterator beg = text.begin();
	Document::iterator at = advance(beg, pos);

	Document::iterator it = text.erase(at);

	return (it != text.end()) ? 1 : 0;
}

//------------------------------------------------------------------------------------------------

int Test_Document::call_insert (std::string& arg1, std::string& arg2)
{
	std::stringstream ss(arg1);
	int pos = 0;
	ss >> pos;

	Document::iterator beg = text.begin();
	Document::iterator at = advance(beg, pos);

	Document::iterator it = text.insert(at, arg2[0]);
	
	// print the text and see ?
	return (*text.find(text.begin(), arg2[0]) == arg2[0]) ? 1 : 0;
}

//------------------------------------------------------------------------------------------------

int Test_Document::call_replace(std::string& arg1, std::string& arg2)
{
	Document::iterator it = text.replace(arg1, arg2);

	return (it != text.end()) ? 1 : 0;
}

//------------------------------------------------------------------------------------------------

int Test_Document::call_get_char_number()
{
	return text.get_char_number();
}

//------------------------------------------------------------------------------------------------

int Test_Document::call_get_word_number()
{
	return text.get_word_number();
}

//------------------------------------------------------------------------------------------------

void Test_Document::run_tests()
{
	int passed_tests = 0;
	int failed_tests = 0;

	for (std::size_t i = 0; i < tests.size(); ++i)
	{
		int result = 0;
		int command_number = 0;

		command_number = get_command_number(tests[i].command);

		switch(command_number)
		{
			case FIND:
			{
				result = call_find(tests[i].arg1);
				break;
			}
			case FIND_TEXT:
			{
				result = call_find_text(tests[i].arg1);
				break;
			}
			case ERASE:
			{
				result = call_erase(tests[i].arg1);
				break;
			}
			case INSERT:
			{
				result = call_insert(tests[i].arg1, tests[i].arg2);
				break;
			}
			case REPLACE:
			{
				result = call_replace(tests[i].arg1, tests[i].arg2);
				break;
			}
			case CHAR_NUM:
			{
				result = call_get_char_number();
				break;
			}
			case WORD_NUM:
			{
				result = call_get_word_number();
				break;
			}

			default:
			{
				throw std::runtime_error("run_tests::No such command number!\n");
				break;
			}
		}

		if (result != tests[i].result)
		{
			std::cout <<"Test: " << tests[i].label <<" expected: "<< tests[i].result <<" experimental: " << result <<'\n';
			++failed_tests;
		}
		else
		{
			++passed_tests;
		}
	}

	std::cout <<"Conducted: "<< failed_tests + passed_tests  <<" Passed: "<< passed_tests  <<" Failed: "<< failed_tests <<'\n';
}

//------------------------------------------------------------------------------------------------

