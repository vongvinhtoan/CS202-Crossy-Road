#include <Lane.hpp>
#include <Game.hpp>

Lane::Lane(LaneType laneType, int id, Game* game)
    : m_laneType(laneType)
    , m_index(id)
    , m_game(game)
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

Game* Lane::getGame() const
{
    return m_game;
}