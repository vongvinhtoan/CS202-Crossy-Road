#pragma once

#include <Lane.hpp>

class LaneWater : public Lane
{
public:
    LaneWater(LaneType laneType, int id);

public:
    GameOverStategy* moveLeft(Player* player, bool& isDone) override;
    GameOverStategy* moveRight(Player* player, bool& isDone) override;
    GameOverStategy* enter(Player* player, bool& isDone) override;

public:
    void update(sf::Time dt) override;
    GameOverStategy* checkCollision(Player* player, bool& isDone) override;
};