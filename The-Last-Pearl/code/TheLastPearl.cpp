// Libraries
#include <sstream>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TheLastPearl.h"
#include "TextureHolder.h"


using namespace sf;

//by John All methods starting off
TheLastPearl::TheLastPearl()
{

	// Get Desktop resolution for window size
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;



	// Calculate ScaleX and ScaleY
	const Vector2f defaultResolution(1920.0f, 1080.0f);
	float scaleX = resolution.x / defaultResolution.x;
	float scaleY = resolution.y / defaultResolution.y;

	
	buccaneerEnemy.setWaypoints(Levels.getWaypoints()); // Use the waypoints from LevelManager
	buccaneerEnemy.spawn(100.f, 500.f, 1); // Spawn the enemy at the starting point 

	// Create Game window
	window.create(VideoMode(resolution.x, resolution.y),"TheLastPearl", Style::Fullscreen);
	// Hide the mouse pointer and replace it with crosshair
	window.setMouseCursorVisible(false);
	textureCursor.loadFromFile("graphics/cursor.png");
	spriteCursor.setTexture(textureCursor);
	spriteCursor.setOrigin(25, 25);

	// Create the background sprite
	 textureBackground.loadFromFile("graphics/background.png");
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);

	// Load the texture for the background vertex array
	m_TextureTiles = TextureHolder::GetTexture(
		"graphics/tiles_sheet.png");
	Levels.SetLevel(1);




}
void TheLastPearl::update()
{
	//handle all update movemetn collisions, projectiles

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
	} // End updating the frame

		
		
	
}
void TheLastPearl::draw()
{
	
	/* Draw the frame */
	if (state == State::InLevel) {
		window.clear();
		
		// Display the mainView in the window and draw everything related to it
		window.setView(GameView);

		// Draw the background
		window.draw(spriteBackground);
		
		window.draw(Levels.rVaLevel, &m_TextureTiles);
		window.draw(buccaneerEnemy.getSprite());
		window.draw(spriteCursor);
	}

	if (state == State::PAUSED) {

	}

	if (state == State::MAIN_MENU) {

	}

	window.display();




}
void TheLastPearl::CheckInputs()
{
	/* Handle inputs & events */
	Event event;
	while (window.pollEvent(event)) {

	} // End event polling

	// Handle the player quitting
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}

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