#include <LaneWater.hpp>
#include <Player.hpp>
#include <cmath>

LaneWater::LaneWater(LaneType laneType, int id, Game* game)
    : Lane(laneType, id, game)
{
}

void LaneWater::update(sf::Time dt)
{
}

GameOverStategy* LaneWater::moveLeft(Player* player, bool& isDone)
{
    player->moveLeft();
    return nullptr;
}

GameOverStategy* LaneWater::moveRight(Player* player, bool& isDone)
{
    player->moveRight();
    return nullptr;
}

GameOverStategy* LaneWater::enter(Player* player, bool& isDone)
{
    sf::FloatRect playerRect = player->getBounds();
    playerRect.top = getIndex() * 100.f;
    playerRect.left = std::round(playerRect.left / 100.f) * 100.f;
    player->moveTo({playerRect.left, playerRect.top});
    return nullptr;
}

GameOverStategy* LaneWater::checkCollision(Player* player, bool& isDone)
{
    return nullptr;
}