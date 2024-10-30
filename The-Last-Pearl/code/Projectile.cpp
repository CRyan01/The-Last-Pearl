#include "Projectile.h"
// By Conor Ryan

// Constructor
Projectile::Projectile(float damage, float speed, const std::string& textureFile)
    : m_Damage(damage), m_Speed(speed), m_Active(true) {
    m_Sprite.setTexture(TextureHolder::GetTexture(textureFile));
}

// Initialize the projectiles position
void Projectile::initialize(float startX, float startY) {
    m_Sprite.setPosition(startX, startY);
}

// Update the projectiles position based on velocity
void Projectile::update(float elapsedTime) {
    m_Sprite.move(m_Velocity * elapsedTime);
}

// Return true if the projectile is active
bool Projectile::isActive() const {
    return m_Active;
}

// Returns the projectiles sprite
Sprite Projectile::getSprite() const {
    return m_Sprite;
}
