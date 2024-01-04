#include <Activities/SaveGameActivity.hpp>

SaveGameActivity::SaveGameActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
	sf::Font& font = getContext()->getFonts()->get(FontID::Tourney);
    ViewNode *background_layer = getLayer(0);
    ViewNode* textLayer = getLayer(1);
    ViewNode *ui_layer = getLayer(2);

    auto window = getContext()->getWindow();
    sf::Vector2f window_size(window->getSize());

    // background_layer
    auto background = std::make_unique<RectangleView>(window_size);
    background->get().setTexture(&getContext()->getTextures()->get(TextureID::Background));
    
    background_layer->attachChild(std::move(background));

	//ui_layer
    //text_layer
    auto text = std::make_unique<TextView>(
        sf::Text("Save Game", getContext()->getFonts()->get(FontID::Tourney_Bold), 100)
    );
    sf::Vector2f textSize = text->getSize();
    text->setPosition(sf::Vector2f((window_size.x - textSize.x) / 3,0));
    textLayer->attachChild(std::move(text));

	//slots_layer
	auto slots = std::make_unique<RectangleButtonView>(sf::Vector2f(1115,196));
	slots->setPosition(sf::Vector2f(242, 166));
	slots->get().setFillColor(utils::hexToColor("9AE0A8"));
	ui_layer->attachChild(std::move(slots));
}

SaveGameActivity::~SaveGameActivity()
{
}

bool SaveGameActivity::handleEvent(sf::Event& event)
{
	return Activity::handleEvent(event);
}

bool SaveGameActivity::handleRealtimeInput()
{
	return Activity::handleRealtimeInput();
}

bool SaveGameActivity::update(sf::Time dt)
{
	return Activity::update(dt);
}

bool SaveGameActivity::draw()
{
	return Activity::draw();
}
