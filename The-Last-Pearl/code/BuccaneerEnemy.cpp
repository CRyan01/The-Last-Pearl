// BuccaneerEnemy.cpp
// Jakub Nowak | K00285355
// BuccaneerEnemy class, a type of enemy derived from the base Enemy class
#include "BuccaneerEnemy.h"
#include "TextureHolder.h"

void BuccaneerEnemy::spawn(float startX, float startY, int seed)
{
    m_Sprite = Sprite(TextureHolder::GetTexture("graphics/buccaneer.png"));
    m_Speed = 40;
    m_Health = 20;
    m_Position.x = startX;
    m_Position.y = startY;
    m_Sprite.setPosition(m_Position);
}