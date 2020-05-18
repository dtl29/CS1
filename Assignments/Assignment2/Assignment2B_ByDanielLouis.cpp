/* Copyright (C) 2017 Daniel Louis (dtl29) All right reserved
Assignment 2 B
Author: Daniel Louis
dtl29@zips.uakron.edu
Purpose: To calculate grades
*/
#include <iostream>

using namespace std;

int main()
{
    // the grade values in the lowest percent they can be to get that grade
    const int GRADE_A = 93;
    const int GRADE_A_MINUS = 90;
    const int GRADE_B_PLUS = 87;
    const int GRADE_B = 83;
    const int GRADE_B_Minus = 80;
    const int GRADE_C_PLUS = 77;
    const int GRADE_C = 73;
    const int GRADE_C_MINUS = 70;
    const int GRADE_D_PLUS = 67;
    const int GRADE_D = 63;
    const int GRADE_D_MINUS = 60;

    int totalExercises;
    int curentExercises;

    double earnedScore = 0;
    double tempEarnedScore;
    double totalScore = 0;
    double tempTotatlScore;
    double percent;

    char letterGrade;
    char precursor;

    cout<<"After every entry press the return key. \n";
    cout<<"Enter how many exercises have been completed so far. "<<endl;
    cin>>totalExercises;
    curentExercises = 1;

    while (curentExercises <= totalExercises)
    {
        cout<<"Score received on exercise "<<curentExercises<<" : ";
        cin>>tempEarnedScore;
        cout<<"Enter the total score possible for the exercises "<<curentExercises<<" : ";
        cin>>tempTotatlScore;

        // this will add up all the points and total points as the user continues to add them
        earnedScore = earnedScore + tempEarnedScore;
        totalScore = totalScore + tempTotatlScore;
        curentExercises++;
    }
    //this will get the percent into a number that can be expressed to the user as their percent
    percent = (earnedScore / totalScore) * 100;
    precursor = ' ';

    if (percent >= GRADE_A_MINUS)
    {
        letterGrade = 'A';
        if (percent < GRADE_A)
        {
            precursor = '-';
        }
    }
    else if (percent >= GRADE_B_Minus)
    {
        letterGrade = 'B';
        if (percent < GRADE_B)
        {
            precursor = '-';
        }
        else if(percent >= GRADE_B_PLUS)
        {
            precursor = '+';
        }
    }
    else if (percent >= GRADE_C_MINUS)
    {
        letterGrade = 'C';
        if (percent < GRADE_C)
        {
            precursor = '-';
        }
        else if (percent >= GRADE_C_PLUS)
        {
            precursor = '+';
        }
    }
    else if (percent >= GRADE_D_MINUS)
    {
        letterGrade = 'D';
        if(percent < GRADE_D)
        {
            precursor = '-';
        }
        else if (percent >= GRADE_D_PLUS)
        {
            precursor = '+';
        }
    }
    else
    {
        letterGrade = 'F';
    }

    cout<<endl;
    cout<<"your total is "<<earnedScore<<" out of "<<totalScore;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<" or "<<percent<<"% "<<endl;
    cout<<"Your letter grade is "<<precursor<<letterGrade<<endl;
}
