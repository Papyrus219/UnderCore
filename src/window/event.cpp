#include "../../include/window/event.hpp"

using namespace undercore;

undercore::Event::Event(Event_type type_) noexcept: type{type_}
{

}

undercore::Event::Event(Keyboard key_pressed_) noexcept: type{Event_type::KEY_PRESSED}, pressed_key{key_pressed_}
{

}

undercore::Event::Event(const Event & other) noexcept: type{other.type}, pressed_key{other.pressed_key}
{

}

Event & undercore::Event::operator=(const Event & other) noexcept
{
    this->type = other.type;
    this->pressed_key = other.pressed_key;

    return *this;
}
