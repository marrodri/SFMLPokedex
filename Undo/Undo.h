//
// Created by Marthel Rodriguez on 11/11/23.
//

#ifndef SFMLTEMPLATE_UNDO_H
#define SFMLTEMPLATE_UNDO_H

#include <stack>
#include "Actions.h"
class Undo {
private:
    static std::stack<Action> previousActions;
public:
    Undo();

    static void pushNewAction(char letter, ActionsEnum action, ComponentEnum component);
    static Action undoAction();
};


#endif //SFMLTEMPLATE_UNDO_H
