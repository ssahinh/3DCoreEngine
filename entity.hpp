#ifndef ENTITY_HPP
#define ENTITY_HPP

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <string>

#include "shader.hpp"
#include "mesh.hpp"
#include "model.hpp"
#include "camera.hpp"

class Entity
{
public:
	Entity();
	
	bool Keys[1024];

	void Draw(Shader shader, Model model);
	void Input(GLFWwindow *window, GLfloat dt);

	
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	
};

#endif