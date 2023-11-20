#include <Activities/CharacterActivity.hpp>

CharacterActivity::CharacterActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
}

CharacterActivity::~CharacterActivity()
{
}

bool CharacterActivity::handleEvent(sf::Event& event)
{
	return Activity::handleEvent(event);
}

bool CharacterActivity::handleRealtimeInput()
{
	return Activity::handleRealtimeInput();
}

bool CharacterActivity::update(sf::Time dt)
{
	return Activity::update(dt);
}

bool CharacterActivity::draw()
{
	return Activity::draw();
}
