#include <LaneViewFactory.hpp>
#include <LaneLandView.hpp>
#include <LaneWaterView.hpp>

LaneViewFactory::LaneViewFactory()
{
    m_laneViewFactories[LaneType::Land] = [](LaneType laneType) -> std::unique_ptr<LaneView> {
        return std::unique_ptr<LaneView>(new LaneLandView(laneType));
    };
    m_laneViewFactories[LaneType::Water] = [](LaneType laneType) -> std::unique_ptr<LaneView> {
        return std::unique_ptr<LaneView>(new LaneWaterView(laneType));
    };
}

std::unique_ptr<LaneView> LaneViewFactory::create(LaneType laneType)
{
    return m_laneViewFactories[laneType](laneType);
}