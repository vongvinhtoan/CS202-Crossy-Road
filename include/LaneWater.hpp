#pragma once

#include <Lane.hpp>

class LaneWater : public Lane
{
public:
    LaneWater(LaneType laneType, int id);

public:
    void update(sf::Time dt) override;
};