#include<iostream>
#include<vector>
#include<limits>
#include<iterator>
#include "Algo.h"
void  changedp(const int &A, const std::vector<int> &coins, std::vector<int> &optSolution) {
	std::vector<int> T(A+1);                 //A table to store the values of the optimal solutions to the subproblems
    Table solutions;      //an (A+1)-by-coins.size() table to store optimal solutions of subproblems

	T.push_back(0);         // Similar to T[0] = 0;
	T.push_back(1);         // Similar to T[1] = 1;

    solutions.push_back(std::vector<int>(coins.size(), 0));  //Initialize the first row, c[0][*], of the solution table to zero
    solutions.push_back(std::vector<int>(coins.size(), 0));  //Initialize the second row, c[1][*]
    solutions.at(1).at(0) = 1;                          //The first coin with denominator 1 is always of the solution when A=1

	int j, q, k, d;
	
    for(int i = 2; i <=A; ++i){ //Build optimal solutions for subproblems
		j = 0;
		
        q = std::numeric_limits<int>::max();     //Positive 'infinity'

		while (j < coins.size() && coins.at(j) <= i){//While there are coins and the current coin is less than or equal to the current amount
			if(T.at(i-coins.at(j)) + 1 <= q){
                k = i-coins.at(j);      //An index to the optimal subsolution
				q = T.at(k) + 1;        //Current optimal solution
                d = j;                  //The current coin's index in the array of coins
			}
			j++;
		}
        solutions.push_back(solutions.at(k));   //The solution at k is the optimal subsolution; hence, copy it in the current solution
        solutions.at(i).at(d)++;        //Increment the count of the denominator, d, used in the optimal solution

        T.push_back(q);  //Store the value of the optimal solution of i;
	}
    copy(solutions.at(A).begin(), solutions.at(A).end(), std::back_inserter(optSolution));  //Copy the optimal solution
}
int getOptValue(const std::vector<int> &optSolution){
    int m = 0;
    for(int i = 0; i < optSolution.size(); ++i)
        m += optSolution.at(i);
    return m;
}
