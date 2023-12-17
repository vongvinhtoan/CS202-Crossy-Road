#include <Game.hpp>

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
    
}

void Game::handleEvent(sf::Event& event)
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