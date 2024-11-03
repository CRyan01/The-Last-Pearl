#pragma once
#include "CaptainEnemy.h"
#include "Tower.h"
#include <sstream>
#include <fstream>
#include <iostream>
using namespace sf;
using namespace std;
//john by
class LevelManager
{//this file is for towers placement and background for levels. 
public :

	//this sets position of everything for levellike tower map ect.

	//void SetLevel(int levelNumber);
	std::vector<Vector2f> getWaypoints() const;

	int towerIndex = 0;
	//const int maxTower = 30;
	void SetLevel(int levelNumber);
	//std::vector<Vector2f> getWaypoints() const;

	//these are all the positions for all object in the game
	Vector2f TowerPos[30];
	
    std::ifstream inFile;
	//may be useful for later this allows reading from a file meaning we can just put the tower positions in a file

	//im gonna start including some enmeies and towers since im pretty sure we want this file to control them but until im sure im just gonna do basic level stuff

	//this is the map
	VertexArray rVaLevel;

	Vector2f EnemySpawnPiont;
	Vector2f JewelSpawnPiont;
 

private:

	std::vector<Vector2f> waypoints; // Store waypoints for the level enemy movemetn
	Vector2i m_LevelSize;
	float m_TimeModifier = 1;
	float m_BaseTimeLimit = 0;
	int m_CurrentLevel = 0;
	const int NUM_LEVELS = 4;
	//these are all used by the map for making it funtion
	int Tile_SizeX;
	int Tile_SizeY;
	const int PixelSize = 50;
	const int VERTS_IN_QUAD = 4;

};





