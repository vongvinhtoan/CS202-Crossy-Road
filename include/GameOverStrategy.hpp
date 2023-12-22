#pragma once

#include <SFML/Graphics.hpp>

class GameOverStategy
{
public:
    GameOverStategy(bool &isDone);
public:
    virtual void update(sf::Time dt) = 0;
    virtual void handleEvent(sf::Event& event) = 0;
    virtual void handleRealtimeInput() = 0;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
protected:
    void done();
private:
    bool *m_isDone;
};