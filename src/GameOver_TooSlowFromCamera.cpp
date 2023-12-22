#include <GameOver_TooSlowFromCamera.hpp>

GameOver_TooSlowFromCamera::GameOver_TooSlowFromCamera(bool &isDone)
: GameOverStategy(isDone)
{
}

void GameOver_TooSlowFromCamera::update(sf::Time dt)
{
    // done();
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