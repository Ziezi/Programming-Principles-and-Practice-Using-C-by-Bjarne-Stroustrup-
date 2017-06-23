/*
	TITLE		    Set of pointers			 Chapter21Exercise6.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Redo §21.6.5 but with std::set<Fruit*> instead.
					Provide a comparison operation Fruit_comparison.
					std::set<Fruit*, Fruit_comparison>. 
					Discuss the differences between the two implementations.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 27. 02. 2017
*/
#include <iostream>
#include <string>
#include <set>
#include <iterator>

struct Date
{
enum Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

	Date (int y, Month m, int d) : year(y), month(m), day(d) { }
	Date (const Date& src) :  year(src.year), month(src.month), day(src.day) { }

int year;
Month month;
int day;
};

//--------------------------------------------------------------------------

std::ostream& operator<< (std::ostream& os, const Date& d)
{
	os << d.year <<"\t"<< d.month <<"\t"<< d.day;
	return os;
}

//--------------------------------------------------------------------------

struct Fruit
{
	Fruit(const std::string& n, int c, double u, int y, Date::Month m, int d)
		: name(n), count(c), unit_price(u), last_date_sale(y, m, d)
	{
	
	}

std::string name;
int count;
double unit_price;
Date last_date_sale;
};

//--------------------------------------------------------------------------

std::ostream& operator<< (std::ostream& os, const Fruit* f)
{
	os << f->name <<"\t"<< f->count <<"\t"<< f->unit_price <<"\t"<< f->last_date_sale;
	return os;
}

//--------------------------------------------------------------------------

struct Fruit_order
{
	bool operator() (const Fruit* lhs, const Fruit* rhs) const
	{
		return lhs->name < rhs->name;
	}
};

//--------------------------------------------------------------------------

int main()
{
	try
	{
		std::set<Fruit*, Fruit_order> greengrocers_sales;
		greengrocers_sales.insert(new Fruit("Orange", 50, 2.40, 2017, Date::Month::feb, 1));
		greengrocers_sales.insert(new Fruit("Banana", 100, 3.15, 2017, Date::Month::feb, 2));
		greengrocers_sales.insert(new Fruit("Ananas", 5, 4.04, 2017, Date::Month::feb, 3));
		greengrocers_sales.insert(new Fruit("Kiwi", 25, 1.12, 2017, Date::Month::feb, 6));

		std::copy(greengrocers_sales.begin(), greengrocers_sales.end(), std::ostream_iterator<Fruit*>(std::cout, "\n"));
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}