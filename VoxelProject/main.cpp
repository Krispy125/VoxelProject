#include <GLFW/glfw3.h>
#include <iostream>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_LENGTH = 600;

int main() {

	// glfw Config
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_LENGTH, "VoxelProject", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Initialization Failed" << std::endl;
		glfwTerminate();
		return -1;
		// Creates Initial Window
	}

	glfwMakeContextCurrent(window);
	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
		// Loop for keeping the window open.
	}
	
	glfwTerminate();
	return 0;


}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{


	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) // Input Processing
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	while (!glfwWindowShouldClose(window))
	{
		// Input
		processInput(window); 

		// Rendering Commands

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		

		// Check and Call Events

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
