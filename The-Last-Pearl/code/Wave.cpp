// Wave.cpp
// Jakub - K00285355
// Manages Wave content and spawning of enemies
#include "Wave.h"
#include <sstream>
#include <fstream>
#include <iostream>

// Constructor that initializes enemies based on the wave number
Wave::Wave(int LevelNumber)
{
	switch (LevelNumber)
	{
	case 1:
		enemySpawnPos = Vector2f(40, 200);
		break;
	case 2:
		//std::cout << "This Happens";
		enemySpawnPos = Vector2f(180, 1040);
		break;
	case 3:
		enemySpawnPos = Vector2f(10, 20);
		break;
	}
	
	CurrentWave = 1;
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

}
bool Wave::IsLevelOver()
{
	return LevelComplete;

}
void Wave::NextWave()
{
	enemies.clear(); // Clear any previous enemies.
	CurrentWave++;
	if (CurrentWave >= CurrentMaxWave)
	{
		LevelComplete = true;
	}
	else
	{
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
		LevelComplete = false;
	}

}

void Wave::initializeEnemies(float dtAsSeconds) {
	elapsedTime += dtAsSeconds;
	if (isWaveComplete())
	{
		//NextWave();
	}
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
			enemy->spawn(enemySpawnPos.x, enemySpawnPos.y, 0); // Default spawn position 
			activeEnemies.push_back(std::move(enemy)); // Move the enemy into the vector

			enemies.pop_back(); // Remove the spawned enemy from the list
		}

		elapsedTime -= spawnDelay;
	}
}
// Spawns enemies based on time and adds them to activeEnemies
void Wave::updateEnemies(float dtAsSeconds, Paths& path) {

	// Get the next target position for this enemy
	Vector2f targetLocation;
	for (auto it = activeEnemies.begin(); it != activeEnemies.end(); ) {
		Enemy* enemy = it->get();

		// Call the enemy's update method 
		enemy->update(dtAsSeconds);

		// Check if the enemy has reached the target
		if (enemy->ReachedPos()) {

			targetLocation = path.nextPos(enemy->currentPos);
			enemy->SetNewTarget(targetLocation); // Set a new target if reached
			enemy->currentPos++; // Move to the next position in the path
			if (enemy->currentPos >= path.returnPathsSize())
			{
				CollectedDamage += enemy->Damage();
				enemy->hit(200000);
				enemy->DeathMoney = 0;
			}
		}

		// Remove the enemy if it is not alive anymore
		if (!enemy->isAlive()) {
			//enemy money collection
				MoneyTotal += enemy->DeathMoney;
			
			it = activeEnemies.erase(it); // Remove defeated enemy
			if (isWaveComplete())
			{
				activeEnemies.clear();
				NextWave();
			}

		}
		else {
			++it; // Move to the next enemy//need to check this seems useless
		}
	}

}

bool Wave::isWaveComplete() {

	// << "\nhey this works " << activeEnemies.empty();
	return activeEnemies.empty();
}

vector<Enemy*> Wave::getActiveEnemies() const
{
	vector<Enemy*> rawEnemies;
	rawEnemies.reserve(activeEnemies.size());  // Reserve space for efficiency
	for (const auto& enemy : activeEnemies) {
		rawEnemies.push_back(enemy.get());  // Convert unique_ptr to raw pointer
	}
	return rawEnemies;
}

int Wave::GetDamage()
{

	int newint = CollectedDamage;
	CollectedDamage = 0;

	return newint;

}

int Wave::GetMoney()
{
	int newMoney= MoneyTotal;

	MoneyTotal = 0;
	return newMoney;

}