//
// Created by Marthel Rodriguez on 11/11/23.
//

#include "States.h"
States::States() {
    for (int i = 0; i < LAST_STATE; i++) {
        //go through the states map, enable to false.
        states[static_cast<statesEnum>(i)] = false;
    }
}

bool States::checkState(statesEnum state) const{
    return states.at(state);
}

void States::enableState(statesEnum state) {
    states[state] = true;
}

void States::disabledState(statesEnum state) {
    states[state] = false;
}

void States::toggleState(statesEnum state) {
    states[state] = !states[state];
}

