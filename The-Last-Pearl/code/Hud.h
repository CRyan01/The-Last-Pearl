// Hud.h
//This will manage what the player sees so the icons and th money/health
#pragma once
#include <iostream>
#include "TextureHolder.h"
#include <SFML/Graphics.hpp>
#include "Tower.h"
#include "Player.h"

using namespace sf;
class Hud 
{
public:
	void draw(RenderWindow& window);
	bool input(Tower::TowerType& selectedTowerType,Vector2f mousePos);
	Hud(Player& player);
private:
	String playerMoney_Health;
	Text Playermoney_HealthText;
	Sprite spriteMusketTowerIcon;
	Sprite spriteCannonTowerIcon;
	Sprite spriteMortarTowerIcon;
	Sprite spriteCrossbowTowerIcon;
	Sprite spriteGoldIcon;
	Sprite spriteBuildMenuBackground;
	Player* thePlayer;
};