#pragma once
#include "Tower.h"

// By Conor Ryan
class CannonTower : public Tower {
public:
    CannonTower(float x, float y);

    void shoot() override;
};
