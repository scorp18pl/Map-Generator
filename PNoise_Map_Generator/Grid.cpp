#include "Grid.h"
#include <random>
#include <iostream>


//Calculates a vector for a given angle.
//Angle is represented as a fraction of 2 PI.
glm::vec2 Grid::getVector(float angle_frac) {
	float angle_rad = 2 * std::_Pi * angle_frac;
	return glm::vec2(std::cos(angle_rad), std::sin(2 * std::_Pi * angle_rad));
}

//Constructs a grid object. Sets all
//vector values to <0.0f, 0.0f>.
Grid::Grid(size_t width, size_t height) 
	:width(width), height(height) {
	this->vectors = new glm::vec2 *[height];

	for (size_t i = 0; i < height; i++) {
		this->vectors[i] = new glm::vec2[width];
		for (size_t j = 0; j < width; j++) {
			this->vectors[i][j] = glm::vec2(0.0f, 0.0f);
		}
	}
}

Grid::Grid(size_t side) 
	:Grid(side, side) {
}

void Grid::randomize() {
	std::random_device device;
	std::mt19937 gen(device());
	std::uniform_real_distribution<> dist(0.0f, 1.0f);
	
	for (size_t i = 0; i < this->height; i++) {
		for (size_t j = 0; j < this->width; j++) {
			float angle = dist(gen);
			this->vectors[i][j] = Grid::getVector(angle);
		}
	}

}

void Grid::print() {
	for (size_t i = 0; i < this->height; i++) {
		for (size_t j = 0; j < this->width; j++) {
			glm::vec2 vec = this->vectors[i][j];
			std::cout << vec.x << " " << vec.y << std::endl;
		}
	}
}

glm::vec2 Grid::getVector(size_t x, size_t y) {
	return this->vectors[y][x];
}
