#include <sstream>
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "TextureHolder.h"
#include "TowerManager.h"
#include "BuccaneerEnemy.h"
#include "LevelManager.h"
#include "Paths.h"
#include "Wave.h"
#include "Player.h"
#include "Hud.h"
#pragma once

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
	void CheckInputs();
	//sets up the new Level
	void StartLevel(int LevelNumber);
	//SetUps the main Menu
	void MainMenu();

	

	// Returns true if a tower is already built in a plot
	bool isPlotOccupied(Vector2f position);

	// A function to detect collisions
	void detectCollisions();
private:

	// A regular RenderWindow //what people see
	RenderWindow window;
	TextureHolder holder;
	ProjectileHolder projectileHolder;
	// The main Views
	View GameView;
	View MainMenuView;

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

	Paths MainPath;

	// Textures
	Texture textureCursor;
	Texture MainMenuTexture;
	Texture textureBackground;

	// Sprites
	Sprite MainMenuSprite;
	Sprite spriteCursor;
	Sprite spriteBackground;

	//main Menu Sprites
	Sprite Level1Sprite;
	Sprite Level2Sprite;
	Sprite Level3Sprite;
	
	Projectile bullet;
	// Text
	Font font;
	Text pausedText;
	Text HealthText;
	Text MainMenuTitle;
	Text Level1text;
	Text Level2text;
	Text Level3text;
	stringstream playertext;

	enum class State { PAUSED, Betweeen_Levels, InLevel, MAIN_MENU };
	State state;

	//for the levels
	LevelManager Levels;

	// Texture for the background and the level tiles
	Texture m_TextureTiles;

	// Store the towers predefined positions - CR
	vector<Vector2f> towerPositions;
	// Store selection box sprite for tower positions - CR
	vector<Sprite> towerSelectionBoxSprites;
	// Sprite to display on the selected tower - CR
	Sprite spriteSelectedTower;
	// Position of the currently selected box - CR
	Vector2f selectedTowerPosition = Vector2f(-1, -1);
	// No tower selected by default
	Tower::TowerType selectedTowerType = Tower::TowerType::None;
	// Store the tower objects
	vector<Tower> towers;
	// Store tower positions which are occupied
	vector<Vector2f> occupiedTowerPositions;

	Wave currentWave{10};                     // Start with wave 1
	vector<Enemy*> activeEnemies;             // Store pointers to active enemies
	TowerManager TheGameTowers;

	//the player
	Player CaptainJackSparrow;

	Hud PlayerHud;
	

};
