#include "TowerManager.h"
#include "TextureHolder.h"
#include <iostream>

TowerManager::TowerManager()
{
	AllGameTowers.clear();

}

void TowerManager::update(float seconds, const std::vector<Enemy*>& enemies, ProjectileHolder& projectileHolder) 
{
	for (auto& tower : AllGameTowers) 
	{
		tower.update(seconds, enemies, projectileHolder);
	}
	projectileHolder.update(seconds);  // Ensure projectiles are updated
}

void TowerManager::draw(sf::RenderWindow& window, ProjectileHolder& projectileHolder) 
{
	for (const auto& tower : AllGameTowers) 
	{
		window.draw(tower.getSprite());
	}
	projectileHolder.draw(window);  // Draw all projectiles
}
void TowerManager::TowerInputs(Event event, Vector2f mouseWorldPos)
{
	if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
	{

		for (int i = 0; i < AllGameTowers.size() + 0; i++)
		{
			if (AllGameTowers.at(i).getSprite().getGlobalBounds().contains(mouseWorldPos))
			{
				AllGameTowers.at(i).ClickedOn = true;
			}
			else
			{
				AllGameTowers.at(i).ClickedOn = false;
			}

		}

	}


}

void TowerManager::Reset()
{
	AllGameTowers.clear();

}

Tower* TowerManager::getTowerAtPosition(const Vector2f& position) {
	for (auto& tower : AllGameTowers) {
		if (tower.getSprite().getGlobalBounds().contains(position.x, position.y)) {
			std::cout << "here" << std::endl;
			return &tower;
		}
		std::cout << "there" << std::endl;
	}
	return nullptr; // No tower found at the position
}