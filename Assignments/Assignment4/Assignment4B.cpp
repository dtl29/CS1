/*
Copyright (C) 2017 Daniel Louis (dtl29) All right reserved
Assignment 4 B
Author: Daniel Louis
dtl29@zips.uakron.edu
Purpose: finding the square root of a number without calling the sqrt function
*/
#include <iostream>
#include<cmath>
#include "Assignment4BHeader.hpp"
using namespace std;

int main()
{
    float initialValue;
    char loopAsk = 'y';

    //the square root of the first 10 integers
     for(int i=1; i<=10;i++)
    {
        cout<<"Testing mySquareRoot() for the first 10 integers\n";
        cout<<"The approximate square root of: "<<i<<" is: "<< mySquareRoot(i)<<endl;
    }

    //having the user enter a value to find its square root
    do
    {
        cout<<"Enter a real number between 1 and 100."<<endl;
        cin>>initialValue;
        //making sure the user entered the proper information
        if(cin.fail() || initialValue>100 || initialValue<1)
        {
            cin.clear();
            cin.ignore(10000,'\n');
            cout<<"Please try another real number between 1 and 100.\n";
            continue;
        }

        double squareRoot = mySquareRoot(initialValue);//function declaration for mySquareRoot
        cout<< "The square root of: "<<initialValue<<" is: "<<squareRoot<<endl;
        cout<<"Using the sqrt() function with: "<<initialValue <<" is: "<<sqrt(initialValue)<<endl;

        //ask if the user would like to enter another number
        cout<<endl;
        cout<<"Do you want find another square root?(Y/N).\n";
        cin>>loopAsk;
    }while(loopAsk == 'y' || loopAsk == 'Y');

    return 0;
}
double mySquareRoot(float value)
{
    float upperBound = value, lowerBound = 0, root = 0;
    //i found that 20 iterations did not give a good approximation so I had it iterate more to refine the number
    int stepCount =200;

    //loop through with the equation to find the best root
    while(stepCount > 0)
    {
        //the equation c= a+p/2
        root=(upperBound + lowerBound)/2.0;

        //this will end the loop once found a perfect square instead of continue iterations
        if(root * root == value)
        {
            return root;
        }

        //this will change the upperBound to equal the new root so it will be smaller for the next iteration
        else if((root * root) > value)
        {
            upperBound = root;
        }

        //this will have it change to be a little larger if the root was already to small
        else
        {
            lowerBound = root;
        }

        stepCount--;
    }
    //in case the if statement misses the value it can still return the best approximation
    return root;

}
