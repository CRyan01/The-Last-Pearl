// CaptainEnemy.cpp
// Jakub Nowak | K00285355
// CaptainEnemy class, a type of enemy derived from the base Enemy class
#include "CaptainEnemy.h"
#include "TextureHolder.h"

void CaptainEnemy::spawn(float startX, float startY, int seed) 
{
    m_Sprite = Sprite(TextureHolder::GetTexture("graphics/captain.png"));
    m_Speed = 10;
    m_Health = 100;
    m_Position.x = startX;
    m_Position.y = startY;
    m_Sprite.setPosition(m_Position);
}

bool CaptainEnemy::hit(int damage) 
{
    damage /= 2;  // Takes reduced damage
    return Enemy::hit(damage);
}