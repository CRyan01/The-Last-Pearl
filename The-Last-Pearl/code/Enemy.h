// Enemy.h
// Jakub Nowak | K00285355
// Base Enemy class to be inherited by enemy types
#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Enemy
{
protected:
    // Enemy attributes
    Vector2f m_Position;
    Sprite m_Sprite;
    float m_Speed;
    int m_Health;
    bool m_Alive = true;

    // Constants to control speed variance
    const int MAX_SPEED = 30;  // Maximum speed variance
    const int OFFSET = 70;        // Minimum speed multiplier (70%)

public:
    // Virtual function to handle enemy's spawning (to be implemented by derived classes)
    virtual void spawn(float startX, float startY, int seed);

    // Handle enemy taking damage (Virtual function so it can be overidden by specific enemy types)
    virtual bool hit(int damage);

    // Check if enemy is still alive
    bool isAlive();

    // Get the position of the enemy
    FloatRect getPosition();

    // Get the sprite representing the enemy
    Sprite getSprite();

    // Update the enemy's movement based on target's location
    virtual void update(float elapsedTime, Vector2f targetLocation);
};