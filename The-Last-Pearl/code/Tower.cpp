#include "Tower.h"
#include "TextureHolder.h"
#include <iostream>

// Default constructor for Tower
Tower::Tower() {
    m_Type = TowerType::None;
    m_Damage = 0;
    m_Range = 0;
    m_FireRate = 0;
    m_TimeSinceLastShot = 0;
    m_Active = false;
    m_UpgradeLevel = 0;
    m_MaxUpgradeLevel = 3;
    m_UpgradeCost = 50;
    m_Sprite.setTexture(TextureHolder::GetTexture("graphics/crossbowTower.png"));
    m_Sprite.setOrigin(m_Sprite.getTexture()->getSize().x / 2.0f, m_Sprite.getTexture()->getSize().y / 2.0f);
}

// Parameterized constructor to create a tower with specific attributes
Tower::Tower(TowerType type, float damage, float range, float fireRate, const std::string& textureFile) {
    m_Type = type;
    m_Damage = damage;
    m_Range = range;
    m_FireRate = fireRate;
    m_TimeSinceLastShot = 0;
    m_Active = true;
    m_UpgradeLevel = 0;
    m_MaxUpgradeLevel = 3;
    m_UpgradeCost = 50;
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
// Updates the tower's state each frame, including checking for enemies in range and firing when possible
void Tower::update(float elapsedTime, const std::vector<Enemy*>& enemies, ProjectileHolder& projectileHolder)
{
    m_TimeSinceLastShot += elapsedTime;

    if (canShoot())
    {
        Enemy* targetEnemy = nullptr; // Pointer to the closest target enemy
        float closestDistance = m_Range; // Initial distance set to towers range

        for (const auto& enemy : enemies)
        {
            if (enemy->isAlive())
            {
                // Update closest target if another enemy is within range and closer than the previous one
                float distance = std::hypot(enemy->getPosition().left - m_Position.x, enemy->getPosition().top - m_Position.y);
                if (distance <= m_Range && distance < closestDistance)
                {
                    closestDistance = distance;
                    targetEnemy = enemy;
                }
            }
        }

        if (targetEnemy)
        {
            shoot(targetEnemy, projectileHolder);
            m_TimeSinceLastShot = 0;  // Reset cooldown after shooting
        }
    }
}
// Shoot method to create a projectile aimed at the target position
void Tower::shoot(Enemy* target, ProjectileHolder& projectileHolder)
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

    projectileHolder.shoot(m_Position, target, texturePath, m_Damage, m_Range);
}

// Upgrade a tower if possible
void Tower::upgrade() {
    if (canUpgrade()) {
        m_UpgradeLevel++;
        m_Damage += 5;
        m_Range += 20.0f;
        m_UpgradeCost += 25;
        std::cout << "Tower upgraded" << std::endl;
    } else {
        std::cout << "Max upgrade level reached" << std::endl;
    }
}

// Check if a tower can be upgraded
bool Tower::canUpgrade() const {
    return m_UpgradeLevel < m_MaxUpgradeLevel;
}

// Get the upgrade level of a tower
int Tower::getUpgradeLevel() const {
    return m_UpgradeLevel;
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

// Returns upgrade cost
int Tower::getUpgradeCost() const {
    return m_UpgradeCost;
}