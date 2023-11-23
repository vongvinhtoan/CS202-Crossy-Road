#pragma once

#include <ViewNode.hpp>

class ProcessBarView : public ViewNode
{
public:
    ProcessBarView();
    template <typename... Args>
    ProcessBarView(Args &&...args)
        : m_bar(std::forward<Args>(args)...)
    {
        m_bar.setFillColor(sf::Color::White);
        m_bar.setOutlineColor(sf::Color::Black);
        m_bar.setOutlineThickness(1.0f);

        m_progress.setFillColor(sf::Color::Blue);
        m_progress.setOutlineColor(sf::Color(0, 0, 0, 0));
        m_progress.setOutlineThickness(-1.0f);

        setProgress(0.0f);
    }

    virtual ~ProcessBarView() final;

private:
    virtual void update(sf::Time dt) final override;
    virtual void handleEvent(sf::Event &event) final override;
    virtual void handleRealtimeInput() final override;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const final override;

public:
    virtual bool contains(sf::Vector2f point) const final override;

public:
    void setProgress(float progress);
    sf::Vector2f getSize() const;

private:
    sf::RectangleShape m_bar;
    sf::RectangleShape m_progress;
    sf::Text m_text;
    sf::Text m_name;
    float m_progressValue = 0.0f;
};
