/*
	TITLE			   Sum integers from file   Chapter10Exercise11.h
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: This program reads file containing text and numbers
					   and sum only the numbers.
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Date: 07.05.2015
*/ 
 
/*
	Function: read_numbers();
	 
	It reads a file line by line,
	extracts all the whitespace
	separated tokens and from them
	it stores only the integers in
	the vector.
*/
void read_numbers(std::string& file_name, std::vector<int>& numbers)
{
	std::ifstream ifs(file_name.c_str());
	if (!ifs)
	{
		throw std::runtime_error("Can't open input file\n");
	}

	std::string line;
	while (getline(ifs, line))
	{
		std::stringstream ss(line);
		std::string token;

		while (ss >> token)
		{
			std::stringstream ss1(token);
			int number;

			if (ss >> number)
			{
				numbers.emplace_back(number);
			}
		}
	}
}
//-------------------------------------------------------------------------------

/*
	Function: sum_vector();


*/
int sum_vector(std::vector<int>& numbers)
{
	int sum = 0;
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		sum += numbers[i];
	}
	return sum;
}