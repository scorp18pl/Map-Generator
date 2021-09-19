#include "Texture.h"

Texture::Texture(unsigned char *bytes, int widthImg, int heightImg, 
				 int numColCh, GLenum texType, GLuint slot, GLenum format, 
				 GLenum pixelType) {
	this->type = texType;

	//Generate an OpenGL texture object and assign an id to it
	glGenTextures(1, &this->id);
	// Assigns the texture to a Texture Unit
	glActiveTexture(GL_TEXTURE0 + slot);
	this->unit = slot;
	glBindTexture(texType, this->id);

	//Set the min and mag filters to nearest
	glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//Set the texture wrap on both axes to repeat
	glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Assigns the image to the OpenGL Texture object
	glTexImage2D(texType, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, bytes); \
	// Generates MipMaps
	glGenerateMipmap(texType);

	// Unbinds the OpenGL Texture object so that it can't accidentally be modified
	glBindTexture(texType, 0);
}

Texture::Texture(const char *image, GLenum texType, GLuint slot, GLenum format, GLenum pixelType) {
	this->type = texType;
	// Stores the width, height, and the number of color channels of the image
	int widthImg, heightImg, numColCh;
	stbi_set_flip_vertically_on_load(true);
	unsigned char *bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

	//Generate an OpenGL texture object and assign an id to it
	glGenTextures(1, &this->id);
	// Assigns the texture to a Texture Unit
	glActiveTexture(GL_TEXTURE0 + slot);
	this->unit = slot;
	glBindTexture(texType, this->id);

	//Set the min and mag filters to nearest
	glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//Set the texture wrap on both axes to repeat
	glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Assigns the image to the OpenGL Texture object
	glTexImage2D(texType, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, bytes); \
		// Generates MipMaps
		glGenerateMipmap(texType);

	// Deletes the image data as it is already in the OpenGL Texture object
	stbi_image_free(bytes);

	// Unbinds the OpenGL Texture object so that it can't accidentally be modified
	glBindTexture(texType, 0);
}

Texture::~Texture() {
	glDeleteTextures(1, &this->id);
}

void Texture::texUnit(Shader *shader, const char *uniform, GLuint unit) {
	// Gets the location of the uniform
	GLuint texUni = glGetUniformLocation(shader->getId(), uniform);
	// Shader needs to be activated before changing the value of a uniform
	shader->activate();
	// Sets the value of the uniform
	glUniform1i(texUni, GL_TEXTURE0 + unit);
}

void Texture::bind() {
	glActiveTexture(GL_TEXTURE0 + this->unit);
	glBindTexture(this->type, this->id);
}

void Texture::unbind() {
	glBindTexture(this->type, 0);
}
