#include <GameOverStrategy.hpp>
#include <Game.hpp>

GameOverStategy::GameOverStategy(Game* game)
    : m_game(game)
{
}

void GameOverStategy::done()
{
    m_game->setDone(true);
}

Game* GameOverStategy::getGame() const
{
    return m_game;
}