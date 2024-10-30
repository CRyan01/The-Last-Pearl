#include "TheLastPearl.h"
// By Conor Ryan
void TheLastPearl::detectCollisions() {
	// Do collision detection
}

// Check if a tower already occupies a slot - CR
bool TheLastPearl::isPlotOccupied(Vector2f position) {
	// Iterate through list of occupied tower positions
	for (const auto& towerPosition : occupiedTowerPositions) {
		if (towerPosition == position) {
			return true; // Return true if the positions are the same
		}
	}
	return false; // Otherwise return false
}