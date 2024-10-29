#include "MusketTower.h"
#include "TextureHolder.h"

// By Conor Ryan
MusketTower::MusketTower(float x, float y) : Tower(15, 120, 1.5f, "graphics/musketTower.png") {  // Initialize with specific attributes
    initialize(x, y);
}

void MusketTower::shoot() {
    if (canShoot()) {
        // Musket-specific shooting logic
        m_TimeSinceLastShot = 0;
    }
}