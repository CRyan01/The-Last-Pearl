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
;

		// Draw towers and projectiles via TowerManager
		TheGameTowers.draw(window, projectileHolder);


		PlayerHud.draw(window);
		window.draw(HealthText);
		
		// Draw the upgrade button
		window.draw(spriteUpgradeButton);
	}

	if (state == State::PAUSED) {
		// Draw pause text in the center of the screen - CR
		window.setView(window.getDefaultView()); // Use the default view to avoid scaling
		window.draw(pausedText);
		
	}

	if (state == State::MAIN_MENU) {
		window.draw(Level1Sprite);
		window.draw(Level2Sprite);
		window.draw(Level3Sprite);
		window.draw(MainMenuTitle);
		window.draw(Level1text);
		window.draw(Level2text);
		window.draw(Level3text);
		window.draw(OnOrOff);
		window.draw(IniniteWave);
	}

	window.draw(spriteCursor);

	window.display();

}