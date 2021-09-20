#ifndef BIOMEMANAGER_CLASS_H
#define BIOMEMANAGER_CLASS_H

#include "RGB.h"

class BiomeManager {
private:
	static const float SEA1_LEVEL;
	static const float SEA2_LEVEL;
	static const float SEA3_LEVEL;
	static const float SEA4_LEVEL;
	static const float SAND_LEVEL;
	static const float GRASS1_LEVEL;
	static const float GRASS2_LEVEL;
	static const float FOREST_LEVEL;
	static const float MOUNTAIN1_LEVEL;
	static const float MOUNTAIN2_LEVEL;
	static const float SNOW_LEVEL;

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
};

#endif

