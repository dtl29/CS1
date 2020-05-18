/*
Assignment 1 B: assignment1B.cpp
Author: Daniel Louis
dtl29@zips.uakron.edu
Purpose: To demonstrates basic output
*/
#include <iostream>
using namespace std;
 //this declares the function
void IfStatemetns();
int activities;
int mET;
int main()
{
    //asking for the users weight
    int weightInPounds;
    int weightInKG;

    //the rest of the variables needed to run the program
    int time;
    double caloriesBurnt;
    //this declares the function
   // void IfStatemetns();
    // asks for the users weight
    cout<<"This program is to find how many calories were burnt for three activities \n";
    cout<<"After every line hit enter"<<endl;
    cout<<"Enter your weight in pounds"<<endl;
    cin>>weightInPounds;
    //this will convert pounds till kg
    weightInKG = weightInPounds / 2.2;
    //this block will figure out what one of the three things the user did and set the values accordingly
    cout<<"Enter what activity you did. "<<endl<<"if you ran at 6 mph then enter 1, if you played basketball enter 2, or if you slept enter 3"<<endl;
    cin>>activities;
    //this calls the function to ask what activity was done
    IfStatemetns();
    //this asks the user for the amount of time they spent on the activity
    cout<<"Enter the time in minutes spent on the activity"<<endl;
    cin>>time;

    //this is the formula to find out how much calories were burnt
    //this is the formula calories/minute=.0175 * MET * Weight(kg) but i brought over the time to the other side to see just the calories
    caloriesBurnt = 0.0175 * mET * weightInKG * time;

    //the final output for the user
    cout<<"you burnt "<<caloriesBurnt<<" calories"<<endl;
    //this is the function to see what activities where done

    return 0;
}

 void IfStatemetns()
{
    if(activities == 1)
    {
        cout<<"MET was 10"<<endl;
        mET = 10;
    }
    if(activities == 2)
    {
        mET = 8;
    }
    if(activities == 3)
    {
        mET = 1;
    }
    //if the user did not select one of the three it will run this
    if(activities != 1 && 2 && 3 )
    {
        cout<<"invalid response enter another"<<endl;
        cout<<"Enter what activity you did. "<<endl
            <<"if you ran enter 1, if you played basketball enter 2, if you slept enter 3"<<endl;
        cin>>activities;
        IfStatemetns();
    }
}
