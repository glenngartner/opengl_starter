//
// Created by glenn on 9/6/2017.
//

#include "gl_helper.h"

GLuint compileShaders(void) {
    GLuint vertex_shader;
    GLuint fragment_shader;
    GLuint program;

    // source code for vertex shader
    static const GLchar *vertexShaderSource[] = {
            "#verion 450 core   \n"
                    ""
                    "void main(void)    \n"
                    "{                  \n"
                    "gl_Position = vec4(0.0, 0.0, 0.5, 1.0);\n"
                    "}                  \n"
    };

    static const GLchar *fragmentShaderSource[] = {
            "#version 450 core  \n"
                    ""
                    "out vec4 color;    \n"
                    "void main(void){   \n"
                    "{                  \n"
                    "   color={0.0, 0.8, 1.0, 1.0);\n"
                    "}\n"
    };

    // create and compile vertex shader
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, vertexShaderSource, NULL);
    glCompileShader(vertex_shader);

    // create and compile fragments shader
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, fragmentShaderSource, NULL);
    glCompileShader(fragment_shader);

    // create a program, attach shaders to it, and link it
    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    // delete the shaders, since the program has them now
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return program;

}
