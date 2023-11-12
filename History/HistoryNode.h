//
// Created by Marthel Rodriguez on 11/10/23.
//

#ifndef SFMLTEMPLATE_HISTORYNODE_H
#define SFMLTEMPLATE_HISTORYNODE_H

/*
 * WRITE, DELETE
 * */
enum ActionsEnum{WRITE, DELETE, SLIDE};
enum ComponentEnum{TEXTINPUT, SLIDER};

struct HistoryNode{
    char letter;
    ActionsEnum action;
    ComponentEnum component;
};


/**
 * Main struct
 * struct HistoryNode{
 *     Snapshot snapshot;
 *     GUIComponent* component;
 * }
 * */
#endif //SFMLTEMPLATE_HISTORYNODE_H
