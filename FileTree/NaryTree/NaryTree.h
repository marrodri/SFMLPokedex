//
// Created by Marthel Rodriguez on 11/20/23.
//

#ifndef SFMLTEMPLATE_NARYTREE_H
#define SFMLTEMPLATE_NARYTREE_H

#include "TreeNode.h"
//what is a set? a data structure that will not permit duplicate entries.
//its similar to map, or a vector. that will help to iterate.
//#include <set>
#include <iostream>
#include <filesystem>
template<typename T>
class NaryTree {
private:
    TreeNode<T> *root = nullptr;

    void push(TreeNode<T> *parent, int depth);
    void print(TreeNode<T> *node);
    //find a child with this data, that is inside this node.
    TreeNode<T>* find(TreeNode<T> *parent, T data);





    void depthFirstTraversal(TreeNode<T> *node);
    TreeNode<T> *createNewTreeNode(const std::filesystem::directory_entry &dirEntry, int depth);
public:

    /// createTree for dummy data.
    void makeTree();
    NaryTree();
    /// read the file from the path to allocate the data.
    void push();
    void print();





};


//DFO: recursive. check the image.

#include "NaryTree.cpp"
#endif //SFMLTEMPLATE_NARYTREE_H
