#include "BiomeManager.h"

#include <cassert>

float BiomeManager::SEA1_LEVEL = 0.0f;
float BiomeManager::SEA2_LEVEL = 0.3f;
float BiomeManager::SEA3_LEVEL = 0.45f;
float BiomeManager::SEA4_LEVEL = 0.48f;
float BiomeManager::SAND_LEVEL = 0.488f;
float BiomeManager::GRASS1_LEVEL = 0.5f;
float BiomeManager::GRASS2_LEVEL = 0.54f;
float BiomeManager::FOREST_LEVEL = 0.52f;
float BiomeManager::MOUNTAIN1_LEVEL = 0.57f;
float BiomeManager::MOUNTAIN2_LEVEL = 0.58f;
float BiomeManager::SNOW_LEVEL = 0.59f;

const RGB BiomeManager::ERROR_COLOR(217, 87, 99);
const RGB BiomeManager::SEA1_COLOR(63, 63, 116);
const RGB BiomeManager::SEA2_COLOR(91, 110, 225);
const RGB BiomeManager::SEA3_COLOR(99, 155, 255);
const RGB BiomeManager::SEA4_COLOR(95, 205, 228);
const RGB BiomeManager::SAND_COLOR(251, 242, 54);
const RGB BiomeManager::GRASS1_COLOR(153, 229, 80);
const RGB BiomeManager::GRASS2_COLOR(106, 190, 48);
const RGB BiomeManager::FOREST_COLOR(55, 148, 110);
const RGB BiomeManager::MOUNTAIN1_COLOR(105, 106, 106);
const RGB BiomeManager::MOUNTAIN2_COLOR(155, 173, 183);
const RGB BiomeManager::SNOW_COLOR(255, 255, 255);

RGB BiomeManager::getColor(float height) {
	if (height >= BiomeManager::SNOW_LEVEL) {
		return BiomeManager::SNOW_COLOR;
	}	

	if (height >= BiomeManager::MOUNTAIN2_LEVEL) {
		return BiomeManager::MOUNTAIN2_COLOR;
	}	
	
	if (height >= BiomeManager::MOUNTAIN1_LEVEL) {
		return BiomeManager::MOUNTAIN1_COLOR;
	}

	//if (height >= BiomeManager::FOREST_LEVEL) {
	//	return BiomeManager::FOREST_COLOR;
	//}

	if (height >= BiomeManager::GRASS2_LEVEL) {
		return BiomeManager::GRASS2_COLOR;
	}

	if (height >= BiomeManager::GRASS1_LEVEL) {
		return BiomeManager::GRASS1_COLOR;
	}

	if (height >= BiomeManager::SAND_LEVEL) {
		return BiomeManager::SAND_COLOR;
	}

	if (height >= BiomeManager::SEA4_LEVEL) {
		return BiomeManager::SEA4_COLOR;
	}

	if (height >= BiomeManager::SEA3_LEVEL) {
		return BiomeManager::SEA3_COLOR;
	}

	if (height >= BiomeManager::SEA2_LEVEL) {
		return BiomeManager::SEA2_COLOR;
	}

	if (height >= BiomeManager::SEA1_LEVEL) {
		return BiomeManager::SEA2_COLOR;
	}

	return BiomeManager::ERROR_COLOR;
}

void BiomeManager::setSeaLevel(float value) {
	assert(value >= 0.0f && value <= 1.0f);

	BiomeManager::SEA1_LEVEL = 0.0f;
	BiomeManager::SEA2_LEVEL = value - 0.1f;
	BiomeManager::SEA3_LEVEL = value - 0.03f;
	BiomeManager::SEA4_LEVEL = value;
	BiomeManager::SAND_LEVEL = value + 0.0008f;
	BiomeManager::GRASS1_LEVEL = value + 0.002f;
	BiomeManager::GRASS2_LEVEL = value + 0.006f;
	BiomeManager::MOUNTAIN2_LEVEL = value + 0.1f;
	BiomeManager::MOUNTAIN1_LEVEL = value + 0.2f;
	BiomeManager::SNOW_LEVEL = value + 0.28f;
}
