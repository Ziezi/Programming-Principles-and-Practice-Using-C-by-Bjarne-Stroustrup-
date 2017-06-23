/*
	TITLE			   Redirect standard I/O	 Chapter10Exercise10.cpp
	"Software - Principles and Practice using C++" by Bjarne Stroustrup"
	COMMENT
			Objective: Implement class that redirects standard I/O; Using C++11 library.
				Input:   
			   Output:  
			   Author: Chris B. Kirov
			     Date: 06.05.2015
*/ 
#include"stdafx.h"
/*
	Function: isFileName();
	Use: bool filename = isFileName(const string& file)
	This function checks if the end of the string
	is a valid file extension.
*/
bool isFileName(const string& file){
	if(file.size()<4)return false;
	static vector<string>fileExtensions;
	fileExtensions.push_back(".txt");
	fileExtensions.push_back(".dat");

	for (size_t i=0; i<fileExtensions.size(); ++i){
		if(fileExtensions[i]== file.substr(file.size()-4,4)) return true;
	}
	return false;
}

// Class representing I/O 
class InputOutput{
public:
	// pointers to I/O stream buffers
	streambuf *cinbuf;
	streambuf *coutbuf;  

	// I/O streams to redirect stdI/O to file
	ifstream in;
	ofstream out;

	// constructor initializing pointer to standard I/O
	InputOutput(): cinbuf(cin.rdbuf()), coutbuf(cout.rdbuf()) { } 

	// modifying member function
	void redirectInputToReadFile();
	void resetInput(){cin.rdbuf(cinbuf);};
	void redirectOuputToWriteFile();
	void resetOutput(){cout.rdbuf(coutbuf);};

	// non-modifying member function
	bool isStandardInput(){return (cinbuf==cin.rdbuf());};
	bool isStandardOutput(){return (coutbuf==cout.rdbuf());};
}IO;


/*
	Function: redirectInputToReadFile();
	Use: void redirectInputToReadFile(void);
	This function redirects the cin
	to read from file.
*/
void InputOutput::redirectInputToReadFile(){
	Token t= ts.get();

	if(t.kind == fileNameToken){
		// creates input stream and attaches it to the typed name
		in.open(t.name.c_str(),ios::in);
		if(!in) error("Cannot open file: ", t.name);
		// redirects cin to input stream: in
		cin.rdbuf(in.rdbuf());
	}
}

/*
	Function: redirectOuputToWriteFile();
	Use: void redirectOuputToWriteFile(void);
	This function redirects the cout
	to write to file.
*/
void InputOutput::redirectOuputToWriteFile(){
	Token t= ts.get();
	cout << "Token in redirectOuputToWriteFile(): " <<" t.kind: " <<t.kind <<" t.name: " <<t.name << '\n';
	if(t.kind == fileNameToken){
		// creates input stream and attaches it to the typed name
		out.open(t.name.c_str(),ios::out);
		if(!out) error("Cannot open file: ", t.name);
		// redirects cout to input stream: out, (by rewireing the buffers?)
		cout.rdbuf(out.rdbuf());
	}
}

