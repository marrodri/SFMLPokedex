//
// Created by Marthel Rodriguez on 11/20/23.
//

#ifndef SFMLTEMPLATE_NARYTREE_CPP
#define SFMLTEMPLATE_NARYTREE_CPP
#include "NaryTree.h"


template<typename T>
void NaryTree<T>::makeTree() {

}

template<typename T>
NaryTree<T>::NaryTree() {

}

template<typename T>
void NaryTree<T>::print(TreeNode<T> *node) {
//    preorder recursive function.
    if (!node->children.empty()) {
        std::cout << node->data << std::endl;
        typename std::set<TreeNode<T>*>::iterator iter = node->children.begin();
        for (;iter != node->children.end(); ++iter) {
            print(*iter);
        }
    }
    std::cout << "node->depth: " << node->depth << "\n";
    std::cout << "node->filename: " << node->fileName << "\n";
    std::cout << "node->path: " << node->path << "\n";
    switch(node->typeOfFile){
        case std::filesystem::file_type::regular:
            std::cout << "node->typeOfFile: "  << "regular" << "\n";
            break;
        case std::filesystem::file_type::directory:
            std::cout << "node->typeOfFile: "  << "directory" << "\n";
            break;
        default:
            std::cout << "unknown\n";
    }
    //push createdChild to the new set of children.

}

template<typename T>
void NaryTree<T>::depthFirstTraversal(TreeNode<T> *node) {

}

template<typename T>
void NaryTree<T>::push(TreeNode<T> *parent, int depth) {
    if (parent) {
        std::set<TreeNode<T>*> newChildren;
        for (const auto & entry : std::filesystem::directory_iterator(parent->path)){
            std::cout << "entry:path: "<<entry.path() << "\n";
            TreeNode<T>* newChild = createNewTreeNode(entry, depth);
            if (newChild->typeOfFile == std::filesystem::file_type::directory) {
                push(newChild, depth+1);
            }
            newChildren.insert(newChild);
        }
        parent->children = newChildren;
    }
}

template<typename T>
TreeNode<T> *NaryTree<T>::createNewTreeNode(const std::filesystem::directory_entry &dirEntry, int depth){
    TreeNode<T> *newChild =  new TreeNode<T>;
    newChild->path = dirEntry.path();
    newChild->typeOfFile = dirEntry.status().type();
    newChild->fileName = dirEntry.path().filename();
    newChild->depth = depth;

    return newChild;
}

template<typename T>
void NaryTree<T>::push() {
    if (!root) {
        root = new TreeNode<T>;
        root->path = "./Files";
        root->fileName = "Files";
        std::set<TreeNode<T>*> newChildren;
        for (const std::filesystem::directory_entry & entry : std::filesystem::directory_iterator(root->path)){
            TreeNode<T>* newChild = createNewTreeNode(entry, 1);
            if(newChild->typeOfFile ==std::filesystem::file_type::directory){
                push(newChild, newChild->depth+1);
            }
            newChildren.insert(newChild);
        }
        root->children = newChildren;
    }
//    return nullptr;
}

template<typename T>
void NaryTree<T>::print() {
    print(root);
}

template<typename T>
TreeNode<T> *NaryTree<T>::find(TreeNode<T> *parent, T data) {
    if (parent) {
        for (TreeNode<T> *t: parent->children) {
            if (t->data == data) {
                return t;
            }
        }
    }
    // Directory/Folder/File
    //if directory exists,try to go inside and see;
    //if folder directory exists, then go inside and push.
    //file exists, check if it can read or not.
    return nullptr;
}

#endif

