#include <Activities/InstructionActivity.hpp>

InstructionActivity::InstructionActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
}

InstructionActivity::~InstructionActivity()
{
}

bool InstructionActivity::handleEvent(sf::Event& event)
{
	return Activity::handleEvent(event);
}

bool InstructionActivity::handleRealtimeInput()
{
	return Activity::handleRealtimeInput();
}

bool InstructionActivity::update(sf::Time dt)
{
	return Activity::update(dt);
}

bool InstructionActivity::draw()
{
	return Activity::draw();
}
