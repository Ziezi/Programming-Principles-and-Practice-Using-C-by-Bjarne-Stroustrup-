/*
	TITLE		   Programming Languages Connection			Chapter22Exercise16.h
	COMMENT
		Objective: Modify the program from the previous exercise so that it reads a file of
				   (name,year,(ancestors)) tuples, such as (Fortran,19S6,()), (Algol,1960,(Fortran))
				   , and (C++,198S,(C,Simula)), and graphs them on a timeline with arrows from 
				   ancestors to descendants. Use this program to draw improved versions of the
				   diagrams in §22.2.2 and §22.2.7. 
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 10.04.2017
*/

#ifndef Chapter22Exercise16_h
#define Chapter22Exercise16_h

/* Unweighted & Directed Node */
class Node
{
public:
	Node() 
		: name(), year(), ancestor_node_names() { }

	Node(const std::string& n, int y)
		: name(n), year(y) { }

	Node(const std::string& n, int y, const std::vector<std::string>& a)
		: name(n), year(y), ancestor_node_names(a) { }

	Node(const Node& src)
		: name(src.name), year(src.year), ancestor_node_names(src.ancestor_node_names) { }

	Node& operator= (const Node& src)
	{
		Node temp(src);
		swap(temp);
		return *this;
	}

	void swap(Node& src)
	{
		std::swap(src.name, name);
		std::swap(src.year, year);
		std::swap(src.ancestor_node_names, ancestor_node_names);
	}

	void add_edge(const std::string& n) { ancestor_node_names.push_back(n); }

	size_t edge_number(void) { return ancestor_node_names.size(); }

	void print_edges(void) 
	{ 
		if (ancestor_node_names.size() == 0)
		{
			std::cout <<" none\n";
			return;
		}

		for (size_t i = 0; i < ancestor_node_names.size(); ++i)
		{
			std::cout << ancestor_node_names[i] <<'\n'; 
		}
	}

	void set_year(int y) { year = y; }
	void set_name(const std::string& n) { name = n; }

	int get_year(void) const { return year; }
	const std::string& get_name(void) const { return name; }

//private:
	std::string name;
	int year;
	// nodes are found by names; if weighted pairs<int, std::string>
	std::vector<std::string> ancestor_node_names;
};

//-------------------------------------------------------------------------------------------------------

void swap(Node& lhs, Node& rhs)
{
	lhs.swap(rhs);
}

//-------------------------------------------------------------------------------------------------------

/* Sort by years to create a chronological graphical representation */

struct less_than_Node
{
	inline bool operator() (const Node& lhs, const Node& rhs) const  { return lhs.get_year() < rhs.get_year(); }
};

//-------------------------------------------------------------------------------------------------------

/* Unweighted & Directed Graph */
class Graph
{
public:
	Graph() 
		: nodes() { }

	Graph(const std::vector<Node>& n)
		: nodes(n) { }

	Graph(const Graph& src)
		:	nodes(src.nodes) { }

	Graph& operator= (const Graph& src)
	{
		Graph temp(src);
		swap(temp);
		return *this;
	}

	void swap(Graph& src)
	{
		std::swap(src.nodes, nodes);
	}

	void add_node(const Node& n) { nodes.emplace_back(n); }

	void add_node(const std::string& node_name, int node_year) { nodes.push_back(Node(node_name, node_year)); }

	size_t get_node_index(const std::string& node_name) 
	{
		for (size_t i = 0; i < nodes.size(); ++i)
		{
			if (nodes[i].get_name() == node_name)
			{
				return i;
			}
		}
		return 0;
	}

	// unweighted & directed edge
	void add_edge(const std::string& src_node_name, const std::string& dest_node_name)
	{
		/*
		auto it = std::find(nodes.begin(), nodes.end(), [src_node_name](const Node& n) { return n.get_name() == src_node_name; });

		if (it != nodes.end())
		{
			it->add_edge(dest_node_name);
		}
		else
		{
			std::cerr << "No node with name: " << src_node_name <<'\n';
		}
		*/

		for (size_t i = 0; i < nodes.size(); ++i)
		{
			if (nodes[i].get_name() == src_node_name)
			{
				nodes[i].add_edge(dest_node_name);
			}
		}
		// if undirected, additionally do: find_node(dest_node_name) and add_edge(src_node_name)
	}
	 
