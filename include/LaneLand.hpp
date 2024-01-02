#pragma once

#include <Lane.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class LaneLand : public Lane
{
public:
    LaneLand(LaneType laneType, int id, Game* game);
    LaneLand(LaneType laneType, int id, Game* game, std::vector<int> lastSafeIndexes);

public:
    void update(sf::Time dt) override;
    std::vector<int> getObstacles() const;

public:
    GameOverStategy* moveLeft(Player* player) override;
    GameOverStategy* moveRight(Player* player) override;
    GameOverStategy* enter(Player* player) override;
    GameOverStategy* updatePlayer(Player* player, sf::Time dt) override;

public:
    std::vector<int> getSafeIndexes() const override;

private:
    std::vector<int>      mObstacles;
};