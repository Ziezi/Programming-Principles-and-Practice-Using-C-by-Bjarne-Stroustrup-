/*
	TITLE		   Currency Converter			   Chapter16Exercise8.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Provide a currency converter.
				   Read the conversion rates from file on startup.
				   Enter amount in an input window and provide a way of
				   selecting currencies to convert to and from (e.g. a pair of menus).        
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/

#ifndef _Chapter16Exercise8_h_
#define _Chapter16Exercise8_h_

class Currency_converter: Window
{
public:
	Currency_converter();
private:
	// data members
	std::map<std::string, double> rates;
	double amount, input_rate, output_rate;
	
	// controls
	In_box input_amount;
	Out_box output_amount;

	Button from_button, to_button;
	Menu from_menu, to_menu;

	// callback
	static void cb_from_button(Address, Address pw) { reference_to<Currency_converter>(pw).from_button_pressed(); }
	static void cb_to_button(Address, Address pw) { reference_to<Currency_converter>(pw).to_button_pressed(); }

	static void cb_from_LEV(Address, Address pw) { reference_to<Currency_converter>(pw).from_LEV_pressed(); }
	static void cb_from_EUR(Address, Address pw) { reference_to<Currency_converter>(pw).from_EUR_pressed(); }
	static void cb_from_USD(Address, Address pw) { reference_to<Currency_converter>(pw).from_USD_pressed(); }
	static void cb_from_GBP(Address, Address pw) { reference_to<Currency_converter>(pw).from_GBP_pressed(); }

	static void cb_to_LEV(Address, Address pw) { reference_to<Currency_converter>(pw).to_LEV_pressed(); }
	static void cb_to_EUR(Address, Address pw) { reference_to<Currency_converter>(pw).to_EUR_pressed(); }
	static void cb_to_USD(Address, Address pw) { reference_to<Currency_converter>(pw).to_USD_pressed(); }
	static void cb_to_GBP(Address, Address pw) { reference_to<Currency_converter>(pw).to_GBP_pressed(); }

	// action
	void from_button_pressed() { from_button.hide(); from_menu.show(); }
	void to_button_pressed() { to_button.hide(); to_menu.show(); }
	
	void from_LEV_pressed() { input_rate = rates["BGN"]; hide_from_menu();}
	void from_EUR_pressed() { input_rate = rates["EUR"]; hide_from_menu();} 
	void from_USD_pressed() { input_rate = rates["USD"]; hide_from_menu();}
	void from_GBP_pressed() { input_rate = rates["GBP"]; hide_from_menu();}

	void to_LEV_pressed() { output_rate = rates["BGN"]; convert(); hide_to_menu(); }
	void to_EUR_pressed() { output_rate = rates["EUR"]; convert(); hide_to_menu(); }
	void to_USD_pressed() { output_rate = rates["USD"]; convert(); hide_to_menu(); }
	void to_GBP_pressed() { output_rate = rates["GBP"]; convert(); hide_to_menu(); }

	// helper
	void read_file(std::string& name, std::map<std::string, double>& m);
	void convert();
	void hide_from_menu() { from_menu.hide(); from_button.show(); }
	void hide_to_menu() { to_menu.hide(); to_button.show(); }
};

//------------------------------------------------------------------------------

Currency_converter::Currency_converter()
	: Window(Point(500, 50), 500, 500, "Chapter 16 Exercise 8"),
	input_amount(Point(75, 0), 70, 20, "Amount: "),
	output_amount(Point(x_max() - 75, 0), 70, 20, "Result: "),
	from_button(Point(160, 0), 80, 30, "From", cb_from_button),
	to_button(Point(x_max() - 240, 0), 80, 30, "To", cb_to_button),
	from_menu(Point(160, 0), 70, 20, Graph_lib::Menu::Kind::vertical, "from"),
	to_menu(Point(x_max() - 240, 0), 70, 20, Graph_lib::Menu::Kind::vertical, "to")
{
	amount = 0;
	input_rate = 0;
	output_rate = 1;

	std::string file_name = "Chapter16Exercise8.txt";
	read_file(file_name, rates);

	attach(input_amount);
	attach(output_amount);
	attach(from_button);
	attach(to_button);

	from_menu.attach(new Button(Point(0, 0), 0 , 0 , "BGN", cb_from_LEV));
	from_menu.attach(new Button(Point(0, 0), 0 , 0 , "EUR", cb_from_EUR));
	from_menu.attach(new Button(Point(0, 0), 0 , 0 , "USD", cb_from_USD));
	from_menu.attach(new Button(Point(0, 0), 0 , 0 , "GBP", cb_from_GBP));

	to_menu.attach(new Button(Point(0, 0), 0 , 0 , "BGN", cb_to_LEV));
	to_menu.attach(new Button(Point(0, 0), 0 , 0 , "EUR", cb_to_EUR));
	to_menu.attach(new Button(Point(0, 0), 0 , 0 , "USD", cb_to_USD));
	to_menu.attach(new Button(Point(0, 0), 0 , 0 , "GBP", cb_to_GBP));

	attach(from_menu);
	attach(to_menu);

	hide_from_menu();
	hide_to_menu();
}

//------------------------------------------------------------------------------

void Currency_converter::convert()
{
	// get input
	std::string input = input_amount.get_string();
	std::stringstream ss(input);
	double i;

	if (ss >> i)
	{
		amount = i;
	}
	else
	{
       output_amount.put("Invalid input"); 
	}

	// calculate output
	if (input_rate != 0 || output_rate != 0)
	{
		double result = amount * input_rate / output_rate;

		std::stringstream so;
		so << std::setprecision(2) << std::fixed << result;

		output_amount.put(so.str());
	}
	else
	{
		output_amount.put("Select from / to"); 
	}
}

//------------------------------------------------------------------------------

void Currency_converter::read_file(std::string& name, std::map<std::string, double>& m)
{
	std::ifstream ifs(name.c_str());

	if (!ifs) 
	{
		throw std::runtime_error("Currency_converter::read_file: Can't open file: " + name);
	}

	std::string input;

	while (getline(ifs, input))
	{
		std::stringstream ss(input);

		std::string cu;
		double am;
		char p1, c, p2;

		if (ss >> p1 >> cu >> c >> am >> p2)
		{
			if (p1 != '(' || c != ',' || p2 != ')' || (cu != "BGN" && cu != "EUR" && cu != "USD" && cu != "GBP"))
			{
				throw std::runtime_error("Currency_converter::read_file: Wrong input format.");
			}
			else
			{
				rates.emplace(std::pair<std::string, double>(cu, am));
			}
		}
		else
		{
			throw std::runtime_error("Currency_converter::read_file: Bad input stream.");
		}
	}
}
//------------------------------------------------------------------------------

#endif
