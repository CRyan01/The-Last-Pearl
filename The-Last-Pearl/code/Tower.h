#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

// By Conor Ryan
class Tower {
public:
    enum class TowerType {
        MusketTower,
        CannonTower
    };

protected:
    // Tower attributes
    float m_Damage;
    float m_Range;
    float m_FireRate;
    float m_TimeSinceLastShot;
    bool m_Active;

    // Position of the tower
    Vector2f m_Position;
    // The towers sprite
    Sprite m_Sprite;

public:
    // Parameterized constructor for the tower
    Tower(float damage, float range, float fireRate, const std::string& textureFile);

    // Initialize the tower with position
    void initialize(float startX, float startY);

    // Check if the tower can shoot
    bool canShoot();

    // Virtual shoot method - to be defined in subclasses
    virtual void shoot();

    // Update the tower
    void update(float elapsedTime);

    // Returns the towers sprite
    Sprite getSprite() const;

    // Returns the towers position
    FloatRect getPosition() const;

    // Returns true if the tower is active
    bool isActive() const;
};