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

    //loop the heads and tales encounter to loop through the 9 battles
    for(int i =1; i<=9;i++)
    {
         //put battle name into variable battleName
        switch (i)
        {
            case 1 : battleName = "Little Round Top";
                break;
            case 2 : battleName = "Cemetry Ridge";
                break;
            case 3 : battleName = "Devil's Den";
                break;
            case 4 : battleName = "The Wheatfield";
                break;
            case 5 : battleName = "The Peach Orchard";
                break;
            case 6 : battleName = "Culps Hill";
                break;
            case 7 : battleName = "Zieglers Grove";
                break;
            case 8 : battleName = "Seminary Ridge";
                break;
            case 9 : battleName = "Gettysburg";
                break;
            default : battleName = "This was not a battle there was to many for one simulation";
        }
        //print the battle name
        cout<<"Battle "<<i<<"-"<<battleName<<endl;
        //prompt for guess
        cout<<"Now General McClellan \n";
        cout<<"Do you predict the coin will come out \n";
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
        //validate input and if invalid stop back and run the loop again
        else
        {
            cout<<"invalid"<<endl;
            i--;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        cout<<endl;
        cout<<"Stand by to fight, General McClellan..."<<endl;
        //coin flip generates a number between 0-1
        coinflip = (rand()%100)/100.0;

        if(coinflip < 0.5)
        {
            coinRead = "Heads";
            if(heads)
            {
                mcClellanVictories++;
                //determine the battle winner
                cout<<"well done, General\n";
                cout<<"McClellan...\n";
                cout<<"you have defeated Lee.\n";
            }
            else
            {
                leeVictories++;
                //determine the battle winner
                cout<<"I am sorry, General\n";
                cout<<"McClellan...\n";
                cout<<"but the battle goes to Lee\n";
            }
        }
        else
        {
            coinRead = "Tales";
            if(heads)
            {
                leeVictories++;
                //determine the battle winner
                cout<<"I am sorry, General\n";
                cout<<"McClellan...\n";
                cout<<"but the battle goes to Lee\n";
            }
            else
            {
                mcClellanVictories++;
                //determine the battle winner
                cout<<"well done, General\n";
                cout<<"McClellan...\n";
                cout<<"you have defeated Lee.\n";
            }
            //determine the battle winner
        }

        cout<<"Result of the coin flip was: "<< coinRead<<endl;
        //tells user how many battles still to go
        cout<<"Battles to go: "<<9-i<<endl;
        cout<<endl;
        //print running score
        cout<<"So far: McClellan "<< mcClellanVictories <<" victories, Lee " << leeVictories <<endl;
        cout<<endl;
    }
    //print final score and winner
     cout<<"McClellan had "<< mcClellanVictories <<" victories, Lee had " << leeVictories<<"victories."<<endl;
     if(mcClellanVictories>leeVictories)
     {
         cout<<"The results show that\n";
         cout<<"George G Meade\n";
         cout<<"won the majority of the battles\n";
         cout<<"and is thus declared the victor\n";
         cout<<"on July 2, 1863.\n";
     }
     else
     {
         cout<<"The results show that\n";
         cout<<"Robert E Lee\n";
         cout<<"won the majority of the battles\n";
         cout<<"and is thus declared the victor\n";
         cout<<"on July 2, 1863.\n";
     }

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
