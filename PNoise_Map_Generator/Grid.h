#ifndef GRID_CLASS_H
#define GRID_CLASS_H

#include <glm/glm.hpp>

class Grid {
private:
	bool has_seed = false;
	int seed;
	int width, height;
	glm::vec2 **vectors;

	static glm::vec2 getVector(float angle_frac);
	glm::vec2 scaleCoordinates(glm::vec2 position);
	glm::vec2 *getCornerVectors(glm::vec2 position);
	glm::vec2 *getOffsetVectors(glm::vec2 position);
	float fade(float x);
	float fade2(float x, float y);
	void randomize();
public:
	Grid(int width, int height);
	Grid(int side);

	float getValue(glm::vec2 position);
	glm::vec2 getVectorAt(int x, int y);

	void resize(int num_fields_x, int num_fields_y);
	void setSeed(int seed);
	void print();
};

#endif