#include "CannonTower.h"
#include "TextureHolder.h"

// By Conor Ryan
CannonTower::CannonTower(float x, float y)
    : Tower(30, 150, 2.5f, "graphics/cannonTower.png") {  // Initialize with specific attributes
    initialize(x, y);
}

void CannonTower::shoot() {
    if (canShoot()) {
        // Cannon-specific shooting logic
        m_TimeSinceLastShot = 0;
    }
}
