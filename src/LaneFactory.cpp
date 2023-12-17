#include <LaneFactory.hpp>
#include <LaneLand.hpp>
#include <LaneWater.hpp>

LaneFactory::LaneFactory()
{
    m_laneFactories[LaneType::Land] = [](LaneType laneType) -> std::unique_ptr<Lane> {
        return std::unique_ptr<Lane>(new LaneLand(laneType));
    };
    m_laneFactories[LaneType::Water] = [](LaneType laneType) -> std::unique_ptr<Lane> {
        return std::unique_ptr<Lane>(new LaneWater(laneType));
    };
}

std::unique_ptr<Lane> LaneFactory::create(LaneType laneType)
{
    return m_laneFactories[laneType](laneType);
}