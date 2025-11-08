#include <GLFW/glfw3.h>
#include <iostream>

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "VoxelProject", NULL, NULL);
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

void processInput(GLFWwindow* window) // Input Processing and Close Button
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
