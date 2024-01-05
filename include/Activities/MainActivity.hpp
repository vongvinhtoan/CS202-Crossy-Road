#pragma once

#include <Activity.hpp>

class RectangleView;
class ArrowView;

class MainActivity : public Activity
{
public:
	MainActivity(ActivityStack& stack, int requestCode, Extra& intent);
	virtual ~MainActivity() final override;
	virtual bool handleEvent(sf::Event& event) final override;
	virtual bool handleRealtimeInput() final override;
	virtual bool update(sf::Time dt) final override;
	virtual bool draw() final override;
    virtual void onActivityResult(int resultCode, Extra* extra) final override;

private:
	sf::Time m_time = sf::Time::Zero;
};
