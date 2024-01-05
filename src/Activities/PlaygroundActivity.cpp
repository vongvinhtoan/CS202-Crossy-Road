#include <Activities/PlaygroundActivity.hpp>
#include <RequestCode.hpp>

PlaygroundActivity::PlaygroundActivity(ActivityStack& stack, int requestCode, Extra& intent)
	: Activity(stack, requestCode, intent)
{
	mGame = std::make_unique<Game>((*getContext()->getConfigs())["playground"]["bufferRange"].asInt());
	if(requestCode == LOAD_SAVE) 
	{
		mGame->loadFromFile(intent.getExtra<std::string>("filename"));
	}
	else if(requestCode == NEW_GAME) 
	{
		mGame->setPlayerTexture(intent.getExtra<sf::Texture*>("characterTexture"));
	}
	mPlaygroundAdapter = std::make_unique<PlaygroundAdapter>(*mGame);
	mGame->setAdapter(mPlaygroundAdapter.get());

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
	if(event.type == sf::Event::KeyPressed) {
		if(event.key.code == sf::Keyboard::Escape) {
			requestActivity(ActivityID::Pause);
		}
	}
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

	if(mGame->isDone()) {
		requestActivity(ActivityID::GameOver);
	}

	return 0;
}

bool PlaygroundActivity::draw()
{
	Activity::draw();
	return true;
}

void PlaygroundActivity::onActivityResult(int resultCode, Extra* extra)
{
	if(resultCode == BACK_TO_HOME) {
		finishActivity();
		requestActivity(ActivityID::Home);
	}
	else if(resultCode == PLAY_AGAIN) {
		finishActivity();
		auto intent = new Extra();
		intent->putExtra("characterTexture", mGame->getPlayer()->getTexture());
		requestActivity(ActivityID::Playground, NEW_GAME, intent);
	}
}