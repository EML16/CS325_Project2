/*****************************************************************************************
 ** Program Filename:  changegreedy.cpp
 ** Author:  Meredith Kiessling  (Project 2 - Group 32)
 ** Date:  10.21.2016
 ** Description: function computes minimum number of coins necessary to make change from
 ** 			amount A. Function returns an array, containing the amount of each
 ** 			coin denomination used and total number of coins used
 ****************************************************************************************/

#include"changegreedy.hpp"


int* changegreedy(int *coin, int n, int amount, int &nCoins){
	//v = value array containing the number of each type of coin
	int *v = new int [n];

	//Initialize array to 0
	for (int i = 0; i < n; i++) {
		v[i] = 0;
	}

	int coins = 0;  //used to hold the number of coins used to make change
	nCoins =0;
	int k = n;   //used to store current index

	//start at the end of the c[] array, working backwards.. selecting highest denomination
	while (amount) {
		k--;
		coins = 0;
		//while the denomination is less than the amount, keep subtracting
		while (coin[k] <= amount) {
			amount = amount - coin[k];
			coins++;
		}

		//store number of each coin used in v[]
		v[k] = coins;
		nCoins += coins;
	}

	return v;
}
