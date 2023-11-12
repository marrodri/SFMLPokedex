//
// Created by Marthel Rodriguez on 11/11/23.
//

#ifndef SFMLTEMPLATE_UNDO_H
#define SFMLTEMPLATE_UNDO_H

#include <stack>
#include "Actions.h"
class Undo {
private:
     std::stack<Action> previousActions;
public:
    Undo();

     void pushNewAction(char letter, ActionsEnum action, ComponentEnum component);
     Action undoAction();
     bool empty();
};


#endif //SFMLTEMPLATE_UNDO_H
