#include <Activities/LoadingActivity.hpp>
#include <Utils.hpp>

LoadingActivity::LoadingActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
	std::cout << "LoadingActivity::LoadingActivity()" << std::endl;

	m_duration = sf::seconds((*getContext()->getConfigs())["loading_bar"]["duration"].asFloat());

	ViewNode* background_layer = getLayer(0);
	ViewNode* foreground_layer = getLayer(1);
	ViewNode* ui_layer = getLayer(2);

	auto window = getContext()->getWindow();
	sf::Vector2f window_size(window->getSize());

	// background_layer
	auto background = std::make_unique<RectangleView>(window_size);
	background->get().setFillColor(utils::hexToColor("#8FE254"));
	background_layer->attachChild(std::move(background));

	// foreground_layer
	auto foreground = std::make_unique<RectangleView>(sf::Vector2f(1035.174, 900));
	auto& foreground_shape = foreground->get();
	foreground_shape.setTexture(&getContext()->getTextures()->get(TextureID::LoadingScreen));
	foreground_shape.setOrigin(foreground_shape.getSize() / 2.f);
	foreground_shape.setPosition(window_size / 2.f); 
	foreground_layer->attachChild(std::move(foreground));

	// ui_layer
	auto loading_bar = std::make_unique<LoadingBarView>(sf::Vector2f(450, 50));
	loading_bar->setOrigin(loading_bar->getSize() / 2.f);
	loading_bar->setPosition(sf::Vector2f(
		window_size.x / 2.f,
		window_size.y - 108.f - loading_bar->getSize().y / 2.f
	));
	m_loading_bar = loading_bar.get();
	ui_layer->attachChild(std::move(loading_bar));
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
	if (m_time >= m_duration)
	{
		finishActivity();
		requestActivity(ActivityID::Home);
	}
	else
	{
		m_loading_bar->setProgress(utils::lerp(0.f, 1.f, m_time.asSeconds() / m_duration.asSeconds(), utils::anim::bounce_out));
	}

	return 0;
}

bool LoadingActivity::draw()
{
	return Activity::draw();
}
