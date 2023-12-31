#include <Game.hpp>
#include <GameOver_TooSlowFromCamera.hpp>
#include <GameOver_HitObstacleOnLand.hpp>
#include <iostream>
#include <PlaygroundAdapter.hpp>
#include <fstream>
#include <Context.hpp>
#include <ConfigManager.hpp>

Game::Game(int bufferRange)
    : m_bufferRange(bufferRange)
    , m_laneFactory()
    , m_camera(std::make_unique<PlaygroundCamera>(Context::getInstance().getWindow()->getSize().y / 2.f - 100.f))
    , m_gameOverStrategy(nullptr)
    , m_isDone(false)
    , m_laneCount(0)
    , m_playgroundAdapter(nullptr)
    , m_lanes(2 * bufferRange)
    , m_player(std::make_unique<Player>())
{
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

    m_player->setPosition({0.f, 0.f});
}

Game::~Game()
{
}

void Game::setAdapter(PlaygroundAdapter* playgroundAdapter)
{
    m_playgroundAdapter = playgroundAdapter;
}

void Game::setDone(bool isDone)
{
    m_isDone = isDone;
}

void Game::update(sf::Time dt)
{
    if(m_gameOverStrategy.get())
    {
        m_gameOverStrategy->update(dt);
    }
    m_player->update(dt);
    m_camera->update(m_player->getPosition().y, dt);

    auto [l, r] = m_camera->getVisibleRange();
    updateLanes(l, r, dt);

    if(m_gameOverStrategy.get()) return;
    auto* curLane = getCurrentLane();
    auto* result = curLane->updatePlayer(m_player.get(), dt);
    if(result)
        setGameOverStrategy(result);
    checkPlayerPosition();
    updateLaneCount();
}

void Game::updateLanes(int l, int r, sf::Time dt)
{
    for(int id = l; id < r; ++id)
    {
        int i = id % (2 * m_bufferRange);
        int pre_i = (i - 1 + 2 * m_bufferRange) % (2 * m_bufferRange);
        if(!m_lanes[i] || m_lanes[i]->getIndex() != id)
        {
            m_lanes[i] = m_laneFactory->createAfter(m_lanes[pre_i].get(), id, this);
        }
        m_lanes[i]->update(dt);
    }
}

void Game::checkPlayerPosition()
{
    if(m_player->getPosition().y - 100.f < m_camera->getScrollPosition() - Context::getInstance().getWindow()->getSize().y / 2.f)
    {
        setGameOverStrategy(new GameOver_HitObstacleOnLand(this));
        m_player->setInvincible(true);
    }
}

void Game::updateLaneCount()
{
    int index = getCurrentLaneIndex();
    if(index > m_laneCount)
    {
        m_laneCount = index;
    }
}

void Game::handleEvent(sf::Event& event)
{
    if(m_gameOverStrategy.get())
    {

        m_gameOverStrategy->handleEvent(event);

        return;
    }
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
    if(m_gameOverStrategy.get())
    {
        m_gameOverStrategy->handleRealtimeInput();
        return;
    }
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
            playerMoveLeft();
            break;
        case Command::MoveRight:
            playerMoveRight();
            break;
        case Command::MoveUp:
            playerMoveUp();
            break;
        case Command::MoveDown:
            playerMoveDown();
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

bool Game::isDone() const
{
    return m_isDone;
}

int Game::getLaneCount() const
{
    return m_laneCount;
}

PlaygroundAdapter* Game::getAdapter() const
{
    return m_playgroundAdapter;
}

void Game::updateKeyBinding(Command command, const sf::Keyboard::Key newKey)
{
    for(auto& [key, cmd] : *mCommandMap)
    {
        if(cmd == command)
        {
            (*mCommandMap)[newKey] = command;
            mCommandMap->erase(key);
            updateConfigFile(command == Command::MoveLeft ? "moveLeft" : command == Command::MoveRight ? "moveRight" : command == Command::MoveUp ? "moveUp" : "moveDown", newKey);
            return;
        }
    }

}

void Game::playerMoveLeft()
{
    Lane* lane = getCurrentLane();
    if(!lane) return;

    auto* result = lane->moveLeft(m_player.get());
    if(result)
        setGameOverStrategy(result);
}

void Game::playerMoveRight()
{
    Lane* lane = getCurrentLane();
    if(!lane) return;

    auto* result = lane->moveRight(m_player.get());
    if(result)
        setGameOverStrategy(result);
}

void Game::playerMoveUp()
{
    int index = getCurrentLaneIndex();
    index = (index + 1) % (2 * m_bufferRange);
    Lane* lane = m_lanes[index].get();
    if(!lane) return;

    auto* result = lane->enter(m_player.get());
    if(result)
        setGameOverStrategy(result);
}

void Game::playerMoveDown()
{
    if(m_player->getPosition().y == 0.f) return;

    int index = getCurrentLaneIndex();
    index = (index - 1 + 2 * m_bufferRange) % (2 * m_bufferRange);
    Lane* lane = m_lanes[index].get();
    if(!lane) return;

    auto* result = lane->enter(m_player.get());
    if(result)
        setGameOverStrategy(result);
}

Lane* Game::getCurrentLane()
{
    int index = m_player->getPosition().y / 100.f;
    index = index % (2 * m_bufferRange);
    return m_lanes[index].get();
}

int Game::getCurrentLaneIndex()
{
    return m_player->getPosition().y / 100.f;
}

void Game::loadFromFile(std::string filename)
{
    auto cin = std::ifstream(filename);
    
    cin >> m_bufferRange;
    
    float cameraPosition;
    cin >> cameraPosition;
    m_camera->setScrollPosition(cameraPosition);

    cin >> m_laneCount;

    int l, r;
    cin >> l >> r;
    for(int id = l; id < r; ++id)
    {
        int i = id % (2 * m_bufferRange);
        m_lanes[i] = m_laneFactory->createFromFile(cin, id, this);
    }
}

void Game::saveToFile(std::string filename)
{
    auto cout = std::ofstream(filename);

    cout << m_bufferRange << std::endl;

    cout << m_camera->getScrollPosition() << std::endl;

    cout << m_laneCount << std::endl;

    auto [l, r] = m_camera->getVisibleRange();
    cout << l << " " << r << std::endl;
    for(int id = l; id < r; ++id)
    {
        int i = id % (2 * m_bufferRange);
        m_lanes[i]->saveToFile(cout);
    }
}

void Game::setPlayerTexture(sf::Texture* texture)
{
    m_player->setTexture(texture);
}