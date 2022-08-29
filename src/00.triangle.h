#pragma once

#include <glad/glad.h>

class _00Triangle
{
public:
    void LoadShader();
    void GenBuffer();
    void Display();

private:
    GLuint VAO{0};
    GLuint VBO{0};
    GLuint ShaderProgram{0};
};