#ifndef MAPGEN_CLASS_H
#define MAPGEN_CLASS_H

#include "Perlin.h"
#include "BiomeManager.h"
#include "Display.h"

class MapGen {
private:
	bool should_display;
	int width, height;

	bool has_seed = false;
	int seed = 0, octaves = 8;
	float persistance;
		
	Perlin *perlin;
	Display *display;

	void convertImage(unsigned char *dir, float *src);
	void combineNoise(unsigned char *image);
public:
	MapGen(int width, int height, float persistance = 0.5f, bool should_display = true);
	~MapGen();

	void start();
	void setSeed(int value);
	void setSeaLevel(float value);
	void setShouldDisplay(bool value);
	void setOctavesNumber(int value);
	void exportImage(unsigned char *image);
};

#endif

