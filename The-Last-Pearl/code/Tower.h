#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Tower {
private:
    // Tower attributes
    const float BASIC_TOWER_DAMAGE = 10;
    const float BASIC_TOWER_RANGE = 100;
    const float BASIC_TOWER_FIRE_RATE = 1.0f;

    // Position of the tower
    Vector2f m_Position;

    // Sprite for the tower
    Sprite m_Sprite;

    // Damage, range, and fire rate of the tower
    float m_Damage;
    float m_Range;
    float m_FireRate;

    // Timer for tracking shooting
    float m_TimeSinceLastShot;

    // Is the tower active?
    bool m_Active;

public:
    // Constructor
    Tower();

    // Spawn a new tower
    void spawn(float startX, float startY);

    // Check if the tower can shoot
    bool canShoot();

    // Handle when the tower shoots
    void shoot();

    // Update the tower each frame
    void update(float elapsedTime);

    // Get the tower's sprite to draw
    Sprite getSprite();

    // Get the tower's position
    FloatRect getPosition();

    // Check if the tower is active
    bool isActive();
};
