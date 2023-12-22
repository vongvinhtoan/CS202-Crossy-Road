#include <Game.hpp>
#include <iostream>

Game::Game(int bufferRange)
    : m_bufferRange(bufferRange)
    , m_laneFactory()
    , m_camera(std::make_unique<PlaygroundCamera>(Context::getInstance().getWindow()->getSize().y / 2.f - 100.f))
    , m_gameOverStrategy(nullptr)
{
    m_lanes.resize(2 * bufferRange);
    m_player = std::make_unique<Player>();

    auto& lane_probability = (*Context::getInstance().getConfigs())["lane_probability"];
    std::vector<std::vector<double>> probabilities;
    for(int i = 0; i < lane_probability.size(); ++i)
    {
        probabilities.push_back(std::vector<double>());
        for(int j = 0; j < lane_probability[i].size(); ++j)
        {
            probabilities[i].push_back(lane_probability[i][j].asDouble());
        }
    }
    m_laneFactory = std::make_unique<LaneFactory>(probabilities);

    initializeCommandMap();
}

void Game::update(sf::Time dt)
{
    m_player->update(dt);
    m_camera->update(m_player->getPosition().y, dt);

    auto [l, r] = m_camera->getVisibleRange();

    for(int id = l; id < r; ++id)
    {
        int i = id % (2 * m_bufferRange);
        int pre_i = (i - 1 + 2 * m_bufferRange) % (2 * m_bufferRange);
        if(!m_lanes[i] || m_lanes[i]->getIndex() != id)
        {
            m_lanes[i] = m_laneFactory->createAfter(m_lanes[pre_i].get(), id);
        }
        m_lanes[i]->update(dt);
    }
}

void Game::handleEvent(sf::Event& event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        auto command = mCommandMap->find(event.key.code);
        if(command != mCommandMap->end())
        {
            solveCommand(command->second);
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

void Game::solveCommand(Command command)
{
    switch(command)
    {
        case Command::MoveLeft:
            m_player->moveLeft();
            break;
        case Command::MoveRight:
            m_player->moveRight();
            break;
        case Command::MoveUp:
            m_player->moveUp();
            break;
        case Command::MoveDown:
            m_player->moveDown();
            break;
    }
}

void Game::initializeCommandMap()
{
    mCommandMap = std::make_unique<std::map<sf::Keyboard::Key, Command>>();
    auto &commands = (*Context::getInstance().getConfigs())["keyBinding"];
    (*mCommandMap)[sf::Keyboard::Key(commands["moveLeft"].asInt())] = Command::MoveLeft;
    (*mCommandMap)[sf::Keyboard::Key(commands["moveRight"].asInt())] = Command::MoveRight;
    (*mCommandMap)[sf::Keyboard::Key(commands["moveUp"].asInt())] = Command::MoveUp;
    (*mCommandMap)[sf::Keyboard::Key(commands["moveDown"].asInt())] = Command::MoveDown;
}

GameOverStategy* Game::gameOver()
{
    return m_gameOverStrategy.get();
}

void Game::setGameOverStrategy(GameOverStategy* gameOverStrategy)
{
    m_gameOverStrategy.reset(gameOverStrategy);
}