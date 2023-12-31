#include <Activities/MainActivity.hpp>
#include <Utils.hpp>

MainActivity::MainActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
	std::cout << "MainActivity::MainActivity()" << std::endl;
	//requestActivity(ActivityID::Playground);

	// auto window = getContext()->getWindow();
	// sf::Vector2f window_size(window->getSize());

	// // covering_layer
	// ViewNode* covering_layer = getLayer(0);
	// //Game-over-screen
	// auto coveringRectangle = std::make_unique<RectangleView>(window_size);
	// // coveringRectangle->get().setFillColor(utils::hexToColor("FF5631"));
	// coveringRectangle->get().setTexture(&getContext()->getTextures()->get(TextureID::BackGroundScreen));

	// covering_layer->attachChild(std::move(coveringRectangle));

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
	//Game-over
	static const sf::Time m_duration = sf::seconds(1.f);
	m_time += dt;
	if (m_time >= m_duration)
	{
		requestActivity(ActivityID::GameOver);
		m_time = sf::Time::Zero;
	}

	//return Activity::update(dt);
	return 0;
}

bool MainActivity::draw()
{
	return Activity::draw();
}

void MainActivity::onActivityResult(int resultCode, Extra* extra)
{
	requestActivity(ActivityID::Playground);
}