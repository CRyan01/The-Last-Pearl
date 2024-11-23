#include "SoundManager.h"
#include <iostream>

// Constructor
SoundManager::SoundManager() {}

// Load a sound effect and store it in the map
void SoundManager::loadSound(const std::string& name, const std::string& filepath) {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(filepath)) {
        std::cerr << "Failed to file: " << filepath << std::endl;
        return;
    }
    soundBuffers[name] = buffer;
    sounds[name].setBuffer(soundBuffers[name]);
}

// Play a sound effect by name
void SoundManager::playSound(const std::string& name) {
    if (sounds.find(name) != sounds.end()) {
        sounds[name].play();
    } else {
        std::cerr << "Sound not found: " << name << std::endl;
    }
}

// Play background music from a file
void SoundManager::playBackgroundMusic(const std::string& filepath, bool loop) {
    if (!backgroundMusic.openFromFile(filepath)) {
        std::cerr << "Failed to load file: " << filepath << std::endl;
        return;
    }
    backgroundMusic.setLoop(loop);
    backgroundMusic.play();
}

// Stop background music
void SoundManager::stopBackgroundMusic() {
    backgroundMusic.stop();
}