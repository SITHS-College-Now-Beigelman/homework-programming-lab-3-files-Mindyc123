//Mindy Chen
//Homework 3
//10.15.24

#include <iostream> 
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{

    double money;
    int transaction;
    double D = 0;
    double W = 0;
    double transAmount;
    string type;
    //char i = 1;
    ifstream inFile; 
    ofstream outFile;

    //Set variable of the file streams

    inFile.open("transactions.txt");
    outFile.open("total.txt");

    //Opens the input and output files

/*    for ( i = 0; i < 7; i++ )
{

   inFile >> type;
   inFile >> transAmount;

   //Reads the lines after the first as the type of transaction and amount of transaction

   if (type == "W")
   { W = money - transAmount;
   outFile << "Your total debit is " fixed << setprecision(2) << W <<endl;
   }

   if (type == "D")
   { D = money + transAmount;
   outFile << "Your total credit is " fixed << setprecision(2) << D <<endl;

   //I changed the cout to outFile so it outputs in the file. I also changed credit and debit to D and W

   }
}

    outFile << "Your total debit for the day is: " << fixed << setprecision(2) << W <<endl;
    outFile << "Your total credit for the day is: " << fixed << setprecision(2) << D <<endl;

    inFile.close();
    outFile.close();
*/
     

     inFile >> money; 
     outFile << "STARTING BALANCE: " << " $ " << fixed << setprecision(2) << money << endl;

     //Reads the first line and outputs it as the starting balance. I also round it to the hundreds place

     outFile << " " << endl;
     outFile << " " << endl;

     //Adds two empty lines. 

     outFile << "TYPE" << setfill('.') << setw(8) << "AMOUNT" << setw(25) << "BALANCE" << endl;

    //Outputs the words TYPE, AMOUNT and BALANCE with certain amounts of . in between using setfill
    
    while (!inFile.eof())

    //While the code is not at the end of file, it will loop the code below
{
    inFile >> type;
    inFile >> transAmount;

    //Reads the lines below the first as the type of transaction and amount of transaction
    
     if (type == "W")
     { W = money - transAmount;
     outFile << "W" << setw(11) << fixed << setprecision(2) << transAmount;
     outFile << setw(28) << fixed << setprecision(2) << W << endl;
    }

     if (type == "D")
     { D = money + transAmount;
     outFile << "D" << setw(11) << fixed << setprecision(2) << transAmount;
     outFile << setw(28) << fixed << setprecision(2) << D << endl;
    }
}
    outFile << " " << endl;
    outFile << " " << endl;

    outFile << "ENDING BALANCE: " << " $" << money + ( D - W ) << endl;

    //Calculates the ending balance by adding the withdrawal subtracted from the deposit to the total balance

    outFile << "TOTAL WITHDRAWALS: " << " $" << fixed << setprecision(2) << W << endl;
    outFile << "TOTAL DEPOSITS: " << " $" << fixed << setprecision(2) << D << endl;

    //Outputs the total withdrawals and deposits

    inFile.close();
    outFile.close();

    //Closes the files

    return 0;
}
/* 
Part 1
Your total debit is 4800.00
Your total debit is 4200.00
Your total debit is 4960.00
Your total credit is 5090.00
Your total credit is 5100.00
Your total credit is 6000.00
Your total debit is 4980.00
Your total debit for the day is: 4980.00
Your total credit for the day is: 6000.00

Part 2
STARTING BALANCE:  $ 5000.00
 
 
TYPE..AMOUNT..................BALANCE
W.....200.00.....................4800.00
W.....800.00.....................4200.00
W......40.00.....................4960.00
D......90.00.....................5090.00
D.....100.00.....................5100.00
D....1000.00.....................6000.00
W......20.00.....................4980.00
 
 
ENDING BALANCE:  $6020.00
TOTAL WITHDRAWALS:  $4980.00
TOTAL DEPOSITS:  $6000.00
*/