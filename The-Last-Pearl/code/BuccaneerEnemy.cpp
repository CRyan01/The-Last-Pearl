// BuccaneerEnemy.cpp
// Jakub Nowak | K00285355
// BuccaneerEnemy class, a type of enemy derived from the base Enemy class
// Spawns a Buccaneer Enemy at specified coordinates with initial variables
#include "BuccaneerEnemy.h"
#include "TextureHolder.h"

void BuccaneerEnemy::spawn(float startX, float startY, int seed)
{
    m_Sprite.setTexture(TextureHolder::GetTexture("graphics/buccaneer.png")); 
    m_Speed = 40;
    m_Health = 20;
    m_Position.x = startX;
    m_Position.y = startY;
    m_Size = m_Sprite.getTexture()->getSize();
    m_Sprite.setOrigin(m_Size.x / 2.0f, m_Size.y / 2.0f);
    m_Sprite.setPosition(m_Position);
    m_Alive = true;
}
// Update the BuccaneerEnemy using the base class method
void BuccaneerEnemy::update(float elapsedTime, Vector2f targetLocation)
{
    Enemy::update(elapsedTime, targetLocation); 
}