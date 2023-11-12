//
// Created by Marthel Rodriguez on 11/10/23.
//

#ifndef SFMLTEMPLATE_ACTIONS_H
#define SFMLTEMPLATE_ACTIONS_H

/*
 * WRITE, DELETE
 * */
enum ActionsEnum{WRITE, DELETE, SLIDE};
enum ComponentEnum{TEXTINPUT, SLIDER};

struct Action{
    char letter;
    ActionsEnum action;
    ComponentEnum component;
};
#endif //SFMLTEMPLATE_ACTIONS_H
