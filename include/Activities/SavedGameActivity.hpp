#pragma once

#include <Activity.hpp>

class SavedGameActivity : public Activity
{
public:
	SavedGameActivity(ActivityStack& stack, int requestCode, Extra& intent);
	virtual ~SavedGameActivity() final override;
	virtual bool handleEvent(sf::Event& event) final override;
	virtual bool handleRealtimeInput() final override;
	virtual bool update(sf::Time dt) final override;
	virtual bool draw() final override;
private:
	std::vector<RoundedCornerButtonView*> m_slots;
};