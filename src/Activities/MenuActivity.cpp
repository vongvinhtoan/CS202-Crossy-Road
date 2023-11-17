#include <Activities/MenuActivity.hpp>

MenuActivity::MenuActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
    ViewNode* layer0 = getLayer(0);
    auto window = getContext()->getWindow();
	auto moving = std::make_unique<MovingSquare>(sf::FloatRect(0.f, 0.f, window->getSize().x, window->getSize().y));
	moving->setOnClick([this](ViewNode& node) {
		requestActivity(ActivityID::Setting);
	});

	auto text_goToSetting = std::make_unique<TextView>(sf::Text("Go to Setting", getContext()->getFonts()->get(FontID::Main), 30));
	text_goToSetting->setOnClick([this](ViewNode& node) {
		requestActivity(ActivityID::Setting);
	});

	moving->attachChild(std::move(text_goToSetting));
    layer0->attachChild(std::move(moving));

	ViewNode* layer1 = getLayer(1);
	layer1->attachChild(std::make_unique<TextView>(sf::Text("Menu", getContext()->getFonts()->get(FontID::Main), 30)));
}

MenuActivity::~MenuActivity()
{
}

bool MenuActivity::handleEvent(sf::Event& event)
{
	return Activity::handleEvent(event);
}

bool MenuActivity::handleRealtimeInput()
{
	return Activity::handleRealtimeInput();
}

bool MenuActivity::update(sf::Time dt)
{
	return Activity::update(dt);
}

bool MenuActivity::draw()
{
	Activity::draw();
	return true;
}
