/*
	TITLE		   Fields						 Chapter11TryThis4.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Implement a data table using fields to determine cell width / spacing.
			Input: - 
		    Ouput: -
		   Author: Chris B. Kirov
		     Data: 20.05.2015
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

/*
	Class Contact

	It stored the table data.
*/
class Contact
{
public:

	Contact(std::string f, std::string l, std::string t, std::string e)
		: first_name(f),  last_name(l), telephone_number(t), email(e)
	{
	
	}

	std::string first_name;
	std::string last_name;
	std::string telephone_number;
	std::string email;
};

void initialize_contacts(std::vector<Contact>& v);
void print_contacts(std::string label1, std::string label2, std::string label3, std::string label4, std::vector<Contact>& v);

//=======================================================================================================
int main()
{
	std::vector<Contact> contacts;

	initialize_contacts(contacts);

	print_contacts("First name", "Last name", "Phone", "E-mail", contacts);
}

//=======================================================================================================

/*
	Function: initialize_contacts();

*/
void initialize_contacts(std::vector<Contact>& v)
{
	std::string a[3] = {"Chris", "Juliya", "Manol"};
	std::string b[3] = {"Kirov", "Lozancheva", "Manolov"};
	std::string c[3] = {"00407435341467" ,"0036932058772", "003598812345678", };
	std::string d[3] = {"hristo_b_kirov@abv.bg", "lozanchevajuli@gmail.com", "manol_manolov@abv.bg"};

	for (size_t i = 0; i < 3; i++)
	{
		v.emplace_back(Contact(a[i], b[i], c[i], d[i]));
	}
}

//-------------------------------------------------------------------------------------------------------
/*
	Function: void printTable();
	 
	It prints the contents of the string arrays. 
*/
void print_contacts(std::string label1, std::string label2, std::string label3, std::string label4, std::vector<Contact>& v)
{
	const int horizontalLineLength = 74;

	// table 
	for (size_t i=0; i < horizontalLineLength ; i++) 
	{
		std::cout << '_';
	}
	std::cout << '\n';

	// title
	std::cout << "\n\t\t\t\tTable\n";

	// upper vertical border
	for (size_t i=0; i < horizontalLineLength ; i++) 
	{
		std::cout << '_';
	}
	std::cout << '\n';

	// labels
	std::cout << std::setw(10) << label1
			      <<'|'<< std::setw(15) << label2
				  <<'|'<< std::setw(20) << label3
				  <<'|'<< std::setw(25) << label4
				  <<'|'<< '\n'; 


	// table data
	for (size_t i = 0; i < v.size(); i++) 
	{
		std::cout << std::setw(10) << v[i].first_name 
			      <<'|'<< std::setw(15) << v[i].last_name 
				  <<'|'<< std::setw(20) << v[i].telephone_number
				  <<'|'<< std::setw(25) << v[i].email 
				  <<'|'<< '\n'; 
	}

	// lower vertical border
	for (size_t i=0; i < horizontalLineLength ; i++) 
	{
		std::cout << '_'; 
	}
	std::cout << '\n';
}