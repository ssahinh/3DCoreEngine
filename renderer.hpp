#ifndef RENDERER_HPP
#define RENDERER_HPP

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.hpp"
#include "camera.hpp"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void Init();
	void Input(GLFWwindow* window, GLfloat dt);
	glm::mat4 GetViewMatrix();

	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

};

#endif