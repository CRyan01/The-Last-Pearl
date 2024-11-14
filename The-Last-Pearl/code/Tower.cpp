#include "Tower.h"
#include "TextureHolder.h"
#include <iostream>
Tower::Tower()
{
    m_Type = TowerType::None;
    m_Damage = 0;
    m_Range = 0;
    m_FireRate = 0;
    m_TimeSinceLastShot = 0;
    m_Active = false;
    m_Sprite.setTexture(TextureHolder::GetTexture("graphics/crossbowTower.png"));
    m_Sprite.setOrigin(m_Sprite.getTexture()->getSize().x / 2.0f, m_Sprite.getTexture()->getSize().y / 2.0f);
}

Tower::Tower(TowerType type, float damage, float range, float fireRate, const std::string& textureFile) 
{
    m_Type = type;
    m_Damage = damage;
    m_Range = range;
    m_FireRate = fireRate;
    m_TimeSinceLastShot = 0;
    m_Active = true;

    m_Sprite.setTexture(TextureHolder::GetTexture(textureFile));
    m_Sprite.setOrigin(m_Sprite.getTexture()->getSize().x / 2.0f, m_Sprite.getTexture()->getSize().y / 2.0f);

}

// Initialize the tower's position on the grid
void Tower::initialize(float startX, float startY) 
{
    m_Position = { startX, startY };
    m_Sprite.setPosition(m_Position);
}

// Check if enough time has passed for the tower to shoot again
bool Tower::canShoot() 
{
    return m_TimeSinceLastShot >= (1.0f / m_FireRate);  // Check if cooldown has passed
}

void Tower::update(float elapsedTime, const std::vector<Enemy*>& enemies, ProjectileHolder& projectileHolder) 
{
    m_TimeSinceLastShot += elapsedTime;

    bool foundEnemy = false;
    for (const auto& enemy : enemies) 
    {
        if (enemy->isAlive()) 
        {
            float distance = std::hypot(enemy->getPosition().left - m_Position.x,
                enemy->getPosition().top - m_Position.y);

            if (distance <= m_Range && canShoot()) 
            {
                foundEnemy = true;
                shoot(enemy->getPosition().getPosition(), projectileHolder);
                m_TimeSinceLastShot = 0;  // Reset after shooting
                break;  // Stop after firing at one enemy to respect fire rate
            }
        }
    }

    if (!foundEnemy) 
    {
        //std::cout << "No enemies within range for tower at (" << m_Position.x << ", " << m_Position.y << ")\n";
    }
}
// Shoot method to create a projectile aimed at the target position
void Tower::shoot(const sf::Vector2f& targetPosition, ProjectileHolder& projectileHolder) 
{
    std::string texturePath;

    // Set texture path based on tower type
    switch (m_Type) {
    case TowerType::CannonTower:
        texturePath = "graphics/cannonBall.png";
        break;
    case TowerType::MusketTower:
        texturePath = "graphics/cannonBall2.png";
        break;
    }

    projectileHolder.shoot(targetPosition, m_Position, texturePath);
    m_TimeSinceLastShot = 0;  // Reset cooldown after shooting
   // std::cout << "Shot a projectile from tower at (" << m_Position.x << ", " << m_Position.y << ") targeting ("
        //<< targetPosition.x << ", " << targetPosition.y << ")\n";
}
// Accessor for projectiles vector
std::vector<Projectile>& Tower::getProjectiles() 
{
    return projectiles;
}



// Returns the tower's sprite 
Sprite Tower::getSprite() const 
{
    return m_Sprite;
}

// Returns the tower's position
FloatRect Tower::getPosition() const 
{
    return m_Sprite.getGlobalBounds();
}

// Returns whether the tower is active
bool Tower::isActive() const 
{
    return m_Active;
}

// Returns the damage dealt by the tower
float Tower::getDamage() const 
{
    return m_Damage;
}