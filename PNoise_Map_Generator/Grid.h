#ifndef GRID_CLASS_H
#define GRID_CLASS_H

#include <glm/glm.hpp>

class Grid {
private:
	size_t width, height;
	glm::vec2 **vectors;

	static glm::vec2 getVector(float angle_frac);
public:
	Grid(size_t width, size_t height);
	Grid(size_t side);

	glm::vec2 getVector(size_t x, size_t y);
	void randomize();

	void print();
};

#endif