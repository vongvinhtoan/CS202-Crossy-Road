#include <Activities/SettingActivity.hpp>
#include <Utils.hpp>

SettingActivity::SettingActivity(ActivityStack &stack, int requestCode, Extra &intent)
	: Activity(stack, requestCode, intent)
{
	std::cout << "SettingActivity::SettingActivity()" << std::endl;

	ViewNode *background_layer = getLayer(0);
	ViewNode *text_layer = getLayer(1);
	ViewNode *ui_layer = getLayer(2);
	ViewNode *peecent_layer = getLayer(3);

	auto window = getContext()->getWindow();
	sf::Vector2f window_size(window->getSize());

	std::cout << "window_size: " << window_size.x << " " << window_size.y << std::endl;

	// background_layer
	auto background = std::make_unique<RectangleView>(window_size);
	auto &background_shape = background->get();
	background_shape.setTexture(&getContext()->getTextures()->get(TextureID::BackGroundScreen));
	background_layer->attachChild(std::move(background));

	// text_layer
	auto text = std::make_unique<TextView>(sf::Text("SETTING", getContext()->getFonts()->get(FontID::Tourney_Bold), 125));
	text->setPosition(sf::Vector2f((window_size.x - text->get().getLocalBounds().width) / 2, 56));
	text_layer->attachChild(std::move(text));

	// ui_layer
	auto effect_sound_bar = std::make_unique<ProcessBarView>(sf::Vector2f(729.05, 82.8));
	effect_sound_bar->setOrigin(effect_sound_bar->getSize() / 2.f);
	effect_sound_bar->setPosition(sf::Vector2f(window_size.x / 2.f, 390));
	m_effect_sound_bar = effect_sound_bar.get();
	ui_layer->attachChild(std::move(effect_sound_bar));

	auto background_music_bar = std::make_unique<ProcessBarView>(sf::Vector2f(729.05, 82.8));
	background_music_bar->setOrigin(background_music_bar->getSize() / 2.f);
	background_music_bar->setPosition(sf::Vector2f(window_size.x / 2.f, 608));
	m_background_music_bar = background_music_bar.get();
	ui_layer->attachChild(std::move(background_music_bar));

	// text_layer
	auto effect_sound_text = std::make_unique<TextView>(sf::Text("Effect Sound", getContext()->getFonts()->get(FontID::Tourney_Bold), 69));
	effect_sound_text->setPosition(sf::Vector2f(435, 250));
	text_layer->attachChild(std::move(effect_sound_text));

	auto background_music_text = std::make_unique<TextView>(sf::Text("Background Music", getContext()->getFonts()->get(FontID::Tourney_Bold), 69));
	background_music_text->setPosition(sf::Vector2f(435, 463));
	text_layer->attachChild(std::move(background_music_text));

	// text_layer
	auto effect_sound_percent = std::make_unique<TextView>(sf::Text("30%", getContext()->getFonts()->get(FontID::Tourney_Bold), 69));
	effect_sound_percent->setPosition(sf::Vector2f(0, 350));
	peecent_layer->attachChild(std::move(effect_sound_percent));

	auto background_music_percent = std::make_unique<TextView>(sf::Text("30%", getContext()->getFonts()->get(FontID::Tourney_Bold), 69));
	background_music_percent->setPosition(sf::Vector2f(0, 570));
	peecent_layer->attachChild(std::move(background_music_percent));
}

SettingActivity::~SettingActivity()
{
}

bool SettingActivity::handleEvent(sf::Event &event)
{
	return Activity::handleEvent(event);
}

bool SettingActivity::handleRealtimeInput()
{
	return Activity::handleRealtimeInput();
}

bool SettingActivity::update(sf::Time dt)
{
	return Activity::update(dt);
}

bool SettingActivity::draw()
{
	return Activity::draw();
}
