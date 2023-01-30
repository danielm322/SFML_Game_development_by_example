//
// Created by daniel on 30/01/23.
//

#ifndef SFML_GAME_DEVELOPMENT_BY_EXAMPLE_STATE_MAINMENU_H
#define SFML_GAME_DEVELOPMENT_BY_EXAMPLE_STATE_MAINMENU_H
#include "BaseState.h"
#include "EventManager.h"

class State_MainMenu : public BaseState{
public:
    State_MainMenu(StateManager* l_stateManager);
    ~State_MainMenu();

    void OnCreate();
    void OnDestroy();

    void Activate();
    void Deactivate();

    void Update(const sf::Time& l_time);
    void Draw();

    void MouseClick(EventDetails* l_details);
private:
    sf::Font m_font;
    sf::Text m_text;
    sf::Vector2f m_buttonSize;
    sf::Vector2f m_buttonPos;
    unsigned int m_buttonPadding;
    sf::RectangleShape m_rects[3];
    sf::Text m_labels[3];
};


#endif //SFML_GAME_DEVELOPMENT_BY_EXAMPLE_STATE_MAINMENU_H
