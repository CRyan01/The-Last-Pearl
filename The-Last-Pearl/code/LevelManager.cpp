#include "LevelManager.h"
//gonna start with some definitions

void LevelManager::SetLevel(int LevelNumber)
{
	
	m_LevelSize.x = 0;
	m_LevelSize.y = 0;
	string leveltoload;
	leveltoload = "Levels/Level1.txt";

	ifstream inputFile(leveltoload);
	string s;


	// Count the number of rows in the file
	while (getline(inputFile, s))
	{
		++m_LevelSize.y;
	}
	std :: cout << m_LevelSize.y<<"\n";
	// Store the length of the rows
	m_LevelSize.x = s.length();

	// Go back to the start of the file
	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	// Prepare the 2d array to hold the int values from the file
	int** arrayLevel = new int* [m_LevelSize.y];
	for (int i = 0; i < m_LevelSize.y; ++i)
	{
		// Add a new array into each array element
		arrayLevel[i] = new int[m_LevelSize.x];
	}

	// Loop through the file and store all the values in the 2d array
	string row;
	int y = 0;
	while (inputFile >> row)
	{
		for (int x = 0; x < row.length(); x++) {

			const char val = row[x];
			std:cout << val;
			arrayLevel[y][x] = atoi(&val);

		}
		std::cout << "\n";
		y++;
	}

	// close the file
	inputFile.close();

	// What type of primitive are we using?
	rVaLevel.setPrimitiveType(Quads);


	int ScreenxWidth = VideoMode::getDesktopMode().width;
	int ScreenYHeight = VideoMode::getDesktopMode().height;
	// Set the size of the vertex array
	rVaLevel.resize(ScreenxWidth * ScreenYHeight*VERTS_IN_QUAD );

	//to et the space apart for screen size


	Tile_SizeX = (ScreenxWidth / m_LevelSize.x)/2;
	Tile_SizeY = (ScreenYHeight/m_LevelSize.y );

	std::cout << "hey " << ScreenxWidth << " / " << m_LevelSize.x << " = " << Tile_SizeX << " \n";
	std::cout << "hey " << ScreenYHeight << " / " << m_LevelSize.y << " = " << Tile_SizeY << " \n";
	// Start at the beginning of the vertex array
	int currentVertex = 0;

	for (int x = 0; x < m_LevelSize.x; x++)
	{
		for (int y = 0; y < m_LevelSize.y; y++)
		{
			if (arrayLevel[y][x] != 0)
			{
				// Position each vertex in the current quad
				rVaLevel[currentVertex + 0].position =
					Vector2f(x * Tile_SizeX, y * Tile_SizeY);

				rVaLevel[currentVertex + 1].position =
					Vector2f((x * Tile_SizeX) + Tile_SizeX, y * Tile_SizeY);

				rVaLevel[currentVertex + 2].position =
					Vector2f((x * Tile_SizeX) + Tile_SizeX, (y * Tile_SizeY) + Tile_SizeY);

				rVaLevel[currentVertex + 3].position =
					Vector2f((x * Tile_SizeX), (y * Tile_SizeY) + Tile_SizeY);

				// Which tile from the sprite sheet should we use
				//tile size times 1,2,3 this make the tile go down
				//int check = arrayLevel[x][y];
					//if (check == 5)
					//	//{
				//	arrayLevel[x][y] = 1;
					//new array add pos
				//}
				int verticalOffset = arrayLevel[y][x] * PixelSize;
			
				std::cout << "hey thingy " << arrayLevel[y][x]<<" && \n ";
				cout << " 1 x= " << x * Tile_SizeX << " y= " << y * Tile_SizeY;
				cout << "\n 2 x= " << (x * Tile_SizeX) + Tile_SizeX << " y= " << y * Tile_SizeY;
				cout << " \n3 x= " << (x * Tile_SizeX) + Tile_SizeX << " y= " << (y * Tile_SizeY) + Tile_SizeY;
				cout << " \n4 x= " << (x * Tile_SizeX) << " y= " << (y * Tile_SizeY) + Tile_SizeY;
				rVaLevel[currentVertex + 0].texCoords =
					Vector2f(0, 0 + verticalOffset);

				rVaLevel[currentVertex + 1].texCoords =
					Vector2f(PixelSize, 0 + verticalOffset);

				rVaLevel[currentVertex + 2].texCoords =
					Vector2f(PixelSize, PixelSize + verticalOffset);

				rVaLevel[currentVertex + 3].texCoords =
					Vector2f(0, PixelSize + verticalOffset);
			}
			// Position ready for the next four vertices
			currentVertex = currentVertex + VERTS_IN_QUAD;
		}
	}



}
