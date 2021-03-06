#include "Grid.h"
#include <random>
#include <iostream>

#define CORNER_VEC_COUNT 4

//Calculates a vector for a given angle.
//Angle is represented as a fraction of 2 PI.
glm::vec2 Grid::getVector(float angle_frac) {
	float angle_rad = 2 * (float)std::_Pi * angle_frac;
	
	return glm::vec2(std::cos(angle_rad), std::sin(angle_rad));
}

//Function takes in a point from
//a [0;1]^2 plane and scales it onto
//the grid plane
glm::vec2 Grid::scaleCoordinates(glm::vec2 position) {
	int cell_count_x, cell_count_y;
	cell_count_x = this->width - 1;
	cell_count_y = this->height - 1;

	//Translate the coordinates
	float x_t, y_t;
	x_t = position.x * (float)cell_count_x;
	y_t = position.y * (float)cell_count_y;

	return glm::vec2(x_t, y_t);
}

//Returns corner vectors for a given position vector.
//WARNING : Returned vector array memory has to be freed!
glm::vec2 *Grid::getCornerVectors(glm::vec2 position) {
	glm::vec2 *vectors = new glm::vec2[CORNER_VEC_COUNT];

	if (vectors == nullptr) {
		std::cout << "Failed to allocate corner vector memory" << std::endl;
		exit(1);
	}

	int floor_x, floor_y, ceil_x, ceil_y;
	floor_x = (int)floorf(position.x);
	floor_y = (int)floorf(position.y);

	ceil_x = floor_x + 1LU;
	ceil_y = floor_y + 1LU;

	vectors[0] = getVectorAt(floor_x, floor_y); //Left - Upper corner
	vectors[1] = getVectorAt(ceil_x, floor_y); //Right - Upper corner
	vectors[2] = getVectorAt(ceil_x, ceil_y); //Right - Lower corner
	vectors[3] = getVectorAt(floor_x, ceil_y); //Left - Lower corner

	return vectors;
}

//Returns offset vectors calculated for a given position.
//Position is relative to it's top - left corner vector position.
//WARNING : Returned vector array memory has to be freed!
glm::vec2 *Grid::getOffsetVectors(glm::vec2 position) {
	glm::vec2 *vectors = new glm::vec2[CORNER_VEC_COUNT];

	if (vectors == nullptr) {
		std::cout << "Failed to allocate offset vector memory" << std::endl;
		exit(1);
	}

	vectors[0] = -position;
	vectors[1] = glm::vec2(1.0f - position.x, -position.y);
	vectors[2] = glm::vec2(1.0f - position.x, 1.0f - position.y);
	vectors[3] = glm::vec2(-position.x, 1.0f - position.y);

	return vectors;
}

float Grid::fade(float x) {
	return x * x * x * (10 + x * (-15 + x * 6));
}

float Grid::fade2(float x, float y) {
	return fade(x) * fade(y);
}

//Constructs a grid object. Sets all
//vector values to <0.0f, 0.0f>.
Grid::Grid(int width, int height) 
	:width(width), height(height) {
	size_t size = (size_t)width * (size_t)height;
	this->vectors = new glm::vec2[size];

#ifdef GRID_ZERO_VEC
	for (size_t i = 0; i < size; i++) {
		this->vectors[i] = glm::vec2(0.0f);
	}
#endif

	randomize();
}

Grid::Grid(int side) 
	:Grid(side, side) {
}

Grid::~Grid() {
	delete[] this->vectors;
}

void Grid::randomize() {
	if (!this->has_seed) {
		std::random_device device;
		setSeed(device());
	}

	std::mt19937 gen(this->seed);
	std::uniform_real_distribution<> dist(0.0f, 1.0f);

	for (int i = 0; i < getSize(); i++) {
		float angle = (float)dist(gen);
		this->vectors[i] = Grid::getVector(angle);
	}
}

void Grid::setSeed(int seed) {
	this->has_seed = true;
	this->seed = seed;
}

void Grid::resize(int num_fields_x, int num_fields_y) {
	delete[] vectors;

	this->width = num_fields_x;
	this->height = num_fields_x;
	this->vectors = new glm::vec2[getSize()];

#ifdef GRID_ZERO_VEC
	for (int i = 0; i < getSize(); i++) {
		this->vectors[i] = glm::vec2(0.0f);
	}
#endif

	randomize();
}

void Grid::print() {
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			glm::vec2 vec = getVectorAt(j, i);
			std::cout << vec.x << " " << vec.y << " " << vec.x * vec.x + vec.y * vec.y << std::endl;
		}
	}
}

//Returns the perlin noise value (between 0 and 1) for
//a given point on [0,1] x [0,1] plane.
float Grid::getValue(glm::vec2 position) {
	glm::vec2 position_s = scaleCoordinates(position);
	glm::vec2 *corner_vectors = getCornerVectors(position_s);

	glm::vec2 position_r = position_s - glm::vec2(floorf(position_s.x), floorf(position_s.y));
	glm::vec2 *offset_vectors = getOffsetVectors(position_r);
	
	float dot_products[4] = {};
	for (int i = 0; i < CORNER_VEC_COUNT; i++) {
		dot_products[i] = glm::dot(corner_vectors[i], offset_vectors[i]);
	}

	delete[] corner_vectors;
	delete[] offset_vectors;

	float fade_values[] = {
		fade2(1.0f - position_r.x, 1.0f - position_r.y),
		fade2(position_r.x, 1.0f - position_r.y),
		fade2(position_r.x, position_r.y),
		fade2(1.0f - position_r.x, position_r.y)
	};

	float value = 0.0f;
	for (int i = 0; i < CORNER_VEC_COUNT; i++) {
		value += fade_values[i] * dot_products[i];
	}

	value += 1.0f;
	value /= 2.0f;

	value = value > 1.0f ? 1.0f : value;
	value = value < 0.0f ? 0.0f : value;

	return value;
}

size_t Grid::getSize() {
	return (size_t)this->width * (size_t)this->height;
}

glm::vec2 Grid::getVectorAt(int x, int y) {
	return this->vectors[y * this->width + x];
}
