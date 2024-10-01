#include "Tower.h"
#include "TextureHolder.h"

Tower::Tower()
    : m_Damage(BASIC_TOWER_DAMAGE), m_Range(BASIC_TOWER_RANGE),
    m_FireRate(BASIC_TOWER_FIRE_RATE), m_TimeSinceLastShot(0),
    m_Active(true) {}

void Tower::spawn(float startX, float startY) {
    m_Sprite = Sprite(TextureHolder::GetTexture("graphics/tower.png"));
    m_Position.x = startX;
    m_Position.y = startY;
    m_Sprite.setOrigin(25, 25);
    m_Sprite.setPosition(m_Position);
}

bool Tower::canShoot() {
    return m_TimeSinceLastShot >= m_FireRate;
}

void Tower::shoot() {
    
    if (canShoot()) {
        // Shooting logic
    }
}

void Tower::update(float elapsedTime) {
    m_TimeSinceLastShot += elapsedTime;

    // Targeting logic
}

Sprite Tower::getSprite() {
    return m_Sprite;
}

FloatRect Tower::getPosition() {
    return m_Sprite.getGlobalBounds();
}

bool Tower::isActive() {
    return m_Active;
}
