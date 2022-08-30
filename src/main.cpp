/*******************************************************************
** This code is part of OpenGL-Template.
**
** OpenGL-Template is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#include <glad/glad.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <iostream>

#include "utils.h"
#include "00.triangle.h"
#include "01.rectangle.h"
#include "02.Uniform.h"

// GLFW function declarations
void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

// The Width of the screen
const unsigned int SCREEN_WIDTH = 800;
// The height of the screen
const unsigned int SCREEN_HEIGHT = 600;

/********************************
 * 
 * recipes ins
 * 
 * *****************************/
// _00Triangle _00Triangle_Ins;
// _01Rectangle _01Rectangle_Ins;
_02Uniform _02Uniform_Ins;

int main(int argc, char *argv[])
{
    // initializes the GLFW library
    glfwInit();

    // Sets the specified window hint to the desired value.
    // sets hints for the next call to glfwCreateWindow. 
    // The hints, once set, retain their values until changed by a call to this function or glfwDefaultWindowHints, or until the library is terminated.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, false);

    // creates a window and its associated OpenGL
    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "OpenGL-Template", nullptr, nullptr);

    // makes the OpenGL or OpenGL ES context of the specified window current on the calling thread.
    // A context must only be made current on a single thread at a time and each thread can have only a single current context at a time.
    glfwMakeContextCurrent(window);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) // (glfwGetProcAddress) Returns the address of the specified function for the current context. 
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    Utils::Print();

    // Step 1:
    {
        // _00Triangle_Ins.LoadShader();
        // _00Triangle_Ins.GenBuffer();

        _02Uniform_Ins.LoadShader();
        _02Uniform_Ins.GenBuffer();
    }

    // sets the key callback of the specified window, which is called when a key is pressed, repeated or released.
    // callback signature:
    // void function_name(GLFWwindow* window, int key, int scancode, int action, int mods)
    glfwSetKeyCallback(window, KeyCallback);

    // sets the framebuffer resize callback of the specified window, which is called when the framebuffer of the specified window is resized.
    // Callback signature:
    // void function_name(GLFWwindow* window, int width, int height)
    glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

    // OpenGL configuration
    // --------------------
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    // enable or disable server-side GL capabilities, includings:
    // GL_ALPHA_TEST / GL_BLEND / GL_DEPTH_TEST / GL_CULL_FACE / etc...
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Use Wireframe mode
    // default is GL_FILL
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // deltaTime variables
    // -------------------
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    // This function returns the value of the close flag of the specified window.
    // 
    while (!glfwWindowShouldClose(window))
    {
        // calculate delta time
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // processes only those events that are already in the event queue and then returns immediately.
        glfwPollEvents();

        // render Here
        // ------
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // specify clear values for the color buffers
        glClear(GL_COLOR_BUFFER_BIT); // clear buffers to preset values, glClear sets the bitplane area of the window to values previously selected by glClearColor, glClearDepth, and glClearStencil. 
        
        // Step 2: Rendering
        {
            // _00Triangle_Ins.Display();
            _02Uniform_Ins.Display();
        }

        // Swaps the front and back buffers of the specified window. 
        /***********************************************************************************
         * 
         * Buffer swapping:
         * 1/ GLFW windows are by default double buffered.
         * 2/ That means that you have two rendering buffers; a front buffer and a back buffer. 
         * 3/ The front buffer is the one being displayed and the back buffer the one you render to.
         * 4/ When the entire frame has been rendered, it is time to swap the back and the front buffers in order to display what has been rendered and begin rendering a new frame. 
         * 5/ about glfwSwapInterval(1);
         * 
         * ********************************************************************************/
        glfwSwapBuffers(window);
    }

    // delete all resources as loaded using the resource manager
    // when the game loop is shutdown...
    // ResourceManager::Clear();

    // https://www.glfw.org/docs/3.3/quick.html#quick_init_term
    // When a window and context is no longer needed, destroy it.
    glfwDestroyWindow(window);

    std::cout << "Ready to Exit..." << std::endl;

    // Terminates the GLFW library. 
    // This function destroys all remaining windows and cursors, restores any modified gamma ramps and frees any other allocated resources. 
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

/**
 * @brief 
 * 
 * @param window 
 * @param key 
 * @param scancode 
 * @param action GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT.
 * @param mode 
 */
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    std::cout << "Key callback...key : " << key << std::endl;
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) 
    {
        glfwSetWindowShouldClose(window, true);
    }
}

/**
 * @brief 
 * 
 * @param window 
 * @param width 
 * @param height 
 */
void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    // glad_glViewport
    glViewport(0, 0, width, height);
}