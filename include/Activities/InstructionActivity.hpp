#pragma once

#include <Activity.hpp>

class InstructionActivity : public Activity
{
public:
	InstructionActivity(ActivityStack& stack, int requestCode, Extra& intent);
	virtual ~InstructionActivity() final override;
	virtual bool handleEvent(sf::Event& event) final override;
	virtual bool handleRealtimeInput() final override;
	virtual bool update(sf::Time dt) final override;
	virtual bool draw() final override;
};
