#include<iostream>
#include<vector>
#include<limits>
#include<iterator>
#include "Algo.h"

Result changeslow(const int &A, const std::vector<int> &coins){
    //changeslow implementation goes here
    Result tmp = std::make_pair(0, std::vector<int>(coins.size(), 0));
    return tmp;
}
Result changegreedy(const int &A, const std::vector<int> &coins){
    //changegreedy implementation goes here
    Result tmp = std::make_pair(0, std::vector<int>(coins.size(), 0));
    return tmp;
}
Result changedp(const int &A, const std::vector<int> &coins){
    std::vector<int> optS(coins.size(), 0);
    int optV;

    std::vector<int> T(A+1, 0);    //A table to store the values of the optimal solutions to the subproblems
    std::vector<int> C(A+1, 0);    //A table to store the coin denominations used

	int j, q, k;
	
    for(int i = 1; i <=A; ++i){ //Build optimal solutions' values for subproblems
		j = 0;
        k = 0;
        q = std::numeric_limits<int>::max();     //Positive 'infinity'
        //While there are coins and the current coin is less than or equal to the current amount	
		while (j < coins.size() && coins.at(j) <= i){		
            if(T.at(i-coins.at(j)) + 1 <= q){
				q = T.at(i - coins.at(j)) + 1;      //Current optimal solution
                k = j;                              //The index of the coin denomination used in the current optimal solution
			}
			j++;
		}
        C.at(i) = k;     //Store the index of the coin denomination d used for the amount i in the expression T[i] = T[i-d] + 1
        T.at(i) = q;     //Store the value of the optimal solution of i;
	}
    //Calculate optimal solutions
    int n = A;
    while(n > 0) {
        k = C.at(n);
        optS.at(k)++;
        n -= coins.at(k);        
    }
    return std::make_pair(T.at(A), optS);
}

int getOptValue(const std::vector<int> &optSolution){
    int m = 0;
    for(int i = 0; i < optSolution.size(); ++i)
        m += optSolution.at(i);
    return m;
}
