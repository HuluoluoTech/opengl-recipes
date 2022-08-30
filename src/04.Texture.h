#pragma once

#include <glad/glad.h>
#include "shader.h"

class _04Texture
{
public:
    void LoadShader();
    void GenBuffer();
    void Display();
    void Clear();
    void LoadTexture();

private:
    GLuint VAO{0};
    GLuint VBO{0};
    GLuint EBO{0};
    GLuint texture{0};
    Shader *_shader{nullptr};
    GLuint ShaderProgram{0};
};