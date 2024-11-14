#include "Projectile.h"
#include <iostream>
// By Conor Ryan

// Constructor
void Projectile::Spawn(float damage, float speed, const std::string& textureFile, sf::Vector2f target, sf::Vector2f spawn) 
{
    m_Damage = damage;
    m_Speed = speed;
    m_Speed = 600;
    m_Active = true;
    m_Sprite.setTexture(TextureHolder::GetTexture(textureFile));
    m_Sprite.setPosition(spawn);

    // Calculate direction and velocity
    sf::Vector2f direction = target - spawn;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    // Ensure length is not too small to avoid zero velocity
    if (length > 0.1f) 
    {
        direction /= length; // direction vector
        m_Velocity = direction * m_Speed;
    }
    else 
    {
        // Set a default fallback direction to the right if target is too close
        m_Velocity = { m_Speed, 0 };
  
       // std::cout << "Projectile spawned with fallback velocity";
    }

    // Debug output
   // std::cout << "Projectile spawned at (" << spawn.x << ", " << spawn.y
     //   << ") with target (" << target.x << ", " << target.y
     //   << "), direction (" << direction.x << ", " << direction.y
      //  << "), length " << length
      //  << ", and velocity (" << m_Velocity.x << ", " << m_Velocity.y << ")\n";
}


// Update the projectiles position based on velocity
void Projectile::update(float elapsedTime) 
{
    if (m_Active) {
        // Debug output for current position
       // std::cout << "Projectile initial position: (" << m_Sprite.getPosition().x
          //  << ", " << m_Sprite.getPosition().y << ")\n";

        // Move the projectile based on velocity and elapsed time
        m_Sprite.move(m_Velocity * elapsedTime);

        // Debug output for new position
      //  std::cout << "Projectile updated position: (" << m_Sprite.getPosition().x
           // << ", " << m_Sprite.getPosition().y << ")\n";
    }
}

bool Projectile::checkCollision(const FloatRect& enemyBounds) const 
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