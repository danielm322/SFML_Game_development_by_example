//
// Created by daniel on 30/01/23.
//

#ifndef SFML_GAME_DEVELOPMENT_BY_EXAMPLE_SHAREDCONTEXT_H
#define SFML_GAME_DEVELOPMENT_BY_EXAMPLE_SHAREDCONTEXT_H

#include "Window.h"
#include "EventManager.h"
struct SharedContext{
    SharedContext() :m_wind(nullptr), m_eventManager(nullptr){}
    Window* m_wind;
    EventManager* m_eventManager;
};

#endif //SFML_GAME_DEVELOPMENT_BY_EXAMPLE_SHAREDCONTEXT_H
