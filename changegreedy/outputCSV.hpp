/*****************************************************************************************
 ** Program Filename:  outputCSV.hpp
 ** Author:  Meredith Kiessling  (Project 2 - Group 32)
 ** Date:  10.21.2016
 ** Description: Program takes in a struct Result vector and prints each result
 ** 			result{number of coins, time}, name of the test case run, and name of
 ** 			function being tested to a csv file
 ****************************************************************************************/

#ifndef OUTPUTCSV_HPP_
#define OUTPUTCSV_HPP_

#include<vector>
#include<string>
#include<iostream>
#include"result.hpp"
using namespace std;


void outputResults(vector<Result> &result, string name);




#endif /* OUTPUTCSV_HPP_ */
