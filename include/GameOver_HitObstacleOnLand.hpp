#pragma once

#include <SFML/Graphics.hpp>
#include <GameOverStrategy.hpp>
#include <PlaygroundAdapter.hpp>

class GameOver_HitObstacleOnLand : public GameOverStategy
{
public:
    GameOver_HitObstacleOnLand(Game* game);

public:
    virtual void update(sf::Time dt) override;
    virtual void handleEvent(sf::Event& event) override;
    virtual void handleRealtimeInput() override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Time                    m_animationTime;
    sf::Time                    m_elapsedTime;
    sf::RectangleShape          m_overlay;
    sf::Vector2f                m_velocity;
    const static sf::Vector2f   m_acceleration;
};