#include "BiomeManager.h"

const float BiomeManager::SEA1_LEVEL = 0.0f;
const float BiomeManager::SEA2_LEVEL = 0.2f;
const float BiomeManager::SAND_LEVEL = 0.25f;
const float BiomeManager::GRASS_LEVEL = 0.4f;
const float BiomeManager::MOUNTAIN_LEVEL = 0.5f;

const RGB BiomeManager::ERROR_COLOR(217, 87, 99);
const RGB BiomeManager::SEA1_COLOR(63, 63, 116);
const RGB BiomeManager::SEA2_COLOR(91, 110, 225);
const RGB BiomeManager::SAND_COLOR(251, 242, 54);
const RGB BiomeManager::GRASS_COLOR(106, 190, 48);
const RGB BiomeManager::MOUNTAIN_COLOR(155, 173, 183);

RGB BiomeManager::getColor(float height) {
	if (height >= BiomeManager::MOUNTAIN_LEVEL) {
		return BiomeManager::MOUNTAIN_COLOR;
	}

	if (height >= BiomeManager::GRASS_LEVEL) {
		return BiomeManager::GRASS_COLOR;
	}

	if (height >= BiomeManager::SAND_LEVEL) {
		return BiomeManager::SAND_COLOR;
	}

	if (height >= BiomeManager::SEA2_LEVEL) {
		return BiomeManager::SEA2_COLOR;
	}

	if (height >= BiomeManager::SEA1_LEVEL) {
		return BiomeManager::SEA1_COLOR;
	}

	return BiomeManager::ERROR_COLOR;
}
