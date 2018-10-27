#include "entity.hpp"
#include "camera.hpp"

Camera* test_camera;
static bool firstMouse = true;
static GLfloat lastX = 400;
static GLfloat lastY = 300;

Entity::Entity()
{
	test_camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));
}

void Entity::Draw(Shader shader, Model g_model)
{
	// shaderý usela amk þunu yapmadan önce
	shader.use();
	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), (GLfloat)800 / (GLfloat)600, 0.1f, 100.0f);
	shader.SetMatrix4("projection", projection);
	view = test_camera->GetViewMatrix();
	shader.SetMatrix4("view", view);
	model = glm::translate(model, glm::vec3(0.0f, -1.75f, -1.0f));
	model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
	shader.SetMatrix4("model", model);
	g_model.Draw(shader);
}

void Entity::Reset(glm::mat4 m_Name)
{
	m_Name = glm::mat4(1.0f);
}

void Entity::IncreaseXaxis(glm::mat4 model, GLfloat x, GLfloat y, GLfloat z)
{
	model = glm::translate(model, glm::vec3(x, y, z));
}

void Entity::Rotate(glm::mat4 model, GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
	model = glm::rotate(model, glm::radians(angle), glm::vec3(x, y, z));
}

void Entity::Input(GLFWwindow* window, GLfloat dt)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		test_camera->ProcessKeyboard(FORWARD, dt);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		test_camera->ProcessKeyboard(BACKWARD, dt);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		test_camera->ProcessKeyboard(LEFT, dt);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		test_camera->ProcessKeyboard(RIGHT, dt);
}

void Entity::mouse_callback(GLFWwindow* window, double xPos, double yPos)
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

	test_camera->ProcessMouseMovement(xoffset, yoffset);
}

void Entity::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	test_camera->ProcessMouseScroll(yoffset);
}

void Entity::framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}
