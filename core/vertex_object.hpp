#ifndef VERTEX_OBJECT_HPP
#define VERTEX_OBJECT_HPP

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.hpp"

class VertexObject
{
public:
	VertexObject();
	~VertexObject();

	void Draw(Shader shader, GLuint VAO);

};

#endif