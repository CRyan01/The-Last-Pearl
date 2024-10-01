// BuccaneerEnemy.h
#pragma once
#include "Enemy.h"

class BuccaneerEnemy : public Enemy
{
public:
    void spawn(float startX, float startY, int seed) override;
    void update(float elapsedTime, Vector2f targetLocation) override;
};