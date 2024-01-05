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
	//Pause-background
	auto coveringRectangle = std::make_unique<RectangleView>(window_size);
	coveringRectangle->get().setFillColor(utils::hexToColor("0085FF00"));
	m_background = coveringRectangle.get();

	background_layer->attachChild(std::move(coveringRectangle));

	// foreground_layer
	ViewNode* foreground_layer = getLayer(1);

	auto &font = getContext()->getFonts()->get(FontID::Main);

	//resume_button
	auto resume_button = std::make_unique<RoundedCornerButtonView>(sf::Vector2f(440, 90));
	resume_button->get().setFillColor(utils::hexToColor("000000"));
	resume_button->get().setPosition(sf::Vector2f(580, 240));
	resume_button->setOnClick([this](ViewNode& view) {
		//requestActivity(ActivityID::Playground);
	});

	auto resume_text = std::make_unique<TextView>("Resume game", font,50);
	resume_text->get().setFillColor(utils::hexToColor("FFFFFF"));
	auto &resume_text_ref = resume_text->get();
	sf::FloatRect textRect = resume_text_ref.getLocalBounds();
	resume_text_ref.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
	resume_text_ref.setPosition(window_size.x/2.0f,
	                 resume_button->getPosition().y + resume_button->get().getSize().y/2.0f);

	//save_button
	auto save_button = std::make_unique<RoundedCornerButtonView>(sf::Vector2f(440, 90));
	save_button->get().setFillColor(utils::hexToColor("FFFFF0000"));
	save_button->get().setPosition(sf::Vector2f(580, 360));
	save_button->setOnClick([this](ViewNode& view) {
		requestActivity(ActivityID::SavedGame);
	});

	auto save_text = std::make_unique<TextView>("Save game", font,50);
	save_text->get().setFillColor(utils::hexToColor("FFFFFF"));
	auto &save_text_ref = save_text->get();
	textRect = save_text_ref.getLocalBounds();
	save_text_ref.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
	save_text_ref.setPosition(window_size.x/2.0f,
	                 save_button->getPosition().y + save_button->get().getSize().y/2.0f);

	//load_button
	auto load_button = std::make_unique<RoundedCornerButtonView>(sf::Vector2f(440, 90));
	load_button->get().setFillColor(utils::hexToColor("FFFFF0000"));
	load_button->get().setPosition(sf::Vector2f(580, 480));
	load_button->setOnClick([this](ViewNode& view) {
		requestActivity(ActivityID::SavedGame);
	});

	auto load_text = std::make_unique<TextView>("Load game", font,50);
	load_text->get().setFillColor(utils::hexToColor("FFFFFF"));
	auto &load_text_ref = load_text->get();
	textRect = load_text_ref.getLocalBounds();
	load_text_ref.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
	load_text_ref.setPosition(window_size.x/2.0f,
	                 load_button->getPosition().y + load_button->get().getSize().y/2.0f);

	//quit_button
	auto quit_button = std::make_unique<RoundedCornerButtonView>(sf::Vector2f(440, 90));
	quit_button->get().setFillColor(utils::hexToColor("FFFFF0000"));
	quit_button->get().setPosition(sf::Vector2f(580, 600));
	quit_button->setOnClick([this](ViewNode& view) {
		//quit
	});

	auto quit_text = std::make_unique<TextView>("Quit game", font,50);
	quit_text->get().setFillColor(utils::hexToColor("FFFFFF"));
	auto &quit_text_ref = quit_text->get();
	textRect = quit_text_ref.getLocalBounds();
	quit_text_ref.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
	quit_text_ref.setPosition(window_size.x/2.0f,
	                 quit_button->getPosition().y + quit_button->get().getSize().y/2.0f);

	foreground_layer->attachChild(std::move(resume_button));
	foreground_layer->attachChild(std::move(save_button));
	foreground_layer->attachChild(std::move(load_button));
	foreground_layer->attachChild(std::move(quit_button));

	foreground_layer->attachChild(std::move(resume_text));
	foreground_layer->attachChild(std::move(save_text));
	foreground_layer->attachChild(std::move(load_text));
	foreground_layer->attachChild(std::move(quit_text));
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
