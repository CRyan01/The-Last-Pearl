#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Tower.h"
#include "MusketTower.h"
#include "CannonTower.h"

using namespace sf;
using namespace std;

// By Conor Ryan
class TowerManager {
public:

    //what does this do
    //update all towers
    //make the towers shoot
    //updates bullets
    //upgrade towers
    //
  

private:
    vector<Tower> AllGameTowers;

public:
    // Constructor
    TowerManager();
    // Create a tower of a specific type at a position
    void createTower(Tower::TowerType type, float x, float y);
    // Update the towers
    void update(float seconds, const std::vector<Enemy*>& enemies, ProjectileHolder& projectileHolder);
    // Draw the towers
    void draw(sf::RenderWindow& window, ProjectileHolder& projectileHolder);
    // Handle tower inputs
    void TowerInputs(Event event,Vector2f mouseWorldPos);
    // Reutrns the tower at a specified position
    Tower* getTowerAtPosition(const Vector2f& position);
    // Resets the towers
    void Reset();
};