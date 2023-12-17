#include <Game.hpp>
#include <iostream>

Game::Game(int bufferRange)
    : m_bufferRange(bufferRange)
    , m_laneFactory(std::make_unique<LaneFactory>())
    , m_camera(std::make_unique<PlaygroundCamera>())
{
    m_lanes.resize(2 * bufferRange);
    m_player = std::make_unique<Player>();
}

void Game::update(sf::Time dt)
{
    m_player->update(dt);
    m_camera->update(dt);
}

void Game::handleEvent(sf::Event& event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Left)
        {
            m_player->moveLeft();
        }
        if(event.key.code == sf::Keyboard::Right)
        {
            m_player->moveRight();
        }
        if(event.key.code == sf::Keyboard::Up)
        {
            m_player->moveUp();
        }
        if(event.key.code == sf::Keyboard::Down)
        {
            m_player->moveDown();
        }
    }
}

void Game::handleRealtimeInput()
{
}

Lane* Game::getLane(int index)
{
    return m_lanes[index].get();
}

Player* Game::getPlayer()
{
    return m_player.get();
}

int Game::getBufferRange() const
{
    return m_bufferRange;
}

PlaygroundCamera* Game::getCamera()
{
    return m_camera.get();
}