/* 
	TITLE	       Statistics        				Chapter27Exercise14.c 
	COMMENT
		Objective: Write a function that takes an array of ints as its 
				   input and finds the smallest and the largest clements; 
				   It should also compute the median and mean. 
				   Use a struct holding the results as the return value. 

			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 19.06.2017
*/
#include <stdio.h>		// printf()
#include <stdlib.h>		// qsort()
#include <stddef.h>		// size_t

typedef struct Statistics
{
	double min;
	double max;
	double median;
	double mean;
} Statistics;

//-----------------------------------------------------------------------

int compare(const void* lhs, const void* rhs)
{
	int* lptr = (int*) lhs;
	int* rptr = (int*) rhs;

	return (lptr - rptr);
}

//-----------------------------------------------------------------------

int accumulate(int data[ ], size_t size)
{
	size_t i = 0;
	int sum = 0;

	for (i; i < size; ++i)
	{
		sum += data[i];
	}

	return sum;
}

//-----------------------------------------------------------------------

Statistics* get_stats(int data[ ], size_t size)
{
	Statistics* stats = (Statistics*) malloc(sizeof(Statistics));
	int sum =  accumulate(data, size);

	if (stats == NULL)
	{
		perror("get_stats::bad malloc!\n");
		exit(-1);
	}

	qsort(data, size, sizeof(int), compare);

	stats->min = data[0];
	stats->max = data[size - 1];
	stats->median = data[size / 2]; // odd / even?
	stats->mean =  (double) sum / (double) size;

	return stats;
}

//-----------------------------------------------------------------------

void init_data(int** data, size_t size)
{
	size_t i = 0;

	for (i; i < size; ++i)
	{
		(*data)[i] = i - 5;
	}
}

//-----------------------------------------------------------------------

void print_data(int data[ ], size_t size)
{
	size_t i = 0;

	printf("{ ");
	for (i; i < size; ++i)
	{
		printf("%d", data[i]);

		if (i < size - 1)
		{
			printf(", ");
		}
	}
	printf(" }\n");
}

//-----------------------------------------------------------------------

int main()
{
	Statistics* stats = 0;
	size_t size = 10;
	int* data = (int*) malloc(sizeof(int) * size);

	init_data(&data, size);

	stats = get_stats(data, size);

	print_data(data, size);
	printf("Statistics:\nmin = %f\nmax = %f\nmedian = %f\nmean = %f\n", stats->min, stats->max, stats->median, stats->mean);

	free(data);
	free(stats);
	getchar();
}