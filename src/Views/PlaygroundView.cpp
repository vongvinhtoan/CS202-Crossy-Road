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
    for(int i = 0; i < bufferRange; ++i)
    {
        auto* lane = m_playgroundAdapter.getLane(i);
        if(lane == nullptr) continue;
        target.draw(*lane, states);
    };
    auto* player = m_playgroundAdapter.getPlayer();
    target.draw(*player, states);
}