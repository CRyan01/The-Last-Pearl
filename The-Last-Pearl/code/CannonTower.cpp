#include "CannonTower.h"
#include "TextureHolder.h"

// By Conor Ryan
CannonTower::CannonTower(float x, float y)
    : Tower(TowerType::CannonTower, 30, 350, 2.5f, "graphics/cannonTower.png") {  // Initialize with specific attributes
    initialize(x, y);
}
// Shoots a projectile at a specified enemy target
void CannonTower::shoot(Enemy* targetEnemy, ProjectileHolder& projectileHolder) {
    Tower::shoot(targetEnemy, projectileHolder);  // Calls base class shoot function
}