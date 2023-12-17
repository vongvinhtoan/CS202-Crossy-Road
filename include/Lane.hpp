#pragma once

enum class LaneType
{
    Land,
    Water,
};

class Lane 
{
public:
    Lane(LaneType laneType);
public:
    LaneType getLaneType() const;
private:
    LaneType m_laneType;
};