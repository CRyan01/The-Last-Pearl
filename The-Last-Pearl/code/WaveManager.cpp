// WaveManager.cpp
#include "WaveManager.h"
#include "Wave.h"

// Constructor that initializes 10 waves for each level
WaveManager::WaveManager(int levelNumber) : currentWaveIndex(0) {
    for (int i = 1; i <= 10; i++) {
        wave.emplace_back(Wave(i)); // Create and store waves in the vector
    }
}

// Returns the current wave 
Wave WaveManager::getCurrentWave() const {
    return wave[currentWaveIndex];
}

// Checks if more waves are available
bool WaveManager::hasMoreWaves() const {
    return currentWaveIndex < wave.size();
}

// Advances to the next wave
void WaveManager::nextWave() {
    if (hasMoreWaves()) {
        currentWaveIndex++;
    }
}