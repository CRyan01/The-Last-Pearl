// Wave.cpp
#include "Wave.h"

// Constructor that initializes enemies based on the wave number
Wave::Wave(int waveNumber) 
{
    if (waveNumber <= 5) 
    {
        // First 5 waves: only Buccaneers
        enemies = std::vector<EnemyType>(waveNumber * 5, BUCCANEER);
    }
    else if (waveNumber <= 8) {
        // Waves 6-8: introduce Pirates alongside Buccaneers
        enemies = std::vector<EnemyType>(waveNumber * 3, BUCCANEER);
        enemies.insert(enemies.end(), waveNumber * 2, PIRATE);
    }
    else {
        // Last two waves (9-10): introduce Captains along with Buccaneers and Pirates
        enemies = std::vector<EnemyType>(waveNumber * 2, BUCCANEER);
        enemies.insert(enemies.end(), waveNumber * 2, PIRATE);
        enemies.insert(enemies.end(), waveNumber, CAPTAIN);
    }
}

// Returns the vector of enemies for this wave
std::vector<EnemyType> Wave::getEnemies() const 
{
    return enemies;
}