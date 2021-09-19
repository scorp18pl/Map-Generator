#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include <glad/glad.h>
#include <stb_image/stb_image.h>

#include "Shader.h"

class Texture {
private:
	GLuint id;
	GLenum type;
	GLuint unit;

public:
	Texture(unsigned char *bytes, int widthImg, int heightImg,
			int numColCh, GLenum texType, GLuint slot, GLenum format,
			GLenum pixelType);

	Texture(const char *image, GLenum texType, GLuint slot, 
			GLenum format, GLenum pixelType);
	~Texture();

	// Assigns a texture unit to a texture
	void texUnit(Shader *shader, const char *uniform, GLuint unit);
	void bind();
	void unbind();
};

#endif
