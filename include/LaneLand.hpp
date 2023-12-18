#pragma once

#include <Lane.hpp>

class LaneLand : public Lane
{
public:
    LaneLand(LaneType laneType, int id);

public:
    void update(sf::Time dt) override;
};