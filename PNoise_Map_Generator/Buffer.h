#ifndef BUFFER_CLASS_H
#define BUFFER_CLASS_H

#include <glad/glad.h>

class Buffer {
protected:
	GLuint id;
	GLenum type;

public:
	void bind();
	void unbind();

	Buffer(GLenum type);
	~Buffer();
};

#endif