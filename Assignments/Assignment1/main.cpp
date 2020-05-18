#include <iostream>
using namespace std;

//asking for the users weight
int weightInPounds;
int weightInKG;
//activities MET values set to in variables
int running6MPHMet = 10;
int basketballMet = 8;
int sleepingMet =1;
int mET;

//the rest of the variables needed to run the program
int time;
double caloriesBurnt;
int activities;
//this declares the function
void ifStatemetns();

int main()
{
    // asks for the users weight
    cout<<"After every line hit enter"<<endl;
    cout<<"Enter your weight in pounds"<<endl;
    cin>>weightInPounds;
    //this will convert pounds till kg
    weightInKG = weightInPounds / 2.2;
    //this block will figure out what one of the three things the user did and set the values accordingly
    cout<<"Enter what activity you did. "<<endl<<"if you ran enter 1, if you played basketball enter 2, if you slept enter 3"<<endl;
    cin>>activities;
    //this calls the function to ask what activity was done
    ifStatemetns();
   //this asks the user for the amount of time they spent on the activity
    cout<<"Enter the time in minutes spent on the activity"<<endl;
    cin>>time;

    //this is the formula to find out how much calories were burnt
    caloriesBurnt = 0.0175 * mET * weightInKG * time;

    //the final output for the user
    cout<<"you burnt "<<caloriesBurnt<<" calories"<<endl;

    return 0;
}
//this is the function to see what activities where done
void ifStatemetns(){
    if(activities == 1){
            cout<<"MET was 10"<<endl;
        mET = 10;
    }
    if(activities == 2){
        mET = 8;
    }
    if(activiteis == 3){
        mET = 1;
    }
    //if the user did not select one of the three it will run this
    if(activities != 1 && 2 && 3 ){
        cout<<"invalid response enter another"<<endl;
        cout<<"Enter what activity you did. "<<endl
            <<"if you ran enter 1, if you played basketball enter 2, if you slept enter 3"<<endl;
        cin>>activiteis;
        ifStatemetns();
    }
}

