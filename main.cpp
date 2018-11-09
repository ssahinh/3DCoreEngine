#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "rendering/game.hpp"
#include "rendering/camera.hpp"
#include "core/shader.hpp"
//#include "core/entity.hpp"
//#include "core/model.hpp"
#include "core/vertex_object.hpp"
#include "rendering/window.hpp"
#include "rendering/texture2D.hpp"

#include "maths/vec2.hpp"
#include "maths/vec3.hpp"
#include "maths/vec4.hpp"
#include "maths/mat4.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "audio/audio_manager.hpp"

//#define STB_IMAGE_IMPLEMENTATION
#include "core/stb_image.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void callbacks();

const GLuint SCR_WIDTH = 800;
const GLuint SCR_HEIGHT = 600;
const std::string& title = "OpenGL";

//Entity entity;
Window window(SCR_WIDTH, SCR_HEIGHT);
AudioManager audio_test;
VertexObject buffers;

using namespace math;

int main()
{
	window.Init(SCR_WIDTH, SCR_HEIGHT, "HATRED ENGINE");

	//callbacks();

	glfwSetKeyCallback(window.window, key_callback);

	glEnable(GL_DEPTH_TEST);

	Shader shader("main_vertex.glsl", "main_frag.glsl");
	//Shader lampShader("lamp_vertex.glsl", "lamp_fragment.glsl");
	//Model testModel("assimp_test/untitled.obj");
	//Model testModel("entity_test/nanosuit.obj");

	static float vertices[] =
	{

			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
			 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

	GLuint VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;
	
	unsigned int floorTexture = Texture2D::loadTexture("SpectrumEx.jpg");
	//unsigned int floorTexture = Texture2D::loadTexture("floor.png");
	shader.use();
	shader.SetInteger("texture1", 0);
	
	//audio_test.play2D("breakout.mp3", GL_TRUE);
	
	while (!glfwWindowShouldClose(window.window))
	{
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();

		
		// Input
		//Engine.ProcessInput(deltaTime);
		//entity.Input(window.window, deltaTime);
		// Update
		//Engine.Update(deltaTime);
		// Render
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		buffers.Draw(shader, VAO);

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
/*
void callbacks()
{
	glfwSetFramebufferSizeCallback(window.window, entity.framebuffer_size_callback);
	glfwSetKeyCallback(window.window, key_callback);
	glfwSetCursorPosCallback(window.window, entity.mouse_callback);
	glfwSetScrollCallback(window.window, entity.scroll_callback);
}
*/