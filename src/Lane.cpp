#include <Lane.hpp>

Lane::Lane(LaneType laneType)
    : m_laneType(laneType)
{

}

LaneType Lane::getLaneType() const
{
    return m_laneType;
}