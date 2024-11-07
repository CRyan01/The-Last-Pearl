// Libraries
#include "TheLastPearl.h"
void TheLastPearl::draw()
{
	window.clear();
	// Display the mainView in the window and draw everything related to it
	window.setView(GameView);
	// Draw the background
	window.draw(spriteBackground);
	/* Draw the frame */
	if (state == State::InLevel) {
		
		
		

		
		
		// Draw the enemies
		for (const auto& enemy : currentWave.getActiveEnemies()) {
			window.draw(enemy->getSprite());
		}

		// Draw selection boxes for tower positions
		for (const auto& box : towerSelectionBoxSprites) {
			window.draw(box);
		}

		// Draw the selected tower sprite
		window.draw(spriteSelectedTower);

		// Draw each tower
	//	for (const Tower& tower : towers) {
		//	window.draw(tower.getSprite());
		//}
		TheGameTowers.draw(window);

		// Draw the tower icons
		window.draw(spriteBuildMenuBackground);
		window.draw(spriteMusketTowerIcon);
		window.draw(spriteCannonTowerIcon);
		window.draw(spriteMortarTowerIcon);
		window.draw(spriteCrossbowTowerIcon);
		window.draw(spriteGoldIcon);

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

	window.draw(spriteCursor);

	window.display();

}