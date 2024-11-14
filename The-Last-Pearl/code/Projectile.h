#pragma once

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "TextureHolder.h"

using namespace sf;

// By Conor Ryan
class Projectile {
public:
    // Constructor
    void Spawn(float damage, float speed, const std::string& textureFile, sf::Vector2f spawn, Enemy* target, float maxRange);


    // Initialize the projectile
    void initialize(Vector2f spawn);

    // Updates the projectile
    void update(float elapsedTime);

    bool checkCollision(const FloatRect& enemyBounds) const;

    // Returns true if the projectile is active
    bool isActive() const;

    bool checkCollision(const FloatRect& enemyBounds);

    void setInactive();

    float getDamage() const;

    // Returns the projectile's sprite
    const Sprite& getSprite() const;

    // Set the projectiles velocity
    void setVelocity(Vector2f velocity);

private:
    Enemy* m_TargetEnemy = nullptr;    
    sf::Vector2f m_StartPosition;      
    float m_MaxRange = 0.0f;           
    sf::Vector2f m_PreviousPosition;
    float m_Damage;
    float m_Speed;
    Vector2f m_Velocity;
    Sprite m_Sprite;
    bool m_Active = false;

};