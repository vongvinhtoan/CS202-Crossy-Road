#pragma once

#include <Lane.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class LaneTrain : public Lane
{
public:
    LaneTrain(LaneType laneType, int id, Game* game, std::vector<bool> lastSafeIndexes);

public:
    void update(sf::Time dt) override;

public:
    GameOverStategy* moveLeft(Player* player) override;
    GameOverStategy* moveRight(Player* player) override;
    GameOverStategy* enter(Player* player) override;
    GameOverStategy* updatePlayer(Player* player, sf::Time dt) override;

public:
    enum class Direction
    {
        Left,
        Right
    };

public:
    bool isWarning() const;
    Direction getDirection() const;
    float getPosition() const;
    int getSize() const;

private:
    bool trainMovedOutOfWindow() const;
    bool trainIsVisibleOnScreen() const;
    bool isHit(float pos);

private:
    float               m_position;
    int                 m_size;
    Direction           m_direction;
    sf::Time            m_elapsedTime;
    bool                m_isTriggered;

private:
    const static float  m_speed;
};