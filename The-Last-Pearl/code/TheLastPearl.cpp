//test
// Libraries
#include "TheLastPearl.h"

using namespace sf;

//by John All methods starting off
TheLastPearl::TheLastPearl()
{

	// Set the default resolution to scale to - CR
	resolution.x = 1920;
	resolution.y = 1080;
	
	//buccaneerEnemy.spawn(-100.f, 200.f, 1); // Spawn the enemy at the starting point

	//now we use a method for this
	



	// Load texture for the selected tower - CR
	spriteSelectedTower.setTexture(TextureHolder::GetTexture("graphics/selectedBox.png"));
	spriteSelectedTower.setOrigin(spriteSelectedTower.getTexture()->getSize().x / 2.0f, spriteSelectedTower.getTexture()->getSize().y / 2.0f);
	spriteSelectedTower.setPosition(-50, -60);
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
	//spriteMusketTowerIcon.setOrigin(spriteSelectedTower.getTexture()->getSize().x / 2.0f, spriteSelectedTower.getTexture()->getSize().y / 2.0f);

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

	HealthText.setFont(font);
	HealthText.setCharacterSize(50);
	HealthText.setFillColor(Color::White);
	playertext << "Money = " << CaptainJackSparrow.money << " Pearl Health " << std::to_string(CaptainJackSparrow.health) << "\\" << std::to_string(CaptainJackSparrow.MaxHp);
	HealthText.setString(playertext.str());
	HealthText.setOrigin(HealthText.getLocalBounds().width / 2, HealthText.getLocalBounds().height / 2);
	HealthText.setPosition(1000, 1000);
	//pathing
	MainPath.SetLevel(1);
	// Start the game in a paused state - CR
	state = State::MAIN_MENU;
	//sf::Vector2f same = (500.0f,500.0f);
	//testing place 
	
	//bullet.Spawn(19, 19, "graphics/tnt.png", Vector2f(500.0f, 500.0f), Vector2f(500.0f, 500.0f));
	PlayerHud=Hud(CaptainJackSparrow);

	MainMenu();
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