#include <glad/glad.h>

#include "utils.h"
#include <iostream>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <cmath>

void Utils::GetMaxVertexAttribs()
{
    int nrAttributes = GL_MAX_VERTEX_ATTRIBS;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
}

void Utils::glfwGetTimes()
{
    float timeValue = glfwGetTime();
    float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
    std::cout << "GreenValue: " << greenValue << std::endl;
}   

void Utils::Print()
{
    Utils::GetMaxVertexAttribs();
    Utils::glfwGetTimes();
}