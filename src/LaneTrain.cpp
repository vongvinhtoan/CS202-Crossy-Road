#include <LaneTrain.hpp>
#include <iostream>
#include <Utils.hpp>
#include <Context.hpp>
#include <GameOver_HitObstacleOnLand.hpp>

LaneTrain::LaneTrain(LaneType laneType, int id, Game* game)
    : Lane(laneType, id, game)
{

}

void LaneTrain::update(sf::Time dt)
{

}

GameOverStategy* LaneTrain::updatePlayer(Player* player, sf::Time dt)
{
    return nullptr;
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