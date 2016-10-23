/****************************************************************************************
 ** Project 2 - Group 32
 ** CS325-400 F16
 **
 ** Fahmy Mohammed
 **
 ** Description - Calculates minimum coins needed for a given change value. Algorithm works
 **               recursively using a divide and conquer approach.
 ****************************************************************************************/

#ifndef ChangeSlow_hpp
#define ChangeSlow_hpp

#include <limits.h>
#include <vector>

using std::vector;

int* changeslow(int coins[], int coinsSize, int changeRequested, int &minCoins);
vector<int> changeslowDC(int coins [], int changeRequested, int coinsSize);
int elementSum(vector<int> vect1, vector<int> vect2);

#endif 
