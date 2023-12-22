#include <LaneLand.hpp>
#include <iostream>
#include <Utils.hpp>
#include <Context.hpp>

LaneLand::LaneLand(LaneType laneType, int id) : Lane(laneType, id)
{
    int obstacleCount = utils::random(1, 3);
    int maxIndex = (*Context::getInstance().getWindow()).getSize().x / 100.f;
    for (int i = 0; i < obstacleCount; i++)
    {
        int obstacle = utils::random(0, maxIndex-1);
        mObstacles.push_back(obstacle);
    }
}

std::vector<int> LaneLand::getObstacles() const
{
    return mObstacles;
}

void LaneLand::update(sf::Time dt)
{
}