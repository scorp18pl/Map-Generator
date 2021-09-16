#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <glad/glad.h>

class Shader {
private:
	GLuint id;

	void compileErrors(unsigned int shader, const char *type);
public:
	Shader(const char *vertexFile, const char *fragmentFile);
	~Shader();

	void activate();
};

#endif
