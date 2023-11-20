#include <Activities/PauseActivity.hpp>

PauseActivity::PauseActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
}

PauseActivity::~PauseActivity()
{
}

bool PauseActivity::handleEvent(sf::Event& event)
{
	return Activity::handleEvent(event);
}

bool PauseActivity::handleRealtimeInput()
{
	return Activity::handleRealtimeInput();
}

bool PauseActivity::update(sf::Time dt)
{
	return Activity::update(dt);
}

bool PauseActivity::draw()
{
	return Activity::draw();
}
