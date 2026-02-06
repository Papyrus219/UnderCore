#ifndef UNDERCORE_WINDOW_HPP
#define UNDERCORE_WINDOW_HPP

#include <string>
#include <queue>
#include <optional>
#include "../setup.hpp"
#include "./keyboard_key.hpp"
#include "./event.hpp"

namespace undercore
{

class Window
{
public:
    Window();
    Window(std::string title_, unsigned int width_, unsigned int height_);

    void Create(std::string title, unsigned int width, unsigned int height);
    void Close() {glfwSetWindowShouldClose(window, true);};

    void Clear();
    void Display();

    bool Get_is_open() {return !glfwWindowShouldClose(window);};
    std::string Get_title() {return title;};
    unsigned int Get_width() {return width;};
    unsigned int Get_height() {return height;};

    std::optional<Event> Poll_event();

    void Colect_events();
private:
    static void Framebuffer_size_callback(GLFWwindow *window, int width, int height);

    std::queue<Event> events_queue{};

    GLFWwindow* window{};

    std::string title{};
    unsigned int width{};
    unsigned int height{};
};

}

#endif // UNDERCORE_WINDOW_HPP
