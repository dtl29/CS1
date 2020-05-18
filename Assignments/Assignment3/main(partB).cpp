/*
Copyright (C) 2017 Daniel Louis (dtl29) All right reserved
Assignment 3 B
Author: Daniel Louis
dtl29@zips.uakron.edu
Purpose: calculates a quadratic equation
*/
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    //variables to plug into the equation and the somewhere to hold the answer of the equation
    double a , b , c;
    double x;
    double x2;
    double discriminant;
    //allows the loop to conclude or repeat
    bool loopFlag = false;
    char repeat = ' ';

    do
    {
        //inputs the values for each part of the quadratic equation
        cout << "Press enter after every input.\n";
        cout << "Calculates quadratic equations such as ax^2 + bx + c = 0\n";
        cout << "Enter the value for a: \n";
        cin >> a;
        cout << "Enter the value for b: \n";
        cin >> b;
        cout << "Enter the value for c: \n";
        cin >> c;


        //does the calculations for the equation and determines the output for that equation
        if(a!=0 && !cin.fail())
        {
            //calculates the quadratic equation
            x = (((-1 * b) - sqrt((b * b) - ( 4 * a * c))) / (2 * a));
            x2 = (((-1 * b) + sqrt((b * b) - ( 4 * a * c))) / (2 * a));
            discriminant = (b * b) - (4 * a * c);

            //if it has one solution
            if(discriminant == 0)
            {
               cout << "For " << a << "x^2 + " << b << "x + " << c << " = 0 the solution is x = " << x << endl;
               cout << "The factors are: \n";
               cout << "(x + " << (-1 * x) << ") (x + " << (-1 * x2) << ")" << endl;
            }
            //if it has two solutions
            else if(discriminant > 0)
            {
               cout << "For " << a << "x^2 + " << b << "x + " << c << " = 0 the solution is x = " << x << " and x = " << x2 << endl;
               cout << "The factors are: \n";
               cout << "(x + "<< (-1*x) << ") (x + " << (-1*x2) << ")" << endl;
            }
            //if it has a complex numbered roots
            else
            {
                double real;
                double imaginary;
                double absolutOfDisciminant = -1 * discriminant;
                real = ((-1 * b) / (2 * a));
                imaginary = sqrt(absolutOfDisciminant) / (2 * a);
                cout << "Complex Numbered root is expressed by a + bi where i is the imaginary number which equals the square root of -1: \n";
                cout << "x = " << real << " + " << imaginary << "i" << endl;
                cout << "or\n";
                cout << "x = " << real << " + " << -1 * imaginary << "i" << endl;

            }
        }
        else if(cin.fail())
        {
            cout << "Sorry that is an invalid input. Please try again.\n";
            cout << endl;
            cin.clear();
            cin.ignore();
            loopFlag = true;
            continue;
        }

        //inputs the request to repeat or end the program
        cout << "repeat?(Y/N)\n";
        cin >> repeat;
        if(repeat == 'y' || repeat == 'Y')
        {
            loopFlag = true;
        }
        else
        {
            loopFlag = false;
        }

    }while(loopFlag);

    return 0;
}
