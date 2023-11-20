#include <Activities/LoadingActivity.hpp>

LoadingActivity::LoadingActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
	std::cout << "LoadingActivity::LoadingActivity()" << std::endl;

	ViewNode* textLayer = getLayer(0);
	auto text = std::make_unique<TextView>("Loading...", getContext()->getFonts()->get(FontID::Tourney_Bold), 150);
	text->setPosition(100, 100);
	textLayer->attachChild(std::move(text));
}

LoadingActivity::~LoadingActivity()
{
}

bool LoadingActivity::handleEvent(sf::Event& event)
{
	return Activity::handleEvent(event);
}

bool LoadingActivity::handleRealtimeInput()
{
	return Activity::handleRealtimeInput();
}

bool LoadingActivity::update(sf::Time dt)
{
	Activity::update(dt);
	
	m_time += dt;
	if (m_time >= m_duration) {
		finishActivity();
		requestActivity(ActivityID::Home);
	}

	return 0;
}

bool LoadingActivity::draw()
{
	return Activity::draw();
}
