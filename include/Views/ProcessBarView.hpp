#pragma once

#include <ViewNode.hpp>
#include <iostream>

class VertexArrayView;

class ProcessBarView : public ViewNode
{
public:
    ProcessBarView();
    ProcessBarView(const sf::Vector2f &size);

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
    float getProgress() const;
    sf::Vector2f getSize() const;
    void setTextFont(const sf::Font &font, unsigned int characterSize = 30);
    void onValueChange(std::function<void(float)> callback);

    template <typename... Args>
    void setName(Args &&...args)
    {
        m_name = sf::Text(std::forward<Args>(args)...);
        m_name.setFillColor(sf::Color::Black);
    }

private:
    sf::RectangleShape m_bar;
    sf::RectangleShape m_progress;
    sf::Text m_text;
    sf::Text m_name;
    VertexArrayView *m_left_arrow;
    VertexArrayView *m_right_arrow;

private:
    std::function<void(float)> m_onValueChange;
    float m_progressValue;
};