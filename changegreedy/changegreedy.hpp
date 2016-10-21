/*****************************************************************************************
 ** Program Filename:  changegreedy.hpp
 ** Author:  Meredith Kiessling  (Project 2 - Group 32)
 ** Date:  10.21.2016
 ** Description: function computes minimum number of coins necessary to make change from
 ** 			amount A. Function returns an array, containing the amount of each
 ** 			coin denomination used and total number of coins used
 ****************************************************************************************/

#ifndef CHANGEGREEDY_HPP_
#define CHANGEGREEDY_HPP_

#include<iostream>
#include<string>

using namespace std;

int* changegreedy(int *coin, int n, int amount, int &nCoins);

#endif /* CHANGEGREEDY_HPP_ */
