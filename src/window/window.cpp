#include "../../include/window/window.hpp"
#include <stdexcept>

using namespace undercore;

undercore::Window::Window()
{
    window = glfwCreateWindow(width, height, title.c_str(), 0, 0);
    if(!window)
    {
        throw std::runtime_error{"Failed to create window."};
    }
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress ))
    {
        std::cerr << "Failed to initialize glad.\n";
        std::exit(EXIT_FAILURE);
    }

    glViewport(0,0,width,height);
    glfwSetFramebufferSizeCallback(window, Framebuffer_size_callback);

    glEnable(GL_DEPTH_TEST);
}

undercore::Window::Window(std::string title_, unsigned int width_, unsigned int height_): title{title_}, width{width_}, height{height_}
{
    window = glfwCreateWindow(width, height, title.c_str(), 0, 0);
    if(!window)
    {
        throw std::runtime_error{"Failed to create window."};
    }
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress ))
    {
        std::cerr << "Failed to initialize glad.\n";
        std::exit(EXIT_FAILURE);
    }

    glViewport(0,0,width,height);
    glfwSetFramebufferSizeCallback(window, Framebuffer_size_callback);

    glEnable(GL_DEPTH_TEST);
}

void undercore::Window::Create(std::string title, unsigned int width, unsigned int height)
{
    this->title = title;
    this->width = width;
    this->height = height;

    window = glfwCreateWindow(width, height, title.c_str(), 0, 0);
    if(!window)
    {
        throw std::runtime_error{"Failed to create window."};
    }
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress ))
    {
        std::cerr << "Failed to initialize glad.\n";
        std::exit(EXIT_FAILURE);
    }

    glViewport(0,0,width,height);
    glfwSetFramebufferSizeCallback(window, Framebuffer_size_callback);

    glEnable(GL_DEPTH_TEST);
}

void undercore::Window::Clear()
{
    glClearColor(0.0, 0.0, 1.0, 1.0);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

void undercore::Window::Display()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

std::optional<Event> undercore::Window::Poll_event()
{
    std::optional<Event> event{};
    if(events_queue.empty()) return event;

    event = events_queue.front();
    events_queue.pop();

    return event;
}

void undercore::Window::Framebuffer_size_callback([[maybe_unused]] GLFWwindow* window, int width, int height)
{
    glViewport(0,0, width, height);
}

void undercore::Window::Colect_events()
{
    if(glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::NUM_1);
    }
    if(glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::NUM_2);
    }
    if(glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::NUM_3);
    }
    if(glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::NUM_4);
    }
    if(glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::NUM_5);
    }
    if(glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::NUM_6);
    }
    if(glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::NUM_7);
    }
    if(glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::NUM_8);
    }
    if(glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::NUM_9);
    }
    if(glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::NUM_0);
    }
    if(glfwGetKey(window, GLFW_KEY_BACKSPACE) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::BACKSPACE);
    }
    if(glfwGetKey(window, GLFW_KEY_TAB) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::TAB);
    }
    if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::Q);
    }
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::W);
    }
    if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::E);
    }
    if(glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::R);
    }
    if(glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::T);
    }
    if(glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::Y);
    }
    if(glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::U);
    }
    if(glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::I);
    }
    if(glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::O);
    }
    if(glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::P);
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::A);
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::S);
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::D);
    }
    if(glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::F);
    }
    if(glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::G);
    }
    if(glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::H);
    }
    if(glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::J);
    }
    if(glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::K);
    }
    if(glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::L);
    }
    if(glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::ENTER);
    }
    if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::L_SHIFT);
    }
    if(glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::Z);
    }
    if(glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::X);
    }
    if(glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::C);
    }
    if(glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::V);
    }
    if(glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::B);
    }
    if(glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::N);
    }
    if(glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::M);
    }
    if(glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::L_CTRL);
    }
    if(glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::L_ALT);
    }
    if(glfwGetKey(window, GLFW_KEY_RIGHT_ALT) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::R_ALT);
    }
    if(glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::R_CTRL);
    }
    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::UP);
    }
    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::DOWN);
    }
    if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::RIGHT);
    }
    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        events_queue.emplace(Keyboard::LEFT);
    }
}
