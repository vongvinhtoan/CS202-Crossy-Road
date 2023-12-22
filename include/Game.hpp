#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <Lane.hpp>
#include <Player.hpp>
#include <PlaygroundCamera.hpp>
#include <LaneFactory.hpp>
#include <Context.hpp>
#include <GameOverStrategy.hpp>

class Game {
public:
    Game(int bufferRange);
public:
    void update(sf::Time dt);
    void handleEvent(sf::Event& event);
    void handleRealtimeInput();
public:
    Lane* getLane(int index);
    Player* getPlayer();
    int getBufferRange() const;
    PlaygroundCamera* getCamera();
    GameOverStategy* gameOver();
    bool isDone() const;
    int getLaneCount() const;

private:
    enum class Command {
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown
    };
    void initializeCommandMap();
    void solveCommand(Command command);
    void setGameOverStrategy(GameOverStategy* gameOverStrategy);

private:
    void playerMoveLeft();
    void playerMoveRight();
    void playerMoveUp();
    void playerMoveDown();
    Lane* getCurrentLane();
    int getCurrentLaneIndex();

private:
    void updateLanes(int l, int r, sf::Time dt);
    void checkPlayerPosition();
    void updateLaneCount();

private:
    std::unique_ptr<std::map<sf::Keyboard::Key, Command>>   mCommandMap;
    std::vector<std::unique_ptr<Lane>>                      m_lanes;
    std::unique_ptr<Player>                                 m_player;
    std::unique_ptr<PlaygroundCamera>                       m_camera;
    std::unique_ptr<LaneFactory>                            m_laneFactory;
    std::unique_ptr<GameOverStategy>                        m_gameOverStrategy; 
    int                                                     m_bufferRange;
    int                                                     m_laneCount;
    bool                                                    m_isDone;
};