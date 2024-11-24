// BuccaneerEnemy.cpp
// Jakub Nowak | K00285355
// BuccaneerEnemy class, a type of enemy derived from the base Enemy class
// Spawns a Buccaneer Enemy at specified coordinates it initial variables

#include "TextureHolder.h"
#include "TheLastPearl.h"

//this method is added to facilitate the creation of the main menu and start of level 1 2 3
void TheLastPearl::MainMenu()
{
	Reset();
	// Create the background sprite
	textureBackground.loadFromFile("graphics/MainMenuBackground.png");

	spriteBackground.setTexture(textureBackground);
	//spriteBackground.setScale(0.5,0.5);
	spriteBackground.setPosition(0, 0);

	MainMenuTitle.setFont(font);
	MainMenuTitle.setString("The Last Pearl");
	MainMenuTitle.setFillColor(sf::Color::Red);
	MainMenuTitle.setCharacterSize(160);
	MainMenuTitle.setPosition(400,300);


	Level1Sprite.setTexture(TextureHolder::GetTexture("graphics/Level1.png"));
	Level1Sprite.setPosition(575,600);
	
	Level2Sprite.setTexture(TextureHolder::GetTexture("graphics/Level2.png"));
	Level2Sprite.setPosition(820, 600);

	Level3Sprite.setTexture(TextureHolder::GetTexture("graphics/Level3.png"));
	Level3Sprite.setPosition(1055, 600);




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
	
	switch (level)
	{
	case 1:
		textureBackground.loadFromFile("graphics/background.png");
		spriteBackground.setTexture(textureBackground);
		spriteBackground.setPosition(0, 0);
		spriteBackground.setScale(1, 1);

		//Levels.SetLevel(1);
		break;
	case 2:
		textureBackground.loadFromFile("graphics/Map3.png");
		spriteBackground.setTexture(textureBackground);
		spriteBackground.setPosition(0, 0);
		spriteBackground.setScale(2,2);

		//Levels.SetLevel(2);
		break;
	case 3:
		textureBackground.loadFromFile("graphics/background.png");
		spriteBackground.setTexture(textureBackground);
		spriteBackground.setPosition(0, 0);

		//Levels.SetLevel(3);
		break;
	}
	MainPath.SetLevel(level);
	CaptainJackSparrow.SetLevel(level);
	currentWave = Wave(level);
	GetTowerPos(level);
}

void TheLastPearl::GetTowerPos(int level)
{

	switch (level)
	{
	case 1:
		//19 towers
		// Preset positions for towers - CR
		towerPositions.push_back(Vector2f(200, 60));
		towerPositions.push_back(Vector2f(600, 60));
		towerPositions.push_back(Vector2f(1000, 60));
		towerPositions.push_back(Vector2f(1400, 60));
		towerPositions.push_back(Vector2f(1800, 60));

		towerPositions.push_back(Vector2f(400, 330));
		towerPositions.push_back(Vector2f(800, 330));
		towerPositions.push_back(Vector2f(1200, 330));
		towerPositions.push_back(Vector2f(1600, 330));

		towerPositions.push_back(Vector2f(400, 600));
		towerPositions.push_back(Vector2f(800, 600));
		towerPositions.push_back(Vector2f(1200, 600));
		towerPositions.push_back(Vector2f(1600, 600));

		towerPositions.push_back(Vector2f(200, 870));
		towerPositions.push_back(Vector2f(600, 870));
		towerPositions.push_back(Vector2f(1000, 870));
		towerPositions.push_back(Vector2f(1400, 870));
		towerPositions.push_back(Vector2f(1800, 870));
		break;
	case 2:


		
		towerPositions.push_back(Vector2f(350, 760));
		towerPositions.push_back(Vector2f(850, 370));
		towerPositions.push_back(Vector2f(1050, 370));
		towerPositions.push_back(Vector2f(1580, 760));
		towerPositions.push_back(Vector2f(110, 450));
		towerPositions.push_back(Vector2f(1800, 450));
		//towerPositions.push_back(Vector2f(350, 650));

		
		break;
	case 3:
		break;
	}

	// Initialize unselected tower boxes - CR
	for (const auto& position : towerPositions) {
		// Create the sprite and load the selection box texture, center its point of origin, set its position
		Sprite selectionBox(TextureHolder::GetTexture("graphics/notSelectedBox.png"));
		selectionBox.setScale(0.8f, 0.8f);
		selectionBox.setOrigin(selectionBox.getTexture()->getSize().x / 2.0f, selectionBox.getTexture()->getSize().y / 2.0f);
		selectionBox.setPosition(position);
		selectionBox.setColor(Color(255, 255, 255, 128));
		towerSelectionBoxSprites.push_back(selectionBox);
	}
}
