#pragma once

#include <SFML/Graphics.hpp>
#include <Player.hpp>
#include <GameOverStrategy.hpp>

class Game;

enum class LaneType
{
    Land,
    MovingWater,
    Count
};

class Lane 
{
public:
    Lane(LaneType laneType, int id, Game* game);

public:
    virtual void update(sf::Time dt) = 0;

public:
    LaneType getLaneType() const;
    int getIndex() const;

public:
    virtual GameOverStategy* moveLeft(Player* player) = 0;
    virtual GameOverStategy* moveRight(Player* player) = 0;
    virtual GameOverStategy* enter(Player* player) = 0;
    virtual GameOverStategy* updatePlayer(Player* player, sf::Time dt) = 0;

public:
    Game* getGame() const;

private:
    int         m_index;
    LaneType    m_laneType;
    Game*       m_game;
};