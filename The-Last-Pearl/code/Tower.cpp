#include "Tower.h"
#include "TextureHolder.h"

Tower::Tower()
{
    m_Type = TowerType::None;
    m_Damage = 0;
    m_Range = 0;
    m_FireRate = 0;
    m_TimeSinceLastShot = 0;
    m_Active = false;
    m_Sprite.setTexture(TextureHolder::GetTexture("graphics/tower.png"));
    m_Sprite.setOrigin(m_Sprite.getTexture()->getSize().x / 2.0f, m_Sprite.getTexture()->getSize().y / 2.0f);
}

Tower::Tower(TowerType type, float damage, float range, float fireRate, const std::string& textureFile) {
    m_Type = type;
    m_Damage = damage;
    m_Range = range;
    m_FireRate = fireRate;
    m_TimeSinceLastShot = 0;
    m_Active = true;
    m_Sprite.setTexture(TextureHolder::GetTexture(textureFile));
    m_Sprite.setOrigin(m_Sprite.getTexture()->getSize().x / 2.0f, m_Sprite.getTexture()->getSize().y / 2.0f);
}

void Tower::initialize(float startX, float startY) {
    m_Position = { startX, startY };
    m_Sprite.setPosition(m_Position);
}

bool Tower::canShoot() {
    return m_TimeSinceLastShot >= m_FireRate;
}

void Tower::shoot() {
    if (canShoot()) {
        m_TimeSinceLastShot = 0;
    }
}

void Tower::update(float elapsedTime) {
    m_TimeSinceLastShot += elapsedTime;
}

Sprite Tower::getSprite() const {
    return m_Sprite;
}

FloatRect Tower::getPosition() const {
    return m_Sprite.getGlobalBounds();
}

bool Tower::isActive() const {
    return m_Active;
}