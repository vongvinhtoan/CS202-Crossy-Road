#pragma once

#include <ViewNode.hpp>

class MovingSquare : public ViewNode
{
public:
    MovingSquare(sf::FloatRect bounds);
    virtual ~MovingSquare() final;

private:
    virtual void update(sf::Time dt) final override;
    virtual void handleEvent(sf::Event& event) final override;
    virtual void handleRealtimeInput() final override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;

public:
    virtual bool contains(sf::Vector2f point) const final;
    sf::Vector2f getVelocity() const;
    void setVelocity(const sf::Vector2f& velocity);

private:
    std::unique_ptr<sf::RectangleShape> m_square;
    sf::Vector2f m_velocity = { 100.f, 100.f };
    sf::FloatRect m_bounds;
};