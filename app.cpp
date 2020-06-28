#include "app.h"

#include <iostream>

Application::Application(GLFWwindow *win) {
	w = win;
}

Application::~Application() {
	
}

float tv[] = {
	0.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	1.0f, 0.0f
};
unsigned int ti[] = {
	0, 1, 3,
	1, 2, 3
};

void Application::run() {
	Shader sh("shaders/gui.vert", "shaders/gui.frag");
	while (!glfwWindowShouldClose(w)) {
		glfwPollEvents();
		glClearColor(0.54902f, 0.886275f, 1, 1); // super color!
		glClear(GL_COLOR_BUFFER_BIT);
		SmartVAO v(tv, ti, 6, {VertAttrPtr(2,2,0)});
		sh.use();
		v.bind();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		std::cout << "drawn" << std::endl;
		glfwSwapBuffers(w);
		unsigned int err = glGetError();
		if (err)
			std::cout << err << std::endl;
	}
}