	void sort_graph(void) { std::sort(nodes.begin(), nodes.end(), less_than_Node()); }

	size_t get_node_number(void) { return nodes.size(); }

	size_t get_total_edge_number(void) 
	{
		size_t edges_number = 0;

		for (size_t i = 0; i < nodes.size(); ++i)
		{
			edges_number += nodes[i].edge_number();
		}
		return edges_number;
	}

	/* directed graph = edges / (node * (node - 1)) E [0, 1], where 1 - complete, dense graph */
	float get_graph_density(void)
	{
		float edges = get_total_edge_number();
		float nodes = get_node_number();

		return edges / (nodes * (nodes - 1));  
	}

	void print_nodes(void)
	{
		for (size_t i = 0; i < nodes.size(); ++i)
		{
			std::cout << nodes[i].get_name() <<": "<< nodes[i].get_year() <<'\n';
		}
	}

// private:
	std::vector<Node> nodes;
};

//-------------------------------------------------------------------------------------------------------

void swap(Graph& lhs, Graph& rhs)
{
	lhs.swap(rhs);
}

//-------------------------------------------------------------------------------------------------------

/* forward declaration */
void get_node(std::istream& is, Node& n);

/* input format: (name , year , ancestor_name1 , ancestor_name2 , ancestor_name3 , ... )  */
std::istream& operator>> (std::istream& is, Node& n)
{
	if (!is)
	{
		return is;
	}

	Node node;

	try
	{
		get_node(is, node);
	}
	catch (std::runtime_error& r)
	{
		std::cout <<"Error!!!\n";
		std::cerr << r.what() <<'\n';
		
		is.setf(std::ios_base::failbit);
		return is;
	}

	n = node;
	
	return is;
}

//-------------------------------------------------------------------------------------------------------

/* specifies the allowed name charactes after the first */
bool is_allowed_name_char(char t)
{
	static std::string allowed("+#/.");

	if (allowed.find(t) != std::string::npos || isspace(t) || isalnum(t)) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

//-------------------------------------------------------------------------------------------------------

void is_char(std::istream& is, char t, const std::string& error_msg)
{
	char c;
	is.get(c);

	if (c != t)
	{
		std::runtime_error(std::string(error_msg));
	}
}

//-------------------------------------------------------------------------------------------------------

/* extracts strings from variable length input format: (name1,name2,name3,...) */
void get_ancestors(std::istream& is, Node& n)
{
	 is_char(is, '(', "get_ancestors: '(' expected!");

	 char c;
	 while (is.get(c) && c != ')')
	 {
		if (isalpha(c))
		{
			std::string name(1, c);

			while (is.get(c) && is_allowed_name_char(c))
			{
				name += c;
			}
			is.putback(c);

			n.add_edge(name);
		}

		is_char(is, ',', "get_ancestors: ',' expected!"); 
	 }
	 
	 is.putback(c);
	 is_char(is, ')', "get_ancestors: ')' expected!");
}

//-------------------------------------------------------------------------------------------------------

void get_year(std::istream& is, Node& n)
{
	char c;
	is.get(c);

	if (isdigit(c))
	{
		is.putback(c);

		int year;
		is >> year;
		n.set_year(year);
	}
}

//-------------------------------------------------------------------------------------------------------

void get_name(std::istream& is, Node& n)
{
	char c;
	is.get(c);

	if (isalpha(c))
	{
		std::string name(1, c);

		while (is.get(c) && is_allowed_name_char(c))
		{
			name += c;
		}

		is.putback(c);

		n.set_name(name);
	}
	else
	{
		std::runtime_error("get_name: alphabetic character expected!\n");
	}
}

//-------------------------------------------------------------------------------------------------------

void get_node(std::istream& is, Node& n)
{
	try
	{
		is_char(is, '(', "get_node: '(' expected!");

		get_name(is, n);

		is_char(is, ',', "get_node: ',' expected!"); 

		get_year(is, n);

		is_char(is, ',', "get_node: ',' expected!"); 

		get_ancestors(is, n);

		is_char(is, ')', "get_node: ')' expected!");
	}
	catch (std::runtime_error& r)
	{
		std::cerr << r.what() <<'\n';
		throw std::runtime_error("get_node: wrong input!");
	}
}

#endif