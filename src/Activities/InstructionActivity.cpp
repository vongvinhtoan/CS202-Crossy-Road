#include <Activities/InstructionActivity.hpp>

InstructionActivity::InstructionActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
	ViewNode *background_layer = getLayer(0);
	ViewNode *text_layer = getLayer(1);
	ViewNode *ui_layer = getLayer(2);
	ViewNode *percent_layer = getLayer(3);

	auto window = getContext()->getWindow();
	sf::Vector2f window_size(window->getSize());
	// background_layer

	auto background = std::make_unique<RectangleView>(window_size);
	auto &background_shape = background->get();
	background_shape.setTexture(&getContext()->getTextures()->get(TextureID::BackGroundScreen));
	background_layer->attachChild(std::move(background));

	// text_layer
	auto text = std::make_unique<TextView>(sf::Text("INSTRUCTION", getContext()->getFonts()->get(FontID::Tourney_Bold), 125));
	text->setPosition(sf::Vector2f((window_size.x - text->get().getLocalBounds().width) / 2, 56));
	text_layer->attachChild(std::move(text));

	//ui_layer
	//home button
	auto home_button = std::make_unique<RectangleButtonView>(sf::Vector2f(128, 128));
    home_button->get().setTexture(&getContext()->getTextures()->get(TextureID::Home));
    home_button->setPosition(sf::Vector2f(64.f, 64.f));
    home_button->setOnClick([this](ViewNode& view) {
        finishActivity(BACK_TO_HOME, new Extra());
    });
	ui_layer->attachChild(std::move(home_button));

	//left_arrow
	auto leftArrow = std::make_unique<RectangleButtonView>(sf::Vector2f(115, 165));
    leftArrow->get().setTexture(&getContext()->getTextures()->get(TextureID::LeftArrow));
    leftArrow->setPosition(sf::Vector2f(64.f, 383.f));
    m_leftArrow = leftArrow.get();
    
	//right_arrow
    auto rightArrow = std::make_unique<RectangleButtonView>(sf::Vector2f(115, 165));
    rightArrow->get().setTexture(&getContext()->getTextures()->get(TextureID::RightArrow));
    rightArrow->setPosition(sf::Vector2f(1413.f, 383.f));
    m_rightArrow = rightArrow.get();

	//instruction_board
	auto instruction_board = std::make_unique<RoundedCornerButtonView>(sf::Vector2f(1125, 615));
	instruction_board->get().setFillColor(utils::hexToColor("D9D9D9"));
	instruction_board->get().setPosition(sf::Vector2f(230, 225));

	//instruction_text
	auto instruction_text = std::make_unique<RectangleView>(sf::Vector2f(1125, 605));
	instruction_text->get().setTexture(&getContext()->getTextures()->get(TextureID::InstructionText));
	instruction_text->setPosition(sf::Vector2f(230, 220));

	ui_layer->attachChild(std::move(leftArrow));
    ui_layer->attachChild(std::move(rightArrow));
	ui_layer->attachChild(std::move(instruction_board));
	ui_layer->attachChild(std::move(instruction_text));
}

InstructionActivity::~InstructionActivity()
{
}

bool InstructionActivity::handleEvent(sf::Event& event)
{
	return Activity::handleEvent(event);
}

bool InstructionActivity::handleRealtimeInput()
{
	return Activity::handleRealtimeInput();
}

bool InstructionActivity::update(sf::Time dt)
{
	return Activity::update(dt);
}

bool InstructionActivity::draw()
{
	return Activity::draw();
}
