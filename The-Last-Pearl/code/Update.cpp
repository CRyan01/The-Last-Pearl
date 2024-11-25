
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


		if (currentWave.IsLevelOver())
		{
			state = State::MAIN_MENU;
			MainMenu();
			//Reset();
			//std::cout << "This getting called?";
		}
		//Ensure enemies are initialized only once per wave
	
		currentWave.initializeEnemies(dtAsSeconds); 
		
		// Update wave enemies
		currentWave.updateEnemies(dtAsSeconds, MainPath);

		// Update towers and add projectiles to the holder
		TheGameTowers.update(dtAsSeconds, currentWave.getActiveEnemies(), projectileHolder);

		auto activeEnemies = currentWave.getActiveEnemies();
		//projectiles
		for (auto& projectile : projectileHolder.getProjectiles())
		{
			if (projectile.isActive())
			{
				for (auto it = activeEnemies.begin(); it != activeEnemies.end();)
				{
					Enemy* enemy = *it;

					if (projectile.getSprite().getGlobalBounds().intersects(enemy->getSprite().getGlobalBounds()))
					{
						

						// Log the damage dealt and remaining health of the enemy
						float damage = projectile.getDamage();
						bool enemyDied = enemy->hit(damage);
						
						if (enemyDied)
						{
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

		int currentWaveNum = currentWave.GetCurrentWave();


		//gets the damage he will suffer
		CaptainJackSparrow.Hit(currentWave.GetDamage());
		//gets the money hes gotten
		CaptainJackSparrow.GetPirateGold(currentWave.GetMoney());
		std::stringstream newText;
		if (currentWave.infinite==true)
		{
			newText << "Money = " << CaptainJackSparrow.money << " Pearl Health " << std::to_string(CaptainJackSparrow.health) << "\\" << std::to_string(CaptainJackSparrow.MaxHp) << "  Wave " << currentWaveNum << " Infinite";
		}
		else
		{
			newText << "Money = " << CaptainJackSparrow.money << " Pearl Health " << std::to_string(CaptainJackSparrow.health) << "\\" << std::to_string(CaptainJackSparrow.MaxHp) << "  Wave " << currentWaveNum << " / 10";

		}
		HealthText.setString(newText.str());
		//end game
		if (CaptainJackSparrow.GameOver())
		{
			state = State::MAIN_MENU;
			MainMenu();
		}
	}
	// Store the cursors position on the screen
	//mouse stuff
	mouseScreenPosition = Mouse::getPosition();

	// Convert mouse position to world coordinates of mainView
	mouseWorldPosition = window.mapPixelToCoords(
		Mouse::getPosition(window), GameView);

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