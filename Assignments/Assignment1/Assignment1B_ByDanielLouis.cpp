/*
Assignment 1 B: assignment1B_ByDanielLouis.cpp
Author: Daniel Louis
dtl29@zips.uakron.edu
Purpose: To demonstrates basic output
*/
#include <iostream>
using namespace std;

int main()
{
    //asking for the users weight
    int weightInPounds;
    int weightInKG;

    //activities MET values set to in variables
    int running6MPHMet = 10;
    int basketballMet = 8;
    int sleepingMet =1;

    //the variable to hold how many minutes the user did each activity, I put it as double just incase the user wants half a minute
    double time;
    //variables to hold the calculations of how many calories it was.
    double caloriesBurntRunning;
    double caloriesBurntBasketball;
    double caloriesBurntSleeping;

    // asks for the users weight
    cout<<"This program is to find how many calories were burnt for three activities \n";
    cout<<"After every line hit the return key"<<endl;
    cout<<"Enter your weight in pounds"<<endl;
    cin>>weightInPounds;

    //this will convert pounds till kg
    weightInKG = weightInPounds / 2.2;

    //this asks the user for the amount of time they spent on the activity
    cout<<"Enter the time in minutes spent on the activity"<<endl;
    cin>>time;

    //this is the formula to find out how much calories were burnt
    caloriesBurntRunning = 0.0175 * running6MPHMet * weightInKG * time;
    caloriesBurntBasketball = 0.0175 * basketballMet * weightInKG * time;
    caloriesBurntSleeping = 0.0175 * sleepingMet * weightInKG * time;

    //this is the output for the user to see
    cout<<"If you ran at 6 mph for "<<time<<" minutes. Then you burnt "<<caloriesBurntRunning<<" calories.\n";
    cout<<"If you played basketball for "<<time<<" minutes. Then you burnt "<<caloriesBurntBasketball<<" calories.\n";
    cout<<"If you slept for "<<time<<" minutes. Then you burnt "<<caloriesBurntSleeping<<" calories.\n";

    return 0;
}

