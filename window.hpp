#ifndef WINDOW_HPP
#define WINDOW_HPP

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

class Window
{
public:
	Window();
	Window(GLuint width, GLuint height);
	~Window();

	void Init(GLuint Width, GLuint Height, const std::string& title);
	GLFWwindow* window;

private:
	GLuint width, height;
};

#endif