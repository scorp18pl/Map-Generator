#ifndef GRID_CLASS_H
#define GRID_CLASS_H

#include <glm/glm.hpp>

class Grid {
private:
	size_t width, height;
	glm::vec2 **vectors;

	static glm::vec2 getVector(float angle_frac);
	glm::vec2 scaleCoordinates(glm::vec2 position);
	glm::vec2 *getCornerVectors(glm::vec2 position);
	glm::vec2 *getOffsetVectors(glm::vec2 position);
	float fade(float x);
	float fade2(float x, float y);
public:
	Grid(size_t width, size_t height);
	Grid(size_t side);

	float getValue(glm::vec2 position);
	glm::vec2 getVectorAt(size_t x, size_t y);
	void randomize();

	void print();
};

#endif