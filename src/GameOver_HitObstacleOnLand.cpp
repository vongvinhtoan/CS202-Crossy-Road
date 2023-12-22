#include <GameOver_HitObstacleOnLand.hpp>

GameOver_HitObstacleOnLand::GameOver_HitObstacleOnLand(bool& isDone)
: GameOverStategy(isDone)
{
}

void GameOver_HitObstacleOnLand::update(sf::Time dt)
{
    // done();
}

void GameOver_HitObstacleOnLand::handleEvent(sf::Event& event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Escape)
        {
            done();
        }
    }
}

void GameOver_HitObstacleOnLand::handleRealtimeInput()
{
}

void GameOver_HitObstacleOnLand::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}