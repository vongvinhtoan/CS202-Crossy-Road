#include <LaneViewFactory.hpp>
#include <LaneLandView.hpp>
#include <LaneMovingWaterView.hpp>
#include <LaneStillWaterView.hpp>
#include <LaneCarView.hpp>
#include <LaneTrainView.hpp>

LaneViewFactory::LaneViewFactory()
{
    m_laneViewFactories[LaneType::Land] = [](LaneType laneType) -> std::unique_ptr<LaneView> {
        return std::unique_ptr<LaneView>(new LaneLandView(laneType));
    };
    m_laneViewFactories[LaneType::MovingWater] = [](LaneType laneType) -> std::unique_ptr<LaneView> {
        return std::unique_ptr<LaneView>(new LaneMovingWaterView(laneType));
    };
    m_laneViewFactories[LaneType::StillWater] = [](LaneType laneType) -> std::unique_ptr<LaneView> {
        return std::unique_ptr<LaneView>(new LaneStillWaterView(laneType));
    };
    m_laneViewFactories[LaneType::Car] = [](LaneType laneType) -> std::unique_ptr<LaneView> {
        return std::unique_ptr<LaneView>(new LaneCarView(laneType));
    };
    m_laneViewFactories[LaneType::Train] = [](LaneType laneType) -> std::unique_ptr<LaneView> {
        return std::unique_ptr<LaneView>(new LaneTrainView(laneType));
    };
}

std::unique_ptr<LaneView> LaneViewFactory::create(LaneType laneType)
{
    return m_laneViewFactories[laneType](laneType);
}