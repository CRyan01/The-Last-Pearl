// PirateEnemy.cpp
#include "PirateEnemy.h"
#include "TextureHolder.h"

void PirateEnemy::spawn(float startX, float startY, int seed) 
{
    m_Sprite = Sprite(TextureHolder::GetTexture("graphics/pirate.png"));
    m_Speed = 80;
    m_Health = 3;
    m_Position.x = startX;
    m_Position.y = startY;
    m_Sprite.setPosition(m_Position);
}