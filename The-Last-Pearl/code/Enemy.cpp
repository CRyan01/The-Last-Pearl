// Enemy.cpp
// Jakub Nowak | K00285355
// Base Enemy class to be inherited by enemy types
#include "Enemy.h"
#include "TextureHolder.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// Handles enemy taking damage
// Returns true when the enemy dies and false if it's still alive
bool Enemy::hit(int damage) {
    m_Health -= damage;

    if (m_Health <= 0) {
        // Set the enemy as dead and change the sprite to destroyed
        m_Alive = false;
        m_Sprite.setTexture(TextureHolder::GetTexture("graphics/destroyed.png"));
        // Enemy is dead
        return true; 
    }
    // Enemy is still alive
    return false;
}
// Returns if the enemy is still alive
bool Enemy::isAlive() 
{
    return m_Alive;
}
// Returns the postition of enemy, used in collision detection
FloatRect Enemy::getPosition() 
{
    return m_Sprite.getGlobalBounds();
}
// Returns enemy sprite for rendering
Sprite Enemy::getSprite() 
{
    return m_Sprite;
}

void Enemy::setWaypoints(const std::vector<Vector2f> & waypoints)
{
    this-> waypoints = waypoints; // store waypoints
    currentWaypointIndex = 0;  // Start at the first waypoint
    m_Position = waypoints[currentWaypointIndex];  // Set initial position
    m_Sprite.setPosition(m_Position);
}


// Update method for all dervied enemy classes, which moves the enemy from waypoint
// to waypoint until they reach the end
void Enemy::update(float elapsedTime, Vector2f targetLocation)
{

    cout << "Enemy Health: " << m_Health << ", Alive: " << m_Alive << endl;
    if (currentWaypointIndex < waypoints.size())
    {
        // Get the current waypoint
        Vector2f waypoint = waypoints[currentWaypointIndex];

        // Move towards the waypoint
        if (m_Position.x < waypoint.x) m_Position.x += m_Speed * elapsedTime;
        if (m_Position.x > waypoint.x) m_Position.x -= m_Speed * elapsedTime;
        if (m_Position.y < waypoint.y) m_Position.y += m_Speed * elapsedTime;
        if (m_Position.y > waypoint.y) m_Position.y -= m_Speed * elapsedTime;

        const float threshold = 1.0f;
        if (abs(m_Position.x - waypoint.x) < threshold && abs(m_Position.y - waypoint.y) < threshold)
        {
            currentWaypointIndex++;  // Move to the next waypoint
        }
    }
    else
    {
        //This is where the logic for taking health away form the pearl
        // will go but for now it will just mark the enemies as dead
        m_Alive = false; // Mark enemy as dead
    }
    // Update sprite position
    m_Sprite.setPosition(m_Position);
}