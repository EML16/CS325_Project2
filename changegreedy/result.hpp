/*****************************************************************************************
 ** Program Filename:  outputCSV.cpp
 ** Author:  Meredith Kiessling  (Project 2 - Group 32)
 ** Date:  10.21.2016
 ** Description: Structure used to hold the results of each test case
 ****************************************************************************************/

#ifndef RESULT_HPP_
#define RESULT_HPP_

#include<iostream>
#include<string>
using namespace std;


struct Result{
	int a;		//amount of change to be made into change
	int numCoins;	//number of coins used to make change
	float time;		//avg run-time
	string testCaseName;	//testcase name
};




#endif /* RESULT_HPP_ */
