// PirateEnemy.h
#pragma once
#include "Enemy.h"

class PirateEnemy : public Enemy 
{
public:
    void spawn(float startX, float startY, int seed) override;
    void update(float elapsedTime, Vector2f targetLocation) override;
};