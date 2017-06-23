/*
	TITLE		    Query GUI 							Query_GUI.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Provide a GUI interface for querying a file of Orders; 
					e.g., "Find all orders from Joe,"
					"Find the tolal value of orders in file Hardware," and
					"List all orders in file Clothing."   

					In current implementation file name matches client name.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 03. 03. 2017
*/

#ifndef Query_GUI_h
#define Query_GUI_h


//-------------------------------------------------------------------------------------

// T - Purchase, U - double
template <class T, class U>
struct multiply_purhase 
{
  U operator() (const T& x, const T& y) const 
  {
	  return x.count * y.unit_price;
  }
};

//-------------------------------------------------------------------------------------

class Query_GUI: public Window
{
public:
	Query_GUI()
		: Window(500, 500, "Order Query"),
		command_ibox(Point(100, 0), 300, 20, "Command:"),
		results_obox(Point(100, 50), 300, 150, "Result:"),
		execute_button(Point(400, 0), 70, 20, "Execute", cb_execute)
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
	static void cb_execute (Address, Address pw) { reference_to<Query_GUI>(pw).execute_pressed(); }

	// action
	void execute_pressed();

	// helper
	bool file_exists (const std::string& file_name);
	void populate_vector (const std::string& file_name);

	void find_all_orders_from (const std::string& client_name);
	void total_value_from (const std::string& file_name);
	void list_all_orders_from (const std::string& file_name);

	std::vector<Order> order_register;
};

//-------------------------------------------------------------------------------------

bool Query_GUI::file_exists(const std::string& file_name)
{
	std::cout <<file_name <<'\n';
	std::ifstream ifs(file_name.c_str());
	return ifs.good();
}
//-------------------------------------------------------------------------------------

void Query_GUI::populate_vector(const std::string& file_name)
{
	std::ifstream ifs(file_name.c_str());

	if (!ifs)
	{
		throw std::runtime_error("Can't open input file!\n");
	}
	
	Order ord;
	while (ifs >> ord)
	{
		order_register.push_back(ord);
		ord = Order();
	}
}

//-------------------------------------------------------------------------------------

void Query_GUI::find_all_orders_from(const std::string& client_name)
{
	if (file_exists(client_name))
	{
		populate_vector(client_name);
	}
}

//-------------------------------------------------------------------------------------

void Query_GUI::total_value_from(const std::string& file_name)
{
	find_all_orders_from(file_name);

	double total = 0.0;
	for (auto it = order_register.begin(); it != order_register.end(); ++it)
	{
		total = std::inner_product(it->sales.begin(),  it->sales.end(), 
									it->sales.begin(),  
									total, 
									std::plus<double>(), multiply_purhase<Purchase, double>());
	}

	std::stringstream ss;
	ss <<"Total value: "<< total <<'\n';

	results_obox.put(ss.str());
	redraw();
}

//-------------------------------------------------------------------------------------

void Query_GUI::list_all_orders_from(const std::string& file_name)
{
	find_all_orders_from(file_name);

	std::stringstream ss;
	for (auto it = order_register.begin(); it != order_register.end(); ++it)
	{
		std::cout << *it; // testl ine <-----------------------------------------------------

		ss << *it;
	}

	results_obox.put(ss.str());
	redraw();
}

//-------------------------------------------------------------------------------------

/* Rudimentary command parser */
void Query_GUI::execute_pressed()
{
	// get command
	std::string command = command_ibox.get_string();

	// extract last word (which is the file name)
	size_t pos = command.find_last_of(" ");

	std::string file_name; 
	if (pos != std::string::npos)
	{
		file_name = command.substr(pos + 1, command.size() - 1); 
	}
	
	// interpret command
	if (command.find("find all orders") != std::string::npos)
	{
		list_all_orders_from(file_name);
	}
	else if (command.find("tolal value of orders") != std::string::npos)
	{
		total_value_from(file_name);
	}
	else if (command.find("list all orders") != std::string::npos)
	{
		list_all_orders_from(file_name);
	}
	else 
	{
		results_obox.put("No such command!\n");
	}
}

#endif