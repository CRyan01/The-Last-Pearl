// PirateEnemy.cpp
// Jakub Nowak | K00285355
// PirateEnemy class, a type of enemy derived from the base Enemy class
// Spawns a Pirate Enemy at specified coordinates it initial variables

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

// Update the PirateEnemy using the base class method
void PirateEnemy::update(float elapsedTime, Vector2f targetLocation)
{
    Enemy::update(elapsedTime, targetLocation); // Call the base class update
}