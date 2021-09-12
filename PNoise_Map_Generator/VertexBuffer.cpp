#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(GLfloat *vertices, GLsizeiptr size)
	:Buffer(GL_ARRAY_BUFFER) {
	bind();
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() {
}
