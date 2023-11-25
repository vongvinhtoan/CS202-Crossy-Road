#include <Views/ProcessBarView.hpp>

ProcessBarView::ProcessBarView()
{
}

ProcessBarView::~ProcessBarView()
{
}

void ProcessBarView::update(sf::Time dt)
{
    m_progress.setSize(sf::Vector2f(m_bar.getSize().x * m_progressValue, m_bar.getSize().y));
}

void ProcessBarView::handleEvent(sf::Event &event)
{
}

void ProcessBarView::handleRealtimeInput()
{
}

void ProcessBarView::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_bar, states);
    target.draw(m_progress, states);
    target.draw(m_name, states);
    target.draw(m_bar, states);
}

bool ProcessBarView::contains(sf::Vector2f point) const
{
    return m_bar.getGlobalBounds().contains(point);
}

void ProcessBarView::setProgress(float progress)
{
    m_progressValue = progress;
    m_text.setString(std::to_string(progress) + "%");
}

float ProcessBarView::getProgress() const
{
    return m_progressValue;
}

sf::Vector2f ProcessBarView::getSize() const
{
    return m_bar.getSize();
}