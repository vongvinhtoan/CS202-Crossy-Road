#include <GameOverStrategy.hpp>

GameOverStategy::GameOverStategy(bool &isDone)
: m_isDone(&isDone)
{
}

void GameOverStategy::done()
{
    *m_isDone = true;
}