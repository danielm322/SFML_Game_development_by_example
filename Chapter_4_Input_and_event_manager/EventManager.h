//
// Created by daniel on 27/01/23.
//

#ifndef SFML_GAME_DEVELOPMENT_BY_EXAMPLE_EVENTMANAGER_H
#define SFML_GAME_DEVELOPMENT_BY_EXAMPLE_EVENTMANAGER_H
#include "SFML/Graphics.hpp"
#include <iostream>
#include <functional> // Defines std::function & std::bind.

enum class EventType{
    KeyDown = sf::Event::KeyPressed,
    KeyUp = sf::Event::KeyReleased,
    MButtonDown = sf::Event::MouseButtonPressed,
    MButtonUp = sf::Event::MouseButtonReleased,
    MouseWheel = sf::Event::MouseWheelMoved,
    WindowResized = sf::Event::Resized,
    GainedFocus = sf::Event::GainedFocus,
    LostFocus = sf::Event::LostFocus,
    MouseEntered = sf::Event::MouseEntered,
    MouseLeft = sf::Event::MouseLeft,
    Closed = sf::Event::Closed,
    TextEntered = sf::Event::TextEntered,
    Keyboard = sf::Event::Count + 1, Mouse, Joystick
};

struct EventInfo{
    EventInfo(){ m_code = 0; }
    EventInfo(int l_event){ m_code = l_event; }
    union{
        int m_code;
    };
};

using Events = std::vector<std::pair<EventType, EventInfo>>;

struct EventDetails{
    EventDetails(const std::string& l_bindName)
            : m_name(l_bindName)
    {
        Clear();
    }
    std::string m_name;
    sf::Vector2i m_size;
    sf::Uint32 m_textEntered;
    sf::Vector2i m_mouse;
    int m_mouseWheelDelta;
    int m_keyCode; // Single key code.
    void Clear(){
        m_size = sf::Vector2i(0, 0);
        m_textEntered = 0;
        m_mouse = sf::Vector2i(0, 0);
        m_mouseWheelDelta = 0;
        m_keyCode = -1;
    }
};

struct Binding{
    Binding(const std::string& l_name)
            : m_name(l_name), m_details(l_name), c(0){}
    void BindEvent(EventType l_type,
                   EventInfo l_info = EventInfo())
    {
        m_events.emplace_back(l_type, l_info);
    }
    Events m_events;
    std::string m_name;
    int c; // Count of events that are "happening".
    EventDetails m_details;
};

using Bindings = std::unordered_map<std::string, Binding*>;
using Callbacks = std::unordered_map<std::string, std::function<void(EventDetails*)>>;

class EventManager {

};


#endif //SFML_GAME_DEVELOPMENT_BY_EXAMPLE_EVENTMANAGER_H
