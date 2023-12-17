#include <PlaygroundAdapter.hpp>
#include <Lane.hpp>
#include <iostream>

PlaygroundAdapter::PlaygroundAdapter(Game& game)
: m_game(&game)
, m_lanes(game.getBufferRange())
, m_player(std::make_unique<PlayerView>())
{
}

int PlaygroundAdapter::getBufferRange() const
{
    return m_game->getBufferRange();
}

LaneView* PlaygroundAdapter::getLane(int index)
{
    Lane* lane = m_game->getLane(index);
    if(lane == nullptr) return nullptr;
    if(m_lanes[index]->getLaneType() != lane->getLaneType())
    {
        m_lanes[index] = m_laneViewFactory->create(lane->getLaneType());
    }
    m_lanes[index]->bind(lane);
}

PlayerView* PlaygroundAdapter::getPlayer()
{
    m_player->bind(m_game->getPlayer(), m_game->getCamera()->getScrollPosition());
    return m_player.get();
}