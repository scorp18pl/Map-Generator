#ifndef MAPGEN_CLASS_H
#define MAPGEN_CLASS_H

#include "Perlin.h"
#include "Display.h"

class MapGen {
private:
	int width, height;
	Perlin *perlin;
	Display *display;

	void combineNoise(unsigned char *image);
public:
	MapGen(int width, int height);
	~MapGen();

	void start();
};

#endif

