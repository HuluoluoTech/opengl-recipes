#pragma once

#include <glad/glad.h>

class _02Uniform
{
public:
    void LoadShader();
    void GenBuffer();
    void Display();

private:
    GLuint VAO{0};
    GLuint VBO{0};
    GLuint EBO{0};
    GLuint ShaderProgram{0};
};