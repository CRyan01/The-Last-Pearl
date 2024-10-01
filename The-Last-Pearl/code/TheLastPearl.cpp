// Libraries
#include <sstream>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TheLastPearl.h"
#include "TextureHolder.h"

using namespace sf;

// Main
int main() {
	
	// Create an instance of TextureHolder
	TextureHolder holder;

	// The game will be in one of three states
	enum class State {PAUSED, PLAYING, MAINMENU};

	// The game will start in the main menu state
	State state = State::MAINMENU;

	// Get the screen resolution and create an SFML window
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	// Calculate ScaleX and ScaleY
	const Vector2f defaultResolution(1920.0f, 1080.0f);
	float scaleX = resolution.x / defaultResolution.x;
	float scaleY = resolution.y / defaultResolution.y;

	RenderWindow window(VideoMode(resolution.x, resolution.y), 
		"TheLastPearl", Style::Fullscreen);

	// Create the main SFML View
	View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

	// Create a cock for timing
	Clock clock;

	// How long has the playing state been active
	Time gameTimeTotal;

	// Where is the mouse in relation to world coordinates
	Vector2f mouseWorldPosition;
	// Where is the mouse in relation to screen coordinates
	Vector2i mouseScreenPosition;

	// Hide the mouse pointer and replace it with crosshair
	window.setMouseCursorVisible(false);
	Sprite spriteCursor;
	Texture textureCursor = TextureHolder::GetTexture("graphics/cursor.png");
	spriteCursor.setTexture(textureCursor);
	spriteCursor.setOrigin(25, 25);

	// The main game loop
	while (window.isOpen()) {

		/* Handle inputs & events */
		Event event;
		while (window.pollEvent(event)) {

		} // End event polling

		// Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		// Handle controls while playing
		if (state == State::PLAYING) {

		} // End controls while playing

		// Handle the main menu state
		if (state == State::MAINMENU) {

		} // End the main menu state
	}

	/* Update the frame */
	if (state == State::PLAYING) {

		// Update delta time
		Time dt = clock.restart();
		// Update total game time
		gameTimeTotal += dt;
		// Get a decimal fraction of 1 from the delta time
		float dtAsSeconds = dt.asSeconds();

		// Store the cursors position on the screen
		mouseScreenPosition = Mouse::getPosition();

		// Convert mouse position to world coordinates of mainView
		mouseWorldPosition = window.mapPixelToCoords(
			Mouse::getPosition(), mainView);

		// Set the cursor to the mouse world location
		spriteCursor.setPosition(mouseWorldPosition);
	}
}