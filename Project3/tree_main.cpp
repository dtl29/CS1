/*
   COPYRIGHT (C) 2017 Student Name (UANET ID ) All rights reserved.
   CS assignment
   Author.  Daniel Louis
            stl29@zips.uakron.edu
   Version. 1.01 09.09.2017
   Purpose: project 3
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tree.hpp"

int main() {
   //srand(time(nullptr)); // randomize the random number generator

    Tree<int> optTree;
    for(int i = 1; i < 32; i++)
    {
        //insert values 1,2,3,...,31
        optTree.insertNode(i);
    }
    optTree.inOrderTraversal();//you will output 1,2,3,...,31
    std::cout << std::endl;
    std::cout << "The depth of the tree is: " << optTree.getDepth() << std::endl;
    optTree.optimize();
    //you will output 30 as the depth
    optTree.inOrderTraversal(); //this will output 1,2,3,...,31
    std::cout << std::endl;
    std::cout << "The depth of the tree after optimized is: " << optTree.getDepth() << std::endl;
    std::cout << std::endl;

}
