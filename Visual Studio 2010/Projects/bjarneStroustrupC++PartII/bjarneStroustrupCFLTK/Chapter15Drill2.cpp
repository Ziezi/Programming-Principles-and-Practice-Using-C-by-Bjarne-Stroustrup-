/*
	TITLE		   Drill 2						    Chapter15Drill1.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: 1. Define a strcuct Person with string name and int age members.
				   2. Define a variable of type Person and initialize it with "Goofy" of age 63
				      and write it on the screen.
				   3. Define >>operator and <<operator for struct Person.
				   4. Define a constructor to initialize the members.
				   5. Make the representation of Person private and provide const members 
				      name() and age() to read the name and age.
				   6. Modify << & >>operator to the private status of the data member.
				   7. Modify constructor to check age [0, 150) and name != ;:"'[]*&^$#@!; 
				      use cerr.
				   8. Read a sequence of Person object into std::vector and print them to std output
				      test with correct and erroneous input.
				   9. Change the representation of Person to have both first and last name, make it an
				      error if only one is supplied, modify << and >>operators. (New class defined)
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

bool valid_input(std::string& n, int a);

// 1.
struct Person
{
	Person( )
		:name(" "), age(0)
	{
	
	}

	// 4.
	Person(std::string& n, int a)
		: name(n), age(a)
	{
		if (!valid_input(n, a))
		{
			throw std::invalid_argument("Person::constuctor: Invalid initialization argument!\n");
		}
	}

	// 5.
	std::string get_name() const { return name; }
	int get_age() const { return age; }
	
private:
	std::string name;
	int age;
};

// 2. 
std::istream& operator>> (std::istream& is, Person& p)
{
	if (!is) // stream in bad state
	{
		return is;
	}

	std::string n;
	int a;

	if (is >> n >> a) // return populated object
	{
		p = Person(n, a);

		return is; // allow chainig
	} 
	else // wrong input format
	{
		return is;
	}
}

std::ostream& operator<< (std::ostream& os, Person& p)
{
	// 6. 
	return os <<"Name: "<< p.get_name() <<", Age: "<< p.get_age();
}

// 7
bool valid_input(std::string& n, int a)
{
	if (a < 0 || a >= 150)
	{
		
		return false;
	}

	std::string test = "!= ; : \" ' [ ] * & ^ $ # @ !";
	for (size_t i = 0; i < test.size(); ++i)
	{
		for (size_t j = 0; j < n.size(); ++j)
		{
			if (test[i] == n[j])
			{
				return false;
			}
		}
	}
	return true;
}
//------------------------------------------------------------------------------------------------------

// 9.
bool valid_input2(std::string& fn, std::string& sn, int a);

struct Person2
{
	Person2()
		: first_name(""), second_name(""), age(0)
	{
	
	}

	Person2(std::string& fn, std::string& sn, int a)
		: first_name(fn), second_name(sn), age(a)
	{
		if (!valid_input2(fn, sn, a))
		{
			throw std::invalid_argument("Person::constuctor: Invalid initialization argument!\n");
		}
	}

	std::string get_first_name() const { return first_name; }
	std::string get_second_name() const { return second_name; }
	int get_age() const { return age; }

private:
	std::string first_name;
	std::string second_name;
	int age;
};

bool valid_input2(std::string& fn, std::string& sn, int a)
{
	if (a < 0 || a >= 150)
	{
		
		return false;
	}

	if (fn.size() == 0 || sn.size() == 0) // name not provided
	{
		return false;
	}

	std::string test = "!= ; : \" ' [ ] * & ^ $ # @ !";
	for (size_t i = 0; i < test.size(); ++i)
	{
		for (size_t j = 0; j < fn.size(); ++j)
		{
			if (test[i] == fn[j] || test[i] == sn[j])
			{
				return false;
			}
		}
	}
	return true;
}

std::istream& operator>> (std::istream& is, Person2& p)
{
	if (!is) // bad state
	{
		return is;
	}

	std::string fn, sn;
	int a;

	if (is >> fn >> sn >> a)
	{
		p = Person2(fn, sn, a);
		return is;
	}
	else // wrong input format
	{
		return is;
	}
}

std::ostream& operator<< (std::ostream& os, Person2& p)
{
	return os <<"First name: "<< p.get_first_name() 
		      <<", Second Name: " << p.get_second_name()
			  <<", Age: "<< p.get_age();
}


//------------------------------------------------------------------------------------------------------
int main()
{
	try 
	{
		// 1.
		//Person p;
		//p.name = "Goofy";
		//p.age = 63;
		//std::cout <<"Name: "<< p.name <<", Age: "<< p.age <<'\n';

		// 2.
		Person p2;
		std::cout <<"Type name and age separated by whitespace:\n";
		std::cin >> p2;

		std::cout <<"You've typed:\n";
		std::cout << p2 << std::endl;
	
	 
		// 8.
		std::vector<Person> people;

		std::string sentinel = "exit";

		while(true)
		{
			std::cout <<"Type name and age:\n";
			std::string input;
			getline(std::cin, input);

			if (input == sentinel)
			{
				break;
			}
			else if (input == "print")
			{
				for (size_t i = 0; i < people.size(); ++i)
				{
					std::cout << people[i] << "\n";
				}
			}

			std::stringstream ss(input);

			std::string n;
			int a;

			if (ss >> n >> a)
			{
				people.emplace_back(Person(n, a));
			}
			else
			{
				std::cout <<"Wrong input format!\n";
			}
		}
		
		// 9.
		Person2 p;
		std::cout <<"Type first name, first name and age separated by whitespace:\n";
		std::cin >> p;

		std::cout <<"You've typed:\n";
		std::cout << p << std::endl;

		getchar();
		getchar();
	}
	catch(std::invalid_argument& e)
	{
		std::cerr << e.what() <<"\n"; 
		getchar();
	}
	catch(...)
	{
		std::cerr << "Exception caught\n"; 
		getchar();
	}
	
}