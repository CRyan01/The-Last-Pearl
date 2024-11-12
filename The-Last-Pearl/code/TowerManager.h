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
    TowerManager();
    void createTower(Tower::TowerType type, float x, float y);
    void update(float seconds, const std::vector<Enemy*>& enemies, ProjectileHolder& projectileHolder);
    void draw(sf::RenderWindow& window, ProjectileHolder& projectileHolder);
    void TowerInputs(Event event,Vector2f mouseWorldPos);

};