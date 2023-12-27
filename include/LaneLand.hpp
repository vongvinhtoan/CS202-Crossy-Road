#pragma once

#include <Lane.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class LaneLand : public Lane
{
public:
    LaneLand(LaneType laneType, int id, Game* game);

public:
    void update(sf::Time dt) override;
    GameOverStategy* checkCollision(Player* player, bool& isDone) override;
    std::vector<float> getObstacles() const;

public:
    GameOverStategy* moveLeft(Player* player, bool& isDone) override;
    GameOverStategy* moveRight(Player* player, bool& isDone) override;
    GameOverStategy* enter(Player* player, bool& isDone) override;

private:
    std::vector<float>    mOriginalObstacles;
    std::vector<float>    mObstacles;
    sf::Time              mElapsedTime;
};