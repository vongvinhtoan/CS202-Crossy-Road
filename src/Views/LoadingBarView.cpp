#include <Views/LoadingBarView.hpp>
#include <iostream>

LoadingBarView::~LoadingBarView()
{
}

void LoadingBarView::update(sf::Time dt)
{
	m_progress.setSize(sf::Vector2f(m_bar.getSize().x * m_progressValue, m_bar.getSize().y));
}

void LoadingBarView::handleEvent(sf::Event &event)
{
}

void LoadingBarView::handleRealtimeInput()
{
}

void LoadingBarView::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(m_bar, states);
	target.draw(m_progress, states);
}

bool LoadingBarView::contains(sf::Vector2f point) const
{
	return m_bar.getGlobalBounds().contains(point);
}

void LoadingBarView::setProgress(float progress)
{
	m_progressValue = progress;
}

sf::Vector2f LoadingBarView::getSize() const
{
	return m_bar.getSize();
}