//
// Created by Marthel Rodriguez on 11/11/23.
//

#include "History.h"

//initializing static variables.


History::History() {

}

void History::pushNewAction(char letter, ActionsEnum action, ComponentEnum component) {
    HistoryNode newAction = HistoryNode({letter, action, component});

//    Action newAction = Action({'b', WRITE, TEXTINPUT});
    previousActions.push(newAction);
}

HistoryNode History::undoAction() {
    HistoryNode undoAction = previousActions.top();
    previousActions.pop();
    return undoAction;
}

bool History::empty(){
    return previousActions.empty();
}
