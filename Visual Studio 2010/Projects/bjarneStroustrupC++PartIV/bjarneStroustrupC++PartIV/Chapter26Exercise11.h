/* 
	TITLE		   Matrix addition complexity and efficiency       Chapter26Exercise11.h
	COMMENT
		Objective: Time the sum example from §26.6 with m being square matrices 
				   with dimensions 100, 10.000, 1.000.000, and 10.000.000.
				   Use random element values in the range [-10: 10). 
				   Rewrite the calculation of v to use a more efficient 
				   (not 0 (n^2)) algorithm and compare the timings.  

				   Naive approach:
				   Size: 100. Time: 0.07 [s]. Sum = 0.97
				   Size: 10000. Time: 44.22 [s]. Sum = 25571.90
				   Abort: Invalid allocation size 65000 GB (1x10e12 double).

				   Summed area table:
				   Size: 100. Time: 0 [s]. Sum = 0.97
				   bad allocation
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 08.06.2017
*/
#ifndef Chapter26Exercise11_h
#define Chapter26Exercise11_h

struct Measurement
{
	Measurement (int s, double t) 
		: size(s), time(t)
	{
	
	}

	int size;
	double time;
};

//---------------------------------------------------------------------------------------

void write_to_file(std::ofstream& ofs, std::vector<Measurement>& d)
{
	ofs <<"Size[Elements]\t\tTime[sec]\n";
	for (auto i = 0; i < d.size(); ++i)
	{
		ofs << d[i].size <<"\t\t"<< d[i].time;

		if (i < d.size() - 1)
		{
			ofs <<'\n';
		}
	}
}

//---------------------------------------------------------------------------------------

// Floating point number within: [min : max]
double random_double (double min, double max) 
{ 
	return min + static_cast<double>(rand()) / static_cast<double>(RAND_MAX/(max - min)); 
}

//---------------------------------------------------------------------------------------
 
double our_random()
{
	return random_double (-10, 10); 
}

//---------------------------------------------------------------------------------------

// Creates a matrix with random doubles with values within [-10:10)
void populate_matrix(Numeric_lib::Matrix<double, 2>& m)
{
	std::generate(m.data(), m.data() + m.size(), our_random); 
}

//---------------------------------------------------------------------------------------

// Sum elements in m[n]; Complexity: O(n)
double row_sum (Numeric_lib::Matrix<double, 2>& m, int n)
{
	double sum = 0;
	int size = m.dim2();
	for (int i = 0; i < size; ++i)
	{
		sum += m[n][i];
	}
	return sum;
}

//---------------------------------------------------------------------------------------

// Sum elementes in m [0: n); Complexity: O(n^2)
double row_accum (Numeric_lib::Matrix<double,2>& m, int n)
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += row_sum(m, i);
	}
	return sum;
}

//---------------------------------------------------------------------------------------

/*
	Creates (and returns a pointer to) Summed Area Table, 
	i.e. matrix whose element is the cumulative sum of the
	previous (upper and left) elements.

	Complexity: O(n^2)
*/
Numeric_lib::Matrix<double,2>* generate_summed_area_table(Numeric_lib::Matrix<double,2>& m)
{
	Numeric_lib::Matrix<double,2>* sat = new Numeric_lib::Matrix<double,2>(m.dim1(), m.dim2());

	// copy first row of the matrix
	(*sat)[0] = m[0];

	// accumulate sum column-wise 
	for (auto row = 1; row < m.dim1(); ++row) 
	{
		for (auto column = 0; column < m.dim2(); ++column)
		{
			(*sat)[row][column] = m[row][column] + (*sat)[row - 1][column];
		}
	}

	// accumulate sum row-wise
	for (auto row = 0; row < m.dim1(); ++row) 
	{
		for (auto column = 1; column < m.dim2(); ++column)
		{
			(*sat)[row][column] += (*sat)[row][column - 1];
		}
	}

	return sat;
}

//---------------------------------------------------------------------------------------

/*
	Complexity: O(1)
	Summation is reduced to accessing a value of the 2D matrix.
*/
double sum_all_elements(Numeric_lib::Matrix<double,2>* sat)
{
	return (*sat)[sat->dim1() - 1][sat->dim2() - 1];
}

//---------------------------------------------------------------------------------------

void test_sum(std::vector<Measurement>& data)
{
	srand((unsigned int)time(0));

	int RAM_size = 6400;  
	for (auto size = 100; size <= RAM_size; size *= 2)
	{
		std::cout <<"Memory to be consumed: " << std::pow(double(sizeof(double) * size), 2) / 1000000000 <<"[GB]\n";

		Numeric_lib::Matrix<double, 2>* m = new Numeric_lib::Matrix<double, 2>(size, size);
		populate_matrix(*m);

		// first test
		std::clock_t t = clock();

		double total_sum = row_accum(*m, m->dim1());

		t = clock() - t;
		double time = double(t) / CLOCKS_PER_SEC;

		std::cout <<"Size: " << size <<" elements. Time: "<< time  <<" [s]. Sum = "<< total_sum <<'\n';
		 
		data.push_back(Measurement(size, time));
	}

	/*
	// O(1) no data gathered 
	for (auto size = 100; size <= RAM_size/2; size *= 2)
	{
		std::cout <<"Memory to be consumed: " << 2 * std::pow(double(sizeof(double) * size), 2) / 1000000000 <<"[GB]\n";

		Numeric_lib::Matrix<double, 2>* m = new Numeric_lib::Matrix<double, 2>(size, size);
		populate_matrix(*m);

		// second test
		Numeric_lib::Matrix<double,2>* sat = generate_summed_area_table(*m);

		std::clock_t t2 = clock();

		double total_sum2 = sum_all_elements(sat);

		t2 = clock() - t2;

		double time2 = double(t2) / CLOCKS_PER_SEC;

		std::cout <<"Size: " << size <<" elements. Time: "<< time2 <<" [s]. Sum = "<< total_sum2 <<'\n';
	}
	*/
}


#endif 