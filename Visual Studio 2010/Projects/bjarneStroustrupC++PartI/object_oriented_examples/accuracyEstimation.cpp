/*
	TITLE			   Machine specific accuracy    accuracyEstimation.cpp
	COMMENT
			Objective: Estimating machine specific calculation accuracy
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Date: 1.10.2015
*/
#include "stdafx.h"
#include <stdio> 

int main(){
	roundingCheck1();
	
	roundingCheck2();
	
	selfSubstitutionForHighAccuracy();
	
	getchar();
	return 0;
}

void roundingCheck1(){
    cout  << "roundingCheck1.\n";
	cout  << "Type anything to start.\n";
	getchar();
	
	double step = 0.1;
	double testvalue = 0;
	for(int i=0; i < 100; i++){	
		testvalue += step;
		printf("testvalue= %.2f", testvalue);
	}
}

void roundingCheck2(){
	cout  << "roundingCheck2.\n";
	cout  << "Type anything to start.\n";
	getchar();
	
	double testvalue = 1;
	for(int i = 0; i < 1000; i++){	
		testvalue = i / 10.;
		printf("testvalue= %.2f", testvalue);
		printf(" i= %f \n", testvalue);
	}
}

void selfSubstitutionForHighAccuracy(){
	cout  << "selfSubstitutionForHighAccuracy\n";
	cout  << "Type anything to start.\n";
	getchar();
	// break condition of the type temp - x < epsilon, where epsilon is needed accuracy could be imposed
	// divergence avoidance could be provided by asserting x < unprobableValue
	long double x = 1 / 3.;
	for (int i = 0; i < 30; i++){
		double temp = (((9 * x) + 1) * x) - 1;
		x = temp;
		cout << "x= " << x << " i= " << i << endl;
	}
}

