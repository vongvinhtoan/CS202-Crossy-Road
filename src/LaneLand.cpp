#include <LaneLand.hpp>
#include <iostream>
#include <Utils.hpp>
#include <Context.hpp>
#include <GameOver_HitObstacleOnLand.hpp>
#include <set>

LaneLand::LaneLand(LaneType laneType, int id, Game* game, std::vector<bool> lastSafeIndexes)
    : Lane(laneType, id, game)
{
    int obstacleCount = utils::random(1, 3);
    if(id == 0)
        obstacleCount = 0;
    int maxIndex = (*Context::getInstance().getWindow()).getSize().x / 100.f;
    
    std::set<int> tmpObstacles;
    for(int i=0; i<obstacleCount; ++i)
    {
        int index = utils::random(0, maxIndex - 1);
        while(tmpObstacles.find(index) != tmpObstacles.end())
        {
            index = utils::random(0, maxIndex - 1);
        }
        tmpObstacles.insert(index);
    }
    mObstacles = std::vector<int>(tmpObstacles.begin(), tmpObstacles.end());

    std::vector<bool> allowedIndexes;
    allowedIndexes.resize(maxIndex, true);
    for(auto& index : tmpObstacles)
    {
        allowedIndexes[index] = false;
    }
    m_safeIndexes = calculateSafeIndexes(allowedIndexes, lastSafeIndexes);
}

std::vector<int> LaneLand::getObstacles() const
{
    return mObstacles;
}

void LaneLand::update(sf::Time dt)
{

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

void LaneLand::loadFromFile(std::istream& in)
{
    Lane::loadFromFile(in);
    int obstacleCount;
    in >> obstacleCount;
    mObstacles.resize(obstacleCount);
    for(int i=0; i<obstacleCount; ++i)
    {
        in >> mObstacles[i];
    }
}

std::ostream& LaneLand::saveToFile(std::ostream& out) const
{
    Lane::saveToFile(out);
    out << mObstacles.size() << " ";
    for(auto& obstacle : mObstacles)
    {
        out << obstacle << " ";
    }
    return out;
}