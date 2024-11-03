// Wave.cpp
// Jakub - K00285355
// Manages Wave content and spawning of enemies
#include "Wave.h"
#include <sstream>
#include <fstream>
#include <iostream>

// Constructor that initializes enemies based on the wave number
Wave::Wave(int waveNumber)
{
	enemies.clear(); // Clear any previous enemies.
	if (waveNumber <= 5)
	{
		// First 5 waves: only Buccaneers
		enemies = std::vector<EnemyType>(waveNumber * 5, BUCCANEER);
	}
	else if (waveNumber <= 8) {
		// Waves 6-8: Pirates alongside Buccaneers
		enemies = std::vector<EnemyType>(waveNumber * 3, BUCCANEER);
		enemies.insert(enemies.end(), waveNumber * 2, PIRATE);
	}
	else {
		// Last two waves (9-10):  Captains along with Buccaneers and Pirates
		enemies = std::vector<EnemyType>(waveNumber * 2, BUCCANEER);
		enemies.insert(enemies.end(), waveNumber * 2, PIRATE);
		enemies.insert(enemies.end(), waveNumber, CAPTAIN);
	}
	CurrentWave = waveNumber;
	std::cout << "Enemy size= " << enemies.size();
}

void Wave::NextWave()
{
	CurrentWave++;
	enemies.clear(); // Clear any previous enemies.
	if (CurrentWave <= 5)
	{
		// First 5 waves: only Buccaneers
		enemies = std::vector<EnemyType>(CurrentWave * 5, BUCCANEER);
	}
	else if (CurrentWave <= 8) {
		// Waves 6-8: Pirates alongside Buccaneers
		enemies = std::vector<EnemyType>(CurrentWave * 3, BUCCANEER);
		enemies.insert(enemies.end(), CurrentWave * 2, PIRATE);
	}
	else {
		// Last two waves (9-10):  Captains along with Buccaneers and Pirates
		enemies = std::vector<EnemyType>(CurrentWave * 2, BUCCANEER);
		enemies.insert(enemies.end(), CurrentWave * 2, PIRATE);
		enemies.insert(enemies.end(), CurrentWave, CAPTAIN);
	}
	std::cout << "Enemy size= " << enemies.size();

}

void Wave::initializeEnemies(float dtAsSeconds) {
	elapsedTime += dtAsSeconds; 
	
	// Check if there are enemies left to spawn
	if (!enemies.empty() && elapsedTime >= spawnDelay) {
		// Create the next enemy based on the type
		EnemyType type = enemies.back();
		std::unique_ptr<Enemy> enemy = nullptr;

		switch (type) {
		case BUCCANEER:
			enemy = std::make_unique<BuccaneerEnemy>();
			break;
		case PIRATE:
			enemy = std::make_unique<PirateEnemy>();
			break;
		case CAPTAIN:
			enemy = std::make_unique<CaptainEnemy>();
			break;
		}

		if (enemy) {
			enemy->spawn(40, 200, 0); // Default spawn position 
			activeEnemies.push_back(std::move(enemy)); // Move the enemy into the vector
			//cout << "Spawned enemy of type: " << type << endl; // Debugg
			//cout << "Total active enemies: " << activeEnemies.size() << endl; // Debug

			enemies.pop_back(); // Remove the spawned enemy from the list
		}

		elapsedTime -= spawnDelay; 
	}
}

void Wave::updateEnemies(float dtAsSeconds,  Paths& path) {

	// Get the next target position for this enemy
	Vector2f targetLocation;
	for (auto it = activeEnemies.begin(); it != activeEnemies.end(); ) {
		Enemy* enemy = it->get();

		// Replace with your actual method for getting the next position

		// Call the enemy's update method with the elapsed time and target location
		enemy->update(dtAsSeconds);

		// Check if the enemy has reached the target
		if (enemy->ReachedPos()) {
			targetLocation = path.nextPos(enemy->currentPos);
			enemy->SetNewTarget(targetLocation); // Set a new target if reached
			enemy->currentPos++; // Move to the next position in the path
			if (enemy->currentPos >= path.returnPathsSize())
			{
				enemy->hit(200000);
			}
		}

		// Remove the enemy if it is not alive anymore
		if (!enemy->isAlive()) {
			it = activeEnemies.erase(it); // Remove defeated enemy
			if (isWaveComplete())
			{
				NextWave();
			}
		}
		else {
			++it; // Move to the next enemy//need to check this seems useless
		}
	}
}

bool Wave::isWaveComplete()  {
	//std::cout << "\nhey this works " << activeEnemies.empty();
	return activeEnemies.empty();
}

const vector<Enemy*>& Wave::getActiveEnemies() const {
	static vector<Enemy*> rawEnemies; // Convert unique_ptr to raw pointer for access
	rawEnemies.clear();
	for (const auto& enemy : activeEnemies) {
		rawEnemies.push_back(enemy.get());
	}
	return rawEnemies;
}