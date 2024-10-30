
#include "TheLastPearl.h"


void TheLastPearl::CheckInputs()
{
	/* Handle events */
	Event event;
	while (window.pollEvent(event))
	{
		//mouse stuff
		// When left mouse button is pressed - CR
		if (event.type == Event::MouseButtonPressed)
		{
			
			if (event.mouseButton.button == Mouse::Left)
			{
				// Check if a selection box was clicked
				bool boxSelected = false;
				for (int i = 0; i < towerSelectionBoxSprites.size(); ++i)
				{
					if (towerSelectionBoxSprites[i].getGlobalBounds().contains(mouseWorldPosition)) {
						// Change the color of the unselected boxes
						for (auto& selectionBox : towerSelectionBoxSprites)
						{

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
				if (!boxSelected)
				{
					selectedTowerPosition = Vector2f(-1, -1);
				}
			}
		}


		// Check if a tower icon was clicked - CR
		if (spriteMusketTowerIcon.getGlobalBounds().contains(mouseWorldPosition)) {
			// Spawn the musket tower
			selectedTowerType = Tower::TowerType::MusketTower;
		} else if (spriteCannonTowerIcon.getGlobalBounds().contains(mouseWorldPosition)) {
			// Spawn the cannon tower
			selectedTowerType = Tower::TowerType::CannonTower;
		}

		// Spawn the selected tower type at the selected position
		if (selectedTowerType != Tower::TowerType::None && selectedTowerPosition.x >= 0) {
			createTower(selectedTowerType, selectedTowerPosition.x, selectedTowerPosition.y);

			// Reset selected type & position after spawning
			selectedTowerType = Tower::TowerType::None;
			selectedTowerPosition = Vector2f(-1, -1);
		}

		if (event.type == Event::KeyPressed) {

			//exiting the game
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}


			// Toggle pause when P is pressed - CR
			if (event.key.code == Keyboard::P) {
				// Switch between PAUSED and InLevel states
				if (state == State::PAUSED) {
					state = State::InLevel;
					clock.restart(); // Reset delta time to avoid frame jump
				}
				else if (state == State::InLevel) 
				{
					state = State::PAUSED;
				}
			}
		}
	}
}