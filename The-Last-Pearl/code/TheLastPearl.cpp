// Libraries
#include "TheLastPearl.h"



using namespace sf;

//by John All methods starting off
TheLastPearl::TheLastPearl()
{
	// Set the default resolution to scale to - CR
	resolution.x = 1920;
	resolution.y = 1080;
	
	buccaneerEnemy.setWaypoints(Levels.getWaypoints()); // Use the waypoints from LevelManager
	buccaneerEnemy.spawn(-100.f, 200.f, 1); // Spawn the enemy at the starting point

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

	// Load texture for the selected tower - CR
	spriteSelectedTower.setTexture(TextureHolder::GetTexture("graphics/selectedBox.png"));
	//spriteSelectedTower.setScale(0.8f, 0.8f);
	spriteSelectedTower.setOrigin(spriteSelectedTower.getTexture()->getSize().x / 2.0f, spriteSelectedTower.getTexture()->getSize().y / 2.0f);
	spriteSelectedTower.setPosition(-50, -60);

	spriteMusketTowerIcon.setTexture(TextureHolder::GetTexture("graphics/musketTower.png"));
	//spriteMusketTowerIcon.setScale(0.4f, 0.4f);
	spriteMusketTowerIcon.setOrigin(spriteSelectedTower.getTexture()->getSize().x / 2.0f, spriteSelectedTower.getTexture()->getSize().y / 2.0f);
	spriteMusketTowerIcon.setPosition(70, 1030);

	spriteCannonTowerIcon.setTexture(TextureHolder::GetTexture("graphics/cannonTower.png"));
	//spriteCannonTowerIcon.setScale(0.4f, 0.4f);
	spriteCannonTowerIcon.setOrigin(spriteSelectedTower.getTexture()->getSize().x / 2.0f, spriteSelectedTower.getTexture()->getSize().y / 2.0f);
	spriteCannonTowerIcon.setPosition(210, 1030);

	// Create Game window
	window.create(VideoMode(resolution.x, resolution.y),"TheLastPearl", Style::Fullscreen);

	// Hide the mouse pointer and replace it with crosshair - CR
	window.setMouseCursorVisible(false);
	textureCursor.loadFromFile("graphics/cursor.png");
	spriteCursor.setTexture(textureCursor);
	spriteCursor.setOrigin(25, 25);

	// Create the background sprite - CR
	textureBackground.loadFromFile("graphics/background.png");
	spriteBackground.setTexture(textureBackground);

	// Setup the GameView - CR
	GameView.setSize(resolution.x, resolution.y);
	GameView.setCenter(resolution.x / 2, resolution.y / 2);

	// Setup the MainMenuView - CR
	MainMenuView.setSize(resolution.x, resolution.y);
	MainMenuView.setCenter(resolution.x / 2, resolution.y / 2);

	// Calculate ScaleX and ScaleY then scale the background image
	// to the current resolution - CR
	Vector2u backgroundSize = textureBackground.getSize();
	// Use the smaller scale
	float scale = min(resolution.x / backgroundSize.x, resolution.y / backgroundSize.y);
	spriteBackground.setScale(scale, scale);
	spriteBackground.setPosition(0, 0);

	// Load the texture for the background vertex array
	m_TextureTiles = TextureHolder::GetTexture(
		"graphics/tiles_sheet.png");
	Levels.SetLevel(1);
	state = State::MAIN_MENU;

	// Set the level to level 1
	//Levels.SetLevel(1);

	// Load the font - CR
	font.loadFromFile("fonts/Roboto-Light.ttf");

	// Set up text for the paused screen - CR
	pausedText.setFont(font);
	pausedText.setCharacterSize(155 * scale);
	pausedText.setFillColor(Color::White);
	pausedText.setString("Press P to Unpause");
	pausedText.setOrigin(pausedText.getLocalBounds().width / 2, pausedText.getLocalBounds().height / 2);
	pausedText.setPosition(resolution.x / 2, resolution.y / 2);

	// Start the game in a paused state - CR
	state = State::PAUSED;
}



void TheLastPearl::run()
{
	// The main game loop
	//we can add more as we need
	while (window.isOpen()) {

		CheckInputs();
		update();
		draw();
	}
}


// Main
int main() {

	TheLastPearl Game;
	Game.run();
	
	return 0;
}