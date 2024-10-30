// BuccaneerEnemy.cpp
// Jakub Nowak | K00285355
// BuccaneerEnemy class, a type of enemy derived from the base Enemy class
// Spawns a Buccaneer Enemy at specified coordinates it initial variables

#include "TextureHolder.h"
#include "TheLastPearl.h"

void TheLastPearl::MainMenu()
{
	// Create the background sprite
	textureBackground.loadFromFile("graphics/MainMenuBackground.png");
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);



}

void TheLastPearl::Level1()
{

	textureBackground.loadFromFile("graphics/background.png");
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);

	Levels.SetLevel(1);

}
