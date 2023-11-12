//
// Created by Marthel Rodriguez on 11/11/23.
//

#ifndef SFMLTEMPLATE_STATES_H
#define SFMLTEMPLATE_STATES_H

#include "statesEnum.h"
#include <map>
class States {
private:
    std::map<statesEnum, bool> states;

public:
    States();
    //pass the state, return true if its the passed state set or
    //false if its a different state set.
    bool checkState(statesEnum state) const;
    void enableState(statesEnum state);
    void disabledState(statesEnum state);
    void toggleState(statesEnum state);
};


#endif //SFMLTEMPLATE_STATES_H
