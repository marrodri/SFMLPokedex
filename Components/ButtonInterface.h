//
// Created by Marthel Rodriguez on 11/24/23.
//

#ifndef SFMLTEMPLATE_BUTTONINTERFACE_H
#define SFMLTEMPLATE_BUTTONINTERFACE_H

/**
 * Protected MainScreenButton Interface
 * */
class ButtonInterface{
    virtual void onClick() = 0;
    virtual void setOnClickFunction()=0;
    virtual void onHoverSound() = 0;
    virtual void onClickSound() = 0;
};

#endif //SFMLTEMPLATE_BUTTONINTERFACE_H
