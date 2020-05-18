/*
   COPYRIGHT (C) 2017 Student Name (UANET ID ) All rights reserved.
   CS assignment
   Author.  Daniel Louis
            stl29@zips.uakron.edu
   Version. 1.01 09.09.2017
   Purpose: project 3
*/
#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include "treenode.hpp"

// Tree class-template definition
template<typename NODETYPE>
class Tree
{
public:
   // insert node in Tree
   void insertNode(const NODETYPE& value) {
      insertNodeHelper(&rootPtr, value);
   }

   // begin preorder traversal of Tree
   void preOrderTraversal() const {
      preOrderHelper(rootPtr);
   }

   // begin inorder traversal of Tree
   void inOrderTraversal() const {
      inOrderHelper(rootPtr);
   }

   // begin postorder traversal of Tree
   void postOrderTraversal() const {
      postOrderHelper(rootPtr);
   }
   // get the depth of the tree
   int getDepth() const{
      int totalDepth{0};
      int currentDepth{0};

      determineDepth(rootPtr, &totalDepth, &currentDepth);
      return totalDepth - 1;
   }

    // begin binary search
    TreeNode<NODETYPE>* binaryTreeSearch(int val) const {
        return binarySearchHelper(rootPtr, val);
    }

    /*
    * function optimize is a member of class Tree
    * precondition: has no arguments
    * will reorganize the tree so it will be equally distributed
    * the right does not organize perfect I can't get it to work
    */
    void optimize()
    {
        int depth;
        TreeNode<NODETYPE> *endTree = this->rootPtr;
        Tree<NODETYPE> *newTree = new Tree<NODETYPE>;

        getLengthOfTree(this->rootPtr, endTree, depth = 0);
        optimizehelper(this->rootPtr, endTree, *newTree, depth = 0);

        newTree->insertNode(this->rootPtr->getData());
        newTree->insertNode(endTree->getData());

        deleteTreehelper(rootPtr);
        this->rootPtr = newTree->rootPtr;
    }

    /*
    * function deleteTree is a member of class Tree
    * will delete the tree and leave it empty
    * precondition: takes no arguments
    */
    void deleteTree(){deleteTreehelper(rootPtr);}

private:
    TreeNode<NODETYPE>* rootPtr{nullptr};

    /*
    * function optimizehelper is a member of class Tree
    * will take a tree and find the midpoint and insert that node into a new tree and then find the midpoint again
    * this will happen for every node except the first and last node
    * precondition: takes two tree nodes for the front and end of the tree
    * and the new tree to hold the new nodes and an integer that is the depth of the tree
    */
    void optimizehelper(TreeNode<NODETYPE> *frontOfTree, TreeNode<NODETYPE> *endOfTree, Tree<NODETYPE> &newTree, int depth)
    {
        int temp = 0;
        TreeNode<NODETYPE> *middleOfTree = frontOfTree;
       // std::cout << "end of tree is " << endOfTree << " " << endOfTree->getData() << '\n';
        getShortDepth(frontOfTree, endOfTree, depth);
        depth = depth/2;
       // std::cout << "stop is equal to " << depth << '\n';
       // std::cout << "mid point is " << middleOfTree << " " << middleOfTree->getData() << '\n';
        goToMidePointer(frontOfTree, middleOfTree, depth);

        if(frontOfTree != middleOfTree)
        {
            newTree.insertNode(middleOfTree->getData());
            optimizehelper(frontOfTree, middleOfTree, newTree, depth = 0);
            optimizehelper(middleOfTree, endOfTree, newTree, depth = 0);
            return;
        }
    }

    /*
    * function getLengthOfTree is a member of class Tree
    * will change the tree node pointer to point to the end of the tree and will change the int to be the amount of nodes in the tree
    * precondition: this takes two arguments on tree node that is referenced and is a pointer that should be at the start of the tree
    * and an int that should be zero before the loop
    */
     void getLengthOfTree(TreeNode<NODETYPE> *start, TreeNode<NODETYPE> *&endOf, int &_count)
    {
        if(start != nullptr)
        {
            if(start->leftPtr != nullptr)
                getLengthOfTree(start->leftPtr, endOf, ++_count);
            if(start->rightPtr != nullptr)
                getLengthOfTree(start->rightPtr, endOf, ++_count);
            if(endOf->getData() <= start->getData())
                endOf = start;
        }
    }

    /*
    * function goToMidePoint is a member of class Tree
    * this will have a pointer point to the middle of an interval of the tree
    * precondition: this takes three arguments, the first is a tree node that points to the start of the tree
    * and the second is another tree node but referenced in so it will keep the pointer and the last argument is an int that should be how
    * many steps will be taken to have set to the midpoint
    */
    void goToMidePointer(TreeNode<NODETYPE> *start, TreeNode<NODETYPE> *&mid, int &stop)
    {
        if(stop <= 0)
        {
            return;
        }
        if(start->leftPtr != nullptr)
        {
            mid = start->leftPtr;
            stop -= 1;
            goToMidePointer(mid, mid, stop);
        }
         if(stop <= 0)
        {
            return;
        }
        if(start->rightPtr != nullptr)
        {
            mid = start->rightPtr;
            stop = stop - 1;
            goToMidePointer(mid, mid, stop);
        }
        if(stop <= 0)
        {
            return;
        }
    }

