//
// Created by daniel on 30/01/23.
//

#ifndef SFML_GAME_DEVELOPMENT_BY_EXAMPLE_STATE_PAUSED_H
#define SFML_GAME_DEVELOPMENT_BY_EXAMPLE_STATE_PAUSED_H

#include "BaseState.h"
#include "EventManager.h"

class State_Paused : public BaseState{
public:
    State_Paused(StateManager* l_stateManager);
    ~State_Paused();

    void OnCreate();
    void OnDestroy();

    void Activate();
    void Deactivate();

    void Update(const sf::Time& l_time);
    void Draw();

    void Unpause(EventDetails* l_details);
private:
    sf::Font m_font;
    sf::Text m_text;
    sf::RectangleShape m_rect;
};

#endif //SFML_GAME_DEVELOPMENT_BY_EXAMPLE_STATE_PAUSED_H
