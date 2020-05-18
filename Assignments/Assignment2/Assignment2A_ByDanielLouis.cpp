/*
Copyright (C) 2017 Daniel Louis (dtl29) All right reserved
Assignment 2 A
Author: Daniel Louis
dtl29@zips.uakron.edu
Purpose: To see if the class room a user selects is within fire code to hold that class
*/
#include <iostream>
using namespace std;

int main()
{
    //the constants for the max class sizes in each classroom
    const int LH312 = 42;
    const int CAS41 = 44;
    const int KH133 = 38;
    //the temporary integer values for the input selection
    int classSize;
    int classRoom;
    int maxClassSize;

    cout << "Press the return key after every entry. \n";
    cout << "Please select a room out of the list of rooms."<<endl;
    cout << "Press 1 for Leigh Hall room 312, press 2 for The College of Arts and Science room 41,";
    cout << " or press 3 for Kolbe Hall room 133."<<endl;
    cin >> classRoom;

    if(classRoom == 1)
    {
        maxClassSize = LH312;
    }
    else if (classRoom == 2)
    {
        maxClassSize = CAS41;
    }
    else if(classRoom == 3)
    {
        maxClassSize = KH133;
    }
    else
    {
        cout << "Sorry that is not a valid input.\n";
        return 0;
    }

    cout << "Please enter how many people will attend the class"<<endl;
    cin >> classSize;

    if (classSize > maxClassSize)
    {
        cout << "Your selection does not accommodate that many students, please pick another room.\n";
        return 0;
    }
    else
    {
        cout << "This room can handle that and has enough room for " << maxClassSize - classSize <<" more students.\n";
    }

    return 0;
}
