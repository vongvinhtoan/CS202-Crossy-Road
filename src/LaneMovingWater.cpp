#include <LaneMovingWater.hpp>
#include <Player.hpp>
#include <cmath>
#include <Utils.hpp>
#include <Context.hpp>
#include <iostream>
#include <GameOver_HitObstacleOnLand.hpp>

LaneMovingWater::LaneMovingWater(LaneType laneType, int id, Game* game, std::vector<bool> lastSafeIndexes)
    : Lane(laneType, id, game)
    , m_speed(utils::random(100.f, 200.f))
    , m_elapsedTime(sf::Time::Zero)
    , m_woodPositions()
{
    m_safeIndexes.clear();
    m_safeIndexes.resize(Context::getInstance().getWindow()->getSize().x / 100.f, true);
    
    if(utils::random(0, 1))
        m_speed *= -1.f;

    m_woodPositions.push_back({utils::random(-100.f, 100.f), 0});
    m_woodPositions[0].second = m_woodPositions[0].first + utils::random(2, 4) * 100;

    while(m_woodPositions.back().second < Context::getInstance().getWindow()->getSize().x)
    {
        std::pair<float, float> new_wood;
        auto lastWood = m_woodPositions.back().second;

        new_wood.first = lastWood + utils::random(3, 5) * 100;
        new_wood.second = new_wood.first + utils::random(2, 4) * 100;

        m_woodPositions.push_back(new_wood);
    }
}

void LaneMovingWater::update(sf::Time dt)
{
    m_elapsedTime += dt;

    removeOldWoods();
    createNewWoods();

    for(auto& wood : m_woodPositions)
    {
        wood.first += m_speed * dt.asSeconds();
        wood.second += m_speed * dt.asSeconds();
    }
}

void LaneMovingWater::removeOldWoods()
{
    if(m_speed < 0) while(m_woodPositions.front().second < 0)
    {
        m_woodPositions.pop_front();
    }
    else while(m_woodPositions.back().first > Context::getInstance().getWindow()->getSize().x)
    {
        m_woodPositions.pop_back();
    }
}

void LaneMovingWater::createNewWoods()
{
    if(m_speed < 0) while(m_woodPositions.back().second < Context::getInstance().getWindow()->getSize().x)
    {
        std::pair<float, float> new_wood;
        auto lastWood = m_woodPositions.back().second;

        new_wood.first = lastWood + utils::random(3, 5) * 100;
        new_wood.second = new_wood.first + utils::random(2, 4) * 100;

        m_woodPositions.push_back(new_wood);
    }
    else while(m_woodPositions.front().second > 0)
    {
        std::pair<float, float> new_wood;
        auto lastWood = m_woodPositions.front().first;

        new_wood.second = lastWood - utils::random(3, 5) * 100;
        new_wood.first = new_wood.second - utils::random(2, 4) * 100;

        m_woodPositions.push_front(new_wood);
    }
}

GameOverStategy* LaneMovingWater::moveLeft(Player* player)
{
    player->moveLeft();
    return nullptr;
}

GameOverStategy* LaneMovingWater::moveRight(Player* player)
{
    player->moveRight();
    return nullptr;
}

GameOverStategy* LaneMovingWater::enter(Player* player)
{
    sf::FloatRect playerRect = player->getBounds();
    playerRect.top = getIndex() * 100.f;
    
    float pos = playerRect.left;

    auto anyWood = m_woodPositions[0];
    pos = std::round((pos - anyWood.first) / 100.f) * 100.f + anyWood.first;

    playerRect.left = pos;
    player->moveTo({playerRect.left, playerRect.top});

    return nullptr;
}

GameOverStategy* LaneMovingWater::updatePlayer(Player* player, sf::Time dt)
{
    auto pos = player->getPosition().x;
    pos += m_speed * dt.asSeconds();
    pos = std::round((pos - m_woodPositions[0].first) / 100.f) * 100.f + m_woodPositions[0].first;
    player->moveTo({pos, player->getPosition().y});
    player->update(dt);

    bool isOnWood = false;
    for(auto& wood : m_woodPositions)
    {
        if(pos < wood.first-50.f) break;
        if(wood.first-50.f <= pos && pos <= wood.second-50.f)
        {
            isOnWood = true;
            break;
        }
    }
    if(!isOnWood)
    {
        for(auto& wood : m_woodPositions)
        return new GameOver_HitObstacleOnLand(getGame());
    }

    if(player->getPosition().x < - 50.f || player->getPosition().x + 50.f > Context::getInstance().getWindow()->getSize().x)
    {
        return new GameOver_HitObstacleOnLand(getGame());
    }
    return nullptr;
}

std::deque<std::pair<float, float>> LaneMovingWater::getWoodPositions()
{
    return m_woodPositions;
}