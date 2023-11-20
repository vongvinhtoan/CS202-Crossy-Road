#include <Activities/PlaygroundActivity.hpp>

PlaygroundActivity::PlaygroundActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
}

PlaygroundActivity::~PlaygroundActivity()
{
}

bool PlaygroundActivity::handleEvent(sf::Event& event)
{
	return Activity::handleEvent(event);
}

bool PlaygroundActivity::handleRealtimeInput()
{
	return Activity::handleRealtimeInput();
}

bool PlaygroundActivity::update(sf::Time dt)
{
	return Activity::update(dt);
}

bool PlaygroundActivity::draw()
{
	return Activity::draw();
}
