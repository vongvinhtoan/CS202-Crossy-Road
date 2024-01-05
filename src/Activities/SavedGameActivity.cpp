#include <Activities/SavedGameActivity.hpp>

SavedGameActivity::SavedGameActivity(ActivityStack& stack, int requestCode, Extra& intent)
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
    auto save_game_text = std::make_unique<TextView>("Saved Game", font, 80);
	save_game_text->get().setFillColor(utils::hexToColor("FFFFFF"));
	auto &save_game_text_ref = save_game_text->get();
	sf::FloatRect textRect = save_game_text_ref.getLocalBounds();
	save_game_text_ref.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
	save_game_text_ref.setPosition(sf::Vector2f(window_size.x/2.0f, 100));

	//slots

	for (int i = 0; i < m_slots.size(); i++)
	{
		auto slot = std::make_unique<RoundedCornerButtonView>(sf::Vector2f(1115,196));
		slot->get().setFillColor(utils::hexToColor("9AE0A8"));
		slot->get().setOutlineThickness(0);
		slot->get().setPosition(sf::Vector2f(242, 166 + i * 250));

		ui_layer->attachChild(std::move(slot));
		m_slots.push_back(slot.get());
	}
	
	textLayer->attachChild(std::move(save_game_text));
}

SavedGameActivity::~SavedGameActivity()
{
}

bool SavedGameActivity::handleEvent(sf::Event& event)
{
	return Activity::handleEvent(event);
}

bool SavedGameActivity::handleRealtimeInput()
{
	return Activity::handleRealtimeInput();
}

bool SavedGameActivity::update(sf::Time dt)
{
	return Activity::update(dt);
}

bool SavedGameActivity::draw()
{
	return Activity::draw();
}
