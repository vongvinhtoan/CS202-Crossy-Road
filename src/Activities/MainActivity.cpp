#include <Activities/MainActivity.hpp>
#include <Utils.hpp>

MainActivity::MainActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
	requestActivity(ActivityID::Setting);
}

MainActivity::~MainActivity()
{
}

bool MainActivity::handleEvent(sf::Event& event)
{
	return Activity::handleEvent(event);
}

bool MainActivity::handleRealtimeInput()
{
	return Activity::handleRealtimeInput();
}

bool MainActivity::update(sf::Time dt)
{
	return Activity::update(dt);
}

bool MainActivity::draw()
{
	return Activity::draw();
}
