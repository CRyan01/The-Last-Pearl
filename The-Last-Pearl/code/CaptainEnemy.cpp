// CaptainEnemy.cpp
// Jakub Nowak | K00285355
// CaptainEnemy class, a type of enemy derived from the base Enemy class
// Spawns a Captain Enemy at specified coordinates it initial variables

#include "CaptainEnemy.h"
#include "TextureHolder.h"
#include <iostream>

void CaptainEnemy::spawn(float startX, float startY, int seed) 
{
    m_Sprite = Sprite(TextureHolder::GetTexture("graphics/captain.png"));
    m_Speed = 500;
    m_Health = 100;
    m_Position.x = startX;
    m_Position.y = startY;
    m_Sprite.setScale(0.1,0.1);
    m_Size = m_Sprite.getTexture()->getSize();
    m_Sprite.setOrigin(m_Size.x / 2.0f, m_Size.y / 2.0f);
    m_Sprite.setPosition(m_Position);
    m_Alive = true;
}

bool CaptainEnemy::hit(int damage) 
{
    damage /= 2;  // Takes reduced damage
    return Enemy::hit(damage);
}

/*void CaptainEnemy::update(float elapsedTime, Vector2f targetLocation)
{
    Enemy::update(elapsedTime, targetLocation); // Call the base class update
}*/