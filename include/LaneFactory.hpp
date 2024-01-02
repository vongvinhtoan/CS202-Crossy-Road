#pragma once

#include <memory>
#include <Lane.hpp>
#include <map>
#include <functional>
#include <vector>

class Game;

struct LaneProbabilities
{
    std::vector<std::vector<double>> probabilities;

    LaneProbabilities(std::vector<std::vector<double>> probabilities)
        : probabilities(probabilities)
    {
    }

    std::vector<double>& operator[](LaneType laneType)
    {
        return probabilities[static_cast<int>(laneType)];
    }
};

class LaneFactory
{
private:
    std::map<LaneType, std::function<std::unique_ptr<Lane>(LaneType, int, Game*, std::vector<bool>)>> m_laneFactories;
    LaneProbabilities m_laneProbabilities;

public:
    LaneFactory(std::vector<std::vector<double>> probabilities);

    std::unique_ptr<Lane> create(LaneType laneType, int id, Game* game, std::vector<bool> lastSafeIndexes);
    std::unique_ptr<Lane> createAfter(Lane* lastLane, int id, Game* game);
};