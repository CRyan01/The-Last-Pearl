#include "LevelManager.h"
#include <SFML/Graphics.hpp>
#include <vector>

std::vector<Vector2f> LevelManager::getWaypoints() const {
	// Vector to store waypoints
	std::vector<Vector2f> waypoints;
	// Set waypoints
	waypoints.push_back(Vector2f(100, 500));
	waypoints.push_back(Vector2f(150, 500));
	waypoints.push_back(Vector2f(200, 550));
	waypoints.push_back(Vector2f(250, 500));
	waypoints.push_back(Vector2f(300, 550));
	waypoints.push_back(Vector2f(350, 500));
	waypoints.push_back(Vector2f(400, 550));
	waypoints.push_back(Vector2f(450, 500));
	return waypoints;
}

/*void LevelManager::SetLevel(int LevelNumber)
{
	switch(LevelNumber)
	{
	case 1:
		// Define waypoints for the first level
		waypoints =
		{
			{100.f, 500.f}, // Start point
			{200.f, 500.f}, // Move right
			{300.f, 400.f}, // Move up
			{400.f, 400.f}, // Move right
			{500.f, 500.f}, // Move down
			{600.f, 500.f}, // Move right
			{700.f, 400.f}, // Move up
			{800.f, 400.f}, // Move right to the end point
		};
		//background sprite tower positions starting money
		break;
	case 2:
		break;
	
	
	}
}*/

LevelManager::LevelManager()
{
	//maybe levels classes like level 1=   Level FameLevel=Level(1);



}