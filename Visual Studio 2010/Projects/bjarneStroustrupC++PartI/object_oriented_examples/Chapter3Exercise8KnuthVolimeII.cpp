/*
	TITLE		Middle-square two digit numbers		KnuthVolumeIIChapter3Exercise8.cpp
	"The art of computer programming, Volume II" by Donald Knuth
	COMMENT
			Objective: Find the period of zero convergence of all 2-digit-seed randomly 
					   generated numbers using the middle square method.
					   !!! Method is not fully developed!!!
			Input: -
			Output: Prints the seed and the number of iterations till the randomly generated
					seqence converges to zero.
*/
//-------------------------------------------------------------------------------------------------
// Declaration segment
#include "stdafx.h"
#include <bitset>
int middleSquare(int seed);
unsigned k = 2;  
unsigned int w = sizeof(unsigned int); 

int middleSquareHashing(unsigned int seed);
vector<int> randomNums;
int numsCount=0;
int maxNumsCount =0;
int  maxSeed = 0;
//-------------------------------------------------------------------------------------------------
// Execution segment
int main()
{
	for (int i=5; i < 101 ; ++i)
	{ 
		cout <<" Seed: " << i << " Generated number: " << middleSquareHashing(i) << endl;
	}
	cout << "Longest convergence period: " << maxNumsCount << endl;
	system("pause");
	return 0;
}

//-------------------------------------------------------------------------------------------------
// Definition segment
/*
	Function: middleSquareHashing(seed);
	Use: int randomNumber = middleSquareHashing(seed);
	All inside computer arithmetic is done modulo W,
	where W = 2^w, w is the word size of the computer. 
	M is power of two: M=2^k. The middle-square hashing method, 
	to hash an integer x: h(x) = [M/W(x^2 * mod(W))].
	To multiply (x^2 * mod(W)) we just shift it bitwise
	by w-k, as W/K = 2^(w-k).
*/

int middleSquareHashing(unsigned int seed)
{
	++numsCount;
	if (maxNumsCount < numsCount) { maxNumsCount = numsCount; maxSeed=seed;}
	if (seed == 0) {cout << "ZERO" << endl; numsCount = 0; return 0;}
	if (seed == 4) {cout << "FOUR" << endl; numsCount = 0; return 0;}
	cout << "Number: " << seed << " Sequence length: "<< maxNumsCount << "Seed with max period: " << maxSeed <<endl;
	return middleSquareHashing((seed*seed) >> (w-k));
}

/*
	Unfinished!
	Function: middleSquare()
	Use : int randnom = middleSquare(seed)
	Internally, the function multiplies the 
	seed by itself, converts it to binary 
	representatio, extracts the middle 4 bits
	of the result, adds leading zeros to 
	restore it to the needed bit format,
	converts it back to integer and returns
	it as result.
*/

int middleSquare(int seed)
{
	int squaredSeed = seed*seed;
	string squaredSeedBitRep = to_string(bitset<sizeof(squaredSeed)> (squaredSeed));
	cout << "Seed: "<< seed << endl; 
	cout << "Seed squared: "<< squaredSeed << endl;
	cout << "Squared seed bit repsresentation: "<< squaredSeedBitRep  << endl;
	return 0;
}

