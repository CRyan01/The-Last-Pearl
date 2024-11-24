// Hud.cpp
// John Hannon k00281825
//this is the cpp file for Hud
//This is ll for display all things related to player
#include "Hud.h"
//test fix?
Hud::Hud()
{
	//thePlayer = NULL;
	

}

Hud::~Hud()
{
	thePlayer = nullptr;
	delete thePlayer;
	//deleteThePlayer;
	//thePlayer = NULL;
}
Hud::Hud(Player& player)
{
	thePlayer = new Player();
	*thePlayer = player;
	spriteMusketTowerIcon.setTexture(TextureHolder::GetTexture("graphics/musketTower.png"));
	//spriteMusketTowerIcon.setOrigin(spriteMusketTowerIcon.getTexture()->getSize().x / 2.0f, spriteMusketTowerIcon.getTexture()->getSize().y / 2.0f);
	spriteMusketTowerIcon.setPosition(100, 990);

	spriteCannonTowerIcon.setTexture(TextureHolder::GetTexture("graphics/cannonTower.png"));
	//spriteCannonTowerIcon.setOrigin(spriteCannonTowerIcon.getTexture()->getSize().x / 2.0f, spriteCannonTowerIcon.getTexture()->getSize().y / 2.0f);
	spriteCannonTowerIcon.setPosition(200, 990);

	spriteMortarTowerIcon.setTexture(TextureHolder::GetTexture("graphics/mortarTower.png"));
	//spriteMortarTowerIcon.setOrigin(spriteMortarTowerIcon.getTexture()->getSize().x / 2.0f, spriteMortarTowerIcon.getTexture()->getSize().y / 2.0f);
	spriteMortarTowerIcon.setPosition(300, 990);

	spriteCrossbowTowerIcon.setTexture(TextureHolder::GetTexture("graphics/crossbowTower.png"));
	//spriteCrossbowTowerIcon.setOrigin(spriteCrossbowTowerIcon.getTexture()->getSize().x / 2.0f, spriteCrossbowTowerIcon.getTexture()->getSize().y / 2.0f);
	spriteCrossbowTowerIcon.setPosition(400, 990);

	spriteGoldIcon.setTexture(TextureHolder::GetTexture("graphics/gold.png"));
	//spriteGoldIcon.setOrigin(spriteGoldIcon.getTexture()->getSize().x / 2.0f, spriteGoldIcon.getTexture()->getSize().y / 2.0f);
	spriteGoldIcon.setPosition(1800, 990);

	spriteBuildMenuBackground.setTexture(TextureHolder::GetTexture("graphics/buildMenuBackground.png"));
	spriteBuildMenuBackground.setPosition(0, 970);
	//std::string dave = "hey" +std::to_string( UpdateTimer) + "health";
	///needs to not be here due to error with read access voilations
	//by John
	// Load the font - John
	

}
void Hud::draw(RenderWindow& window)
{
	// Draw the tower icons
	window.draw(spriteBuildMenuBackground);
	window.draw(spriteMusketTowerIcon);
	window.draw(spriteCannonTowerIcon);
	//window.draw(spriteMortarTowerIcon);
	//window.draw(spriteCrossbowTowerIcon);
	//window.draw(spriteGoldIcon);
	
		
	
}

bool Hud::input(Tower::TowerType& selectedTowerType,Vector2f mousePos)
{
	
	if (spriteMusketTowerIcon.getGlobalBounds().contains(mousePos)) {
		selectedTowerType = Tower::TowerType::MusketTower;
		return true;
	}
	else if (spriteCannonTowerIcon.getGlobalBounds().contains(mousePos)) {
		selectedTowerType = Tower::TowerType::CannonTower;
		return true;
	}
	return false;
}

void Hud::update(float seconds)
{

	if ((firstTime == true) || (UpdateTimer <= 0))
	{


	}

	UpdateTimer -= seconds;
}