#include "TheLastPearl.h"
// By Conor Ryan
void TheLastPearl::CheckInputs() {
    /* Handle events */
    Event event;
    // Boolean to check if a plot is selected
    bool isPlotSelected = (selectedTowerPosition.x >= 0);

    while (window.pollEvent(event)) {

        // Handle tower input events
        TheGameTowers.TowerInputs(event, mouseWorldPosition);

        // Check if lmb was pressed
        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {

            // Check if the upgrade button was clicked
            if (spriteUpgradeButton.getGlobalBounds().contains(mouseWorldPosition)) {
                handleUpgrade(); // upgrade the tower
                return;
            }

            // Check if a tower build icon was clicked
            if (isPlotSelected) {
                if (handleBuildIconClick()) {
                    return;
                }
            }

            // Check if a plot was selected
            if (handlePlotSelection()) {
                return;
            }
            // Handle main menu inputs
            if (state == State::MAIN_MENU)
            {
                if (Level1Sprite.getGlobalBounds().contains(mouseWorldPosition)) {
                    StartLevel(1); // Start Level 1
                    state = State::InLevel;
                }
                else if (Level2Sprite.getGlobalBounds().contains(mouseWorldPosition)) {
                    StartLevel(2); // Start Level 2
                    state = State::InLevel;
                }
                else if (Level3Sprite.getGlobalBounds().contains(mouseWorldPosition)) {
                    StartLevel(3); // Start Level 3
                    state = State::InLevel;
                }
                else if (OnOrOff.getGlobalBounds().contains(mouseWorldPosition))
                {
                    if (currentWave.returnInfinite())
                    {
                        currentWave.infinite = false;
                        OnOrOff.setTexture(TextureHolder::GetTexture("graphics/Off.png"));
                    }
                    else
                    {
                        currentWave.infinite = true;
                        OnOrOff.setTexture(TextureHolder::GetTexture("graphics/On.png"));
                    }

                }
            }

            // Reset selection if no valid plot was clicked
            resetSelectionIfNoClick();
        }

       

        // Handle key exiting and pausing
        if (event.type == Event::KeyPressed) {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                if (state == State::MAIN_MENU) {
                    exit(0); // exit the game
                } else if (state == State::InLevel) {
                    state = State::MAIN_MENU; // return to main menu
                    MainMenu();
                }
            }
            if (event.key.code == Keyboard::P) {
                // Pause the game
                state = (state == State::PAUSED) ? State::InLevel : State::PAUSED;

                // Reset delta time when unpaused
                if (state == State::InLevel) {
                    clock.restart();
                }
            }
            if (state == State::MAIN_MENU) {
                if (Keyboard::isKeyPressed(Keyboard::Enter)) {
                    state = State::InLevel; // Start at Level 1
                    StartLevel(1);
                }
            }
        }
    }
}

// Handle tower upgrades
void TheLastPearl::handleUpgrade() {
    // Make sure a valid position is selected
    if (selectedTowerPosition.x < 0 || selectedTowerPosition.y < 0) {
        return;
    }

    // Get the tower at the selected position
    Tower* selectedTower = TheGameTowers.getTowerAtPosition(selectedTowerPosition);

    // Check if the tower can be upgraded
    if (selectedTower && selectedTower->canUpgrade()) {
        int upgradeCost = selectedTower->getUpgradeCost();

        // Check if the player has enough gold
        if (CaptainJackSparrow.CanBuy(upgradeCost)) {
            CaptainJackSparrow.decreaseBalance(upgradeCost); // decrease the players balance
            selectedTower->upgrade(); // upgrade the tower
            soundManager.playSound("build"); // play a build sound
        } else {
            soundManager.playSound("click"); // play an error sound
        }
    } else {
       // std::cout << "Cannot Upgrade Tower" << std::endl;
    }
}

// Handle building a tower when an icon is clicked
bool TheLastPearl::handleBuildIconClick() {
    // Check if a build icon was clicked
    bool iconClicked = PlayerHud.input(selectedTowerType, mouseWorldPosition);

    if (iconClicked && selectedTowerType != Tower::TowerType::None) {
        int cost = (selectedTowerType == Tower::TowerType::CannonTower) ? 300 : 200;

        // Check if the player has enough gold
        if (CaptainJackSparrow.CanBuy(cost)) {
            // Build the tower
            TheGameTowers.createTower(selectedTowerType, selectedTowerPosition.x, selectedTowerPosition.y);
            occupiedTowerPositions.push_back(selectedTowerPosition); // mark the plot as occupied
            soundManager.playSound("build"); // play a build sound

            // Reset selection boxes
            resetSelection();
        } else {
           // std::cout << "Cannot Build Tower" << std::endl;
        }
        return true; // A build icon was clicked
    }

    return false; // No build icon was clicked
}

// Handles plot selection
bool TheLastPearl::handlePlotSelection() {
    for (size_t i = 0; i < towerSelectionBoxSprites.size(); ++i) {
        if (towerSelectionBoxSprites[i].getGlobalBounds().contains(mouseWorldPosition)) {
            resetSelectionBoxTextures(); // Reset all boxes to the unselected box texture

            // Highlight the selected box
            towerSelectionBoxSprites[i].setTexture(TextureHolder::GetTexture("graphics/selectedBox.png"));

            // Check if the plot is occupied
            if (isPlotOccupied(towerPositions[i])) {
                selectedTowerPosition = towerPositions[i]; // update selected position
                isPlotSelected = true; // mark plot as selected
            } else {
                selectedTowerPosition = towerPositions[i]; // update selected position for a free plot
                isPlotSelected = true; // mark plot as selected
            }
            return true; // A plot was successfully selected
        }
    }
    return false; // No plot was selected
}

// Resets the plot selection when no plot is clicked
void TheLastPearl::resetSelectionIfNoClick() {
    if (spriteUpgradeButton.getGlobalBounds().contains(mouseWorldPosition)) {
        return; // avoid resetting when upgrade button is clicked
    }

    // Reset selection box visuals
    resetSelectionBoxTextures();
    selectedTowerPosition = Vector2f(-1, -1); // clear selection
    isPlotSelected = false; // mark no plot as selected
}

// Resets all selection box textures
void TheLastPearl::resetSelectionBoxTextures() {
    for (auto& selectionBox : towerSelectionBoxSprites) {
        selectionBox.setTexture(TextureHolder::GetTexture("graphics/notSelectedBox.png"));
    }
}

// Resets selection variables
void TheLastPearl::resetSelection() {
    selectedTowerType = Tower::TowerType::None; // clear tower type selection
    selectedTowerPosition = Vector2f(-1, -1); // reset selected position
    isPlotSelected = false; // mark no plot as selected
    resetSelectionBoxTextures(); // reset selection box visuals
}