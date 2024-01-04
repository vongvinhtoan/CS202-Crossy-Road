#include <Activities/LoadGameActivity.hpp>

LoadGameActivity::LoadGameActivity(ActivityStack& stack, int requestCode, Extra& intent)
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
        sf::Text("Load Game", getContext()->getFonts()->get(FontID::Tourney_Bold), 100)
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

LoadGameActivity::~LoadGameActivity()
{
}

bool LoadGameActivity::handleEvent(sf::Event& event)
{
	return Activity::handleEvent(event);
}

bool LoadGameActivity::handleRealtimeInput()
{
	return Activity::handleRealtimeInput();
}

bool LoadGameActivity::update(sf::Time dt)
{
	return Activity::update(dt);
}

bool LoadGameActivity::draw()
{
	return Activity::draw();
}
