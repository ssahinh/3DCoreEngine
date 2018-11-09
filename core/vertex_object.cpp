#include "vertex_object.hpp"
#include "shader.hpp"



VertexObject::VertexObject()
{
}

VertexObject::~VertexObject()
{
}


void VertexObject::Draw(Shader shader, GLuint VAO)
{
	shader.use();

	glm::mat4 model			= glm::mat4(1.0f);
	glm::mat4 view			= glm::mat4(1.0f);
	glm::mat4 projection	= glm::mat4(1.0f);

	model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 1000.0f);

	shader.SetMatrix4("model", model);
	shader.SetMatrix4("view", view);
	shader.SetMatrix4("projection", projection);


	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}
