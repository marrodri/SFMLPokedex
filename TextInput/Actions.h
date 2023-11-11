//
// Created by Marthel Rodriguez on 11/10/23.
//

#ifndef SFMLTEMPLATE_ACTIONS_H
#define SFMLTEMPLATE_ACTIONS_H

enum ActionsEnum{WRITE, DELETE};

struct Action{
    char letter;
    ActionsEnum action;

};
#endif //SFMLTEMPLATE_ACTIONS_H
