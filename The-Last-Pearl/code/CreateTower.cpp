
#include "TowerManager.h"


void TowerManager::createTower(Tower::TowerType type, float x, float y) {
    Tower tower;
    
    // Spawn the correct type of tower
    if (type == Tower::TowerType::MusketTower) {
        tower = Tower(type, 15, 300, 10.0, "graphics/musketTower.png");
    } else if (type == Tower::TowerType::CannonTower) {
        tower = Tower(type, 30, 150, 5.0, "graphics/cannonTower.png");
    }

    // Set the towers position
    tower.initialize(x, y);

    // Add the tower to the list of towers
    AllGameTowers.push_back(tower);


}