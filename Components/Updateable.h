//
// Created by Marthel Rodriguez on 10/12/23.
//

#ifndef SFMLTEMPLATE_UPDATEABLE_H
#define SFMLTEMPLATE_UPDATEABLE_H

//constantly updating each second that is passed by.
class Updateable {
public:
    virtual void update() = 0;
};

#endif //SFMLTEMPLATE_UPDATEABLE_H
