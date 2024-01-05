#pragma once

#include <Lane.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class LaneStillWater : public Lane
{
public:
    LaneStillWater(LaneType laneType, int id, Game* game, std::vector<bool> lastSafeIndexes);

public:
    void update(sf::Time dt) override;

public:
    GameOverStategy* moveLeft(Player* player) override;
    GameOverStategy* moveRight(Player* player) override;
    GameOverStategy* enter(Player* player) override;
    GameOverStategy* updatePlayer(Player* player, sf::Time dt) override;

public:
    std::vector<int> getLeafs() const;

private:
    std::vector<int>    m_leafs;
};