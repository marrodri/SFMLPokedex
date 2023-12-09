//
// Created by Marthel Rodriguez on 11/20/23.
//

#ifndef SFMLTEMPLATE_TREENODE_H
#define SFMLTEMPLATE_TREENODE_H
#include <string>
#include <vector>
#include <set>
#include <filesystem>

template<typename T>
struct TreeNode{
    T data;
    int depth = 0;
    std::string path;
    std::string fileName;
    std::set<TreeNode*> children;
    std::filesystem::file_type typeOfFile;

};
#endif //SFMLTEMPLATE_TREENODE_H
