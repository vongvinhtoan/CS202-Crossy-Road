#pragma once

#include <Activity.hpp>

class PlaygroundActivity : public Activity
{
public:
	PlaygroundActivity(ActivityStack& stack, int requestCode, Extra& intent);
	virtual ~PlaygroundActivity() final override;
	virtual bool handleEvent(sf::Event& event) final override;
	virtual bool handleRealtimeInput() final override;
	virtual bool update(sf::Time dt) final override;
	virtual bool draw() final override;

private:
	std::unique_ptr<Game> 				mGame;
	std::unique_ptr<PlaygroundAdapter> 	mPlaygroundAdapter;
};