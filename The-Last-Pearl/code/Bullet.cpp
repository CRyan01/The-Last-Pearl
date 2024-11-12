#include "Bullet.h"
#include <iostream>

Bullet::Bullet(sf::Vector2f position, sf::Vector2f target, float speed) : speed(speed) {
    shape.setPosition(position);
    shape.setRadius(5.f);  
    shape.setFillColor(Color::Red);

    // Calculate direction vector and normalize it
    Vector2f direction = target - position;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    velocity = (direction / length) * speed;
}

void Bullet::update(float deltaTime) {
    shape.move(velocity * deltaTime);
    std::cout << "Bullet at position (" << shape.getPosition().x << ", " << shape.getPosition().y << ")";
}

bool Bullet::checkCollision(const sf::FloatRect& enemyBounds) const {
    bool collision = shape.getGlobalBounds().intersects(enemyBounds);
    if (collision) {
        std::cout << "Bullet collided with enemy!";
    }
    return collision;
}

void Bullet::setInactive() {
    inactive = true;
}

bool Bullet::isInactive() const {
    return inactive;
}