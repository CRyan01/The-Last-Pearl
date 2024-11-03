#include "LevelManager.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace sf;
using namespace std;
//BY Jakub
std::vector<Vector2f> LevelManager::getWaypoints() const {
    // Vector to store waypoints
    std::vector<Vector2f> waypoints;
    // Set waypoints
    waypoints.push_back(Vector2f(100, 200));
    waypoints.push_back(Vector2f(1800, 200));
    waypoints.push_back(Vector2f(1800, 450));
    waypoints.push_back(Vector2f(120, 450));
    waypoints.push_back(Vector2f(120, 740));
    waypoints.push_back(Vector2f(1920, 740));
    return waypoints;
}


//By John
void LevelManager::SetLevel(int LevelNumber)
{
    // Load the level only if not already loaded / Preventing lag when trying to load the file over and over again
    if (m_CurrentLevel == LevelNumber) return;

    // Store current level number
    m_CurrentLevel = LevelNumber;
    m_LevelSize.x = 0;
    m_LevelSize.y = 0;

    // Create the level filename based on the level number
    string levelToLoad = "Levels/Level" + std::to_string(LevelNumber) + ".txt";
    std::ifstream inputFile(levelToLoad);
    if (!inputFile) {
        throw std::runtime_error("Cannot open level file: " + levelToLoad);
    }

    // Load the level data into a vector
    std::vector<std::vector<int>> arrayLevel;
    std::string row;
    while (getline(inputFile, row)) {
        std::vector<int> rowData(row.length());
        for (size_t x = 0; x < row.length(); ++x) {
            rowData[x] = row[x] - '0'; // Assuming level data is single digits
        }
        arrayLevel.push_back(rowData);
        ++m_LevelSize.y;
    }
    m_LevelSize.x = arrayLevel[0].size(); // Assuming all rows are the same length

    // What type of primitive are we using?
    rVaLevel.clear(); 
    rVaLevel.setPrimitiveType(Quads);
    // Set the size of the vertex array
    rVaLevel.resize(m_LevelSize.x * m_LevelSize.y * VERTS_IN_QUAD);

    //to et the space apart for screen size

    int ScreenxWidth = VideoMode::getDesktopMode().width;
    int ScreenYHeight = VideoMode::getDesktopMode().height;
    Tile_SizeX = (ScreenxWidth / m_LevelSize.x) / 2;
    Tile_SizeY = (ScreenYHeight / m_LevelSize.y);
    //this is done since the towers will be restarted
    towerIndex = 0;

    //std::cout << "hey " << ScreenxWidth << " / " << m_LevelSize.x << " = " << Tile_SizeX << " \n";
    //::cout << "hey " << ScreenYHeight << " / " << m_LevelSize.y << " = " << Tile_SizeY << " \n";
    
    // Start at the beginning of the vertex array
    int currentVertex = 0;

    for (int x = 0; x < m_LevelSize.x; x++)
    {
        for (int y = 0; y < m_LevelSize.y; y++)
        {
            if ((arrayLevel[y][x] != 0)||(arrayLevel[y][x]==9))
            {
                // Position each vertex in the current quad
                rVaLevel[currentVertex + 0].position = Vector2f(x * Tile_SizeX, y * Tile_SizeY);
                rVaLevel[currentVertex + 1].position = Vector2f((x * Tile_SizeX) + Tile_SizeX, y * Tile_SizeY);
                rVaLevel[currentVertex + 2].position = Vector2f((x * Tile_SizeX) + Tile_SizeX, (y * Tile_SizeY) + Tile_SizeY);
                rVaLevel[currentVertex + 3].position = Vector2f((x * Tile_SizeX), (y * Tile_SizeY) + Tile_SizeY);

                if (arrayLevel[y][x] == 9)
                {
                    TowerPos[towerIndex].x = x;
                    TowerPos[towerIndex].y = y;
                    arrayLevel[y][x] = 4;
                    towerIndex++;
                }

                // Which tile from the sprite sheet should we use
                //tile size times 1,2,3 this make the tile go down
                int verticalOffset = arrayLevel[y][x] * PixelSize;
                rVaLevel[currentVertex + 0].texCoords = Vector2f(0, 0 + verticalOffset);
                rVaLevel[currentVertex + 1].texCoords = Vector2f(PixelSize, 0 + verticalOffset);
                rVaLevel[currentVertex + 2].texCoords = Vector2f(PixelSize, PixelSize + verticalOffset);
                rVaLevel[currentVertex + 3].texCoords = Vector2f(0, PixelSize + verticalOffset);
            }
            // Position ready for the next four vertices
            currentVertex += VERTS_IN_QUAD;
        }
    }
}