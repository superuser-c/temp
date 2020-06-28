#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "json/json.hpp"

#include "app.h"

void on_framebuffer_size(GLFWwindow* w, int width, int height) {
	glViewport(0, 0, width, height);
}

int main() {
	enum { WINDOW_START_WIDTH=800, WINDOW_START_HEIGHT=600 };
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow *w = glfwCreateWindow(WINDOW_START_WIDTH, WINDOW_START_HEIGHT,
		"Just That 1.0 alpha", NULL, NULL);
	if (w == NULL) {
		glfwTerminate();
		std::cout << "ERROR: Window creation failed." << std::endl;
		std::cin.get();
		return -1;
	}
	glfwMakeContextCurrent(w);
	glfwSetFramebufferSizeCallback(w, on_framebuffer_size);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		glfwTerminate();
		std::cout << "ERROR: GLAD library initialization failed." << std::endl;
		std::cin.get();
		return -1;
	}
	Application app(w);
	app.run();
	glfwTerminate();
	return 0;
}
