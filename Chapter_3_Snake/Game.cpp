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
    m_textbox.Setup(5, 14, 350, sf::Vector2f(225,0));
    m_textbox.Add("Seeded random number generator with: " + std::to_string(time(NULL)));
    m_current_lives = m_snake.GetLives();
    m_current_score = m_snake.GetScore();
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
        if (m_current_lives > m_snake.GetLives())
        {
            m_textbox.Add("Now you have: " + std::to_string(m_snake.GetLives()) + " lives");
            m_current_lives = m_snake.GetLives();
        }
        if (m_current_score < m_snake.GetScore())
        {
            m_textbox.Add("You ate an apple, score: " + std::to_string(m_snake.GetScore()));
            m_current_score = m_snake.GetScore();
        }
        if (m_snake.HasLost()) {
            m_textbox.Add("GAME OVER! Score: "
                          + std::to_string((long long)m_snake.GetScore()));
            m_snake.Reset();
//            m_textbox.Add();
        }
    }
}

void Game::Render(){
    m_window.BeginDraw();
    // Render here.
    m_world.Render(*m_window.GetRenderWindow());
    m_snake.Render(*m_window.GetRenderWindow());
    m_textbox.Render(*m_window.GetRenderWindow());
    m_window.EndDraw();
}

Window* Game::GetWindow(){ return &m_window; }
sf::Time Game::GetElapsed(){ return m_clock.getElapsedTime(); }
void Game::RestartClock(){ m_elapsed += m_clock.restart().asSeconds(); }