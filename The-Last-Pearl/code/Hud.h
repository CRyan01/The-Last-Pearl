// Hud.h
//This will manage what the player sees so the icons and th money/health
#pragma once
#include <iostream>
#include "Tower.h"
#include "Player.h"
#include <string>
#include <sstream>

using namespace sf;
class Hud 
{
public:
	void draw(RenderWindow& window);
	bool input(Tower::TowerType& selectedTowerType,Vector2f mousePos);
	Hud(Player& player);
	Hud();
	void update(float seconds);
	~Hud();
private:
	sf::Font chracterlook;
	sf::Text HealthText;
	Sprite spriteMusketTowerIcon;
	Sprite spriteCannonTowerIcon;
	Sprite spriteMortarTowerIcon;
	Sprite spriteCrossbowTowerIcon;
	Sprite spriteGoldIcon;
	Sprite spriteBuildMenuBackground;
	Player* thePlayer=nullptr;

	
	//timers for update
	float reset = 0.5f;
	float UpdateTimer =reset;
	bool firstTime = true;
	
};