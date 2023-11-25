#include <Activities/GameOverActivity.hpp>

GameOverActivity::GameOverActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
}

GameOverActivity::~GameOverActivity()
{
}

bool GameOverActivity::handleEvent(sf::Event& event)
{
	return Activity::handleEvent(event);
}

bool GameOverActivity::handleRealtimeInput()
{
	return Activity::handleRealtimeInput();
}

bool GameOverActivity::update(sf::Time dt)
{
	return Activity::update(dt);
}

bool GameOverActivity::draw()
{
	return Activity::draw();
}