    /*
    * function getShortDepth is a member of class Tree
    * this will step through the tree from the start to then end and will count the amount of steps
    * precondition: this takes three arguments two of tree node pointers the first pointing to the starting point and the
    * other pointing to the end of the interval and a referenced int that will hold the amount of steps; the int should be zero to start with
    */
    void getShortDepth(TreeNode<NODETYPE>* start, TreeNode<NODETYPE>* endWith, int &_count)
    {
        if(start == endWith)
            return;
        if(start->leftPtr != nullptr)
        {
            getShortDepth(start->leftPtr, endWith, ++_count);
        }
        if(start->rightPtr != nullptr && start->getData() <= endWith->getData())
        {
            getShortDepth(start->rightPtr, endWith, ++_count);
        }
    }

    /*
    * function deleteTreeHelper is a member of class Tree
    * precondition: this takes one argument of a tree node pointer pointing at the start of the tree
    * will step through the tree and free up the pointers and point them to null
    */
    void deleteTreehelper(TreeNode<NODETYPE> *root)
    {
        if(root->getLeftPtr() == nullptr && root->getRightPtr() == nullptr)
        {
            return;
        }
        if(root->leftPtr != nullptr)
            deleteTreehelper(root->leftPtr);
        if(root->rightPtr != nullptr)
            deleteTreehelper(root->rightPtr);
        delete root;
        root = 0;
    }

   // utility function called by insertNode; receives a pointer
   // to a pointer so that the function can modify pointer's value
    void insertNodeHelper(TreeNode<NODETYPE>** ptr, const NODETYPE& value) {
      // subtree is empty; create new TreeNode containing value
        if (*ptr == nullptr) {
            *ptr = new TreeNode<NODETYPE>(value);
        }
        else { // subtree is not empty
             // data to insert is less than data in current node
            if (value <= (*ptr)->data) {
                insertNodeHelper(&((*ptr)->leftPtr), value);
            }
            else {
                insertNodeHelper(&((*ptr)->rightPtr), value);
            }
        }
    }

   // utility function to perform preorder traversal of Tree
   void preOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         std::cout << ptr->data << ' '; // process node
         preOrderHelper(ptr->leftPtr); // traverse left subtree
         preOrderHelper(ptr->rightPtr); // traverse right subtree
      }
   }

   // utility function to perform inorder traversal of Tree
   void inOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         inOrderHelper(ptr->leftPtr); // traverse left subtree
         std::cout << ptr->data << ' '; // process node
         inOrderHelper(ptr->rightPtr); // traverse right subtree
      }
   }

   // utility function to perform postorder traversal of Tree
   void postOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         postOrderHelper(ptr->leftPtr); // traverse left subtree
         postOrderHelper(ptr->rightPtr); // traverse right subtree
         std::cout << ptr->data << ' '; // process node
      }
   }

    // calculate the depth of the tree
    void determineDepth(TreeNode<NODETYPE>* root, int *totalDepth, int *currentDepth) const
    {
        if(root == this->rootPtr)
        {
            if(root->getLeftPtr() != nullptr)
            {
                determineDepth(root->getLeftPtr(),totalDepth,currentDepth);
            }
            else if (root->getRightPtr() != nullptr)
            {
                determineDepth(root->getRightPtr(),totalDepth,currentDepth);
            }
            else
            {
                *totalDepth = 0;
                return;
            }
        }
        *currentDepth = *currentDepth + 1;

        if(root->getLeftPtr() != nullptr)
        {
            determineDepth(root->getLeftPtr(),totalDepth,currentDepth);
        }
        if(root->getRightPtr() != nullptr)
        {
            determineDepth(root->getRightPtr(),totalDepth,currentDepth);
        }
        if (*currentDepth > *totalDepth)
        {
            *totalDepth = *currentDepth;
        }
        *currentDepth = *currentDepth - 1;
    }

   // do a binary search on the Tree
   //recursive search; I wanted to try both search using loops and recursive calls
   TreeNode<NODETYPE>* binarySearchHelper(TreeNode<NODETYPE> *root, int value) const
   {
        std::cout << "comparing " << value << " to " << root->getData();
       if(root->getData() == value)
       {
           std::cout << "; search complete" << std::endl;
           return root;
       }
       else if((value < root->getData())&&(root->getLeftPtr() != nullptr))
       {
           std::cout << "; smaller, walk left" << std::endl;
           return binarySearchHelper(root->getLeftPtr(), value);
       }
       else if ((value > root->getData()) && (root->getRightPtr() != nullptr))
       {
           std::cout << "; larger, walk right" << std::endl;
           return binarySearchHelper(root->getRightPtr(), value);
       }
       else
       {
            if(value > root->getData())
            {
                std::cout << "; smaller, end of tree\n";
            }
            else
            {
                std::cout << "; larger, end of tree\n";
            }
            return nullptr;
       }
   }
};

#endif // TREE_HPP
