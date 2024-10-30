// Wave.h
#pragma once
#include <vector>

// Define enemy types as a enum
enum EnemyType { BUCCANEER, PIRATE, CAPTAIN };

class Wave {
public:
    // Constructor that initializes the wave 
    Wave(int waveNumber);

    // Returns a list of enemies for this wave
    std::vector<EnemyType> getEnemies() const;

private:
    std::vector<EnemyType> enemies; // Holds types of enemies in the wave
};