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
    Wave(int LevelNumber);

    // Initializes enemy objects based on enemy type
    void initializeEnemies(float dtAsSeconds);

    // Updates each enemy in the wave
    void updateEnemies(float dtAsSeconds,  Paths& path);

    // Returns true if all enemies are dead
    bool isWaveComplete() ;

    // get active enemies
    vector<Enemy*> getActiveEnemies() const;

    void NextWave();

    int GetDamage();
    int GetMoney();

    bool IsLevelOver();

private:
    vector<EnemyType> enemies; // Holds types of enemies in the wave
    vector<std::unique_ptr<Enemy>> activeEnemies;  // Active enemies in the wave
    float spawnDelay = 1.5f; // Delay of 0.5 seconds between enemy spawns
    float elapsedTime = 0.0f; 
    int CurrentWave=0;
    int Damage = 0;
    bool LevelComplete = false; // Track wave completion status
    int CurrentMaxWave = 11;
       //all damage collected
    int CollectedDamage = 0;
    //Money Collection for player

    int MoneyTotal = 0;

    Vector2f enemySpawnPos;
};