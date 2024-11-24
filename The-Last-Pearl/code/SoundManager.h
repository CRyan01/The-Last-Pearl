#pragma once

#include <SFML/Audio.hpp>
#include <map>
#include <string>

using namespace sf;

class SoundManager {
private:
    Music backgroundMusic; // The background music

    // Map container for sound buffers and sounds, uses the a string and the sound as kvp
    std::map<std::string, sf::SoundBuffer> soundBuffers;
    std::map<std::string, sf::Sound> sounds;

public:
    SoundManager(); // Constructor

    // Load a sound and stire it in the map
    void loadSound(const std::string& name, const std::string& filepath);

    // Play a sound by name
    void playSound(const std::string& name);

    // Play background music
    void playBackgroundMusic(const std::string& filepath, bool loop = true);

    // Stop background music
    void stopBackgroundMusic();
};