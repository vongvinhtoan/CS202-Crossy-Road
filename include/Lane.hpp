#pragma once

#include <SFML/Graphics.hpp>
#include <Player.hpp>
#include <GameOverStrategy.hpp>

enum class LaneType
{
    Land,
    Water,
    Count
};

class Lane 
{
public:
    Lane(LaneType laneType, int id);

public:
    virtual void update(sf::Time dt) = 0;
    virtual GameOverStategy* checkCollision(Player* player, bool& isDone) = 0;

public:
    LaneType getLaneType() const;
    int getIndex() const;

public:
    virtual GameOverStategy* moveLeft(Player* player, bool& isDone) = 0;
    virtual GameOverStategy* moveRight(Player* player, bool& isDone) = 0;
    virtual GameOverStategy* enter(Player* player, bool& isDone) = 0;

private:
    int         m_index;
    LaneType    m_laneType;
};