#pragma once

#include <Lane.hpp>
#include <queue>

class LaneMovingWater : public Lane
{
public:
    LaneMovingWater(LaneType laneType, int id, Game* game);
    LaneMovingWater(LaneType laneType, int id, Game* game, std::vector<int> lastSafeIndexes);

public:
    GameOverStategy* moveLeft(Player* player) override;
    GameOverStategy* moveRight(Player* player) override;
    GameOverStategy* enter(Player* player) override;
    GameOverStategy* updatePlayer(Player* player, sf::Time dt) override;

public:
    std::vector<int> getSafeIndexes() const override;

public:
    void update(sf::Time dt) override;

public:
    std::deque<std::pair<float, float>> getWoodPositions();

private:
    void removeOldWoods();
    void createNewWoods();

private:
    sf::Time                            m_elapsedTime;
    float                               m_speed;
    std::deque<std::pair<float, float>> m_woodPositions;
};