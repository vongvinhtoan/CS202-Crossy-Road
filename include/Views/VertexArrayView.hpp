#pragma once

#include <ViewNode.hpp>

class VertexArrayView : public ViewNode
{
public:
    template <typename... Args>
    VertexArrayView(Args &&...args)
        : m_array(std::forward<Args>(args)...)
    {
    }

    virtual ~VertexArrayView() final;

private:
    virtual void update(sf::Time dt) final override;
    virtual void handleEvent(sf::Event &event) final override;
    virtual void handleRealtimeInput() final override;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const final override;

public:
    virtual bool contains(sf::Vector2f point) const final override;
    void setFillColor(const sf::Color &color);
    sf::VertexArray &get();

private:
    sf::VertexArray m_array;
};
