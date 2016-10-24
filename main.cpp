#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<iterator>
#include<utility>
#include "Algo.h"
using namespace std;

typedef pair<int, vector<int> > InputPair;      //A pair of an amount, A, and list of coins
int main(int argc, char* argv[]) {
	if(argc != 2){
		cout<<"Usage: "<<argv[0]<<" <input_file_name>"<<endl;
		return -1;
	}

    string filename(argv[1]);       //File name with extension
	ifstream inputFile(filename, ios::in);
    filename = filename.substr(0, filename.size()-4);   //drop the file name extension
	ofstream outputFile(filename + "change.txt", ios::out);	//	
	
    vector<InputPair> inputs;      //A list of inputs

	//Read from the input file and store in a vector
	string line;
    int n, amount;
    vector<int> coins;
	while(getline(inputFile, line)){		
		if(line.size() > 1){

			stringstream ss(line);
			ss.ignore(1, '[');	//skip the open bracket
			while(ss>>n){
				coins.push_back(n);
				ss.ignore(1, ','); //skip the comma
			}
            inputFile>>amount;  //  Read the amount from the next line

		    inputs.push_back(make_pair(amount, coins));
            coins.clear();
        }
    }
    outputFile<<"Algorithm changedp:\n";
    for(auto it = inputs.begin(); it != inputs.end(); ++it){
        auto A = it->first;
        auto coins = it->second;

        Result result;

        result = changedp(A, coins);

        //Write output to a file
        outputFile<<"\t[";
        
        copy(result.second.begin(), result.second.end(), ostream_iterator<int>(outputFile, ","));
		
        outputFile.seekp(-1, ios::cur);	//Overwrite the trail comma
        
        outputFile<<"]\n";
        outputFile<<"\t"<<result.first<<endl;   
    }

	return 0;
}
