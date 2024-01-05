#pragma once

#include <Lane.hpp>
#include <queue>

class LaneMovingWater : public Lane
{
public:
    LaneMovingWater(LaneType laneType, int id, Game* game, std::vector<bool> lastSafeIndexes);

public:
    GameOverStategy* moveLeft(Player* player) override;
    GameOverStategy* moveRight(Player* player) override;
    GameOverStategy* enter(Player* player) override;
    GameOverStategy* updatePlayer(Player* player, sf::Time dt) override;
    void loadFromFile(std::istream& in) override;
    std::ostream& saveToFile(std::ostream& out) const override;

public:
    void update(sf::Time dt) override;

public:
    std::deque<std::pair<float, float>> getWoodPositions();

private:
    void removeOldWoods();
    void createNewWoods();

private:
    float                               m_speed;
    std::deque<std::pair<float, float>> m_woodPositions;
};