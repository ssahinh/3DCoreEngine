#ifndef TEXTURE2D_HPP
#define TEXTURE2D_HPP

#define GLEW_STATIC
#include <GL/glew.h>

#include "../core/model.hpp"
#include "../core/stb_image.h"

class Texture2D
{
public:
	Texture2D();
	~Texture2D();

	static unsigned int loadTexture(const char* path);
};

#endif