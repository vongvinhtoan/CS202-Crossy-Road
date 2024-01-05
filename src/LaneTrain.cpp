#include <LaneTrain.hpp>
#include <iostream>
#include <Utils.hpp>
#include <Context.hpp>
#include <GameOver_HitObstacleOnLand.hpp>

const float LaneTrain::m_speed = 1500.f;

LaneTrain::LaneTrain(LaneType laneType, int id, Game* game, std::vector<bool> lastSafeIndexes)
    : Lane(laneType, id, game)
    , m_position(Context::getInstance().getWindow()->getSize().x)
    , m_size(utils::random(20, 30))
    , m_direction(utils::random(0, 1) ? Direction::Left : Direction::Right)
    , m_elapsedTime(sf::Time::Zero)
    , m_isTriggered(false)
{
    m_safeIndexes.clear();
    m_safeIndexes.resize(Context::getInstance().getWindow()->getSize().x / 100.f, true);
}

void LaneTrain::update(sf::Time dt)
{
    const double expectedTriggerTime = 7.5f;
    const double numFrames = expectedTriggerTime * 60.f;
    const double stoppingProbability = (numFrames - 1.f) / numFrames;

    if(utils::random(0.0, 1.0) > stoppingProbability && !m_isTriggered)
    {
        m_isTriggered = true;
        std::cout << "Train triggered" << std::endl;
        Context::getInstance().getSounds()->play(SoundEffect::TrainHorn);
        m_elapsedTime = sf::Time::Zero;
        m_position = m_direction == Direction::Left ? Context::getInstance().getWindow()->getSize().x : (-100.f * m_size);
    }

    if(m_isTriggered)
    {
        m_elapsedTime += dt;
        if(!isWarning()) 
        {
            if(trainMovedOutOfWindow())
            {
                m_isTriggered = false;
                m_elapsedTime = sf::Time::Zero;
                m_position = Context::getInstance().getWindow()->getSize().x;
            }
            else
            {
                m_position += m_direction == Direction::Left ? -m_speed * dt.asSeconds() : m_speed * dt.asSeconds();
            }
        }
    }

}

bool LaneTrain::trainMovedOutOfWindow() const
{
    return m_direction == Direction::Left ? m_position + 100.f * m_size < 0.f : m_position > Context::getInstance().getWindow()->getSize().x;
}

bool LaneTrain::isWarning() const
{
    const static sf::Time warningStamp = sf::seconds(2.5f);
    return m_elapsedTime < warningStamp;
}

GameOverStategy* LaneTrain::updatePlayer(Player* player, sf::Time dt)
{
    if(isHit(player->getPosition().x))
    {
        return new GameOver_HitObstacleOnLand(getGame());
    }
    return nullptr;
}

bool LaneTrain::isHit(float pos)
{
    if(pos + 100.f <= m_position || pos >= m_position + 100.f * m_size) return false;
    return true;
}

GameOverStategy* LaneTrain::moveLeft(Player* player)
{
    if(player->getPosition().x <= 0.f) 
        return nullptr;

    player->moveLeft();
    return nullptr;
}

GameOverStategy* LaneTrain::moveRight(Player* player)
{
    if(player->getPosition().x + 100.f >= Context::getInstance().getWindow()->getSize().x) 
        return nullptr;
    
    player->moveRight();
    return nullptr;
}

GameOverStategy* LaneTrain::enter(Player* player)
{
    sf::FloatRect playerRect = player->getBounds();
    playerRect.top = getIndex() * 100.f;
    playerRect.left = std::round(playerRect.left / 100.f) * 100.f;
    player->moveTo({playerRect.left, playerRect.top});
    return nullptr;
}

LaneTrain::Direction LaneTrain::getDirection() const
{
    return m_direction;
}

float LaneTrain::getPosition() const
{
    return m_position;
}

int LaneTrain::getSize() const
{
    return m_size;
}

void LaneTrain::loadFromFile(std::istream& in)
{
    Lane::loadFromFile(in);
    int size;
    in >> size;
    m_size = size;
    int direction;
    in >> direction;
    m_direction = static_cast<Direction>(direction);

    in >> m_isTriggered;
    float elapsedTime;
    in >> elapsedTime;
    m_elapsedTime = sf::seconds(elapsedTime);
}

std::ostream& LaneTrain::saveToFile(std::ostream& out) const
{
    Lane::saveToFile(out);
    out << m_size << " ";
    out << static_cast<int>(m_direction) << " ";
    out << m_isTriggered << " ";
    out << m_elapsedTime.asSeconds() << " ";
    return out;
}