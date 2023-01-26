//
// Created by daniel on 26/01/23.
//

#include "Game.h"
Game::Game(): m_window("Snake", sf::Vector2u(800, 600)),
              m_snake(m_world.GetBlockSize()),
              m_world(sf::Vector2u(800,600))
{
    m_clock.restart();
    m_elapsed = 0.0f;
}

Game::~Game(){}

void Game::HandleInput(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
       && m_snake.GetPhysicalDirection() != Direction::Down)
    {
        m_snake.SetDirection(Direction::Up);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
              && m_snake.GetPhysicalDirection() != Direction::Up)
    {
        m_snake.SetDirection(Direction::Down);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
              && m_snake.GetPhysicalDirection() != Direction::Right)
    {
        m_snake.SetDirection(Direction::Left);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
              && m_snake.GetPhysicalDirection() != Direction::Left)
    {
        m_snake.SetDirection(Direction::Right);
    }
}

void Game::Update(){
    m_window.Update(); // Update window events.
    float timeStep = 1.0f / m_snake.GetSpeed();
    if(m_elapsed >= timeStep) {
        m_snake.Tick();
        m_world.Update(m_snake);
        m_elapsed -= timeStep;
        if (m_snake.HasLost()) {
            m_snake.Reset();
        }
    }
}

void Game::Render(){
    m_window.BeginDraw();
    // Render here.
    m_world.Render(*m_window.GetRenderWindow());
    m_snake.Render(*m_window.GetRenderWindow());
    m_window.EndDraw();
}

Window* Game::GetWindow(){ return &m_window; }
sf::Time Game::GetElapsed(){ return m_clock.getElapsedTime(); }
void Game::RestartClock(){ m_elapsed += m_clock.restart().asSeconds(); }