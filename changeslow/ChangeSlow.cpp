/****************************************************************************************
 ** Project 2 - Group 32
 ** CS325-400 F16
 **
 ** Fahmy Mohammed
 **
 ** Description - Calculates minimum coins needed for a given change value. Algorithm works
 **               recursively using a divide and conquer approach.
 ****************************************************************************************/

#include "ChangeSlow.hpp"


/****************************************************************************************
 ** Description: Calculates the minimum number of coins used for a given change value
 ** Parameters:  int coins[], int coinsSize, int changeRequested, int &minCoins
 ** Pre-Conditions: coins[] must contain coin values with at least a "1" coin
 ** Post-Conditions: Returns a vector containing count of each coin used
 ****************************************************************************************/
vector<int> changeslowDC(int coins [], int changeRequested, int coinsSize) {

    vector<int> coinCount (coinsSize, 0); //Holds count of each coin used. Initialized to 0
    
    //Check for change of 0
    if(changeRequested == 0)
        return coinCount;
    
    //Check if there is a coin that is the same as change requested
    for(int i = 0; i < coinsSize; i++)
    {
        if (coins[i] == changeRequested)
        {
            coinCount[i]++; //if coin = change, then increment count of coin
            return coinCount;
        }
    }
   
    int min = INT_MAX;
    
    //Loop through each coin
    for(int i = 0; i < coinsSize; i++)
    {
        //Only use coins that are less than change requested
        if(coins[i] < changeRequested)
        {
            //Minimum coins for i
            vector<int> subProblem1 = changeslowDC(coins, coins[i], coinsSize);
            // Minimum coins for K - i
            vector<int> subProblem2 = changeslowDC(coins, changeRequested - coins[i], coinsSize);
            
            int minCount = elementSum(subProblem1, subProblem2);
            
            //New minmum coins
            if(minCount < min)
            {
                min = minCount;
                for(int j = 0; j < coinsSize; j++) //Update coin count
                    coinCount[j] = subProblem1[j] + subProblem2[j];
            }
        }
    }
    return coinCount;
}

/****************************************************************************************
 ** Description: Sums up values in each element of both vectors
 ** Parameters:  vector<int> vect1, vector<int> vect2
 ** Pre-Conditions: Both vectors must contain ints
 ** Post-Conditions: Returns sum of all elements in boths vectors
 ****************************************************************************************/
int elementSum(vector<int> vect1, vector<int> vect2){
    int sum = 0;
    for(int i = 0; i < vect1.size(); i++)
        sum += vect1[i] + vect2[i];
    return sum;
}




