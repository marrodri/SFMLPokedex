//
// Created by Marthel Rodriguez on 12/6/23.
//

#ifndef SFMLTEMPLATE_APPHANDLER_H
#define SFMLTEMPLATE_APPHANDLER_H
#include <iostream>
#include <string>

class AppHandler {
private:
    static std::string searchInput;
public:
    /**
     * searchInput methods
     **/
    static void updateSearchInput(const std::string &input);
    static std::string getSearchInput();



    /**
     * menu bar configuration.
     **/


    /**
     * fileTree configuration.
     **/

};


#endif //SFMLTEMPLATE_APPHANDLER_H