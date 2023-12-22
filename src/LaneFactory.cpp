#include <LaneFactory.hpp>
#include <LaneLand.hpp>
#include <LaneWater.hpp>
#include <Utils.hpp>

LaneFactory::LaneFactory(std::vector<std::vector<double>> probabilities)
    : m_laneProbabilities(probabilities)
{
    m_laneFactories[LaneType::Land] = [](LaneType laneType, int id) -> std::unique_ptr<Lane> {
        return std::unique_ptr<Lane>(new LaneLand(laneType, id));
    };
    m_laneFactories[LaneType::Water] = [](LaneType laneType, int id) -> std::unique_ptr<Lane> {
        return std::unique_ptr<Lane>(new LaneWater(laneType, id));
    };
}

std::unique_ptr<Lane> LaneFactory::create(LaneType laneType, int id)
{
    return m_laneFactories[laneType](laneType, id);
}

std::unique_ptr<Lane> LaneFactory::createAfter(Lane* lastLane, int id)
{
    if(!lastLane)
        return create(LaneType::Land, id);

    double prob = utils::random(0.0, 1.0);
    double sum = 0.0;

    LaneType lastLaneType = lastLane->getLaneType();

    for(int i = 0; i < m_laneProbabilities[lastLaneType].size(); ++i)
    {
        sum += m_laneProbabilities[lastLaneType][i];
        if(prob < sum)
        {
            return create(LaneType(i), id);
        }
    }
    return create(LaneType::Land, id);
}