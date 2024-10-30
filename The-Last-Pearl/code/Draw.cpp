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
		
		
		

		
		
		//window.draw(Levels.rVaLevel, &m_TextureTiles);
		window.draw(buccaneerEnemy.getSprite());

		// Draw selection boxes for tower positions
		for (const auto& box : towerSelectionBoxSprites) {
			window.draw(box);
		}

		// Draw the selected tower sprite
		window.draw(spriteSelectedTower);

		// Draw each tower
		for (const Tower& tower : towers) {
			window.draw(tower.getSprite());
		}

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

	window.draw(spriteCursor);

	window.display();

}