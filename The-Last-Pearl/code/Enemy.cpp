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
        //we dont have this texture anymore need to get it again
       // m_Sprite.setTexture(TextureHolder::GetTexture("graphics/destroyed.png"));
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

//this is important for movement enemy will now move to the set Position
void Enemy::update(float elapsedTime)
{
   
        // Move towards the waypoint
        if (m_Position.x < CurrentTarget.x) m_Position.x += m_Speed * elapsedTime;
        if (m_Position.x > CurrentTarget.x) m_Position.x -= m_Speed * elapsedTime;
        if (m_Position.y < CurrentTarget.y) m_Position.y += m_Speed * elapsedTime;
        if (m_Position.y > CurrentTarget.y) m_Position.y -= m_Speed * elapsedTime;
        //problem tooo straight
        //abs= no negtive
        const float threshold = 10;
        if (abs(m_Position.x - CurrentTarget.x) < threshold && abs(m_Position.y - CurrentTarget.y) < threshold)
        {
            HasReachedPos = true;  // tells game ot move to next piont
        }
    
    // Update sprite position
    m_Sprite.setPosition(m_Position);
}

bool Enemy::ReachedPos()
{
    return HasReachedPos;

}
//this set the new target for enemy
void Enemy::SetNewTarget(Vector2f newTarget)
{
    CurrentTarget = newTarget;
    HasReachedPos = false; 


}

int Enemy::Damage()
{
    return Enemydamage;

}

int Enemy::getHealth()
{
    return m_Health;
}
