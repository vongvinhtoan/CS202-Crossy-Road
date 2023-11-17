#include <Activities/SettingActivity.hpp>

SettingActivity::SettingActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
    ViewNode* layer0 = getLayer(0);
    auto window = getContext()->getWindow();
	auto moving = std::make_unique<MovingSquare>(sf::FloatRect(0.f, 0.f, window->getSize().x, window->getSize().y));
	moving->setOnClick([this](ViewNode& node) {
		finishActivity();
	});

	auto text_goToSetting = std::make_unique<TextView>(sf::Text("Back to Menu", getContext()->getFonts()->get(FontID::Main), 30));
	text_goToSetting->setOnClick([this](ViewNode& node) {
		finishActivity();
	});

	moving->attachChild(std::move(text_goToSetting));
    layer0->attachChild(std::move(moving));

	ViewNode* layer1 = getLayer(1);
	layer1->attachChild(std::make_unique<TextView>(sf::Text("Setting", getContext()->getFonts()->get(FontID::Main), 30)));
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
	return Activity::update(dt);
}

bool SettingActivity::draw()
{
	getContext()->getWindow()->clear(sf::Color::Blue);
	Activity::draw();
	return true;
}
