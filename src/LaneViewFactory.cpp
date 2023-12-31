#include <LaneViewFactory.hpp>
#include <LaneLandView.hpp>
#include <LaneMovingWaterView.hpp>

LaneViewFactory::LaneViewFactory()
{
    m_laneViewFactories[LaneType::Land] = [](LaneType laneType) -> std::unique_ptr<LaneView> {
        return std::unique_ptr<LaneView>(new LaneLandView(laneType));
    };
    m_laneViewFactories[LaneType::MovingWater] = [](LaneType laneType) -> std::unique_ptr<LaneView> {
        return std::unique_ptr<LaneView>(new LaneMovingWaterView(laneType));
    };
}

std::unique_ptr<LaneView> LaneViewFactory::create(LaneType laneType)
{
    return m_laneViewFactories[laneType](laneType);
}