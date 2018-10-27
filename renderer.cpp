#include "renderer.hpp"

static Camera* camera;
static bool firstMouse = true;
static GLfloat lastX = 400;
static GLfloat lastY = 300;

Renderer::Renderer()
{
	camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));
}

void Renderer::Init()
{

}

glm::mat4 Renderer::GetViewMatrix()
{
	return camera->GetViewMatrix();
}

void Renderer::Input(GLFWwindow * window, GLfloat dt)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera->ProcessKeyboard(FORWARD, dt);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera->ProcessKeyboard(BACKWARD, dt);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera->ProcessKeyboard(LEFT, dt);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera->ProcessKeyboard(RIGHT, dt);
}

void Renderer::mouse_callback(GLFWwindow* window, double xPos, double yPos)
{
	if (firstMouse)
	{
		lastX = xPos;
		lastY = yPos;
		firstMouse = false;
	}

	float xoffset = xPos - lastX;
	float yoffset = lastY - yPos;
	lastX = xPos;
	lastY = yPos;

	camera->ProcessMouseMovement(xoffset, yoffset);
}

void Renderer::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera->ProcessMouseScroll(yoffset);
}

void Renderer::framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}


Renderer::~Renderer()
{
}