#include "entity.hpp"
#include "camera.hpp"

Camera* camera;
static bool firstMouse = true;
static GLfloat lastX = 400;
static GLfloat lastY = 300;

Entity::Entity()
{
	camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));
}

Entity::Entity(Model model, glm::vec3 position, GLfloat rotX, GLfloat rotY, GLfloat rotZ)
	:model(model), position(position), rotX(rotX), rotY(rotY), rotZ(rotZ)
{
}

void Entity::Draw(Shader shader, Model g_model)
{
	// shaderý usela amk þunu yapmadan önce
	shader.use();
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = camera->GetViewMatrix();
	projection = glm::perspective(glm::radians(45.0f), static_cast<GLfloat>(800) / static_cast<GLfloat>(600), 0.1f, 100.0f);

	shader.SetMatrix4("view", view);
	shader.SetMatrix4("projection", projection);

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(0.0f, -1.75f, -1.0f));
	model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
	shader.SetMatrix4("model", model);
	g_model.Draw(shader);
	
}

void Entity::Input(GLFWwindow * window, GLfloat dt)
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

	camera->ProcessMouseMovement(xoffset, yoffset);
}

void Entity::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera->ProcessMouseScroll(yoffset);
}

void Entity::framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}
