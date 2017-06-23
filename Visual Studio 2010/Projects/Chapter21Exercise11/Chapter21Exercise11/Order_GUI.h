/*
	TITLE		    GUI Order & files					Order_GUI.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Chapter 21 Exercise 11
					Provide a GUI interface for entering Orders into files.  
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 01. 03. 2017
*/

#ifndef Order_GUI_h
#define Order_GUI_h


class Order_GUI: public Window
{
public:
	Order_GUI()
		: Window(700, 150, "Order Sheet"),
		client_name_ibox(Point(70, 0), 140, 20, "Name: "),
		client_address_ibox(Point((x_max() - 70) / 2, 0), 140, 20, "Address: "),
		date_obox(Point(x_max() - 150, 0), 140, 20, "Date: "),
		add_client_button(Point((x_max() - 70) / 2, 50), 70, 20, "Add", cb_add_client),

		products_name_ibox(Point(70, 0), 140, 20, "Item: "), 
		products_quantity_ibox(Point((x_max() - 70) / 2, 0), 70, 20, "Quantity: "),
		price_ibox(Point(x_max() - 150, 0), 70, 20, "Price: "),
		add_item(Point(x_max() - 150, 50), 70, 20, "Add", cb_add_item),
		purhcase_button(Point((x_max() - 70) / 2, 100), 70, 20, "Buy", cb_purhcase),

		continue_button(Point(70 , 100), 70, 20, "Continue", cb_continue),
		quit_button(Point(x_max() - 140, 100), 70, 20, "Quit", cb_quit)
	{
		attach(client_name_ibox);
		attach(client_address_ibox);

		std::string date = get_date();
		attach(date_obox);
		date_obox.put(date);
		attach(add_client_button);

		attach(products_name_ibox);
		attach(products_quantity_ibox);
		attach(price_ibox);
		attach(add_item);
		attach(purhcase_button);

		attach(continue_button);
		attach(quit_button);

		hide_second_page();
		hide_third_page();
	}

private:
	// controls
	// page 1
	In_box client_name_ibox;
	In_box client_address_ibox;
	Out_box date_obox;
	Button add_client_button;
	 
	// page 2
	In_box products_name_ibox;
	In_box products_quantity_ibox;
	Button add_item;
	In_box price_ibox;
	Button purhcase_button;

	// page 3
	Button continue_button;
	Button quit_button;

	// callbacks
	static void cb_add_client (Address, Address pw) { reference_to<Order_GUI>(pw).add_client_pressed(); }
	static void cb_add_item (Address, Address pw) { reference_to<Order_GUI>(pw).add_item_pressed(); }
	static void cb_purhcase (Address, Address pw) { reference_to<Order_GUI>(pw).purchased_pressed(); }
	static void cb_quit (Address, Address pw) { reference_to<Order_GUI>(pw).quit_pressed(); }
	static void cb_continue (Address, Address pw) { reference_to<Order_GUI>(pw).continue_pressed(); }

	// actions
	void add_client_pressed();
	void add_item_pressed();	
	void purchased_pressed();
	void quit_pressed() { hide(); }
	void continue_pressed() { hide_third_page(); show_first_page(); }

	// helpers
	void hide_first_page();
	void show_first_page();

	void hide_second_page();
	void show_second_page();

	void hide_third_page() { continue_button.hide(); quit_button.hide(); }
	void show_third_page() { continue_button.show(); quit_button.show(); }

	std::string get_date();
	std::string get_file_name();

	// data members
	std::vector<Order> order_register;
};

//-----------------------------------------------------------------------------------------------------

void Order_GUI::add_client_pressed()
{
	// add client

	// get client name
	std::string client_name = client_name_ibox.get_string();

	// get client address
	std::string client_address = client_address_ibox.get_string();

	// get date
	std::string date = get_date();

	// display date
	date_obox.put(date);

	// create client info
	order_register.emplace_back(Order(client_name, client_address, date));

	// update pages
	hide_first_page();
	show_second_page();
}

//-----------------------------------------------------------------------------------------------------

void Order_GUI::add_item_pressed()
{
	// add purchase

	// get iten name
	std::string name = products_name_ibox.get_string();

	// get item units
	int units = products_quantity_ibox.get_int();

	// get price
	std::string p = price_ibox.get_string();
	std::stringstream ss(p);
	double price = 0;
	ss >> price;

	// create new purchase
	order_register[order_register.size() - 1].add_purchase(Purchase(name, price, units));
}

//-----------------------------------------------------------------------------------------------------

void Order_GUI::purchased_pressed()
{
	// write order to file
	std::string file(get_file_name());
	file.append(".txt");
	std::ofstream ofs(file.c_str());

	for (auto it = order_register.begin(); it != order_register.end(); ++it)
	{
		ofs << *it;
	}

	// empty vector
	order_register.clear();

	// update pages
	hide_second_page();
	show_third_page();
}

//-----------------------------------------------------------------------------------------------------

void Order_GUI::hide_first_page() 
{ 
	client_name_ibox.hide();
	client_address_ibox.hide();
	date_obox.hide();
	add_client_button.hide();
}

//-----------------------------------------------------------------------------------------------------

void Order_GUI::show_first_page()
{ 
	client_name_ibox.show();
	client_address_ibox.show(); 
	date_obox.show(); 
	add_client_button.show();
}

//-----------------------------------------------------------------------------------------------------

void Order_GUI::hide_second_page() 
{ 
	products_name_ibox.hide(); 
	products_quantity_ibox.hide();
	add_item.hide(); 
	price_ibox.hide();
	purhcase_button.hide();
}

//-----------------------------------------------------------------------------------------------------

void Order_GUI::show_second_page() 
{ 
	products_name_ibox.show();
	products_quantity_ibox.show();
	add_item.show(); 
	price_ibox.show();
	purhcase_button.show();
}

//-----------------------------------------------------------------------------------------------------

std::string Order_GUI::get_date()
{
	// get date
	auto t = time(NULL);
	auto tm = *std::localtime(&t);
	
	// convert to string
	std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
	std::string date = oss.str();
    return date;
}

//-----------------------------------------------------------------------------------------------------

/*	Get name of the last client */
std::string Order_GUI::get_file_name()
{
	return order_register[order_register.size() - 1].client_name;
}

//-----------------------------------------------------------------------------------------------------

 

#endif
