/*
   ACADEMIC INTEGRITY PLEDGE

   - I have not used source code obtained from another
     student nor any other unauthorized source, either
     modified or unmodified.

   - All source code and documentation used in my program
     is either my original work or was derived by me from
     the source code published in the textbook for this
     course or presented in class.

   - I have not discussed coding details about this project
     with anyone other than my instructor. I understand
     that I may discuss the concepts of this program with
     other students and that another student may help me
     debug my program so long as neither of us writes
     anything during the discussion or modifies any
     computer file during the discussion.

   - I have violated neither the spirit nor letter of these
     restrictions.



   Signed: Daniel Louis Date: 10/23/2017


   COPYRIGHT (C) 2016 (your name). All Rights Reserved.
   (Description of program)
   author (your name)
   version 1.01 (date)
*/

/*
Copyright (C) 2017 Daniel Louis (dtl29) All right reserved
Project 1
Author: Daniel Louis
dtl29@zips.uakron.edu
Purpose: battle of seven days from the civil war made into a game
*/
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <ctime>
#include <limits>
#include <iomanip>
using namespace std;

int main()
{
    srand(time(0));
    //declare variables
    int leeVictories = 0 , mcClellanVictories = 0;
    char headsTales = ' ';
    bool heads;
    double coinflip;
    string battleName;
    string coinRead;

    //start game text here or beginning instructions
    cout.width(15);
    cout<<"Let the "<<endl;
    cout << "flip of a coin will rewrite history\n";
    cout<<endl;
    cout<<endl;
    cout.width(35);
    cout<<"/---------------------------- \\\\"<<endl;
    cout.width(32);
    cout<<"| return to seven days | \n";
    cout.width(35);
    cout<<"//----------------------------\\"<<endl;
    cout<<endl;
    cout << "It is July 1, 1862, the final day\n";
    cout<< "of the Battle of Seven Days...";
    cout<<endl;
    cout<<endl;
    cout<<"In this re-enactment of the second day\n";
    cout<<"of battle, you are George B. McClellan \n";
    cout<<"in charge of the Unionists \n";
    cout<<endl;
    cout<<endl;
    cout<<"We will flip a coin to determine the";
    cout<<"outcome of the small battles for \n";
    cout<<"territories within the Seven Days area \n";
    cout<<endl;
    cout<<"You have to predict whether the coin \n";
    cout<<"will come up heads or tails... \n";

    //prompt for guess
    cout<<"Now General McClellan \n";
    cout<<" Do you predict the coin will come out \n";
    cout<<"Head (h) or tails (t) \n";
    cout<<"Please choose (h/t)\n";
    cin>> headsTales;
    cout<<endl;

    if(headsTales == 'h' || headsTales == 'H' )
    {
        heads = true;
        //echo guess
        cout<<"You have selected heads.\n";
    }
    else if (headsTales == 't' || headsTales == 'Y')
    {
        heads = false;
        //echo guess
        cout<<"You have selected tails.\n";
    }
    else
    {
        cout<<"invalid"<<endl;
        i--;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
    }

    cout<<endl;
    cout<<"Stand by to fight, General McClellan..."<<endl;

    coinflip = (rand()%100)/100.0;

    cout<<"Result of the coin flip was: "<< coinflip<<endl;
    //print running score
    cout<<"So far: McClellan "<< mcClellanVictories <<" victories, Lee " << leeVictories <<endl;
    cout<<endl;


    //print historical data
    cout<<"In the actual Battle at Seven Days, \n";
    cout<<"the Northern troops turned back Lee's \n";
    cout<<"final assaults at Malvern Hill (July  \n";
    cout<<"1).... \n";
    cout<<endl;
    cout<<"The Confederates lost about 16,000  \n";
    cout<<"men... \n";
    cout<<endl;
    cout<<"The Unionists lost about 20,000 men ... \n";
    cout<<endl;
    cout<<"McClellan's failure to capture  \n";
    cout<<"Richmond, and the subsequent  \n";
    cout<<"withdrawal of the Union's Army from  \n";
    cout<<"the Yorktown Peninsula, signified the \n";
    cout<<"end of the Peninsular Campaign."<<endl;

    return 0;
}
