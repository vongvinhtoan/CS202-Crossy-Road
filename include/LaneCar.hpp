#pragma once

#include <Lane.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <deque>

class LaneCar : public Lane
{
public:
    LaneCar(LaneType laneType, int id, Game* game, std::vector<bool> lastSafeIndexes);

public:
    void update(sf::Time dt) override;

public:
    GameOverStategy* moveLeft(Player* player) override;
    GameOverStategy* moveRight(Player* player) override;
    GameOverStategy* enter(Player* player) override;
    GameOverStategy* updatePlayer(Player* player, sf::Time dt) override;
    void loadFromFile(std::istream& in) override;
    std::ostream& saveToFile(std::ostream& out) const override;

public:
    std::deque<float> getCars() const;
    int getCarSize() const;
    int getCarSpace() const;
    int getDirection() const;
    bool isStopping() const;
    bool isStopped() const;

private:
    void removeOldCars();
    void createNewCars();
    bool isHit(float pos);

private:
    std::deque<float>   m_cars;
    int                 m_carSize;
    int                 m_carSpace;
    float               m_carSpeed;
    bool                m_isStopping;
    sf::Time            m_elapsedTime;

private:
    static const sf::Time   m_prepareTime;
    static const sf::Time   m_stopTime;
};