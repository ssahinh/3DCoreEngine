#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "game.hpp"
#include "camera.hpp"
#include "shader.hpp"
#include "entity.hpp"
#include "model.hpp"
#include "window.hpp"
#include "texture2D.hpp"

#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"
#include "mat4.hpp"

//#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void callbacks();

const GLuint SCR_WIDTH = 800;
const GLuint SCR_HEIGHT = 600;
const std::string& title = "OpenGL";

Entity entity;
Window window(SCR_WIDTH, SCR_HEIGHT);

using namespace math;

int main()
{

	Mat4 position = Mat4::translation(Vec3<GLfloat>(2.0f, 3.0f, 4.0f));

	window.Init(SCR_WIDTH, SCR_HEIGHT, "hatred");

	callbacks();
	Shader shader("main_vertex.glsl", "main_frag.glsl");
	static Model testModel("assimp_test/untitled.obj");
	
	//Engine.Init();
	
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;
	
	//unsigned int floorTexture = loadTexture("floor.png");
	unsigned int floorTexture = Texture2D::loadTexture("floor.png");
	shader.use();
	shader.SetInteger("texture1", 0);

	while (!glfwWindowShouldClose(window.window))
	{
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();

		// Input
		//Engine.ProcessInput(deltaTime);
		entity.Input(window.window, deltaTime);
		// Update
		//Engine.Update(deltaTime);
		// Render
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		entity.Draw(shader, testModel);
		//Engine.Render();
		
		glfwSwapBuffers(window.window);
	}

	glfwTerminate();
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// When a user presses the escape key, we set the WindowShouldClose property to true, closing the application
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	
}

void callbacks()
{
	glfwSetFramebufferSizeCallback(window.window, entity.framebuffer_size_callback);
	glfwSetKeyCallback(window.window, key_callback);
	glfwSetCursorPosCallback(window.window, entity.mouse_callback);
	glfwSetScrollCallback(window.window, entity.scroll_callback);
}