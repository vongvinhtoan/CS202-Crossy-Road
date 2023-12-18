#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <Lane.hpp>
#include <Player.hpp>
#include <PlaygroundCamera.hpp>
#include <LaneFactory.hpp>
#include <Context.hpp>

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

private:
    std::vector<std::unique_ptr<Lane>>  m_lanes;
    std::unique_ptr<Player>             m_player;
    std::unique_ptr<PlaygroundCamera>   m_camera;
    std::unique_ptr<LaneFactory>        m_laneFactory;
    int                                 m_bufferRange;
};