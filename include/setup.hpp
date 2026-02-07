#ifndef UNDERCORE_SETUP_HPP
#define UNDERCORE_SETUP_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace undercore
{

///@brief Struct existing to setup and clean glfw.
struct Setup
{
    Setup()
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    ~Setup()
    {
        glfwTerminate();
    }
};

///@brief This object exist to call setup constructor and destructor (At program beginning and end respectively).
extern Setup setup;

}

#endif //UNDERCORE_SETUP_HPP
