/*
Copyright (C) 2017 Daniel Louis (dtl29) All right reserved
Assignment 4 A
Author: Daniel Louis
dtl29@zips.uakron.edu
Purpose: to calculate interest rates
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Assignement4AHeader.hpp"

int main()
{
    double initialBalance , interestRate , acountBalance;
    char loopstop = 'y';

    //loop to keep entering new accounts
    do
    {
        //retrieve the information needed from the user
        std::cout<<"Please hit enter after every value entered."<<std::endl;
        std::cout<<"Please enter the initial balance of the account: \n";
        std::cin>>initialBalance;
         if(std::cin.fail())
        {
            std::cout<<"Sorry invalid balance try another, please.";
            std::cin.clear();
            std::cin.ignore(100000,'\n');
            continue;
        }

        std::cout<<"Please enter the interest rate with a decimal number such as 5% would be entered as 0.05 and .5% would be .005. Interest rate: \n";
        std::cin>>interestRate;
        if(std::cin.fail()) //to catch an input error
        {
            std::cout<<"Sorry invalid interest rate try again, please.";
            std::cin.clear();
            std::cin.ignore(100000,'\n');
            continue;
        }
        else
        {
            acountBalance = newBalance(initialBalance,interestRate);//calls the first newBalance function

            std::cout.precision(2);
            std::cout.setf(std::ios::fixed, std::ios::floatfield);
            //simple display output for the user
            std::cout<<"Account Balance after 1 year: $"<< acountBalance<<std::endl;

            acountBalance = newBalance(initialBalance, interestRate, 10);//calls the second newBalance function
            std::cout<<"Account Balance after 10 years: $"<<acountBalance<<std::endl;

            int year = yearsNeeded(initialBalance, interestRate, 1000000);//calls the yearNeeded function
            std::cout<<"How long until it reaches $1 mil: " << year<<std::endl;
        }

        //finish loopFlag to end the loop
       std::cout<<"Do you want to enter a new amount? (Y/N)\n";
       std::cin>>loopstop;
    }while(loopstop == 'y' || loopstop == 'Y' );
    return 0;
}
//function to fins the account balance after 1 year
double newBalance( double initialBalance, double interestRate)
{
    return initialBalance + (initialBalance * interestRate);
}
//function to figure out what the account balance will be after x years
double newBalance(double initialBalance, double interestRate, int n)
{
    return initialBalance * (pow((1+interestRate),n));
}
//this function will find the number of years it will take to reach the goal
double yearsNeeded(double initialBalance, double interestRate , double goal)
{
    double newAcountBalance = initialBalance;
    int year=0;
    for(int i=0 ;newAcountBalance <= goal && newAcountBalance>0;i++)
    {
        bool flag = true;
        newAcountBalance = newAcountBalance + (newAcountBalance * interestRate);
        if(newAcountBalance>=goal && flag) //this prevents the year having more than one input for i after the loop finishes
        {
            year = i;
            flag = false;
        }
    }
    return year + 1; // have to add one since the loop stops without adding the last year
}
