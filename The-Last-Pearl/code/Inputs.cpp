#include "TheLastPearl.h"
// By Conor Ryan
void TheLastPearl::CheckInputs() {
    /* Handle events */
    Event event;
    // Boolean to check if a plot is selected
    bool isPlotSelected = (selectedTowerPosition.x >= 0);

    while (window.pollEvent(event)) {

        //tower events
        TheGameTowers.TowerInputs(event,mouseWorldPosition);
        // Check if lmb was pressed
        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {

            // Boolean to indicate if a tower build icon was clicked
            bool iconClicked = false;

            // Check if a tower build icon was clicked if a valid plot is selected
            if (isPlotSelected) {
                // selectedTowerType
                iconClicked = PlayerHud.input(selectedTowerType, mouseWorldPosition);
            }

            // If a valid tower build icon is clicked
            if (iconClicked && selectedTowerType != Tower::TowerType::None) {
                // Create and place the tower

                int cost;
                switch (selectedTowerType)
                {
                case Tower::TowerType::CannonTower:
                    cost = 400;
                    break;
                case Tower::TowerType::MusketTower:
                    cost = 200;
                    break;
                }
                if (CaptainJackSparrow.CanBuy(cost))
                {
                    TheGameTowers.createTower(selectedTowerType, selectedTowerPosition.x, selectedTowerPosition.y);
                    // Mark the plot as occupied
                    occupiedTowerPositions.push_back(selectedTowerPosition);
                }
               

                // Reset selection variables
                selectedTowerType = Tower::TowerType::None;
                selectedTowerPosition = Vector2f(-1, -1);
                isPlotSelected = false;

                // Reset selection box colors
                for (auto& selectionBox : towerSelectionBoxSprites) {
                    selectionBox.setTexture(TextureHolder::GetTexture("graphics/notSelectedBox.png"));
                }

                continue; // Skip plot selection since an icon was clicked
            }

            // If no icon was clicked check if a plot was selected
            bool boxSelected = false;
            for (int i = 0; i < towerSelectionBoxSprites.size(); ++i) {
                if (towerSelectionBoxSprites[i].getGlobalBounds().contains(mouseWorldPosition)) {
                    // Reset all selection boxes to unselected texture
                    for (auto& selectionBox : towerSelectionBoxSprites) {
                        selectionBox.setTexture(TextureHolder::GetTexture("graphics/notSelectedBox.png"));
                    }

                    // Set the selected box to the highlighted texture
                    towerSelectionBoxSprites[i].setTexture(TextureHolder::GetTexture("graphics/selectedBox.png"));

                    // Only set the position the plot is unoccupied
                    if (!isPlotOccupied(towerPositions[i])) {
                        selectedTowerPosition = towerPositions[i];
                        isPlotSelected = true;
                    }
                    else {
                        selectedTowerPosition = Vector2f(-1, -1);
                        isPlotSelected = false;
                    }

                    boxSelected = true;
                    break;
                }
            }

            // Reset selection if no plot box was clicked
            if (!boxSelected) {
                // Reset selection box color
                for (auto& selectionBox : towerSelectionBoxSprites) {
                    selectionBox.setTexture(TextureHolder::GetTexture("graphics/notSelectedBox.png"));
                }
                selectedTowerPosition = Vector2f(-1, -1);
                isPlotSelected = false;
            }
            if (state == State::MAIN_MENU)
            {
                if (Level1Sprite.getGlobalBounds().contains(mouseWorldPosition))
                {
                    StartLevel(1);
                    state = State::InLevel;
                }
                else if (Level2Sprite.getGlobalBounds().contains(mouseWorldPosition))
                {
                    StartLevel(2);
                    state = State::InLevel;
                }
                else if (Level3Sprite.getGlobalBounds().contains(mouseWorldPosition))
                {
                    StartLevel(3);
                    state = State::InLevel;
                }


            }
        }

        // Handle key events for exiting and pausing
        if (event.type == Event::KeyPressed) {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) 
            {
                if (state == State::MAIN_MENU)
                {
                    exit(0);
                }
                else if (state == State::InLevel)
                {
                    state = State::MAIN_MENU;
                    MainMenu();
                   // Reset();
                }
            }
            if (event.key.code == Keyboard::P)
            {
                state = (state == State::PAUSED) ? State::InLevel : State::PAUSED;

                if (state == State::InLevel)
                {
                    clock.restart(); // Reset delta time to avoid frame jump

                }
            }
            if (state == State::MAIN_MENU)
            {
                if (Keyboard::isKeyPressed(Keyboard::Enter))
                {
                    state = State::InLevel;
                    StartLevel(1);
                }
            }
        }
    }
}
