/*
	TITLE			Vector & List use 	 		Chapter21Drill1.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: After each line print the container.
					1. Define a struct Item { string name; int id; double value; };
					and make a vector<Item> vi, and fill it with 10 items from file.
					2. Sort by name.
					3. Sort by id.
					4. Sort by value in decreasing order.
					5. Insert Item("horse shoe", 99, 12.34) and ltem("Canon 5400", 9988, 499.95).
					6. Remove two items defined by name.
					7. Remove two items defined by id.
					8. Repeat the previous steps with list.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 26. 02. 2017
*/
#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <list>
#include <algorithm>
 
//--------------------------------------------------------------------

struct Item
{
	Item()
		: name(), id(), value()
	{
	
	}

	Item(std::string n, int i, double v)
		: name(n), id(i), value(v)
	{
	
	}

	Item(const Item& src)
		: name(src.name), id(src.id), value(src.value)
	{
	
	}

	Item& operator= (const Item& src)
	{
		Item temp(src);
		swap(temp);
		return *this;
	}

	void swap(Item& src)
	{
		std::swap(src.name, name);
		std::swap(src.id, id);
		std::swap(src.value, value);
	}

std::string name;
int id;
double value;
};

//--------------------------------------------------------------------

void swap(Item& lhs, Item& rhs)
{
	lhs.swap(rhs);
}

//--------------------------------------------------------------------

std::istream& operator>> (std::istream& is, Item& i)
{
	if (!is) // bad stream
	{
		return is;
	}

	std::string n;
	int ii;
	double v;

	if (is >> n>> ii >> v)
	{
		i.name = n;
		i.id = ii;
		i.value = v;

		return is;
	}
	else // wrong format
	{
		is.setf(std::ios_base::failbit);
		return is;
	}
}

//--------------------------------------------------------------------

std::ostream& operator<< (std::ostream& os, Item& i)
{
	return os << i.name <<" "<< i.id <<" "<< i.value;
}

//--------------------------------------------------------------------

struct Cmp_Name
{
	inline bool operator() (const Item& lhs, const Item& rhs) const 
	{
		return lhs.name < rhs.name;
	}
};

//--------------------------------------------------------------------

bool item_by_id (const Item& lhs, const Item& rhs)  
{
	return lhs.id < rhs.id;
}


//--------------------------------------------------------------------

template <class Container>
void initialize_items(Container& v)
{
	std::string name("Chapter21Drill1initializeItem.txt");
	std::ifstream ifs(name.c_str());

	if (!ifs)
	{
		throw std::runtime_error("Can't open input file!\n");
	}

	Item input;
	while (ifs >> input)
	{
		v.emplace_back(input);
	}

	std::cout <<"Initialized with: "<< v.size() <<" elements.\n";
}

//--------------------------------------------------------------------

template <class Container>
void print(Container& v)
{
	std::cout <<"\n";
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		std::cout << *i <<'\n';
	}
	std::cout <<"\n";
}

//--------------------------------------------------------------------

template <class Container, class Iter, class T>
void insert(Container& v, Iter iter, T val)
{
	v.insert(iter, val);
}
//--------------------------------------------------------------------

struct find_name 
{
    find_name(const std::string& t) 
		: target(t)
	{
	
	}

    bool operator() (const Item& src) const 
	{ 
		return src.name == target; 
	}

    std::string target;
};

//--------------------------------------------------------------------

struct find_id
{
    find_id(int i) 
		: target(i)
	{
	
	}

    bool operator() (const Item& src) const 
	{ 
		return src.id == target; 
	}

    int target;
};

//--------------------------------------------------------------------

template <class Container, class T>
void erase_name (Container& v, const T& name)
{
	auto found = std::find_if(v.begin(), v.end(), find_name(name));

	if (found != v.end())
	{
		v.erase(found);
	}
	else
	{
		std::cout <<"\nName: "<< name <<" not found!\n";
	}
}

//--------------------------------------------------------------------

template <class Container, class T>
void erase_id (Container& v, T id)
{
	auto found = std::find_if(v.begin(), v.end(), find_id(id));

	if (found != v.end())
	{
		v.erase(found);
	}
	else
	{
		std::cout <<"\nName: "<< id <<" not found!\n";
	}
}

//--------------------------------------------------------------------


void test_vector()
{
	// 1.
	std::vector<Item> items;
	initialize_items(items);
	print(items);

	// 2.
	std::sort(items.begin(), items.end(), Cmp_Name());
	print(items);

	// 3.
	std::sort(items.begin(), items.end(), item_by_id);
	print(items);

	// 4.
	std::sort(items.begin(), items.end(), [] (const Item& lhs, const Item& rhs) { return lhs.value > rhs.value; });
	print(items);

	// 5. 
	std::vector<Item>::iterator i = items.begin();
	insert(items, i, Item("horse shoe", 99, 12.34));
	insert(items, i, Item("Canon S400", 9988, 499.95));
	print(items);

	// 6.
	std::string name("horse shoe");
	erase_name(items, name);
	print(items);

	name = "Canon S400";
	erase_name(items, name);
	print(items);

	// 7.
	int id = 0;
	erase_id(items, id);
	print(items);

	id = 1;
	erase_id(items, id);
	print(items);
}

//--------------------------------------------------------------------

void test_list()
{
	std::cout << "\nPart 8\n";
	//. 8
	std::list<Item> items2;
	initialize_items(items2);
	print(items2);

	items2.sort(Cmp_Name());
	// std::sort(items2.begin(), items2.end(), Cmp_Name());
	print(items2);

	items2.sort(item_by_id);
	print(items2);

	items2.sort([] (const Item& lhs, const Item& rhs) { return lhs.value > rhs.value; });
	print(items2);

	std::list<Item>::iterator i2 = items2.begin();
	insert(items2, i2, Item("horse shoe", 99, 12.34));
	insert(items2, i2, Item("Canon S400", 9988, 499.95));
	print(items2);

	std::string name2("horse shoe");
	erase_name(items2, name2);
	print(items2);

	name2 = "Canon S400";
	erase_name(items2, name2);
	print(items2);

	int id2 = 0;
	erase_id(items2, id2);
	print(items2);

	id2 = 1;
	erase_id(items2, id2);
	print(items2);
}

//--------------------------------------------------------------------

int main()
{
	try
	{
		test_vector();
		test_list();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}