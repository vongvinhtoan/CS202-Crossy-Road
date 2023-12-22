#pragma once

#include <SFML/Graphics.hpp>

enum class LaneType
{
    Land,
    Water,
    Count
};

class Lane 
{
public:
    Lane(LaneType laneType, int id);

public:
    virtual void update(sf::Time dt) = 0;

public:
    LaneType getLaneType() const;
    int getIndex() const;

private:
    int         m_index;
    LaneType    m_laneType;
};