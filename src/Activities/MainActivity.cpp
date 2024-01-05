#include <Activities/MainActivity.hpp>
#include <Utils.hpp>

MainActivity::MainActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
	std::cout << "MainActivity::MainActivity()" << std::endl;
	requestActivity(ActivityID::Home);
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
	Activity::update(dt);
	return 0;
}

bool MainActivity::draw()
{
	return Activity::draw();
}

void MainActivity::onActivityResult(int resultCode, Extra* extra)
{
}