#include "ElementBuffer.h"

ElementBuffer::ElementBuffer(GLuint *indices, GLsizeiptr size) 
	:Buffer(GL_ELEMENT_ARRAY_BUFFER) {
	bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}
