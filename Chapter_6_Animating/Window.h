//
// Created by daniel on 26/01/23.
//

#ifndef SFML_GAME_DEVELOPMENT_BY_EXAMPLE_WINDOW_H
#define SFML_GAME_DEVELOPMENT_BY_EXAMPLE_WINDOW_H
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "EventManager.h"

class Window{
public:
    Window();
    Window(const std::string& l_title,const sf::Vector2u& l_size);
    ~Window();
    void BeginDraw(); // Clear the window.
    void EndDraw(); // Display the changes.
    void Update();
    bool IsDone();
    bool IsFullscreen();
    bool IsFocused();

//    void ToggleFullscreen();
    void Draw(sf::Drawable& l_drawable);
    void ToggleFullscreen(EventDetails* l_details);
    void Close(EventDetails* l_details = nullptr);

    EventManager* GetEventManager();
    sf::RenderWindow* GetRenderWindow();
    sf::Vector2u GetWindowSize();
    sf::FloatRect GetViewSpace();

private:
    void Setup(const std::string& l_title,
               const sf::Vector2u& l_size);
    void Destroy();
    void Create();
    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    EventManager m_eventManager;
    bool m_isDone;
    bool m_isFullscreen;
    bool m_isFocused;
};

#endif //SFML_GAME_DEVELOPMENT_BY_EXAMPLE_WINDOW_H
