// PirateEnemy.cpp
// Jakub Nowak | K00285355
// PirateEnemy class, a type of enemy derived from the base Enemy class
// Spawns a Pirate Enemy at specified coordinates it initial variables

#include "PirateEnemy.h"
#include "TextureHolder.h"

void PirateEnemy::spawn(float startX, float startY, int seed) 
{
    m_Sprite = Sprite(TextureHolder::GetTexture("graphics/pirate.png"));
    m_Speed = 300;
    m_Health = 200;
    m_Position.x = startX;
    m_Position.y = startY;
    m_Sprite.setPosition(m_Position);
    m_Sprite.setScale(0.1, 0.1);
    m_Alive = true;
    DeathMoney = 30;
    CurrentTarget = m_Sprite.getPosition();
}

// Update the PirateEnemy using the base class method
void PirateEnemy::update(float elapsedTime)
{
    Enemy::update(elapsedTime); // Call the base class update
}