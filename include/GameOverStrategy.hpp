#pragma once

#include <SFML/Graphics.hpp>

class Game;

class GameOverStategy
{
public:
    GameOverStategy(Game* game);
public:
    virtual void update(sf::Time dt) = 0;
    virtual void handleEvent(sf::Event& event) = 0;
    virtual void handleRealtimeInput() = 0;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
protected:
    void done();
    Game* getGame() const;
private:
    Game* m_game;
};