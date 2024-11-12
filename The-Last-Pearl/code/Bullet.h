#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

class Bullet {
public:
    CircleShape shape;   // Shape to represent the bullet
    Vector2f velocity;   // Movement vector for the bullet
    float speed;         // Speed of the bullet
    bool inactive = false;  // Status flag to indicate if bullet is inactive

    // Constructor to initialize a bullet with position, target, and speed
    Bullet(sf::Vector2f position, sf::Vector2f target, float speed);

    // Updates bullet position based on velocity and delta time
    void update(float deltaTime);

    // Checks if bullet has collided with an enemy's bounding box
    bool checkCollision(const sf::FloatRect& enemyBounds) const;

    // Marks bullet as inactive
    void setInactive();

    // Checks if bullet is inactive
    bool isInactive() const;
};