/* 
   TITLE	       Reading data into vector object   vect_temp.cpp
   COMMENT
 		Objective: Introduce vector objects and
                   their member functions for number manipulations.
 			Input: Requests a number. 
 		   Output: Prints the average value and median or the input sequence of numbers(temperatures).
		   Author: Chris B. Kirov
		     Date: 01.10.2015
*/
#include "../../std_lib_facilities.h"

int main(){
	// prompt message
	cout << "\tCalculate mean value and median of sequence of temperature values." << endl;
	cout << "\n\n\nType temperatures values as floating point numbers." << endl;
	cout << "Press ENTER to confirm and RANDOM LETTER for input termination." << endl;
	cout << "\nType temperature value: " << endl;
	// input
	vector<double>temps;
	double temp;
    while (cin >> temp) temps.push_back(temp);

	if (temps.size() = 0) cout << "\n\tNo data!\n\n\n" << endl;
	else if (temps.size() = 1){
		cout << "\n\tAverage Temperature: " << temps[0] << endl;
		cout << "\n\tMedian Temperature: " << temps[0] << endl;
		cout << "\n\n\n" << endl;
	}else{
		// mean value calculation	
		double sum = 0;
		for (int i = 0; i < temps.size(); ++i) sum += temps[i]; 
			
		double tmean = 0;
		tmean = sum / temps.size();
		cout << "\n\tAverage Temperature: " << tmean << endl;
		// median calculation
		int par = temps.size() % 2;	
		// parity check for the sample size: remainder = 0 => sample size is even
		// odd sample size: median = value of the middle element  
		if (par == 1){
			sort(temps.begin(), temps.end());
			// defined to return integer from the integer division 
			int middle = (temps.size() / 2) + 1;										 
			cout << "\n\tMedian Temperature: " << temps[middle-1] << endl;
			cout << "\n\n\n" << endl;
		}else if (par == 0){
			// even sample size: median = average of the two middle values
			sort(temps.begin(), temps.end());
			int nth = temps[(temps.size() / 2)-1];							 
			int nthpo = temps[temps.size() / 2];
			double tmedian = (nth + nthpo) / 2;
			cout << "\n\tMedian Temperature: " << tmedian << endl;
			cout << "\n\n\n" << endl;
		}
	}
	getchar();
	return 0;
}
