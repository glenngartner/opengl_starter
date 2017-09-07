//
// Created by glenn on 9/6/2017.
//

#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "window_helper.h"
#include "gl_helper.h"

int main() {

    // window system initialization
    GLFWwindow *window;
    static const GLfloat clearColor[] = {1.0f, 0.0f, 0.0f, 1.0f};
    GLuint render_program;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

    window = glfwCreateWindow(800, 600, "Hello GLFW", nullptr, nullptr);

    if (window == nullptr) {
        std::cout << "Failed to create openGL window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // app startup

    // create the vao
    render_program = compileShaders();
    GLuint vao;
    std::cout << "GL Version: " << glGetString(GL_VERSION) << std::endl;
    glCreateVertexArrays(1, &vao);
    glBindVertexArray(vao);


    // render loop
    while (!glfwWindowShouldClose(window)) {

        inputHandler(window);

        glClearBufferfv(GL_COLOR, 0, clearColor);
        glUseProgram(render_program);
        glDrawArrays(GL_POINTS, 0, 1);
        glPointSize(40.0f);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;

}