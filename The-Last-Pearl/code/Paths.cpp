//by John Hannon K00281825
#include "Paths.h"

Paths::Paths()
{
	//cureently hardocded as no other metho is know
	//Level1Pos.push_back(Vector2f(100, 200));
	Level1Pos.push_back(Vector2f(1800, 200));
	Level1Pos.push_back(Vector2f(1800, 450));
	Level1Pos.push_back(Vector2f(120, 450));
	Level1Pos.push_back(Vector2f(120, 740));
	Level1Pos.push_back(Vector2f(1800, 740));
	// Level1Pos.push_back(Vector2f(1920, 740));

	Level2Pos.push_back(Vector2f(150, 600));
	Level2Pos.push_back(Vector2f(1238, 600));
	Level2Pos.push_back(Vector2f(1220, 130));
	Level2Pos.push_back(Vector2f(680, 130));
	Level2Pos.push_back(Vector2f(680, 600));
	Level2Pos.push_back(Vector2f(1755, 600));
	Level2Pos.push_back(Vector2f(1755, 1000));

	Level3Pos.push_back(Vector2f(200, 600));//fturn
	Level3Pos.push_back(Vector2f(200, 80));//up
	Level3Pos.push_back(Vector2f(500, 80));//right
	Level3Pos.push_back(Vector2f(500, 600));//down
	Level3Pos.push_back(Vector2f(1000, 600));//right
	Level3Pos.push_back(Vector2f(1000, 80));//up
	Level3Pos.push_back(Vector2f(1800, 80));//right
	Level3Pos.push_back(Vector2f(1800, 600));//down

}
Paths::~Paths()
{
	//done for memory
	CurrentPath.clear();
	Level1Pos.clear();
	Level2Pos.clear();
	Level3Pos.clear();
	Level4Pos.clear();
	Level5Pos.clear();


}
void Paths::SetLevel(int levelNumber)
{
	
	//setting which vector we using
	CurrentPath.clear();
	switch (levelNumber)
	{
	case 1:
		CurrentPath = Level1Pos;
		break;
	case 2:
		CurrentPath = Level2Pos;
		break;
	case 3:
		CurrentPath = Level3Pos;
		break;
	case 4:
		CurrentPath = Level4Pos;
		break;
	case 5:
		CurrentPath = Level5Pos;
		break;
	}


}

Vector2f Paths::nextPos(int currentPos) 
{
	currentPos++;
	//std::
	// << "\nCurrent position "<<currentPos;
	if (currentPos >= CurrentPath.size())
	{
		
		return CurrentPath.at(CurrentPath.size() - 1);
	}
	else
	{
		return CurrentPath.at(currentPos );
	}

}

int Paths::returnPathsSize()
{

	return CurrentPath.size();

}