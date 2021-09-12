#ifndef VertexBuffer_CLASS_H
#define VertexBuffer_CLASS_H

#include <glad/glad.h>
#include "Buffer.h"

class VertexBuffer : public Buffer {
public:
	VertexBuffer(GLfloat *vertices, GLsizeiptr size);
	~VertexBuffer();
};

#endif
