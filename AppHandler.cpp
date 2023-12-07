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



