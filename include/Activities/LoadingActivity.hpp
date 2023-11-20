#pragma once

#include <Activity.hpp>

class LoadingActivity : public Activity
{
public:
	LoadingActivity(ActivityStack& stack, int requestCode, Extra& intent);
	virtual ~LoadingActivity() final override;
	virtual bool handleEvent(sf::Event& event) final override;
	virtual bool handleRealtimeInput() final override;
	virtual bool update(sf::Time dt) final override;
	virtual bool draw() final override;

private:
	LoadingBarView* m_loading_bar;
	sf::Time m_time;
	sf::Time m_duration;
};
