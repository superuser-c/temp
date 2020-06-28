#pragma once
#ifndef JT_APP_H
#define JT_APP_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Application {
public:
	Application(GLFWwindow *win);
	~Application();
	void run();
private:
	GLFWwindow *w;
};
#endif
