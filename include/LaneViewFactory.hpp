#pragma once

#include <memory>
#include <Views/LaneView.hpp>
#include <map>
#include <functional>

class LaneViewFactory
{
private:
    std::map<LaneType, std::function<std::unique_ptr<LaneView>(LaneType)>> m_laneViewFactories;

public:
    LaneViewFactory();

    std::unique_ptr<LaneView> create(LaneType laneType);
};