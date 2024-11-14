
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



		//Ensure enemies are initialized only once per wave
	
		currentWave.initializeEnemies(dtAsSeconds); 
		
		// Update wave enemies
		currentWave.updateEnemies(dtAsSeconds, MainPath);

		// Update towers and add projectiles to the holder
		TheGameTowers.update(dtAsSeconds, currentWave.getActiveEnemies(), projectileHolder);

		auto activeEnemies = currentWave.getActiveEnemies();
		//std::cout << "Active enemies count in update: " << activeEnemies.size() << std::endl;

		for (auto& projectile : projectileHolder.getProjectiles())
		{
			if (projectile.isActive())
			{
				for (auto it = activeEnemies.begin(); it != activeEnemies.end();)
				{
					Enemy* enemy = *it;

					if (projectile.getSprite().getGlobalBounds().intersects(enemy->getSprite().getGlobalBounds()))
					{
						std::cout << "Collision detected!" << std::endl;

						// Log the damage dealt and remaining health of the enemy
						float damage = projectile.getDamage();
						bool enemyDied = enemy->hit(damage);
						std::cout << "Enemy took " << damage << " damage. " << "Remaining health: " << enemy->getHealth() << std::endl;

						if (enemyDied)
						{
							std::cout << "Enemy defeated and removed from active list." << std::endl;
							it = activeEnemies.erase(it);
						}
						else
						{
							++it;
						}
						projectile.setInactive();
						break;
					}
					else
					{
						++it;
					}
				}
			}
		}

		


		CaptainJackSparrow.Hit(currentWave.GetDamage());
		std::stringstream newText;
		newText << "Money = " << CaptainJackSparrow.money << " Pearl Health " << std::to_string(CaptainJackSparrow.health) << "\\" << std::to_string(CaptainJackSparrow.MaxHp);
		HealthText.setString(newText.str());

		if (CaptainJackSparrow.GameOver())
		{
			exit(0);
		}
	}
	// Store the cursors position on the screen
	//mouse stuff
	mouseScreenPosition = Mouse::getPosition();

	// Convert mouse position to world coordinates of mainView
	mouseWorldPosition = window.mapPixelToCoords(
		Mouse::getPosition(), GameView);

	// Set the cursor to the mouse world location
	spriteCursor.setPosition(mouseWorldPosition);
	// Set the cursor to the mouse world location
	spriteCursor.setPosition(mouseWorldPosition);
	/* Update the frame */
	//if (state == State::InLevel) {
	//	Level1();

	//} // End updating the frame
	
	if (state == State::MAIN_MENU)
	{
		//MainMenu();

		CheckInputs();
	}

	
}