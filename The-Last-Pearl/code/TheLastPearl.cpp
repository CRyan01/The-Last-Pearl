// Libraries
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TheLastPearl.h"
#include "TextureHolder.h"


using namespace sf;

//by John All methods starting off
TheLastPearl::TheLastPearl()
{

	// Get Desktop resolution for window size
	//resolution.x = VideoMode::getDesktopMode().width;
	//resolution.y = VideoMode::getDesktopMode().height;

	resolution.x = 1920;
	resolution.y = 1080;
	
	buccaneerEnemy.setWaypoints(Levels.getWaypoints()); // Use the waypoints from LevelManager
	buccaneerEnemy.spawn(-100.f, 200.f, 1); // Spawn the enemy at the starting point 

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

void TheLastPearl::update()
{
	/* Update the frame */
	if (state == State::InLevel) {
		
		// Update delta time
		Time dt = clock.restart();

		// Update total game time
		gameTimeTotal += dt;

		// Get a decimal fraction of 1 from the delta time
		float dtAsSeconds = dt.asSeconds();

		// Store the cursors position on the screen
		mouseScreenPosition = Mouse::getPosition();

		//Update Buccaneer Enemy
		buccaneerEnemy.update(dtAsSeconds, Vector2f(0, 0));

		// Convert mouse position to world coordinates of mainView
		mouseWorldPosition = window.mapPixelToCoords(
			Mouse::getPosition(), GameView);

		// Set the cursor to the mouse world location
		spriteCursor.setPosition(mouseWorldPosition);
	}		
} // End updating the frame

void TheLastPearl::draw()
{
	
	/* Draw the frame */
	if (state == State::InLevel) {
		window.clear();
		
		// Display the mainView in the window and draw everything related to it
		window.setView(GameView);

		// Draw the background
		window.draw(spriteBackground);
		
		//window.draw(Levels.rVaLevel, &m_TextureTiles);
		window.draw(buccaneerEnemy.getSprite());
		window.draw(spriteCursor);
	}

	if (state == State::PAUSED) {
		// Draw pause text in the center of the screen - CR
		window.setView(window.getDefaultView()); // Use the default view to avoid scaling
		window.draw(pausedText);
	}

	if (state == State::MAIN_MENU) {

	}

	window.display();




}
void TheLastPearl::checkInputs()
{
	/* Handle events */
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::KeyPressed) {
			// Toggle pause when P is pressed - CR
			if (event.key.code == Keyboard::P) {
				// Switch between PAUSED and InLevel states
				if (state == State::PAUSED) {
					state = State::InLevel;
					clock.restart(); // Reset delta time to avoid frame jump
				} else if (state == State::InLevel) {
					state = State::PAUSED;
				}
			}
		}
		// Handle the player quitting - CR
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}
	} // End event polling

}



void TheLastPearl::run()
{
	// The main game loop
	//we can add more as we need
	while (window.isOpen()) {

		checkInputs();
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