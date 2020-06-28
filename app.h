#pragma once
#ifndef JT_APP_H
#define JT_APP_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "loader/loader.h"

class Application {
public:
	Application(GLFWwindow *win, PackSet *pckst);
	~Application();
	void run();
private:
	GLFWwindow *w;
	PackSet *ps;
};
#endif
