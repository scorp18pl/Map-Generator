#ifndef MAPGEN_CLASS_H
#define MAPGEN_CLASS_H

#include "Perlin.h"
#include "BiomeManager.h"
#include "Display.h"

class MapGen {
private:
	int width, height;
	Perlin *perlin;
	Display *display;

	void convertImage(unsigned char *dir, float *src);
	void combineNoise(unsigned char *image, int iterations);
public:
	MapGen(int width, int height);
	~MapGen();

	void start();
};

#endif

