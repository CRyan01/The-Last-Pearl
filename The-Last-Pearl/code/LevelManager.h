#pragma once
#include "CaptainEnemy.h"
#include "Tower.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include "WaveManager.h"
using namespace sf;
using namespace std;
//john by
class LevelManager
{//this file is for towers placement and background for levels. 
public :
	//this sets position of everything for levellike tower map ect.
	
	LevelManager() : waveManager(1) 
	{  
		SetLevel(1); // Default to level 1 
	}
	LevelManager(int levelNumber) : waveManager(levelNumber) 
	{
		SetLevel(levelNumber);
	}
	std::vector<Vector2f> getWaypoints() const;
	

	

	int towerIndex = 0;
	//const int maxTower = 30;
	void SetLevel(int levelNumber);
	//std::vector<Vector2f> getWaypoints() const;
	Vector2f TowerPos[30];

	WaveManager waveManager; // Manager for waves within the level
	
    std::ifstream inFile;
	//may be useful for later this allows reading from a file meaning we can just put the tower positions in a file

	//im gonna start including some enmeies and towers since im pretty sure we want this file to control them but until im sure im just gonna do basic level stuff

	//this is the map
	VertexArray rVaLevel;

	int Tile_SizeX;
	 int Tile_SizeY;
	 const int PixelSize = 50;
	const int VERTS_IN_QUAD = 4;

private:


	std::vector<Vector2f> waypoints; // Store waypoints for the level
	Vector2i m_LevelSize;
	Vector2f m_StartPosition;
	float m_TimeModifier = 1;
	float m_BaseTimeLimit = 0;
	int m_CurrentLevel = 0;
	const int NUM_LEVELS = 4;

};





