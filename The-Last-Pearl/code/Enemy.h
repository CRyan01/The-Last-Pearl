// Enemy.h
// Jakub Nowak | K00285355
// Base Enemy class to be inherited by enemy types
#pragma once
#include <SFML/Graphics.hpp>
#include <vector> // Include vector header

using namespace sf;

class Enemy
{
protected:
    // Enemy attributes
    Vector2f m_Position;
    Sprite m_Sprite;
    Vector2u m_Size;
    float m_Speed;
    int m_Health;
    bool m_Alive = true;
    //damage to pearl
    int Enemydamage = 20;
    // Constants to control speed variance
    const int MAX_SPEED = 30;  // Maximum speed variance
    const int OFFSET = 70;        // Minimum speed multiplier (70%)

    int currentWaypointIndex; // Track the current waypoint

    Vector2f CurrentTarget;

    bool HasReachedPos=false;
public:
    // Virtual function to handle enemy's spawning (to be implemented by derived classes)
    virtual void spawn(float startX, float startY, int seed) = 0;

    // Handle enemy taking damage (Virtual function so it can be overridden by specific enemy types)
    virtual bool hit(int damage);

    // Check if enemy is still alive
    bool isAlive();

    // Get the position of the enemy
    FloatRect getPosition();

    // Get the sprite representing the enemy
    Sprite getSprite();

    // Update the enemy's movement based on target's location
    virtual void update(float elapsedTime);

 
    //has it reached where it needs ot go
    bool ReachedPos();
    //setting its new palce to go
    void SetNewTarget(Vector2f newPos);

    //for when enemy makes it to the ending damage to pearl
    int Damage();

    int currentPos=-1;
};