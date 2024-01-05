#include <LaneStillWater.hpp>
#include <iostream>
#include <Utils.hpp>
#include <Context.hpp>
#include <GameOver_HitObstacleOnLand.hpp>
#include <set>

LaneStillWater::LaneStillWater(LaneType laneType, int id, Game* game, std::vector<bool> lastSafeIndexes)
    : Lane(laneType, id, game)
{
    std::set<int> tmpLeafs;
    int maxIndex = (*Context::getInstance().getWindow()).getSize().x / 100.f;

    const static std::function<std::vector<bool>(std::vector<int>)> markIndexes = [&](std::vector<int> indexes) {
        std::vector<bool> allowedIndexes;
        allowedIndexes.resize(maxIndex, false);
        for(auto& index : indexes)
        {
            allowedIndexes[index] = true;
        }
        return allowedIndexes;
    };

    while(isLegitIndexes(
            calculateSafeIndexes(
                markIndexes(std::vector<int>(tmpLeafs.begin(), tmpLeafs.end())),
                lastSafeIndexes
            )
          ) == false
    ) {
        auto index = utils::random(0, maxIndex - 1);
        while(tmpLeafs.find(index) != tmpLeafs.end())
        {
            index = utils::random(0, maxIndex - 1);
        }
        tmpLeafs.insert(index);
    }

    auto capLeaf = utils::random(2, maxIndex / 2);
    while(tmpLeafs.size() < capLeaf)
    {
        auto index = utils::random(0, maxIndex - 1);
        while(tmpLeafs.find(index) != tmpLeafs.end())
        {
            index = utils::random(0, maxIndex - 1);
        }
        tmpLeafs.insert(index);
    }

    m_safeIndexes = calculateSafeIndexes(
        markIndexes(std::vector<int>(tmpLeafs.begin(), tmpLeafs.end())),
        lastSafeIndexes
    );
    m_leafs = std::vector<int>(tmpLeafs.begin(), tmpLeafs.end());
}

void LaneStillWater::update(sf::Time dt)
{

}

GameOverStategy* LaneStillWater::updatePlayer(Player* player, sf::Time dt)
{
    sf::FloatRect playerRect = player->getBounds();
    for (int i = 0; i < m_leafs.size(); i++)
    {
        sf::FloatRect obstacleRect = sf::FloatRect(m_leafs[i] * 100.f + 25.f, getIndex() * 100.f + 25.f, 50.f, 50.f);
        if (playerRect.intersects(obstacleRect))
        {
            return nullptr;
        }
    }
    if(player->getTexture() == &Context::getInstance().getTextures()->get(TextureID::CharacterPenguin))
        return nullptr;
    return new GameOver_HitObstacleOnLand(getGame());
}

GameOverStategy* LaneStillWater::moveLeft(Player* player)
{
    if(player->getPosition().x <= 0.f) 
        return nullptr;

    player->moveLeft();
    return nullptr;
}

GameOverStategy* LaneStillWater::moveRight(Player* player)
{
    if(player->getPosition().x + 100.f >= Context::getInstance().getWindow()->getSize().x) 
        return nullptr;
    
    player->moveRight();
    return nullptr;
}

GameOverStategy* LaneStillWater::enter(Player* player)
{
    sf::FloatRect playerRect = player->getBounds();
    playerRect.top = getIndex() * 100.f;
    playerRect.left = std::round(playerRect.left / 100.f) * 100.f;
    player->moveTo({playerRect.left, playerRect.top});
    return nullptr;
}

std::vector<int> LaneStillWater::getLeafs() const
{
    return m_leafs;
}

void LaneStillWater::loadFromFile(std::istream& in)
{
    Lane::loadFromFile(in);
    int leafsCount;
    in >> leafsCount;
    m_leafs.resize(leafsCount);
    for(int i = 0; i < leafsCount; ++i)
    {
        in >> m_leafs[i];
    }
}

std::ostream& LaneStillWater::saveToFile(std::ostream& out) const
{
    Lane::saveToFile(out);
    out << m_leafs.size() << std::endl;
    for(auto& leaf : m_leafs)
    {
        out << leaf << std::endl;
    }
    return out;
}