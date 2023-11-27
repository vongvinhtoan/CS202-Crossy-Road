#include <Views/ProcessBarView.hpp>
#include <iostream>

ProcessBarView::ProcessBarView()
{
}

ProcessBarView::~ProcessBarView()
{
}

void ProcessBarView::update(sf::Time dt)
{
    m_progress.setSize(sf::Vector2f(m_bar.getSize().x * m_progressValue, m_bar.getSize().y));

    char m_text_buffer[10];
    sprintf(m_text_buffer, "%0.1f%%", m_progressValue * 100.0f);
    m_text.setString(m_text_buffer);
    auto text_size = m_text.getLocalBounds();
    m_text.setOrigin(
        text_size.left,
        text_size.top + text_size.height / 2.0f);
    m_text.setPosition(
        62.13f,
        m_bar.getSize().y / 2.0f);

    text_size = m_name.getLocalBounds();
    m_name.setOrigin(
        text_size.left,
        text_size.top + text_size.height);
    m_name.setPosition(
        0,
        -32);
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
    target.draw(m_text, states);
}

bool ProcessBarView::contains(sf::Vector2f point) const
{
    return m_bar.getGlobalBounds().contains(point);
}

void ProcessBarView::setProgress(float progress)
{
    m_progressValue = progress;
}

float ProcessBarView::getProgress() const
{
    return m_progressValue;
}

sf::Vector2f ProcessBarView::getSize() const
{
    return m_bar.getSize();
}

void ProcessBarView::setTextFont(const sf::Font &font, unsigned int characterSize)
{
    m_text.setFont(font);
    m_text.setCharacterSize(characterSize);
    ;
}