#ifndef PERLIN_CLASS_H
#define PERLIN_CLASS_H

#include "Grid.h"

class Perlin {
private:
	int width, height;

	Grid *grid;

	uint8_t getPixelValue(int x, int y);
public:
	Perlin(int window_width, int window_height);
	~Perlin();

	void addNoise(unsigned char *image, float weight, int num_fields_x, int num_fields_y);
	void addNoise(unsigned char *image, float weight, int num_fields);
};

#endif