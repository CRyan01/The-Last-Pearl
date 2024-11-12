#pragma once
#include "Tower.h"

// By Conor Ryan
class MusketTower : public Tower {
public:
    MusketTower(float x, float y);

    void shoot(const sf::Vector2f& targetPosition, ProjectileHolder& projectileHolder);
};
