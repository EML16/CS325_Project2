#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<chrono>
#include "Algo.h"
using namespace std;
typedef Result (*Algorithm)(const int &, const vector<int>&);

int main(int argc, char *argv[]) {
	if(argc != 3) {
		cout<<"Usage: "<<argv[0]<<" algo_id[1|2|3] <logfile>"<<endl;
		return -1;
	}
	int algo_no = atoi(argv[1]);	        //The id of the algorithm to execute, 1: changeslow 2: changegreedy 3:changedp
	ofstream logfile(argv[2], ios::out);    //An output file where a line contains the amount and the number of coins used

	Algorithm f;					//A pointer to the algorithm to execute
    switch(algo_no) {
        case 1: 
            f = changeslow; break;
	    case 2:
            f = changegreedy; break;
        case 3:
            f = changedp; break;
        default:
            cout<<"Invalid algorithm id: "<<algo_no<<endl;
            return -1;
	}
    
    Result res;
    int duration = 0;

    vector<int> V1{1, 5, 10, 25, 50};
    
    //*******WARMUP RUN************** 
    for(int i = 2010; i <= 2200; i += 5){
        duration = 0;
        for(int k = 0; k < 10; ++k) {
            //auto start =  chrono::high_resolution_clock::now();
            res = f(i, V1);
            //auto end = chrono::high_resolution_clock::now();
            
            //duration += chrono::duration_cast<chrono::microseconds>(end-start).count();        
        }

    }    
    //************END OF WARMUP RUN ************
    
    copy(V1.begin(), V1.end(), ostream_iterator<int>(logfile, " "));
    logfile<<endl;
    logfile<<"\tAmount\tNo. Coins\tRunning time in microseconds\n";
    for(int i = 2010; i <= 2200; i += 5){
        duration = 0;
        for(int k = 0; k < 10; ++k) {
            auto start =  chrono::high_resolution_clock::now();
            res = f(i, V1);
            auto end = chrono::high_resolution_clock::now();
            
            duration += chrono::duration_cast<chrono::microseconds>(end-start).count();        
        }

        logfile<<"\t"<<i<<"\t"<<res.first<<"\t"<<duration/10<<endl;
    }    

    vector<int> V2{1, 2, 6, 12, 24, 48, 60};
    copy(V2.begin(), V2.end(), ostream_iterator<int>(logfile, " "));
    logfile<<endl;
    logfile<<"\tAmount\tNo. Coins\tRunning time in microseconds\n";
    for(int i = 2000; i <= 2200; ++i){
        duration = 0;
        for(int k = 0; k < 10; ++k) {
            auto start =  chrono::high_resolution_clock::now();
            res = f(i, V2);
            auto end = chrono::high_resolution_clock::now();
            
            duration += chrono::duration_cast<chrono::microseconds>(end-start).count();        
        }

        logfile<<"\t"<<i<<"\t"<<res.first<<"\t"<<duration/10<<endl;
    }    
    vector<int> V3{1, 6, 13, 37, 150};
    copy(V3.begin(), V3.end(), ostream_iterator<int>(logfile, " "));
    logfile<<endl;
    logfile<<"\tAmount\tNo. Coins\tRunning time in microseconds\n";
    for(int i = 2000; i <= 2200; ++i){
        duration = 0;
        for(int k = 0; k < 10; ++k) {
            auto start =  chrono::high_resolution_clock::now();
            res = f(i, V3);
            auto end = chrono::high_resolution_clock::now();
            
            duration += chrono::duration_cast<chrono::microseconds>(end-start).count();        
        }

        logfile<<"\t"<<i<<"\t"<<res.first<<"\t"<<duration/10<<endl;
    }    

    vector<int> V4(30);
    iota(V4.begin(), V4.end(), 1);
    
    copy(V4.begin(), V4.end(), ostream_iterator<int>(logfile, " "));
    logfile<<endl;
    logfile<<"\tAmount\tNo. Coins\tRunning time in microseconds\n";
    for(int i = 2000; i <= 2200; ++i){
        duration = 0;
        for(int k = 0; k < 10; ++k) {
            auto start =  chrono::high_resolution_clock::now();
            res = f(i, V4);
            auto end = chrono::high_resolution_clock::now();
            
            duration += chrono::duration_cast<chrono::microseconds>(end-start).count();        
        }

        logfile<<"\t"<<i<<"\t"<<res.first<<"\t"<<duration/10<<endl;
    }    

	return 0;
}
