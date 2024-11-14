
#include "TheLastPearl.h"





void TheLastPearl::update()
{
	/* Update the frame */
	if (state == State::InLevel)
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

		//Ensure enemies are initialized only once per wave
	
		currentWave.initializeEnemies(dtAsSeconds); 
		
		// Update wave enemies
		currentWave.updateEnemies(dtAsSeconds, MainPath);

		// Update towers and add projectiles to the holder
		TheGameTowers.update(dtAsSeconds, currentWave.getActiveEnemies(), projectileHolder);

		// Check for projectile-enemy collisions
		for (auto& projectile : projectileHolder.getProjectiles()) 
		{
			if (projectile.isActive()) 
			{
				for (auto it = activeEnemies.begin(); it != activeEnemies.end();) 
				{
					Enemy* enemy = *it;
					if (enemy->isAlive() && projectile.checkCollision(enemy->getSprite().getGlobalBounds())) 
					{
						if (enemy->hit(projectile.getDamage())) 
						{
							it = activeEnemies.erase(it);  // Remove dead enemy
						}
						else 
						{
							++it;
						}
						projectile.setInactive();  // Deactivate projectile after collision
						break;  // Stop checking other enemies for this projectile
					}
					else 
					{
						++it;
					}
				}
			}
		}

		// Convert mouse position to world coordinates of mainView
		mouseWorldPosition = window.mapPixelToCoords(
			Mouse::getPosition(), GameView);

		// Set the cursor to the mouse world location
		spriteCursor.setPosition(mouseWorldPosition);
	}
	std::stringstream newText;
	newText<< "Money = " << CaptainJackSparrow.money << " Pearl Health " << std::to_string(CaptainJackSparrow.health) << "\\" << std::to_string(CaptainJackSparrow.MaxHp);
	HealthText.setString(newText.str());
	// Set the cursor to the mouse world location
	spriteCursor.setPosition(mouseWorldPosition);
	/* Update the frame */
	//if (state == State::InLevel) {
	//	Level1();

	//} // End updating the frame

	if (state == State::MAIN_MENU)
	{
		MainMenu();

		CheckInputs();
	}
}