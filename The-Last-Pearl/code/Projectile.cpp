#include "Projectile.h"
#include <iostream>
// By Conor Ryan

// Constructor
void Projectile::Spawn(float damage, float speed, const std::string& textureFile,Vector2f Target,Vector2f spawn)
  {
    m_Damage=damage;
     m_Speed=speed; 
    m_Active=true;
    m_Sprite.setTexture(TextureHolder::GetTexture(textureFile));
    m_Sprite.setScale(0.1,0.1);
    m_Sprite.setPosition(spawn.x, spawn.y);
    
    std::cout << "\n TestBullets shootign";
}



// Update the projectiles position based on velocity
void Projectile::update(float elapsedTime) {

   // m_Sprite.move(m_Velocity * elapsedTime);
}

// Return true if the projectile is active
bool Projectile::isActive() const {
    return m_Active;
}

// Returns the projectiles sprite
Sprite Projectile::getSprite()  {
    return m_Sprite;
}
