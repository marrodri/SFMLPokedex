//
// Created by Marthel Rodriguez on 11/11/23.
//

#ifndef SFMLTEMPLATE_HISTORY_H
#define SFMLTEMPLATE_HISTORY_H

#include <stack>
#include "HistoryNode.h"
class History {
private:
     std::stack<HistoryNode> previousActions;
public:
    History();

     void pushNewAction(char letter, ActionsEnum action, ComponentEnum component);
     HistoryNode undoAction();
     bool empty();
};


#endif //SFMLTEMPLATE_HISTORY_H
