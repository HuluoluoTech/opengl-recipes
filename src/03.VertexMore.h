#pragma once

#include <glad/glad.h>
#include "shader.h"

class _03VertexMore
{
public:
    void LoadShader();
    void GenBuffer();
    void Display();
    void Clear();

private:
    GLuint VAO{0};
    GLuint VBO{0};
    Shader *_shader{nullptr};
    GLuint ShaderProgram{0};
};