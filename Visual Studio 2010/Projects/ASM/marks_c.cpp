// TITLE  C program calling assembly procedure and vise versa marks_c.cpp
// COMMENTS
//			Objective: To illustrate mix-mode program calling 
//				Input: Requests an array of integers.
//			   Output: Prints the: Minimum, Maximum and Average 

#include <stdio.h>
#define CLASS_SIZE 50

int main(void)
{
	int		marks[CLASS_SIZE];
	int		minimum, maximum, average;
	int		class_size, i;
	int		find_avg(int, int);
	extern  void stats(int*, int, int*, int*, int*);

	printf("Please enter class size (<50): ");
	scanf("%d", &class_size);
	printf("Please enter marks: ");
	for(i=0; i<class_size; i++) {scanf("%d", &marks[i]);}

	stats(marks, class_size, &minimum, &maximum, &average);
	printf("Minimum = %d, Maximum = %d, Average = %d\n", minimum, maximum, average);

	return 0;
}

// Funtion: find_avg - returns rounded average required by the assembly procedure STATS in file marks_a.asm

int find_avg(int total, int number)
{
	return((int)((double)total/number + 0.5));
}