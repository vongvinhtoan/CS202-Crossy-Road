#include <LaneLand.hpp>
#include <iostream>
#include <Utils.hpp>
#include <Context.hpp>
#include <GameOver_HitObstacleOnLand.hpp>

LaneLand::LaneLand(LaneType laneType, int id, Game* game)
    : Lane(laneType, id, game)
    , mElapsedTime(sf::Time::Zero)
{
    int obstacleCount = utils::random(1, 3);
    if(id == 0)
        obstacleCount = 0;
    int maxIndex = (*Context::getInstance().getWindow()).getSize().x / 100.f;
    for (int i = 0; i < obstacleCount; i++)
    {
        int obstacle = utils::random(0, maxIndex-1);
        mOriginalObstacles.push_back(obstacle);
        mObstacles.push_back(obstacle);
    }
}

std::vector<float> LaneLand::getObstacles() const
{
    return mObstacles;
}

void LaneLand::update(sf::Time dt)
{
    mElapsedTime += dt;
    while (mElapsedTime.asSeconds() > 2.f)
        mElapsedTime -= sf::seconds(2.f);
    for(int i=0; i<mObstacles.size(); ++i)
    {
        auto& obstacle = mObstacles[i];
        auto& originalObstacle = mOriginalObstacles[i];
        // obstacle = originalObstacle + mElapsedTime.asSeconds();
    }
}

GameOverStategy* LaneLand::updatePlayer(Player* player, sf::Time dt)
{
    sf::FloatRect playerRect = player->getBounds();
    for (int i = 0; i < mObstacles.size(); i++)
    {
        sf::FloatRect obstacleRect = sf::FloatRect(mObstacles[i] * 100.f + 25.f, getIndex() * 100.f + 25.f, 50.f, 50.f);
        if (playerRect.intersects(obstacleRect))
        {
            return new GameOver_HitObstacleOnLand(getGame());
        }
    }
    return nullptr;
}

GameOverStategy* LaneLand::moveLeft(Player* player)
{
    if(player->getPosition().x <= 0.f) 
        return nullptr;

    player->moveLeft();
    auto* gameOverStrategy = updatePlayer(player, sf::Time::Zero);
    if (gameOverStrategy)
    {
        return gameOverStrategy;
    }
    return nullptr;
}

GameOverStategy* LaneLand::moveRight(Player* player)
{
    if(player->getPosition().x + 100.f >= Context::getInstance().getWindow()->getSize().x) 
        return nullptr;
    
    player->moveRight();
    auto* gameOverStrategy = updatePlayer(player, sf::Time::Zero);
    if (gameOverStrategy)
    {
        return gameOverStrategy;
    }
    return nullptr;
}

GameOverStategy* LaneLand::enter(Player* player)
{
    sf::FloatRect playerRect = player->getBounds();
    playerRect.top = getIndex() * 100.f;
    playerRect.left = std::round(playerRect.left / 100.f) * 100.f;
    player->moveTo({playerRect.left, playerRect.top});
    auto* gameOverStrategy = updatePlayer(player, sf::Time::Zero);
    if (gameOverStrategy)
    {
        return gameOverStrategy;
    }
    return nullptr;
}