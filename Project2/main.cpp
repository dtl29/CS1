/*
Copyright (C) 2017 Daniel Louis (dtl29) All right reserved
Project 2
Author: Daniel Louis
dtl29@zips.uakron.edu
Purpose: Moving Hospital Beds
*/
#include <iostream>
#include <fstream>

//function prototypes
void enterBedsToArray(std::ifstream &, char [][8],char *[][8]);
void printGrid(char [][8]);
void checkOuts(char *[][8]);
void newPatientInput(int, int &);
void newPatient(char [][8],int&);
void transfer(char *[][8]);
void vacancyCounterF(char [][8], int &);


int main()
{
    std::ifstream beds;
    char bedsArray[5][8];
    char *pntrToBeds[5][8];
    int vacancyCounter = 0;
    char contiue = ' ';
    int newPateints;

    //opening the file and validating that it opened
    beds.open("Beds1.txt");
    if(beds.fail())
    {
        std::cout<<"The file failed to load.";
        return 0;
    }
    //function calls
    enterBedsToArray(beds, bedsArray,pntrToBeds);
    printGrid(bedsArray);
    std::cout<<"Grid Loaded.\n";
    checkOuts(pntrToBeds);
    transfer(pntrToBeds);
    printGrid(bedsArray);
    std::cout<<"Check outs and transfers completed.\n";

    //loop for user input to continue or not
    do
    {
        vacancyCounterF(bedsArray, vacancyCounter);
        if(vacancyCounter < 1)
        {
            std::cout<<"*** No more rooms are available today ***\n";
            return 4;
        }
        newPatientInput(vacancyCounter,newPateints);
        newPatient(bedsArray, newPateints);
        printGrid(bedsArray);

        std::cout<<"Do you want to enter any more patients?(Y/N)\n";
        std::cin>>contiue;
    }while(contiue == 'Y' || contiue == 'y');
    std::cout<<"**More rooms are available today***\n";
    return 0;
}
//function enterBedsToArray
//precondition: this function takes 3 arguments; one of the input file, the next being an array to hold the streamed info, and
//a array of pointers pointing to the array
//postcondition: this will read in the file and place it into the char array while also pointing each pointer at the char array
//this function will not return anything however each parameter is a referenced argument. and will close the input file
void enterBedsToArray(std::ifstream &beds, char bedsArray[][8],char *pntrTobeds[][8])
{
    for(int i = 0; i < 5; i++)
    {
        for(int k = 0; k < 8; k++)
        {
            bedsArray[i][k] = beds.get();
            beds.get();
            pntrTobeds[i][k] = &bedsArray[i][k];
        }
    }
    beds.close();
}
//function printGrid
//precondition: has one parameter of a char array
//postcondition: will print out a 2D char array of 5X8 to standard output
void printGrid(char bedsArray[][8])
{
    std::cout<<"----------------\n";
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(bedsArray[i][j] == '0')
                std::cout<<"V ";
            else if(bedsArray[i][j] == '1')
                std::cout<<"C ";
            else if(bedsArray[i][j] == '2')
                std::cout<<"O ";
            else if(bedsArray[i][j] == '3')
                std::cout<<"N ";
            else if(bedsArray[i][j] == '4')
                std::cout<<"T ";
            else
                std::cout<<"U ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"----------------\n";
}
//function checkOuts
//precondition: takes a parameter of a 2D char pointer array of 5X8
//postcondition: will change the values of any '1's found in the array and change them to '0'
void checkOuts(char *bedsArray[][8])
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(*bedsArray[i][j] == '1')
            {
                *bedsArray[i][j] = '0';
            }
        }
    }
}
//function transfer
//precondition: takes a parameter of a 2D char pointer array of 5X8
//postcondition: will find and '4's in the array and place them in the first open room in the array
void transfer(char *bedsArray[][8])
{
    bool swaped = true;
    bool firstRoomfound = false;
    bool oneRoomChanged = false;
    char *vPtr;
    char *tPtr;
    while(swaped)
    {
        swaped = false;
        firstRoomfound = false;
        oneRoomChanged = false;
        for(int i = 0; i < 5 && !oneRoomChanged; i++)
        {
            for(int j = 0; j < 8 && !oneRoomChanged; j++)
            {
                if(*bedsArray[i][j] == '0')
                {
                    if(!firstRoomfound)
                    {
                        firstRoomfound = true;
                        vPtr = &*bedsArray[i][j];
                    }
                }
                else if(*bedsArray[i][j] == '4')
                {
                   swaped = true;
                   oneRoomChanged = true;
                   *bedsArray[i][j] = '0';
                   *vPtr = '2';
                }
            }
        }
    }
}
//function vacancyCounterF
//precondition: this takes two parameters one of an 2D char array of an [5][8] and a referenced integer
//postcondition: will changed the integer so it will return the value of '0's in the array
void vacancyCounterF(char bedsArray[][8], int & vacancyCounter)
{
    vacancyCounter = 0;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(bedsArray[i][j]=='0')
            {
                vacancyCounter += 1;
            }
        }
    }
}
//function newPatient
//precondition: there are two parameters; one being an 2D char array of a 5X8, and an referenced integer
//postcondition: the referenced int will count down to 0, and the array will be updated for every '0' found will be replaced
//with a '2' until the count is 0.
void newPatient(char bedsArray[][8],int &numberOfPatients)
{
    bool placed = true;

    while(placed)
    {
        placed = false;

        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(bedsArray[i][j] == '0' && !placed)
                {
                    bedsArray[i][j] = '2';
                    placed = true;
                    numberOfPatients -=1;
                }
                if(numberOfPatients <= 0)
                {
                    return;
                }
            }
        }
    }
}
//function newPatientInput
//this function will take the input from the user to have how many patients they want to add
void newPatientInput(int emptyRooms,int &newPatients)
{
    newPatients = 0;

    std::cout << "Please enter the number of new patients, from one up to " << emptyRooms << ": ";
    std::cin>>newPatients;
    while(std::cin.fail() || newPatients > emptyRooms || newPatients < 1)
    {
        std::cout << "Sorry that input was incorrect please try another.\n";
        std::cin >> newPatients;
    }
}
