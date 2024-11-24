
#include "TowerManager.h"
// Here is where the base values for the towers can be changed:
// Like damage, range and fire rate. -Jakub

void TowerManager::createTower(Tower::TowerType type, float x, float y) {
    Tower tower;
    
    // Spawn the correct type of tower
    if (type == Tower::TowerType::MusketTower) {
        tower = Tower(type, 100, 400, 1.5, "graphics/musketTower.png");
    } else if (type == Tower::TowerType::CannonTower) {
        tower = Tower(type, 30, 250, 8.0, "graphics/cannonTower.png");
    }

    // Set the towers position
    tower.initialize(x, y);

    // Add the tower to the list of towers
    AllGameTowers.push_back(tower);
}