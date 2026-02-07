#ifndef UNDERCORE_EVENT_HPP
#define UNDERCORE_EVENT_HPP

#include "./keyboard_key.hpp"

namespace undercore
{

///@brief Enum class listing the available event types.
enum class Event_type
{
    NONE = 0,
    KEY_PRESSED
};

/**
 * @brief Class abstracting window events.
 */
class Event
{
public:
    /**
     * @name Constructors
     * @{
     */

    Event() = default;
    Event(Event_type type_) noexcept;

    /**
     * @brief Contruct Event of type KEY_PRESSED.
     */
    Event(Keyboard key_Pressed_) noexcept;

    Event(const Event & other) noexcept;
    Event(Event && other) noexcept = default;;

    //@}

    /**
     * @name Operators
     * @{
     */

    Event & operator=(const Event & other) noexcept;
    Event & operator=(Event && other) noexcept = default;

    ///@}

    /**
     * @name Getters
     * @{
     */

    Event_type Get_type() const noexcept {return type;};
    Keyboard Get_key() const noexcept {return pressed_key;};

    ///@}

    /**
     * @name Destructors
     * @{
     */

    ~Event() = default;

    ///@}
private:
    Event_type type{};
    Keyboard pressed_key{};
};

}

#endif // UNDERCORE_EVENT_HPP
