#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Projectile.h"
#include "Enemy.h"
#include "TextureHolder.h"
#include "ProjectileHolder.h"

using namespace sf;

// By Conor Ryan
class Tower {
public:
    enum class TowerType {
        None,
        MusketTower,
        CannonTower
    };

private:
    // Tower attributes
    TowerType m_Type;
    float m_Damage;
    float m_Range;
    float m_FireRate;
    float m_TimeSinceLastShot;
    bool m_Active;
    Vector2f m_Position;
    Sprite m_Sprite;

    // Track active projectiles for this tower (replaced bullets with projectiles)
    std::vector<Projectile> projectiles;

public:
    Tower();

    // Parameterized constructor for the tower
    Tower(TowerType type, float damage, float range, float fireRate, const std::string& textureFile);

    // Initialize the tower with position
    void initialize(float startX, float startY);

    // Check if the tower can shoot
    bool canShoot();

    // Access tower damage
    float getDamage() const;

    // Shoot method to create a projectile aimed at the target position
    void shoot(const Vector2f& targetPosition, ProjectileHolder& projectileHolder);

    // Update the tower
    void update(float elapsedTime, const std::vector<Enemy*>& enemies, ProjectileHolder& projectileHolder);

    // Returns the tower's sprite
    Sprite getSprite() const;

    // Returns the tower's position
    FloatRect getPosition() const;

    // Returns true if the tower is active
    bool isActive() const;

    bool ClickedOn = false;

    // Upgrade the tower attributes (if applicable)
    void upgrade();

    // Non-const version for modifying projectiles
    std::vector<Projectile>& getProjectiles();

    // Const version for read-only access, such as in drawing
    const std::vector<Projectile>& getProjectiles() const;
};