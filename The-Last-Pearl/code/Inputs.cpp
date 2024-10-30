
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
				bool boxSelected = false;
				// Check if a selection box was clicked

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



			// Check if a tower icon was clicked - CR
			if (spriteMusketTowerIcon.getGlobalBounds().contains(mouseWorldPosition)) {
				// Spawn the musket tower
				selectedTowerType = TowerType::MusketTower;
			}
			else if (spriteCannonTowerIcon.getGlobalBounds().contains(mouseWorldPosition)) {
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
		
			

			


		
	}
}



