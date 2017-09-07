#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "window_helper.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

void inputHandler(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        std::puts("You're pressing ESC");
        glfwSetWindowShouldClose(window, true);
    }
}
