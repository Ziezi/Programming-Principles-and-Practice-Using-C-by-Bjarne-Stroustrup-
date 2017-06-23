/*
	TITLE		    class Purchase & Order     Chapter21Exercise9.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Define an Order class with (customer) 
					name, address, data and vector<Purchase>
					members.

					Purchase is a class with (product) name,
					unit prince, and count members.

					Define a mechanism for reading and writing
					to and from file. 

					Define a mechanism for printing orders.

					Create a file of at least 10 orders,
					read it into a vector<Order>, sort it by
					name (of customer), and write it back to
					file.

					Create another file of at least ten Orders,
					of which about the third are the same as in 
					the first file, read into a list<Order>, 
					sort by address of customer and write back
					out to file.

					Mergre the two files into third using std::merge(); 
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 28. 02. 2017
*/

#ifndef Chapter21Exercise9_h
#define Chapter21Exercise9_h

class Purchase
{
public:
	Purchase()
		: product_name(), unit_price(), count()
	{
	
	}


	Purchase(const std::string& n, double u, int c)
		: product_name(n), unit_price(u), count(c)
	{
	
	}

	Purchase(const Purchase& src)
		: product_name(src.product_name), unit_price(src.unit_price), count(src.count)
	{
	
	}

	Purchase& operator= (const Purchase& src)
	{
		Purchase temp(src);
		swap(temp);
		return *this;
	}

	void swap(Purchase& src)
	{
		std::swap(product_name, src.product_name);
		std::swap(unit_price, src.unit_price);
		std::swap(count, src.count);
	}

	std::string product_name;
	double unit_price;
	int count;
};

//----------------------------------------------------------------------------

void swap(Purchase& lhs, Purchase& rhs)
{
	lhs.swap(rhs);
}

//----------------------------------------------------------------------------

/* Input format: name price count*/
std::istream& operator>> (std::istream& is, Purchase& dest)
{
	if (!is)
	{
		return is;
	}

	std::string line;
	getline(is, line);
	std::stringstream ss(line);

	std::string name;
	double price;
	int count;

	if (ss >> name >> price >> count)
	{
		dest = Purchase(name, price, count);
	}

	return is;
}

//----------------------------------------------------------------------------

std::ostream& operator<< (std::ostream& os, Purchase& src)
{
	os << src.product_name <<"\t"<< src.unit_price <<"\t"<< src.count;
	return os;
}

//----------------------------------------------------------------------------

class Order
{
public:
	Order()
		: client_name(), address(), date()
	{
	
	}

	Order(const std::string& n, const std::string& a, const std::string& d)
		: client_name(n), address(a), date(d)
	{
	
	}

	Order(const Order& src)
		: client_name(src.client_name), address(src.address), date(src.date), sales(src.sales)
	{
	
	}

	Order& operator= (const Order& src)
	{
		Order temp(src);
		swap(temp);
		return *this;
	}

	void swap(Order& src)
	{
		std::swap(client_name, src.client_name);
		std::swap(address, src.address);
		std::swap(date, src.date);
		std::swap(sales, src.sales);
	}

	void add_purchase(const std::string& name, double cost, int units)
	{
		sales.emplace_back(Purchase(name, cost, units));
	}

	void add_purchase(const Purchase& src)
	{
		sales.emplace_back(src);
	}

	bool operator < (const Order& src) const
    {
        return client_name < src.client_name;
    }

	std::string client_name; // separate class ?
	std::string address;	 // separate class ?
	std::string date;		 // separate class ?
	std::vector<Purchase> sales;
};

//----------------------------------------------------------------------------

void swap(Order& lhs, Order& rhs)
{
	lhs.swap(rhs);
}

//----------------------------------------------------------------------------

/* 
	Input format: 
	
	// empty line
	client_name address data 
	product_name price count
	product_name price count
	product_name price count
	product_name price count 
	// empty line
*/
std::istream& operator>> (std::istream& is, Order& dest)
{
	if (!is)
	{
		return is;
	}

	std::string line;
	getline(is, line);
	std::stringstream ss(line);

	std::string name, address, date;
	if (ss >> name >> address >> date)	// read client details
	{
		dest.client_name = name;
		dest.address = address;
		dest.date = date;
	}

	std::string line2;
	while (getline(is, line2) && !line2.empty()) // read purchases till empty line
	{
		Purchase p;
		std::stringstream ss2(line2);
		
		if (ss2 >> p)
		{
			dest.add_purchase(p);
		}
	}

	return is;
}

//----------------------------------------------------------------------------

std::ostream& operator<< (std::ostream& os, Order& src)
{
	os << src.client_name <<"\t"<< src.address <<"\t"<< src.date <<'\n';

	for (auto it = src.sales.begin(); it != src.sales.end(); ++it)
	{
		os << *it <<'\n';
	}
	os <<"\n";
	return os;
}

//----------------------------------------------------------------------------

struct Order_Customer_Address
{
	bool operator() (const Order& lhs, const Order& rhs)
	{
		return lhs.address< rhs.address;
	}
};

#endif