#include <GameOverStrategy.hpp>
#include <Game.hpp>

GameOverStategy::GameOverStategy(Game* game)
    : m_game(game)
{
}

void GameOverStategy::done()
{
    std::cout << "Game Over" << std::endl;
    m_game->setDone(true);
}

Game* GameOverStategy::getGame() const
{
    return m_game;
}