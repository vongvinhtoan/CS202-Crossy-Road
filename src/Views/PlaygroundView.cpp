#include <Views/PlaygroundView.hpp>
#include <iostream>

PlaygroundView::PlaygroundView(PlaygroundAdapter& playgroundAdapter)
: m_playgroundAdapter(playgroundAdapter)
{
}

PlaygroundView::~PlaygroundView()
{
}

void PlaygroundView::update(sf::Time dt)
{
}

void PlaygroundView::handleEvent(sf::Event& event)
{
}

void PlaygroundView::handleRealtimeInput()
{
}

void PlaygroundView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    int bufferRange = m_playgroundAdapter.getBufferRange();
    for(int i = bufferRange * 2 - 1; i >= 0; --i)
    {
        auto* lane = m_playgroundAdapter.getLane(i);
        if(lane == nullptr) continue;
        lane->draw(target, states);
    };
    auto* player = m_playgroundAdapter.getPlayer();
    player->draw(target, states);
}