#include <Activities/GameOverActivity.hpp>

GameOverActivity::GameOverActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
	std::cout << "GameOverActivity::GameOverActivity()" << std::endl;

	auto window = getContext()->getWindow();
	sf::Vector2f window_size(window->getSize());

	auto& configs = (*getContext()->getConfigs())["count_down_time"];
	int count_down_time = configs.asInt();

	//count_down_time
	m_numberTexts.resize(count_down_time);
	for (int i = 0; i < count_down_time; ++i)
	{
		m_numberTexts[i] = count_down_time - i;
	}

	// background_layer
	ViewNode* background_layer = getLayer(0);
	//Game-over-background
	auto coveringRectangle = std::make_unique<RectangleView>(window_size);
	coveringRectangle->get().setFillColor(utils::hexToColor("FF563100"));
	m_background = coveringRectangle.get();

	background_layer->attachChild(std::move(coveringRectangle));

	// foreground_layer
	ViewNode* foreground_layer = getLayer(1);
	//Game-over-text
	auto &font = getContext()->getFonts()->get(FontID::Tourney_Bold);
	auto gameOverText = std::make_unique<TextView>("GAME OVER", font, 250);
	gameOverText->get().setFillColor(utils::hexToColor("FFFFFF00"));
	auto &text = gameOverText->get();
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	text.setPosition(sf::Vector2f(window_size.x / 2.0f, window_size.y / 2.0f));
	m_gameOverText = gameOverText.get();

	///home-button
	auto homeButton = std::make_unique<RectangleButtonView>(sf::Vector2f(204, 204));
    homeButton->setPosition(sf::Vector2f(925.f, 318.f));
    homeButton->setOnClick([this](ViewNode& view) {
		m_isAnimationFinished = true;
		finishActivity(BACK_TO_HOME, new Extra());
    });
	m_homeButton = homeButton.get();
	homeButton->disable();

	//play-again-button
	auto playAgainButton = std::make_unique<RectangleButtonView>(sf::Vector2f(204, 204));
    playAgainButton->setPosition(sf::Vector2f(444.f, 324.f));
	playAgainButton->setOnClick([&](ViewNode& view) {
		m_isAnimationFinished = true;
		replay();
    });
	playAgainButton->disable();
	m_playAgainButton = playAgainButton.get();

	foreground_layer->attachChild(std::move(gameOverText));
    foreground_layer->attachChild(std::move(homeButton));
	foreground_layer->attachChild(std::move(playAgainButton));
}

GameOverActivity::~GameOverActivity()
{
}

bool GameOverActivity::handleEvent(sf::Event& event)
{
	return Activity::handleEvent(event);
}

bool GameOverActivity::handleRealtimeInput()
{
	return Activity::handleRealtimeInput();
}

bool GameOverActivity::update(sf::Time dt)
{
	Activity::update(dt);

	m_elapsedTime += dt;

	if (!m_isAnimationFinished){
		if(m_elapsedTime <= sf::seconds(1.5f))
		{
			auto duration = 1.5f;
			auto color = m_background->get().getFillColor();
			color.a = 0.81 * 255 * m_elapsedTime.asSeconds() / duration;
			m_background->get().setFillColor(color);
		}
		if (sf::seconds(.5f) <= m_elapsedTime && m_elapsedTime <= sf::seconds(1.f))
		{
			auto duration = 0.5f;
			auto color = m_gameOverText->get().getFillColor();
			color.a = utils::lerp(0, 255, utils::anim::quadratic_ease_out((m_elapsedTime.asSeconds() - .5f) / duration));
			m_gameOverText->get().setFillColor(color);
		}
		if (m_elapsedTime >= sf::seconds(2.5f))
		{
			//hide game over text
			auto color = m_gameOverText->get().getFillColor();
			color.a = 0;
			m_gameOverText->get().setFillColor(color);

			m_homeButton->enable();
			m_homeButton->get().setTexture(&getContext()->getTextures()->get(TextureID::Home));
			m_playAgainButton->enable();
			m_playAgainButton->get().setTexture(&getContext()->getTextures()->get(TextureID::PlayAgainArrow));
		}
	}

	return false;
}

bool GameOverActivity::draw()
{
	return Activity::draw();
}

void GameOverActivity::replay()
{
	std::cout<<"GameOverActivity::replay()"<<std::endl;
	
	//make game over text visible
	auto color = m_gameOverText->get().getFillColor();
	color.a = 255;
	m_gameOverText->get().setFillColor(color);

	m_homeButton->disable();
	m_playAgainButton->disable();

	m_elapsedTime = sf::Time::Zero;

	//count_down_time
	auto window = getContext()->getWindow();
	sf::Vector2f window_size(window->getSize());

	int index = 0;
	while (index < m_numberTexts.size())
	{
		auto &text = m_gameOverText->get();
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
		text.setPosition(sf::Vector2f(window_size.x / 2.0f, window_size.y / 2.0f));
		m_gameOverText->get().setString(sf::String(std::to_string(m_numberTexts[index])));

		m_elapsedTime = sf::Time::Zero;
		m_elapsedTime >= sf::seconds(index * 0.5f) ? ++index : index = m_numberTexts.size();
	}
}