//
// Created by Marthel Rodriguez on 12/6/23.
//

#include "AppHandler.h"

std::string AppHandler::searchInput;

/**
 * searchInput methods
 **/
std::string AppHandler::getSearchInput() {
    return searchInput;
}

void AppHandler::updateSearchInput(const std::string &input) {
    searchInput = input;
}

/**
 * menu Methods
 **/
void AppHandler::closeProgram() {
    std::cout << "running closeProgram from AppHandler" << std::endl;
}

void AppHandler::openFileTree() {
    std::cout << "running openFileTree from AppHandler" << std::endl;
    std::cout << "OPENING FILE TREE SCREEN" << std::endl;
}

void AppHandler::changeBackground() {
    std::cout << "running changeBackground from AppHandler" << std::endl;
}

void AppHandler::changeFontFamily() {
    std::cout << "running changeFontFamily from AppHandler" << std::endl;
}

void AppHandler::changeFontColor() {
    std::cout << "running changeFontColor from AppHandler" << std::endl;
}




