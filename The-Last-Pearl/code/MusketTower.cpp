#include "MusketTower.h"
#include "TextureHolder.h"

// By Conor Ryan
MusketTower::MusketTower(float x, float y) 
    : Tower(TowerType::MusketTower, 15, 320, 1.5f, "graphics/musketTower.png") {  // Initialize with specific attributes
    initialize(x, y);
}

void MusketTower::shoot(const sf::Vector2f& targetPosition, ProjectileHolder& projectileHolder) {
    Tower::shoot(targetPosition, projectileHolder);
}