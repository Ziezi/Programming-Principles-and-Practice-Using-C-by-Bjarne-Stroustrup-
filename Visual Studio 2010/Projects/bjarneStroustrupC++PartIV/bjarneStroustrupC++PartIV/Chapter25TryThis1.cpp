/*
	TITLE		   Free store management	Chapter25TryThis1.cpp
	COMMENT
		Objective: Complete the program in §25.3.1 and print out 
				   the addresses and sizes of the objects created
				   to see:if and how "holes" appear on your machine. 
				   If you have time, you might draw memory layouts.  
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 09.05.2017
*/
#include <iostream>

struct Node
{
	Node(Node* n, Node* p)
		: next(n), prev(p)
	{
	
	}

	int data;
	Node* next;
	Node* prev;
};

//-----------------------------------------------------------------------

struct Device
{
	Device(const std::string& m, const std::string& n)
		: dev_msg(m), name(n)
	{
	
	}

	std::string dev_msg;
	std::string name;
};

//-----------------------------------------------------------------------

struct Message
{
	std::string msg;
	std::string src;
	std::string dest;
};

//-----------------------------------------------------------------------

Message* get_input(Device& d)
{
	Message* m = new Message();
	m->msg = d.dev_msg;
	m->src = d.name;

	return m; 
}

//-----------------------------------------------------------------------

int main()
{
	try
	{
		int iterations = 5;
		int i = 0;

		Device d("Device Message", "Random Peripheral");

		std::cout <<"Compact?:\n";
		while (i <= iterations)
		{
			Message* p = get_input(d);
			Node* n1 = new Node(nullptr, nullptr);
			Node* n2 = new Node(nullptr, nullptr);
			
			std::cout <<"p address: " << p <<" sizeof(object p): "<< sizeof(*p) <<'\n';
			std::cout <<"n1 address: " << n1 <<" sizeof(object n1): "<< sizeof(*n1) <<'\n';
			std::cout <<"n2 address: " << n2 <<" sizeof(object n2): "<< sizeof(*n2) <<'\n';

			delete p;
			
			getchar();

			++i;
		}

		i = 0;
		std::cout <<"With memory holes due to misalignment:\n";
		while (i <= iterations)
		{
			Message* p = get_input(d);

			Node* n1 = new Node(nullptr, nullptr);

			std::cout <<"p address: " << p <<" sizeof(object p): "<< sizeof(*p) <<'\n';
			std::cout <<"n1 address: " << n1 <<" sizeof(object n1): "<< sizeof(*n1) <<'\n';

			delete p;

			Node* n2 = new Node(nullptr, nullptr);

			std::cout <<"n2 address: " << n2 <<" sizeof(object n2): "<< sizeof(*n2) <<'\n';
			getchar();

			++i;
		}
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}