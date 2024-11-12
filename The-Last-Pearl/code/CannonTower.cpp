#include "CannonTower.h"
#include "TextureHolder.h"

// By Conor Ryan
CannonTower::CannonTower(float x, float y)
    : Tower(TowerType::CannonTower, 30, 350, 2.5f, "graphics/cannonTower.png") {  // Initialize with specific attributes
    initialize(x, y);
}

void CannonTower::shoot(const sf::Vector2f& targetPosition, ProjectileHolder& projectileHolder) {
    Tower::shoot(targetPosition, projectileHolder);  
}