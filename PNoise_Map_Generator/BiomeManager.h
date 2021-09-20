#ifndef BIOMEMANAGER_CLASS_H
#define BIOMEMANAGER_CLASS_H

#include "RGB.h"

class BiomeManager {
private:
	static float SEA1_LEVEL;
	static float SEA2_LEVEL;
	static float SEA3_LEVEL;
	static float SEA4_LEVEL;
	static float SAND_LEVEL;
	static float GRASS1_LEVEL;
	static float GRASS2_LEVEL;
	static float FOREST_LEVEL;
	static float MOUNTAIN1_LEVEL;
	static float MOUNTAIN2_LEVEL;
	static float SNOW_LEVEL;

	static const RGB ERROR_COLOR;
	static const RGB SEA1_COLOR;
	static const RGB SEA2_COLOR;
	static const RGB SEA3_COLOR;
	static const RGB SEA4_COLOR;
	static const RGB SAND_COLOR;
	static const RGB GRASS1_COLOR;
	static const RGB GRASS2_COLOR;
	static const RGB FOREST_COLOR;
	static const RGB MOUNTAIN1_COLOR;
	static const RGB MOUNTAIN2_COLOR;
	static const RGB SNOW_COLOR;

	BiomeManager();
public:
	static RGB getColor(float height);
	static void setSeaLevel(float value);
};

#endif

