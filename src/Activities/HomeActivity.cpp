#include <Activities/HomeActivity.hpp>

HomeActivity::HomeActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
	std::cout << "HomeActivity::HomeActivity()" << std::endl;

	ViewNode* textLayer = getLayer(0);
	auto text = std::make_unique<TextView>(sf::Text("Home!!!", getContext()->getFonts()->get(FontID::Main), 30));
	text->setPosition(100, 100);
	textLayer->attachChild(std::move(text));
}

HomeActivity::~HomeActivity()
{
}

bool HomeActivity::handleEvent(sf::Event& event)
{
	return Activity::handleEvent(event);
}

bool HomeActivity::handleRealtimeInput()
{
	return Activity::handleRealtimeInput();
}

bool HomeActivity::update(sf::Time dt)
{
	return Activity::update(dt);
}

bool HomeActivity::draw()
{
	return Activity::draw();
}
