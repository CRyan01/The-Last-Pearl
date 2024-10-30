#pragma once

#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

using namespace sf;

// By Conor Ryan
class Projectile {
public:
    // Constructor
    Projectile(float damage, float speed, const std::string& textureFile); 

    // Initialize the projectile
    void initialize(float startX, float startY);

    // Updates the projectile
    void update(float elapsedTime);

    // Returns true if the projectile is active
    bool isActive() const;

    // Returns the projectiles sprite
    Sprite getSprite() const;

    // Set the projectiles velocity
    void setVelocity(Vector2f velocity);

private:
    float m_Damage;
    float m_Speed;
    Vector2f m_Velocity;
    Sprite m_Sprite;
    bool m_Active;
};