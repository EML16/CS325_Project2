# CS325_Project2
Code and report files for Project 2 - Coin Change Algorithm Analysis 

Amounts.txt contains the same values as Coin1.txt from original assignment. 
Please feel free to change coin denominations and sums in Amounts.txt for testing. 

Compilation Instructions:

    $ chmod +x compile.sh       % make the script executable
    $ ./compile.sh              % generates exeMain 
    $ ./exeMain Amounts.txt     % run changedp and prints the output in Amountschange.txt
 
Results are printed in similar format as Coin1.txt, however, the amount of coins needed to make
the desired change amount will be printed in place of the change amount and the denomination of 
coins used will be relpaced by the quatity on the denomination used in reaching the change sum. 
For example, an input of...
        
        [1, 2, 3]
        3
        
will print in Amountschange.txt as..

        [0, 0, 1]
        3

    


