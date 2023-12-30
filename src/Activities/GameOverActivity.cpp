#include <Activities/GameOverActivity.hpp>

GameOverActivity::GameOverActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
	std::cout << "GameOverActivity::GameOverActivity()" << std::endl;

	auto window = getContext()->getWindow();
	sf::Vector2f window_size(window->getSize());

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
	m_homeButton = std::make_unique<RectangleButtonView>(sf::Vector2f(204, 204));
    m_homeButton->get().setTexture(&getContext()->getTextures()->get(TextureID::Home));
    m_homeButton->setPosition(sf::Vector2f(925.f, 318.f));
    m_homeButton->setOnClick([this](ViewNode& view) {
		requestActivity(ActivityID::Home);
    });

	//play-again-button
	auto m_playAgainButton = std::make_unique<RectangleButtonView>(sf::Vector2f(204, 204));
    m_playAgainButton->get().setTexture(&getContext()->getTextures()->get(TextureID::PlayAgainArrow));
    m_playAgainButton->setPosition(sf::Vector2f(444.f, 324.f));
    m_playAgainButton->setOnClick([this](ViewNode& view) {
		finishActivity();
    });

	foreground_layer->attachChild(std::move(gameOverText));
    foreground_layer->attachChild(std::move(m_homeButton));
	foreground_layer->attachChild(std::move(m_playAgainButton));
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

	if(m_elapsedTime <= sf::seconds(1.f))
	{
		auto duration = 1.f;
		auto color = m_background->get().getFillColor();
		color.a = 0.81 * 255 * m_elapsedTime.asSeconds() / duration;
		m_background->get().setFillColor(color);
	}
	if(sf::seconds(.5f) <= m_elapsedTime && m_elapsedTime <= sf::seconds(1.f))
	{
		auto duration = 0.5f;
		auto color = m_gameOverText->get().getFillColor();
		color.a = utils::lerp(0, 255, utils::anim::quadratic_ease_out((m_elapsedTime.asSeconds() - .5f) / duration));
		m_gameOverText->get().setFillColor(color);
	}

	return false;
}

bool GameOverActivity::draw()
{
	return Activity::draw();
}
