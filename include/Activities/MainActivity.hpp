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
	RectangleView* rect;
	sf::Vector2f dest = sf::Vector2f(0, 0);
	sf::Vector2f pos_cur = sf::Vector2f(0, 0);
	sf::Vector2f pos_old = sf::Vector2f(0, 0);
	ArrowView* m_velocity_arrow;
	ArrowView* m_acceleration_arrow;
	ArrowView* m_spring_force_arrow;
	ArrowView* m_damping_force_arrow;
};
