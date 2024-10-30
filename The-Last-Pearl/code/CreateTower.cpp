
#include "TheLastPearl.h"
#include "Tower.h"


//Tower TheLastPearl::createTower(Tower::TowerType type, float x, float y) {
    // Spawn the correct tower
//    Tower tower = createTower(type, x, y);
//    tower.initialize(x, y); // Set its position
//
    // Add the tower to the list of towers to draw it later
  //  towers.push_back(tower);
    // Default
 //   return Tower(Tower::TowerType::MusketTower, 0, 0, 0, "graphics/tower.png");
//}

Tower TheLastPearl::createTower(Tower::TowerType type, float x, float y) {
    Tower tower;

    // Spawn the correct tower based on the type
    if (type == Tower::TowerType::MusketTower) {
        tower = Tower(type, 15, 120, 1.5f, "graphics/musketTower.png");
    } else if (type == Tower::TowerType::CannonTower) {
        tower = Tower(type, 30, 150, 2.5f, "graphics/cannonTower.png");
    } else {
        // Default case
        tower = Tower(Tower::TowerType::MusketTower, 0, 0, 0, "graphics/tower.png");
    }

    // Set its position and initialize
    tower.initialize(x, y);

    // Add the tower to the list of towers to draw it later
    towers.push_back(tower);

    // Return the created tower (if needed for further use)
    return tower;
}