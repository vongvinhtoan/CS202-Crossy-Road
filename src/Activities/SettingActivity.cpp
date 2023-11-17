#include <Activities/SettingActivity.hpp>

SettingActivity::SettingActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
	sf::Vector2f moving_position;
	sf::Vector2f moving_velocity(100.f, 100.f);
	if(requestCode == 1) {
		moving_position = intent.getExtra<sf::Vector2f>("moving_position");
		moving_velocity = intent.getExtra<sf::Vector2f>("moving_velocity");
	}

	ViewNode* layer0 = getLayer(0);
	auto window_size_u = getContext()->getWindow()->getSize();
	sf::Vector2f window_size(window_size_u.x, window_size_u.y);
	auto background = std::make_unique<RectangleView>(sf::RectangleShape(window_size));
	background->get().setFillColor(sf::Color::Blue);
	layer0->attachChild(std::move(background));
	getViewRoot()->setPosition(sf::Vector2f(window_size.x, 0));

    ViewNode* layer1 = getLayer(1);
    auto window = getContext()->getWindow();
	auto moving = std::make_unique<MovingSquare>(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
	moving->setPosition(moving_position);
	moving->setVelocity(moving_velocity);
	moving->setOnClick([this](ViewNode& node) {
		finishActivity();
	});

	auto text_goToSetting = std::make_unique<TextView>(sf::Text("Back to Menu", getContext()->getFonts()->get(FontID::Main), 30));
	text_goToSetting->setOnClick([this](ViewNode& node) {
		finishActivity();
	});

	moving->attachChild(std::move(text_goToSetting));
    layer1->attachChild(std::move(moving));

	ViewNode* layer2 = getLayer(2);
	layer2->attachChild(std::make_unique<TextView>(sf::Text("Setting", getContext()->getFonts()->get(FontID::Main), 30)));
}

SettingActivity::~SettingActivity()
{
}

bool SettingActivity::handleEvent(sf::Event& event)
{
	Activity::handleEvent(event);
	return false;
}

bool SettingActivity::handleRealtimeInput()
{
	Activity::handleRealtimeInput();
	return false;
}

bool SettingActivity::update(sf::Time dt)
{
	ViewNode* root = getViewRoot();
	const static sf::Time introAnimationTime = sf::seconds(1.0f);
	if(t + dt <= introAnimationTime)
		t += dt;
	float window_width = getContext()->getWindow()->getSize().x;
	const std::function<float(float)> lerp = [](float t) {
		const float n1 = 7.5625f;
		const float d1 = 2.75f;

		if (t < 1 / d1)
			return n1 * t * t;
		else if (t < 2 / d1)
			return n1 * (t -= 1.5f / d1) * t + 0.75f;
		else if (t < 2.5 / d1)
			return n1 * (t -= 2.25f / d1) * t + 0.9375f;
		else
			return n1 * (t -= 2.625f / d1) * t + 0.984375f;
	};
	root->setPosition(sf::Vector2f((1 - lerp(t.asSeconds() / introAnimationTime.asSeconds())) * window_width, 0));

	return Activity::update(dt);
}

bool SettingActivity::draw()
{
	// getContext()->getWindow()->clear(sf::Color::Blue);
	Activity::draw();
	return true;
}
