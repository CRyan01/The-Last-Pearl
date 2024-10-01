//Enemy.cpp
#include "Enemy.h"
#include "TextureHolder.h"
#include <cstdlib>
#include <ctime>

using namespace std;

bool Enemy::hit(int damage) {
    m_Health -= damage;

    if (m_Health <= 0) {
        m_Alive = false;
        m_Sprite.setTexture(TextureHolder::GetTexture("graphics/destroyed.png"));
        // Enemy is dead
        return true; 
    }
    // Enemy is still alive
    return false;
}

bool Enemy::isAlive() 
{
    return m_Alive;
}

FloatRect Enemy::getPosition() 
{
    return m_Sprite.getGlobalBounds();
}

Sprite Enemy::getSprite() 
{
    return m_Sprite;
}

// Code from zombie to face a target ie. Guards
void Enemy::update(float elapsedTime, Vector2f targetLocation)
{
    float targetX = targetLocation.x;
    float targetY = targetLocation.y;

    if (targetX > m_Position.x)
    {
        m_Position.x += m_Speed * elapsedTime;
    }
    if (targetY > m_Position.y)
    {
        m_Position.y += m_Speed * elapsedTime;
    }
    if (targetX < m_Position.x)
    {
        m_Position.x -= m_Speed * elapsedTime;
    }
    if (targetY < m_Position.y)
    {
        m_Position.y -= m_Speed * elapsedTime;
    }
    // if we're going with the idea of using a spawn tower which spawns guards we can make the enemies fight the guards
    // Move the sprite and rotate towards target
    m_Sprite.setPosition(m_Position);
    float angle = (atan2(targetY - m_Position.y, targetX - m_Position.x) * 180) / 3.141;
    m_Sprite.setRotation(angle);
}