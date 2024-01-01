#include <LaneStillWater.hpp>
#include <iostream>
#include <Utils.hpp>
#include <Context.hpp>
#include <GameOver_HitObstacleOnLand.hpp>

LaneStillWater::LaneStillWater(LaneType laneType, int id, Game* game)
    : Lane(laneType, id, game)
{

}

void LaneStillWater::update(sf::Time dt)
{

}

GameOverStategy* LaneStillWater::updatePlayer(Player* player, sf::Time dt)
{
    return nullptr;
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