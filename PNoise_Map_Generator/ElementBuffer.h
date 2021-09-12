#ifndef ELEMENT_BUFFER_H
#define ELEMENT_BUFFER_H

#include <glad/glad.h>
#include "Buffer.h"

class ElementBuffer : public Buffer {
public:
	ElementBuffer(GLuint *indices, GLsizeiptr size);
};

#endif

