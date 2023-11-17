//
// Created by Marthel Rodriguez on 11/16/23.
//

#ifndef SFMLTEMPLATE_SOUNDFX_H
#define SFMLTEMPLATE_SOUNDFX_H

#include <SFML/Audio.hpp>
#include <iostream>
class SoundFX {
private:
    static sf::SoundBuffer soundBufferHover;
    static sf::SoundBuffer soundBufferClick;
    static sf::SoundBuffer soundBufferBack;
    static sf::Sound hoverSound;
    static sf::Sound clickSound;
public:
    SoundFX();

    static void playHoverSound();
    static void playClickSound();
};


#endif //SFMLTEMPLATE_SOUNDFX_H
