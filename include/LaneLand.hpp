#pragma once

#include <Lane.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class LaneLand : public Lane
{
public:
    LaneLand(LaneType laneType, int id);

public:
    void update(sf::Time dt) override;
    std::vector<int> getObstacles() const;

private:
    std::vector<int>    mObstacles;
};