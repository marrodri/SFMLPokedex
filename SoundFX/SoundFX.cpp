//
// Created by Marthel Rodriguez on 11/16/23.
//

#include "SoundFX.h"


//path to use to fetch and use the sound effect.
//Resources/SFX/hover_sound.wav

sf::SoundBuffer SoundFX::soundBufferHover;
sf::SoundBuffer SoundFX::soundBufferClick;
sf::SoundBuffer SoundFX::soundBufferBack;
sf::Sound SoundFX::hoverSound;
sf::Sound SoundFX::clickSound;

SoundFX::SoundFX() {
    if(!soundBufferHover.loadFromFile("Resources/SFX/hover_sound.wav")){
        std::cout <<"ERROR IN LOADING HOVER WAV SOUND";
    }
    else{
        std::cout << "hover sound loaded\n";
        hoverSound.setBuffer(soundBufferHover);
    }
}

void SoundFX::playHoverSound() {
    if (!soundBufferHover.loadFromFile("Resources/SFX/hover_sound.wav")) {
        std::cout <<"ERROR IN LOADING HOVER WAV SOUND";
    }
    else {
        std::cout << "hover sound loaded\n";
        hoverSound.setBuffer(soundBufferHover);
    }
    hoverSound.play();
}


void SoundFX::playClickSound() {
    if (!soundBufferClick.loadFromFile("Resources/SFX/accept_sound.wav")) {
        std::cout <<"ERROR IN LOADING Click WAV SOUND";
    }
    else {
        std::cout << "hover sound loaded\n";
        clickSound.setBuffer(soundBufferClick);
    }
    clickSound.play();
}
