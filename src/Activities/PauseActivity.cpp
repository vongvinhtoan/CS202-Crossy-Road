#include <Activities/PauseActivity.hpp>

PauseActivity::PauseActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
	std::cout << "PauseActivity::PauseActivity()" << std::endl;

	auto window = getContext()->getWindow();
	sf::Vector2f window_size(window->getSize());

	auto& configs = (*getContext()->getConfigs())["count_down_time"];
	int count_down_time = configs.asInt();

	// background_layer
	ViewNode* background_layer = getLayer(0);
	//Game-over-background
	auto coveringRectangle = std::make_unique<RectangleView>(window_size);
	coveringRectangle->get().setFillColor(utils::hexToColor("0085FF00"));
	m_background = coveringRectangle.get();

	background_layer->attachChild(std::move(coveringRectangle));

	// foreground_layer
	ViewNode* foreground_layer = getLayer(1);

	//resume_button
	auto resume_button = std::make_unique<RoundedCornerButtonView>(sf::Vector2f(440, 100));
	resume_button->get().setFillColor(utils::hexToColor("FFFFF0000"));
	resume_button->get().setPosition(sf::Vector2f(591, 251));

	foreground_layer->attachChild(std::move(resume_button));

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
	Activity::update(dt);

	m_elapsedTime += dt;

	if(m_elapsedTime <= sf::seconds(1.f))
	{
		auto duration = 1.f;
		auto color = m_background->get().getFillColor();
		color.a = 0.81 * 255 * m_elapsedTime.asSeconds() / duration;
		m_background->get().setFillColor(color);
	}

	return 0;
}

bool PauseActivity::draw()
{
	return Activity::draw();
}
