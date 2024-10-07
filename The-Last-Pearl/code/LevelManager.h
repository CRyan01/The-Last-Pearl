#pragma once
#include "CaptainEnemy.h"
#include "Tower.h"
#include <fstream>
//john by
class LevelManager
{//this file is for towers placement and background for levels. 
public :
	//this sets position of everything for levellike tower map ect.
	void SetLevel(int levelNumber);
	LevelManager();
	
	
	int TowerPosXY[15][15];
    std::ifstream inFile;
	//may be useful for later this allows reading from a file meaning we can just put the tower positions in a file

	//im gonna start including some enmeies and towers since im pretty sure we want this file to control them but until im sure im just gonna do basic level stuff
	
 


private:

};