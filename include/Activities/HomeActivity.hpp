#pragma once

#include <Activity.hpp>

class HomeActivity : public Activity
{
public:
	HomeActivity(ActivityStack& stack, int requestCode, Extra& intent);
	virtual ~HomeActivity() final override;
	virtual bool handleEvent(sf::Event& event) final override;
	virtual bool handleRealtimeInput() final override;
	virtual bool update(sf::Time dt) final override;
	virtual bool draw() final override;
    virtual void onActivityResult(int resultCode, Extra* extra) final override;

private:
	sf::Texture*	m_playerTextureID;
};
