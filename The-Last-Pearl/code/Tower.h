#pragma once
#include <SFML/Graphics.hpp>
#include <string>
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
    int radius = 100;
  
    
    
public:
    Tower();

    // Parameterized constructor for the tower
    Tower(TowerType type, float damage, float range, float fireRate, const std::string& textureFile);
    //ammo
    ProjectileHolder Bullets;
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

    CircleShape Sight = CircleShape(radius);
    bool ClickedOn = false;

     void upgrade() ;
};