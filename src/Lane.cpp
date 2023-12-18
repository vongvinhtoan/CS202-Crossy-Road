#include <Lane.hpp>

Lane::Lane(LaneType laneType, int id)
    : m_laneType(laneType)
    , m_index(id)
{

}

LaneType Lane::getLaneType() const
{
    return m_laneType;
}

int Lane::getIndex() const
{
    return m_index;
}