/*
	TITLE			Templates				     Chapter19Drill.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: 
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 20.1.2016
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <typeinfo>

// 1. Define template struct
template<class T>
struct S
{
	// 2. add a constructor that initializes val
	S()
		: arr(new T[10])
	{ 
	
	}

	S(T v, int n = 10) 
		: val(v), arr(new T[n])
	{
	
	}

	// 5. add function template get() that returns val's value
	T& get ();

	// 9. add function that modifies val
	void set (const T& val);

	// 10 and 11. implement subscript operator []
	T& operator[] (int i);
	const T& operator[] (int i) const;

	// 6. make val private
private:
	T val;
	T *arr;
};

//--------------------------------------------------------------------------

// class S member functions implementations
// 5. add function template get() that returns val's value
template <class T>
T& S<T>::get () 
{
	return val;
}

//--------------------------------------------------------------------------

// 9. add function that modifies val
template <class T>
void S<T>::set(const T& v)
{
	val = v;
}

//--------------------------------------------------------------------------

// 10 and 11 implement subscript operator []
// write and read 
template<class T>
T& S<T>::operator [] (int i)
{
	return arr[i];
}

//--------------------------------------------------------------------------

// read-only ability
template<class T>
const T& S<T>::operator [] (int i) const 
{
	return arr[i];
}

//--------------------------------------------------------------------------

// non-member functions
// 4. read and print the values of the above defined structure
template<class T>
void print_S(S<T>& s)
{
	// T print_val = s.val;
	// modified after 6
	T print_val = s.get(); 

    std::cout << print_val <<'\n';
}

//--------------------------------------------------------------------------

// 12. defina a function that reads from std::cin into v
template<class T>
void read_val (T& v)
{
	std::string prompt("Type a value of type: ");
	std::cout << prompt << typeid(v).name() <<"\n>>";

	std::cin >> v;
}

//--------------------------------------------------------------------------

// 14. defina a ostream to cover the S<vector<int>> type
template<class T>
std::ostream& operator<< (std::ostream& os, std::vector<T>& v)
{	
	os <<"[";
	for (size_t i = 0; i < v.size(); ++i)
	{
		os <<" "<< v[i];
	}
	os <<"]";
	return os;
}

//--------------------------------------------------------------------------

template<class T>
std::istream& operator>> (std::istream& is, std::vector<T>& v)
{
	std::string input;
	getline(is, input);

	std::stringstream ss(input);

	T val;
	while (ss >> val)
	{
		v.push_back(val);			
	}
	
	return is;
}

//--------------------------------------------------------------------------

int main ()
{
	try
	{
		// 3. define variables S of different types
		// a. int
		int int_val = 1;
		S<int> sint(int_val);

		// b. double 
		double dou_val = 2.5;
		S<double> sdou(dou_val);

		// c. char
		char cha_val = 'a';
		S<char> scha(cha_val);

		// d. string
		std::string str_val = "abcd";
		S<std::string> sstr(str_val);

		// e. vector<int>
		std::vector<int> vec_val(5,5);
		S < std::vector<int> > svec(vec_val);
	
		// 4. read and print the values of the above defined structures
		// a. int
		print_S(sint);

		// b. double
		print_S(sdou);

		// c. char
		//print_S<char>(scha);

		// d. string
		print_S(sstr);

		// e. vector<int>
		std::cout <<"vector: " << svec.get().at(0) <<'\n';

		// 9. test set 
		int v = 1000;
		sint.set(v);
		print_S(sint);
	 
		// 10 and 11 test operator []
		// a. operator []
		sdou[0] = 1.25;
		std::cout << sdou[0] <<'\n'; 

		// 12.
		int val = 0;
		read_val<int>(val);
		std::cout <<"val: "<< val <<'\n';
		std::cin.ignore();

		// 13. use read_val() to read each of the variables 
		S<double> s1;
		read_val(s1[0]);
		std::cout <<"s1[0]: "<< s1[0] <<'\n';
		std::cin.ignore();

		S<int> s2;
		read_val(s2[0]);
		std::cout <<"s2[0]: "<< s2[0] <<'\n';
		std::cin.ignore();

		S<char> s3;
		read_val(s3[0]);
		std::cout <<"s3[0]: "<< s3[0] <<'\n';
		std::cin.ignore();

		S<std::string> s4;
		read_val(s4[0]);
		std::cout <<"s4[0]: "<< s4[0] <<'\n';
		std::cin.ignore();

		// 14.
		S<std::vector<int>> s5;
		read_val<std::vector<int>>(s5[0]);
		std::cout <<"s5[0]: "<< s5[0] <<'\n';
		std::cin.ignore();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	catch (...)
	{
		std::cerr << "Unhandled Exception\n";
	}
	getchar();
}