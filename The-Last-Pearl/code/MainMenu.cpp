// BuccaneerEnemy.cpp
// Jakub Nowak | K00285355
// BuccaneerEnemy class, a type of enemy derived from the base Enemy class
// Spawns a Buccaneer Enemy at specified coordinates it initial variables

#include "TextureHolder.h"
#include "TheLastPearl.h"

//this method is added to facilitate the creation of the main menu and start of level 1 2 3
void TheLastPearl::MainMenu()
{
	// Create the background sprite
	textureBackground.loadFromFile("graphics/MainMenuBackground.png");

	spriteBackground.setTexture(textureBackground);
	//spriteBackground.setScale(0.5,0.5);
	spriteBackground.setPosition(0, 0);

	MainMenuTitle.setFont(font);
	MainMenuTitle.setString("The Last Pearl");
	MainMenuTitle.setFillColor(sf::Color::Red);
	MainMenuTitle.setCharacterSize(150);
	MainMenuTitle.setPosition(400,300);


	Level1Sprite.setTexture(TextureHolder::GetTexture("graphics/Level1.png"));
	Level1Sprite.setPosition(550,600);
	
	Level2Sprite.setTexture(TextureHolder::GetTexture("graphics/Level2.png"));
	Level2Sprite.setPosition(800, 600);

	Level3Sprite.setTexture(TextureHolder::GetTexture("graphics/Level3.png"));
	Level3Sprite.setPosition(1050, 600);




	Level1text.setFont(font);
	Level1text.setString("Level 1");
	Level1text.setFillColor(sf::Color::Black);
	Level1text.setCharacterSize(50);
	Level1text.setPosition(550,500 );

	Level2text.setFont(font);
	Level2text.setString("Level 2");
	Level2text.setFillColor(sf::Color::Black);
	Level2text.setCharacterSize(50);
	Level2text.setPosition(800, 500);


	Level3text.setFont(font);
	Level3text.setString("Level 3");
	Level3text.setFillColor(sf::Color::Black);
	Level3text.setCharacterSize(50);
	Level3text.setPosition(1050, 500);

	


}

void TheLastPearl::StartLevel(int level)
{
	std::cout << level;
	textureBackground.loadFromFile("graphics/background.png");
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);

	Levels.SetLevel(1);

}
