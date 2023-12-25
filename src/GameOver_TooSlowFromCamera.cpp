#include <GameOver_TooSlowFromCamera.hpp>
#include <Game.hpp>

GameOver_TooSlowFromCamera::GameOver_TooSlowFromCamera(Game* game)
    : GameOverStategy(game)
{
}

void GameOver_TooSlowFromCamera::update(sf::Time dt)
{
    getGame()->setDone(true);
}

void GameOver_TooSlowFromCamera::handleEvent(sf::Event& event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Escape)
        {
            done();
        }
    }
}

void GameOver_TooSlowFromCamera::handleRealtimeInput()
{
}

void GameOver_TooSlowFromCamera::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}