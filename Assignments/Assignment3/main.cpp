/*
Copyright (C) 2017 Daniel Louis (dtl29) All right reserved
Assignment 3 A
Author: Daniel Louis
dtl29@zips.uakron.edu
Purpose: to create a simple program that will produce a box of X from valid input form the user.
*/
#include <iostream>

using namespace std;

int main()
{
    // variables to hold the values for input
    int length;
    int width;
    //variables to complete the loop
    bool loopFlag = true;
    bool repeatFlag = false;
    char repeat = 'n';

    do
    {
         //asks for inputs from the user
        do
        {
            cout<<"After you enter a value press the return key.\n";
            cout << "Please enter the length that's less than 75 and greater than 0.\n";
            cin >> length;
            cout<<"Please enter the width that's less than 75 and greater than 0.\n";
            cin >> width;

            //checking if the input fits the range specified
            if(cin.fail() || (width > 75 || length > 75)||(width <0 || length < 0))
            {
                cout << "Sorry those inputs are invalid, please try entering new values." << endl;
                loopFlag = true;
                cin.clear();
                cin.ignore();
                continue;
            }
            else
            {
                loopFlag = false;
            }
        }while(loopFlag);

        //the loop that will produce the rectangle of Xs from the input
        for(int i = 0; i < length; i++)
        {
            for(int i = 0; i < width; i++)
            {
                cout << "X";
            }
            cout << "\n";
        }

        //asking for input to repeat the loop or not
        cout << "do you want to repeat?(Y/N)\n";
        cin >> repeat;
        if(repeat == 'y' || repeat == 'Y')
        {
            repeatFlag = true;
        }
        else
        {
            repeatFlag = false;
        }

    }while(repeatFlag);

    return 0;
}
