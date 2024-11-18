#pragma once

#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Projectile.h"
#include <vector>
#include <string>
using namespace sf;

// By Conor Ryan
class ProjectileHolder {
public:
    ProjectileHolder();
    ProjectileHolder(float damage, float speed, const std::string& textureFile);

    void update(float seconds);
    void draw(RenderWindow& window);
    void shoot(sf::Vector2f spawn, Enemy* target, const std::string& texturePath, float damage, float maxRange);
    void clearInactive();
    void Reset();

    // New getter for accessing projectiles
    std::vector<Projectile>& getProjectiles();

private:
    std::vector<Projectile> bullets;  // Store all active projectiles
    float damage;
    float speed;
    std::string TextureName;
    Projectile TheBullet;
};