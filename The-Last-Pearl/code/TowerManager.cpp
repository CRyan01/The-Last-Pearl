#include "TowerManager.h"
#include "TextureHolder.h"
TowerManager::TowerManager()
{
	AllGameTowers.clear();



}

void TowerManager::draw(RenderWindow& window)
{
	for (int i = 0; i < AllGameTowers.size()+0; i++)
	{
		window.draw(AllGameTowers.at(i).getSprite());
		if (AllGameTowers.at(i).ClickedOn)
		{
			window.draw(AllGameTowers.at(i).Sight);
		}
	}


}
void TowerManager::update(float seconds)
{
	for (int i = 0; i < AllGameTowers.size() + 0; i++)
	{
		AllGameTowers.at(i).update(seconds);
		
	}

}
void TowerManager::TowerInputs(Event event,Vector2f mouseWorldPos)
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