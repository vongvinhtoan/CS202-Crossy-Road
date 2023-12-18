#include <LaneFactory.hpp>
#include <LaneLand.hpp>
#include <LaneWater.hpp>

LaneFactory::LaneFactory()
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