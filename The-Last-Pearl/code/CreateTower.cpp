
#include "TowerManager.h"


void TowerManager::createTower(Tower::TowerType type, float x, float y) {
    Tower tower;
    
    // Spawn the correct type of tower
    if (type == Tower::TowerType::MusketTower) {
        tower = Tower(type, 15, 300, 1.5f, "graphics/musketTower.png");
    } else if (type == Tower::TowerType::CannonTower) {
        tower = Tower(type, 30, 300, 2.5f, "graphics/cannonTower.png");
    }

    // Set the towers position
    tower.initialize(x, y);

    // Add the tower to the list of towers
    AllGameTowers.push_back(tower);


}