/*****************************************************************************************
 ** Program Filename:  main.cpp
 ** Author:  Meredith Kiessling  (Project 2 - Group 32)
 ** Date:  10.21.2016
 ** Description: Program runs each test case outline in the project requirements (questions
 ** 			3, 4, 5) and prints to csv file the number of coins used to make change
 ** 			and average run-time
 ****************************************************************************************/


#include"result.hpp"
#include"changegreedy.hpp"
#include<vector>
#include "outputCSV.hpp"
#include<ctime>
#include<time.h>
#include<iomanip>
#include<cstdlib>
#include<limits.h>

using namespace std;

float getRunTime(int arr[], int size, int amount, int &coins);


int main() {

	//testCase1 (test a = 2010, 2015, 2020, ... 2200)
	int v1[] = {1, 5, 10, 25, 50};
	int size1 = 5;


	//testcase2 (test a = 2000, 2001, 2002,...,2200)
	int v2a[] = {1, 2, 6, 12, 24, 48, 60};
	int size2a = 7;
	int v2b[] = {1, 6, 13, 37, 150};
	int size2b = 5;

	//testcase3 (test a = 2000, 2001, 2002,...,2200)
	int v3[] = {1,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30};
	int size3 = 16;


	//TestCase 1:
	int numberCoins = 0;
	vector<Result> data;
	float avgTime;

	//testCase1
	for(int i = 2010; i <= 2200; i=i+10){
		int *res;
		//get result
		res = changegreedy(v1, size1, i, numberCoins);

		//get average run-time (runs each calculation 1000x and takes the average
		avgTime = getRunTime(v1, size1, i, numberCoins);

		//save result and average run-time
		data.emplace_back(Result { i, numberCoins, avgTime, "testCase1" });

		delete[] res;
	}



	//TestCase2a
	for (int i = 2000; i <= 2200; i++) {
		int *res;
		//get result
		res = changegreedy(v2a, size2a, i, numberCoins);

		//get average run-time (runs each calculation 1000x and takes the average
		avgTime = getRunTime(v2a, size2a, i, numberCoins);

		//save result and average run-time
		data.emplace_back(Result { i, numberCoins, avgTime, "testCase2a"});

		delete[] res;
	}

	//TestCase2b
	for (int i = 2000; i <= 2200; i++) {

		int *res;

		//get result
		res = changegreedy(v2b, size2b, i, numberCoins);

		//get average run-time (runs each calculation 1000x and takes the average
		avgTime = getRunTime(v2b, size2b, i, numberCoins);

		//save result and average run-time
		data.emplace_back(Result {i, numberCoins, avgTime, "testCase2b" });

		delete[] res;
	}


	//TestCase3
	for (int i = 2000; i <= 2200; i++) {
		int *res;

		//get result
		res = changegreedy(v3, size3, i, numberCoins);

		//get average run-time (runs each calculation 1000x and takes the average
		avgTime = getRunTime(v3, size3, i, numberCoins);

		//save result and average run-time
		data.emplace_back(Result {i, numberCoins, avgTime, "testCase3" });

		delete[] res;
	}


	outputResults(data, "greedy");

	return 0;

}

/****************************************************************************************
 ** Function:  getRunTime()
 ** Description: takes in parameters needed to run greedychange(). Runs the function X
 ** 			times, and returns average run-time
 ** Parameters:  int arr[], int size, int amoount, int &coins
 ** Pre-Conditions: arr[] ascending ordered array of coin denominations
 ** Post-Conditions:
****************************************************************************************/
float getRunTime(int arr[], int size, int amount, int &coins){
	clock_t t;
	float time;
	int *res;
	clock_t totalTicks = 0;


	for (int i = 0; i < 100; i++) {

		t = clock();
		res = changegreedy(arr, size, amount, coins);
		t = clock() - t;
		//cout << "t = " << t;
		totalTicks += t;
		//cout << "totalTicks = " << totalTicks << endl;
		delete[] res;
	}

	time = totalTicks / (float) CLOCKS_PER_SEC;

	float avgTime;

	avgTime = time/100;

	return avgTime;
}



