/*
	TITLE			File Handler          Chapter19Exercise12.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Design and implement a file handler that
					takes a string argument (file name),
					opens the file in the constructor and
					closes it in the destructor.

		     Input: -
			Output: - 
			Author: Chris B. Kirov
			  Date: 06. 2. 2016
*/

#ifndef CHAPTER19EXERCISE12_H
#define CHAPTER19EXERCISE12_H

class File_handle 
{
private:
	File_handle ();												// prevent default constructor
	File_handle (const File_handle& src);						// prevent copy creation
	File_handle& operator= (const File_handle& src );			// prevent copy assignment
public:
	explicit File_handle (std::string& file_name);				// constuctor
	~File_handle();												// destructor

	std::fstream& get_file() { return file; }					// access file

private:
	std::string file_name;										// data members
	std::fstream file;
};
//-------------------------------------------------------------------------------------------

// constructor
File_handle::File_handle(std::string& s)
	: file_name(s), file(std::fstream())
{
	file.open(file_name.c_str(), std::ios_base::in | std::ios_base::out |  std::ios_base::app);

	if (!file)
	{
		throw std::runtime_error("Can not open file: " + file_name);
	}
}

//-------------------------------------------------------------------------------------------

File_handle::~File_handle() 
{
	if (file.is_open())
	{
		file.close();
	}
}

//-------------------------------------------------------------------------------------------

class CFile_handle
{
private:
	CFile_handle ();											// prevent default constructor	
	CFile_handle (const CFile_handle&);							// prevent copy creation
	CFile_handle& operator= (const CFile_handle&);				// prevent copy assignment
public:
	CFile_handle (const std::string& n, const std::string& m);  // constructor		
	~CFile_handle ();											// destructor

	// modifying member function
	FILE* get_file () { return file; }
private:
	FILE* file;											// data member
};

//-------------------------------------------------------------------------------------------

CFile_handle::CFile_handle(const std::string& file_name, const std::string& mode = "r")
	: file(fopen(file_name.c_str(), mode.c_str()))
{
	if (!file)
	{
		throw std::runtime_error("Can not open file: " + file_name);
	}
}

//-------------------------------------------------------------------------------------------

CFile_handle::~CFile_handle()
{
	if (file) 
	{
		fclose(file);
	}
}

#endif 