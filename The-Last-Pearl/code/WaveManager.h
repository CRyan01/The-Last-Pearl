// WaveManager.h
#pragma once
#include <vector>
#include "Wave.h"

class WaveManager {
public:

    WaveManager() : currentWaveIndex(0) {} // Default constructor
    // Initialize the WaveManager with a level number and load waves
    WaveManager(int levelNumber);

    // Get the current wave object
    Wave getCurrentWave() const;

    // Check if there are more waves to proceed to
    bool hasMoreWaves() const;

    // Move to the next wave
    void nextWave();

private:
    int currentWaveIndex; // Tracks the current wave
    std::vector<Wave> wave; // Vector holding all waves for the level
};