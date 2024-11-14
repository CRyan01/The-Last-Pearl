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
	//if (!chracterlook.loadFromFile("fonts/2font.ttf"))
	///{
	//	std::cout<<"I hate fonts ";
	//	return;
	//}
	//else
	//{
	//	std::cout << "wow we have a font";
	//}
	
	/*/if (thePlayer != nullptr) {
		Playermoney_HealthText.setFont(font);
		Playermoney_HealthText.setCharacterSize(15);
		//std::cout << "test 1 " << thePlayer->money;
		//std::cout << "test 2 " << thePlayer->health;
		//std::stringstream ss;
		//ss << "Money = " << player.money;
		//std::string Money = ss.str();// " Pearl Health " + std::to_string(thePlayer->health) + "\\" + std::to_string(thePlayer->MaxHp));
		Playermoney_HealthText.setString("Money = ");
		Playermoney_HealthText.setFillColor(Color::Black);
		Playermoney_HealthText.setPosition(1000, 200);
	}*/


}
void Hud::draw(RenderWindow& window)
{
	// Draw the tower icons
	////////window.draw(HealthText);
	window.draw(spriteBuildMenuBackground);
	window.draw(spriteMusketTowerIcon);
	window.draw(spriteCannonTowerIcon);
	window.draw(spriteMortarTowerIcon);
	window.draw(spriteCrossbowTowerIcon);
	window.draw(spriteGoldIcon);
	//std::cout << "drawing the thing";
		
	
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