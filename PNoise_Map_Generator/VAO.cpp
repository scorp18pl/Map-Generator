#include "VAO.h"

void VAO::linkAttributes(VertexBuffer &VBO, GLuint layout, 
						 GLuint numComponents, GLenum type, 
						 GLsizeiptr stride, void *offset) {
	VBO.bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	VBO.unbind();
}

void VAO::bind() {
	glBindVertexArray(this->id);
}

void VAO::unbind() {
	glBindVertexArray(0);
}

VAO::VAO() {
	glGenVertexArrays(1, &this->id);
}

VAO::~VAO() {
	glDeleteVertexArrays(1, &this->id);
}
