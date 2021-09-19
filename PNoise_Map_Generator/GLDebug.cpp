#include "GLDebug.h"

#include <GLFW/glfw3.h>
#include <iostream>

void GLclearError() {
	while (glGetError() != GL_NO_ERROR);
}

bool GLlogCall(const char *function, const char *file, int line) {
	bool value = true;
	GLenum error = glGetError();
	while (error != GL_NO_ERROR) {
		value = false;
		std::cout << "[OpenGL Error] (" << error << "): " << function 
			<< " " << file << " " << line << std::endl;
		error = glGetError();
	}
	return value;
}