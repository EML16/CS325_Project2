/*****************************************************************************************
 ** Program Filename:  outputCSV.cpp
 ** Author:  Meredith Kiessling  (Project 2 - Group 32)
 ** Date:  10.21.2016
 ** Description: Program takes in a struct Result vector and prints each result
 ** 			result{number of coins, time}, name of the test case run, and name of
 ** 			function being tested to a csv file
 ****************************************************************************************/

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<cstdlib>
#include"outputCSV.hpp"
#include<iomanip>
using namespace std;


/****************************************************************************************
 ** Function:  outputResults(..)
 ** Description: prints results (amount, number of coins used to make change, time..
 ** 			 ...test case name, name of function being tested) to csv file for data
 ** 			 processing
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
****************************************************************************************/
void outputResults(vector<Result> &result, string algorithmName) {
	ofstream outfile;
	string outputName = "proj2data.csv";
	outfile.open(outputName, ios::app);
	outfile << endl;


	//USE ITERATOR to print name of algorithm, change array & number of coins
	for (vector<Result>::iterator it = result.begin() ; it != result.end(); ++it) {
		outfile << it->a << "," << it->numCoins << "," << fixed << setprecision(10) << it->time << "," << it->testCaseName
				<< "," << algorithmName << endl;
	}


	outfile.close();
}
