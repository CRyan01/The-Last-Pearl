//by John Hannon K00281825
#include "Paths.h"

Paths::Paths()
{
	//cureently hardocded as no other metho is know
	Level1Pos.push_back(Vector2f(100, 200));
Level1Pos.push_back(Vector2f(1800, 200));
Level1Pos.push_back(Vector2f(1800, 450));
Level1Pos.push_back(Vector2f(120, 450));
Level1Pos.push_back(Vector2f(120, 740));
Level1Pos.push_back(Vector2f(1800, 740));
// Level1Pos.push_back(Vector2f(1920, 740));


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
	levelNumber - 1;
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