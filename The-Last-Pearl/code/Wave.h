// Wave.h
#pragma once
#include "Enemy.h"
#include "BuccaneerEnemy.h"
#include "PirateEnemy.h"
#include "CaptainEnemy.h"
#include "Paths.h"
#include <vector>
#include <memory>

using namespace std;

// Define enemy types as an enums
enum EnemyType { BUCCANEER, PIRATE, CAPTAIN };

class Wave {
public:
    // Constructor that initializes the wave 
    Wave(int waveNumber);

    // Initializes enemy objects based on enemy type
    void initializeEnemies(float dtAsSeconds);

    // Updates each enemy in the wave
    void updateEnemies(float dtAsSeconds, const Paths& path);

    // Returns true if all enemies are dead
    bool isWaveComplete() const;

    // Ability to get active enemies
    const vector<Enemy*>& getActiveEnemies() const;

private:
    vector<EnemyType> enemies; // Holds types of enemies in the wave
    vector<unique_ptr<Enemy>> activeEnemies; // Stores unique pointers 
    float spawnDelay = 0.5f; // Delay of 0.5 seconds between enemy spawns
    float elapsedTime = 0.0f; 
    //bool waveComplete = true; // Track wave completion status
};