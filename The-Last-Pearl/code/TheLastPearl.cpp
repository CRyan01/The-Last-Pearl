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
	state = State::MAIN_MENU;




}
void TheLastPearl::update()
{
	//handle all update movemetn collisions, projectiles
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
	/* Update the frame */
	if (state == State::InLevel) {
		Level1();
	
	} // End updating the frame

	if (state == State::MAIN_MENU)
	{
		MainMenu();

		CheckInputs();
	}

		
		
	
}
void TheLastPearl::draw()
{
	window.clear();
	// Display the mainView in the window and draw everything related to it
	window.setView(GameView);
	// Draw the background
	window.draw(spriteBackground);
	/* Draw the frame */
	if (state == State::InLevel) {
		
		
		

		
		
		window.draw(Levels.rVaLevel, &m_TextureTiles);
		window.draw(buccaneerEnemy.getSprite());
	
	}

	if (state == State::PAUSED) {

	}

	if (state == State::MAIN_MENU) {

	}

	window.draw(spriteCursor);

	window.display();




}
void TheLastPearl::CheckInputs()
{
	/* Handle inputs & events */
	Event event;
	while (window.pollEvent(event)) {

		switch (state)
		{
		case State::MAIN_MENU:

			if (Mouse::XButton1)
			{
				state=State::InLevel;
			}



		}

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