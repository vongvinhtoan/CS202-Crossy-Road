#include <LaneCar.hpp>
#include <iostream>
#include <Utils.hpp>
#include <Context.hpp>
#include <GameOver_HitObstacleOnLand.hpp>

const sf::Time LaneCar::m_stopTime = sf::seconds(5.f);
const sf::Time LaneCar::m_prepareTime = sf::seconds(2.5f);

LaneCar::LaneCar(LaneType laneType, int id, Game* game, std::vector<bool> lastSafeIndexes)
    : Lane(laneType, id, game)
    , m_cars()
    , m_carSize(utils::random(1, 3))
    , m_carSpace(utils::random(4, 6))
    , m_carSpeed(utils::random(200.f, 400.f))
{
    if(utils::random(0, 1))
        m_carSpeed *= -1.f;

    m_cars.push_back(utils::random(-100.f, 100.f));
    while(m_cars.back() + m_carSize * 100.f < Context::getInstance().getWindow()->getSize().x)
    {
        m_cars.push_back(m_cars.back() + (m_carSize + m_carSpace) * 100.f);
    }

    m_safeIndexes.resize(Context::getInstance().getWindow()->getSize().x / 100.f);
    for(int i=0; i<m_safeIndexes.size(); i++)
    {
        m_safeIndexes[i] = i;
    }
}

void LaneCar::update(sf::Time dt)
{
    const double stoppingTime = 7.5f;
    const double numFrames = stoppingTime * 60.f;
    const double stoppingProbability = (numFrames - 1.f) / numFrames;
    if(utils::random(0.0, 1.0) > stoppingProbability && !m_isStopping)
    {
        m_isStopping = true;
        m_elapsedTime = sf::Time::Zero;
    }

    if(m_isStopping)
    {
        m_elapsedTime += dt;
        if(m_elapsedTime > m_stopTime)
        {
            m_isStopping = false;
            m_elapsedTime = sf::Time::Zero;
        }
    }

    removeOldCars();
    createNewCars();

    if(!m_isStopping || m_elapsedTime <= m_prepareTime)
    for(auto& car : m_cars)
    {
        car += m_carSpeed * dt.asSeconds();
    }
}

void LaneCar::removeOldCars()
{
    if(m_carSpeed < 0) while(m_cars.front() + m_carSize * 100.f < 0)
    {
        m_cars.pop_front();
    }
    else while(m_cars.back() > Context::getInstance().getWindow()->getSize().x)
    {
        m_cars.pop_back();
    }
}

void LaneCar::createNewCars()
{
    if(m_carSpeed < 0) while(m_cars.back() + m_carSize * 100.f < Context::getInstance().getWindow()->getSize().x)
    {
        m_cars.push_back(m_cars.back() + (m_carSize + m_carSpace) * 100.f);
    }
    else while(m_cars.front() > 0)
    {
        m_cars.push_front(m_cars.front() - (m_carSize + m_carSpace) * 100.f);
    }
}

GameOverStategy* LaneCar::updatePlayer(Player* player, sf::Time dt)
{
    if(isHit(player->getPosition().x))
    {
        return new GameOver_HitObstacleOnLand(getGame());
    }
    return nullptr;
}

GameOverStategy* LaneCar::moveLeft(Player* player)
{
    if(player->getPosition().x <= 0.f) 
        return nullptr;

    player->moveLeft();
    return nullptr;
}

GameOverStategy* LaneCar::moveRight(Player* player)
{
    if(player->getPosition().x + 100.f >= Context::getInstance().getWindow()->getSize().x) 
        return nullptr;
    
    player->moveRight();
    return nullptr;
}

GameOverStategy* LaneCar::enter(Player* player)
{
    sf::FloatRect playerRect = player->getBounds();
    playerRect.top = getIndex() * 100.f;
    playerRect.left = std::round(playerRect.left / 100.f) * 100.f;
    player->moveTo({playerRect.left, playerRect.top});
    player->update(sf::Time::Zero);

    if(isHit(player->getPosition().x))
    {
        return new GameOver_HitObstacleOnLand(getGame());
    }

    return nullptr;
}

bool LaneCar::isHit(float pos)
{
    for(auto& car : m_cars)
    {
        if(car >= pos + 100.f) break;
        if(pos + 100.f < car || car + m_carSize * 100.f < pos) continue;
        return true;
    }
    return false;
}

std::deque<float> LaneCar::getCars() const
{
    return m_cars;
}

int LaneCar::getCarSize() const
{
    return m_carSize;
}

int LaneCar::getCarSpace() const
{
    return m_carSpace;
}