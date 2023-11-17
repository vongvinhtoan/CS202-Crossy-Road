#pragma once

#include <Activity.hpp>

class SettingActivity : public Activity
{
public:
	SettingActivity(ActivityStack& stack, int requestCode, Extra& intent);
	virtual ~SettingActivity() final override;
	virtual bool handleEvent(sf::Event& event) final override;
	virtual bool handleRealtimeInput() final override;
	virtual bool update(sf::Time dt) final override;
	virtual bool draw() final override;

private:
	sf::Time t = sf::Time::Zero;
};
