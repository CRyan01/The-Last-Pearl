
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

		//Update Buccaneer Enemy
		buccaneerEnemy.update(dtAsSeconds);

		if (buccaneerEnemy.ReachedPos())
		{
			buccaneerEnemy.SetNewTarget(MainPath.nextPos(buccaneerEnemy.currentPos));
			buccaneerEnemy.currentPos++;
		}


		// Convert mouse position to world coordinates of mainView
		mouseWorldPosition = window.mapPixelToCoords(
		Mouse::getPosition(), GameView);

		// Set the cursor to the mouse world location
		spriteCursor.setPosition(mouseWorldPosition);
	}		

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