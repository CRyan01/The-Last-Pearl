#include "MusketTower.h"
#include "TextureHolder.h"

// By Conor Ryan
MusketTower::MusketTower(float x, float y) 
    : Tower(TowerType::MusketTower, 15, 320, 1.5f, "graphics/musketTower.png") {  // Initialize with specific attributes
    initialize(x, y);
}
// Shoots a projectile at a specified enemy target
void MusketTower::shoot(Enemy* targetEnemy, ProjectileHolder& projectileHolder) {
    Tower::shoot(targetEnemy, projectileHolder);  // Calls base class shoot function
}