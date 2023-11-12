//
// Created by Marthel Rodriguez on 11/11/23.
//

#include "Undo.h"

//initializing static variables.


Undo::Undo() {

}

void Undo::pushNewAction(char letter, ActionsEnum action, ComponentEnum component) {
    Action newAction = Action({letter, action, component});

//    Action newAction = Action({'b', WRITE, TEXTINPUT});
    previousActions.push(newAction);
}

Action Undo::undoAction() {
    Action undoAction = previousActions.top();
    previousActions.pop();
    return undoAction;
}

bool Undo::empty(){
    return previousActions.empty();
}
