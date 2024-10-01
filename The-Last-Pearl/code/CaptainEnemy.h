// CaptainEnemy.h
#pragma once
#include "Enemy.h"

class CaptainEnemy : public Enemy 
{
public:
    void spawn(float startX, float startY, int seed) override;
    bool hit(int damage) override;  // Override hit to reduce damage
};