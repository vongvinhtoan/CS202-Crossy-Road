#pragma once

#include <GameOverStrategy.hpp>

class GameOver_TooSlowFromCamera : public GameOverStategy
{
public:
    GameOver_TooSlowFromCamera(bool &isDone);
public:
    void update(sf::Time dt) override;
    void handleEvent(sf::Event& event) override;
    void handleRealtimeInput() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};