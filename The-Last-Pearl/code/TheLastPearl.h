#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "TextureHolder.h"
#include "LevelManager.h"
#include "BuccaneerEnemy.h"
using namespace sf;
using namespace std;
class TheLastPearl
{
	//cant really add much without enemies and what not but will stry m best
public:
	TheLastPearl();
	void run();
	void draw();
	//drawing to the screen
	void update();
	//updating wha is happennning
	void Initialize();
	//may or may not be used more for just level start up extra
	void checkInputs();
private:

	// A regular RenderWindow //what people see
	RenderWindow window;


	TextureHolder holder;
	// The main Views
	View GameView;
	View MainMenuview;

	// Create a cock for timing
	Clock clock;

	// How long has the playing state been active
	Time gameTimeTotal;

	// Where is the mouse in relation to world coordinates
	Vector2f mouseWorldPosition;
	// Where is the mouse in relation to screen coordinates
	Vector2i mouseScreenPosition;

	Vector2f resolution;

	
	BuccaneerEnemy buccaneerEnemy;
	

	//textures

	Sprite spriteCursor;
	Texture textureCursor;
	Texture MainMenuTexture;

	Sprite spriteBackground;
	Texture textureBackground;

	//Sprites
	Sprite MainMenuSprite;

	// Text
	Font font;
	Text pausedText;

	enum class State { PAUSED, Betweeen_Levels, InLevel, MAIN_MENU };
	//State state = State::InLevel;
	State state;
	LevelManager Levels;

	//for the levels
	// Texture for the background and the level tiles
	Texture m_TextureTiles;


};
