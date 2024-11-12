#pragma once
#include "Tower.h"

// By Conor Ryan
class CannonTower : public Tower {
public:
    CannonTower(float x, float y);

    void shoot(const sf::Vector2f& targetPosition, ProjectileHolder& projectileHolder);
};
