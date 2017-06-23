/*
	TITLE			 Read numbers from file and sum         	Chapter10Exercise1.h
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Write a function that reads a file (filled with whitespace-separated numbers)
			           and sum them.
				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 05.04.2015
*/

/*
	Function: populate_file();
	 
	It creates a file and 
	populates it with values
	separated by white space.
*/
void populate_file(std::string& n)
{
	std::ofstream ofs(n.c_str());
	if(!ofs)
	{
		std::cerr <<"File cannot be openned.\n";
	}

	int value = 1;
	for (int i = 0; i < 100; ++i)
	{	
		ofs << value << " ";
	}
}
//--------------------------------------------------------------------

/*
	Function: fill_vector();

*/
 void fill_vector(std::istream& is, std::vector<int>& v)
{
		if(!is)
		{
			std::cerr <<"Can't open input stream!\n";
		}

		std::string line;
		while(getline(is, line))
		{
			std::stringstream ss(line);
			int number;

			while (ss >> number)
			{
				v.emplace_back(number);
			}
		}
}
//--------------------------------------------------------------------

/*
	Function: sum_vector();
	 
	It returns the sum of the
	vector elements.
*/
int sum_vector(std::vector<int>& v)
{
	int sum = 0;
	for (size_t i = 0; i < v.size(); ++i)
	{
		sum += v[i];
	}
	return sum;
}
