#include <PlaygroundAdapter.hpp>
#include <Lane.hpp>
#include <iostream>

PlaygroundAdapter::PlaygroundAdapter(Game& game)
: m_game(&game)
, m_lanes(game.getBufferRange() * 2)
, m_player(std::make_unique<PlayerView>())
, m_laneViewFactory(std::make_unique<LaneViewFactory>())
, m_scoreView(std::make_unique<TextView>("", Context::getInstance().getFonts()->get(FontID::Main), 30))
{
    for(int i = 0; i < m_lanes.size(); ++i)
    {
        m_lanes[i] = m_laneViewFactory->create(LaneType::Land);
    }
}

int PlaygroundAdapter::getBufferRange() const
{
    return m_game->getBufferRange();
}


LaneView* PlaygroundAdapter::getLane(int index)
{
    auto bufferRange = m_game->getBufferRange();
    index = index % (bufferRange * 2);
    if(index < 0) index += (bufferRange * 2);

    Lane* lane = m_game->getLane(index);
    if(lane == nullptr) {
        return nullptr;
    }
    if(m_lanes[index]->getLaneType() != lane->getLaneType())
    {
        m_lanes[index] = m_laneViewFactory->create(lane->getLaneType());
    }
    m_lanes[index]->bind(lane, m_game->getCamera());
    return m_lanes[index].get();
}

PlayerView* PlaygroundAdapter::getPlayer()
{
    m_player->bind(m_game->getPlayer(), m_game->getCamera());
    return m_player.get();
}

TextView* PlaygroundAdapter::getScoreView()
{
    auto score = m_game->getLaneCount();
    m_scoreView->get().setString("Score: " + std::to_string(score));
    return m_scoreView.get();
}

Game* PlaygroundAdapter::getGame() const
{
    return m_game;
}

std::tuple<int, int> PlaygroundAdapter::getDrawRange() const
{
    auto camera_pos = m_game->getCamera()->getScrollPosition();
    auto int_pos = camera_pos;
    auto index = int_pos / 100;
    auto window_height = Context::getInstance().getWindow()->getSize().y;
    auto height_index_count = window_height / 100 + 4;
    auto start_index = index - height_index_count / 2;
    auto end_index = index + height_index_count / 2;
    return std::make_tuple(start_index, end_index); 
}