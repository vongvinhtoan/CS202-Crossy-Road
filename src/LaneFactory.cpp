#include <LaneFactory.hpp>
#include <LaneLand.hpp>
#include <LaneWater.hpp>
#include <Utils.hpp>
#include <Game.hpp>

LaneFactory::LaneFactory(std::vector<std::vector<double>> probabilities)
    : m_laneProbabilities(probabilities)
{
    m_laneFactories[LaneType::Land] = [](LaneType laneType, int id, Game* game) -> std::unique_ptr<Lane> {
        return std::unique_ptr<Lane>(new LaneLand(laneType, id, game));
    };
    m_laneFactories[LaneType::Water] = [](LaneType laneType, int id, Game* game) -> std::unique_ptr<Lane> {
        return std::unique_ptr<Lane>(new LaneWater(laneType, id, game));
    };
}

std::unique_ptr<Lane> LaneFactory::create(LaneType laneType, int id, Game* game)
{
    return m_laneFactories[laneType](laneType, id, game);
}

std::unique_ptr<Lane> LaneFactory::createAfter(Lane* lastLane, int id, Game* game)
{
    if(!lastLane)
        return create(LaneType::Land, id, game);

    double prob = utils::random(0.0, 1.0);
    double sum = 0.0;

    LaneType lastLaneType = lastLane->getLaneType();

    for(int i = 0; i < m_laneProbabilities[lastLaneType].size(); ++i)
    {
        sum += m_laneProbabilities[lastLaneType][i];
        if(prob < sum)
        {
            return create(LaneType(i), id, game);
        }
    }
    return create(LaneType::Land, id, game);
}