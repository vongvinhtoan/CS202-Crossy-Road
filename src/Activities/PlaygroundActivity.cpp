#include <Activities/PlaygroundActivity.hpp>

PlaygroundActivity::PlaygroundActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
	std::cout << "PlaygroundActivity::PlaygroundActivity()" << std::endl;
	
	mGame = std::make_unique<Game>((*getContext()->getConfigs())["playground"]["bufferRange"].asInt());
	mPlaygroundAdapter = std::make_unique<PlaygroundAdapter>(*mGame);

	ViewNode* playgroundLayer = getLayer(0);
	std::unique_ptr<PlaygroundView> playgroundView = std::make_unique<PlaygroundView>(*mPlaygroundAdapter);
	playgroundLayer->attachChild(std::move(playgroundView));
}

PlaygroundActivity::~PlaygroundActivity() 
{
}

bool PlaygroundActivity::handleEvent(sf::Event& event)
{
	Activity::handleEvent(event);
	mGame->handleEvent(event);
	return 0;
}

bool PlaygroundActivity::handleRealtimeInput()
{
	Activity::handleRealtimeInput();
	mGame->handleRealtimeInput();
	return 0;
}

bool PlaygroundActivity::update(sf::Time dt)
{
	Activity::update(dt);
	mGame->update(dt);

	auto* gameOverStrategy = mGame->gameOver();
	if(gameOverStrategy)
	{
		std::cout << "Game Over" << std::endl;
		finishActivity();
	}

	return 0;
}

bool PlaygroundActivity::draw()
{
	return Activity::draw();
}