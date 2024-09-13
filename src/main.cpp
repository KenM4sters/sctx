#include <iostream>
#include <GLFW/glfw3.h>

int main(int argc, char** argv) {

    glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "", nullptr, nullptr);

    glfwSetWindowCloseCallback(window, [](GLFWwindow* window) {
        glfwSetWindowShouldClose(window, true);
    });

    glfwMakeContextCurrent(window);

    while(!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    return 0;
}