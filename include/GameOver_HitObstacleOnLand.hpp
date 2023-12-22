#pragma once

#include <SFML/Graphics.hpp>
#include <GameOverStrategy.hpp>

class GameOver_HitObstacleOnLand : public GameOverStategy
{
public:
    GameOver_HitObstacleOnLand(bool& isDone);

public:
    virtual void update(sf::Time dt) override;
    virtual void handleEvent(sf::Event& event) override;
    virtual void handleRealtimeInput() override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};