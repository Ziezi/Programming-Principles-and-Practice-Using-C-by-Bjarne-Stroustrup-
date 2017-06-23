/*
	TITLE	   Sum to 30			   sumTo30.cpp
	Objective: Are any 3 of the following numbers:
               1,3,5,7,9,13,15
               summing up to 30.
		Input: -
	   Output: The triples that sums up to 30.
		 Date: 08.04.2015
	   Author: Chris B. Kirov
*/

#include"stdafx.h"
int main(){
	cout << "Find which three numbers from the following: 1,3,5,7,9,13,15.\n";
	cout << "Sum up to 30.\n";

	vector<int>nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(9);
	nums.push_back(13);
	nums.push_back(15);

	int sum=0;
	int first=0;
	int second=0;
	int third=0;

	for(int i=0; i < nums.size(); ++i){
		for (int j =0; j < nums.size(); ++j){
			for (int k=0;  k < nums.size(); ++k){
				sum = nums[i] + nums[j] + nums[k];
				if (sum==30){ cout << first << ": " << second << ": " <<  third << '\n'; break; }
			}	
		}
	}
	
	cout << "\nNo such triplet exists.\n";
	getchar();
	
	return 0;
}