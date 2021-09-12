#ifndef VERTEX_ARRAY_OBJECT_CLASS_H
#define VERTEX_ARRAY_OBJECT_CLASS_H

#include <glad/glad.h>
#include "VertexBuffer.h"

class VAO {
private:
	GLuint id;
public:
	void linkAttributes(VertexBuffer &VBO, GLuint layout, 
						GLuint numComponents, GLenum type, 
						GLsizeiptr stride, void *offset);
	void bind();
	void unbind();

	VAO();
	~VAO();
};

#endif