/*
   COPYRIGHT (C) 2017 Student Name (UANET ID ) All rights reserved.
   CS assignment
   Author.  Daniel Louis
            stl29@zips.uakron.edu
   Version. 1.01 09.09.2017
   Purpose: project 3
*/
#ifndef TREENODE_HPP
#define TREENODE_HPP

// TreeNode class-template definition.

// forward declaration of class Tree
template<typename NODETYPE> class Tree;

// TreeNode class-template definition
template<typename NODETYPE>
class TreeNode {
   friend class Tree<NODETYPE>;
public:
   // constructor
   TreeNode(const NODETYPE& d) : data{d} {}

   // return copy of node's data
   NODETYPE getData() const {return data;}

   // return a leftPtr
   TreeNode* getLeftPtr() const {
      return leftPtr;
   }

   // return a rightPtr
   TreeNode* getRightPtr() const {
      return rightPtr;
   }

   // set value for leftPtr
   void setLeftPtr(TreeNode* ptr) {
      leftPtr = ptr;
   }

   // set value for rightPtr
   void setRightPtr(TreeNode* ptr) {
      rightPtr = ptr;
   }
private:
   TreeNode<NODETYPE>* leftPtr{nullptr}; // pointer to left subtree
   NODETYPE data;
   TreeNode<NODETYPE>* rightPtr{nullptr}; // pointer to right subtree
};

#endif // TREENODE_HPP
