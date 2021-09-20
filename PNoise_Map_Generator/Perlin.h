#ifndef PERLIN_CLASS_H
#define PERLIN_CLASS_H

#include "Grid.h"

class Perlin {
private:
	int width, height;

	Grid *grid;

	float getPixelValue(int x, int y);
public:
	Perlin(int window_width, int window_height);
	~Perlin();

	void setSeed(int seed);

	void addNoise(float *image, float weight, int num_fields_x, int num_fields_y);
	void addNoise(float *image, float weight, int num_fields);

	void setNoise(float *image, int num_fields_x, int num_fields_y);
	void setNoise(float *image, int num_fields);
};

#endif