#! /bin/sh
g++ -std=c++11 -c Algo.cpp -o Algo.o
g++ -std=c++11 -c main.cpp -o main.o
g++ -std=c++11 -c calcNoCoins.cpp -o calcNoCoins.o
g++ -o exeMain Algo.o main.o
g++ -o exeCalcNoCoins Algo.o calcNoCoins.o

rm *.o
