// Libraries
#include <sstream>
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TheLastPearl.h"
#include "TextureHolder.h"
#include "MusketTower.h"
#include "CannonTower.h"



using namespace sf;

//by John All methods starting off
TheLastPearl::TheLastPearl()
{

	// Set the default resolution to scale to - CR
	resolution.x = 1920;
	resolution.y = 1080;

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

		// Draw selection boxes for tower positions
		for (const auto& box : towerSelectionBoxSprites) {
			window.draw(box);
		}

		// Draw the selected tower sprite
		window.draw(spriteSelectedTower);

		// Draw the tower icons
		window.draw(spriteMusketTowerIcon);
		window.draw(spriteCannonTowerIcon);

		// Draw the cursor
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
		// When left mouse button is pressed - CR
		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			// Check if a selection box was clicked
			bool boxSelected = false;
			for (int i = 0; i < towerSelectionBoxSprites.size(); ++i) {
				if (towerSelectionBoxSprites[i].getGlobalBounds().contains(mouseWorldPosition)) {
					// Change the color of the unselected boxes
					for (auto& selectionBox : towerSelectionBoxSprites) {
						selectionBox.setTexture(TextureHolder::GetTexture("graphics/notSelectedBox.png"));
					}
					// Change the color of the selected box to green
					towerSelectionBoxSprites[i].setTexture(TextureHolder::GetTexture("graphics/selectedBox.png"));

					// Update the currently selected towers position
					selectedTowerPosition = towerPositions[i];
					boxSelected = true;
					break; // break when found
				}
			}

			// Reset the selected position if no box was clicked
			if (!boxSelected) {
				selectedTowerPosition = Vector2f(-1, -1);
			}

			// Check if a tower icon was clicked - CR
			if (spriteMusketTowerIcon.getGlobalBounds().contains(mouseWorldPosition)) {
				// Spawn the musket tower
				selectedTowerType = TowerType::MusketTower;
			} else if (spriteCannonTowerIcon.getGlobalBounds().contains(mouseWorldPosition)) {
				// Spawn the cannon tower
				selectedTowerType = TowerType::CannonTower;
			}

			// Spawn the selected tower type at the selected position
			if (selectedTowerType != TowerType::None && selectedTowerPosition.x >= 0) {
				Tower* tower = nullptr;

				// Spawn the correct type of tower
				//if (selectedTowerType == TowerType::MusketTower) {
				//	tower = new MusketTower(selectedTowerPosition.x, selectedTowerPosition.y);
				//} else if (selectedTowerType == TowerType::CannonTower) {
				//	tower = new CannonTower(selectedTowerPosition.x, selectedTowerPosition.y);
				//}

				// Add the newly created tower to the list of towers
				//if (tower) {
				//	towers.push_back(std::move(tower)); // Move the unique_ptr to the vector
				//}

				// Reset selected type & position after spawning
				//selectedTowerType = TowerType::None;
				//selectedTowerPosition = Vector2f(-1, -1);
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