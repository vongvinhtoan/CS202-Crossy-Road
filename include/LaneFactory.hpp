#pragma once

#include <memory>
#include <Lane.hpp>
#include <map>
#include <functional>

class LaneFactory
{
private:
    std::map<LaneType, std::function<std::unique_ptr<Lane>(LaneType)>> m_laneFactories;

public:
    LaneFactory();

    std::unique_ptr<Lane> create(LaneType laneType);
};