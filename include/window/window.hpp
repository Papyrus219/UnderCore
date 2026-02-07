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

/**
 * Class abstracting GLFW window.
 */
class Window
{
public:
    /**
    * @name Constructors
    * @{
    */

    /**
     * @throw std::runtime_error    When window creation failed.
     */
    Window();

    /**
     * @throw std::runtime_error    When window creation failed.
     */
    Window(std::string title_, unsigned int width_, unsigned int height_);

    ///@}

    /**
     * @brief Create window, if we use simple constructor.
     * @throw std::runtime_error    When window creation failed.
     */
    void Create(std::string title, unsigned int width, unsigned int height);
    void Close() noexcept {glfwSetWindowShouldClose(window, true);};

    void Clear() noexcept;
    void Display() noexcept;

    /**
    * @name Getters
    * @{
    */

    bool Get_is_open() const noexcept {return !glfwWindowShouldClose(window);};
    std::string Get_title() const noexcept {return title;};
    unsigned int Get_width() const noexcept {return width;};
    unsigned int Get_height() const noexcept {return height;};

    ///@}

    /**
     * @name Events
     * @{
     */

    /**
     * @brief Take first waiting event.
     * @retval optional<Event>  First waiting event.
     * @retval empty_optional   No more events in queue.
     */
    std::optional<Event> Poll_event() noexcept;

    /// @brief Colect all avalible events and put them in queue.
    void Colect_events() noexcept;

    ///@}
private:
    static void Framebuffer_size_callback(GLFWwindow *window, int width, int height);

    /**
     * @name Events
     * @{
     */

    ///@brief Queue of accumulated events waiting to be served.
    std::queue<Event> events_queue{};

    ///@}

    ///@brief GLFW object wich class abstract.
    GLFWwindow* window{};

    std::string title{};
    unsigned int width{};
    unsigned int height{};
};

}

#endif // UNDERCORE_WINDOW_HPP
