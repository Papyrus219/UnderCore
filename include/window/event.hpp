#ifndef UNDERCORE_EVENT_HPP
#define UNDERCORE_EVENT_HPP

#include "./keyboard_key.hpp"

namespace undercore
{

enum class Event_type
{
    NONE = 0,
    KEY_PRESSED
};

class Event
{
public:
    Event() = default;
    Event(Event_type type_) noexcept;
    Event(Keyboard key_Pressed_) noexcept;

    Event(const Event & other) noexcept;
    Event(Event && other) noexcept = default;;

    Event & operator=(const Event & other) noexcept;
    Event & operator=(Event && other) noexcept = default;

    Event_type Get_type() const noexcept {return type;};
    Keyboard Get_key() const noexcept {return pressed_key;};

    ~Event() = default;
private:
    Event_type type{};
    Keyboard pressed_key{};
};

}

#endif // UNDERCORE_EVENT_HPP
