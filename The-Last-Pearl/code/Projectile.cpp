#include "Projectile.h"
#include <iostream>
// By Conor Ryan

// Constructor
void Projectile::Spawn(float damage, float speed, const std::string& textureFile, sf::Vector2f spawn, Enemy* target, float maxRange)
{
    m_Damage = damage;
    m_Speed = speed;
    m_Active = true;
    m_StartPosition = spawn;
    m_TargetEnemy = target;
    m_MaxRange = maxRange;

    m_Sprite.setTexture(TextureHolder::GetTexture(textureFile));
    m_Sprite.setPosition(spawn);

    // Calculate initial direction towards the target enemy
    if (m_TargetEnemy) {
        Vector2f direction = m_TargetEnemy->getSprite().getPosition() - spawn;
        float length = sqrt(direction.x * direction.x + direction.y * direction.y);
        if (length > 0.1f) {
            direction /= length;
            m_Velocity = direction * m_Speed;
        }
    }
}


// Update the projectiles position based on velocity
void Projectile::update(float elapsedTime)
{
    if (m_Active && m_TargetEnemy && m_TargetEnemy->isAlive())
    {
        // Calculate the distance traveled from the starting position
        sf::Vector2f currentPos = m_Sprite.getPosition();
        float distanceTraveled = std::sqrt(
            (currentPos.x - m_StartPosition.x) * (currentPos.x - m_StartPosition.x) +
            (currentPos.y - m_StartPosition.y) * (currentPos.y - m_StartPosition.y)
        );

        // Check if the projectile has exceeded its maximum range
        if (distanceTraveled > m_MaxRange)
        {
            setInactive();
            return;
        }

        // Update direction toward the moving target
        sf::Vector2f direction = m_TargetEnemy->getSprite().getPosition() - currentPos;
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if (length > 0.1f)
        {
            direction /= length;
            m_Velocity = direction * m_Speed;
        }

        // Move the projectile toward the enemy
        m_Sprite.move(m_Velocity * elapsedTime);
    }
    else
    {
        setInactive();  // Deactivate if theres no target or the target is dead
    }
}
// Checks if the projectile collides with an enemy's bounds
bool Projectile::checkCollision(const sf::FloatRect& enemyBounds)
{
    return m_Sprite.getGlobalBounds().intersects(enemyBounds);
}

void Projectile::setInactive()
{
    m_Active = false;
  //  std::cout << "Projectile set to inactive.\n";
}

// Return true if the projectile is active
bool Projectile::isActive() const 
{
    return m_Active;
}

// Returns the projectiles sprite
const Sprite& Projectile::getSprite() const 
{
    return m_Sprite;
}

float Projectile::getDamage() const {
    return m_Damage;
}