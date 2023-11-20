#include <Activities/SettingActivity.hpp>

SettingActivity::SettingActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
}

SettingActivity::~SettingActivity()
{
}

bool SettingActivity::handleEvent(sf::Event& event)
{
	return Activity::handleEvent(event);
}

bool SettingActivity::handleRealtimeInput()
{
	return Activity::handleRealtimeInput();
}

bool SettingActivity::update(sf::Time dt)
{
	return Activity::update(dt);
}

bool SettingActivity::draw()
{
	return Activity::draw();
}
