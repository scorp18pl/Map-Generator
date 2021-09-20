#ifndef BIOMEMANAGER_CLASS_H
#define BIOMEMANAGER_CLASS_H

#include "RGB.h"

class BiomeManager {
private:
	static const float SEA1_LEVEL;
	static const float SEA2_LEVEL;
	static const float SAND_LEVEL;
	static const float GRASS_LEVEL;
	static const float MOUNTAIN_LEVEL;

	static const RGB ERROR_COLOR;
	static const RGB SEA1_COLOR;
	static const RGB SEA2_COLOR;
	static const RGB SAND_COLOR;
	static const RGB GRASS_COLOR;
	static const RGB MOUNTAIN_COLOR;

	BiomeManager();
public:
	static RGB getColor(float height);
};

#endif

