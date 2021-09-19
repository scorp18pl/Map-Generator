#include "Buffer.h"

Buffer::Buffer(GLenum type) 
	:type(type) {
	glGenBuffers(1, &this->id);
}

// Binds the buffer to it's binding point
void Buffer::bind() {
	glBindBuffer(this->type, this->id);
}

// Unbinds the buffer
void Buffer::unbind() {
	glBindBuffer(this->type, 0);
}

Buffer::~Buffer() {
	glDeleteBuffers(1, &this->id);
}
