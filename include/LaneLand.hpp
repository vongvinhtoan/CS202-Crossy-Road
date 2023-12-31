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
    std::vector<float> getObstacles() const;

public:
    GameOverStategy* moveLeft(Player* player) override;
    GameOverStategy* moveRight(Player* player) override;
    GameOverStategy* enter(Player* player) override;
    GameOverStategy* updatePlayer(Player* player, sf::Time dt) override;

private:
    std::vector<float>    mOriginalObstacles;
    std::vector<float>    mObstacles;
    sf::Time              mElapsedTime;
};