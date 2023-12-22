#pragma once

#include <SFML/Graphics.hpp>
#include <SecondOrderDynamics.hpp>

class PlaygroundCamera
{
public:
	PlaygroundCamera(float scrollPosition = 0.f);
	~PlaygroundCamera();
public:
	void update(float playerPosition, sf::Time dt);
	float getScrollPosition() const;
	std::tuple<int, int> getVisibleRange() const;
	void stop();
private:
	float   									mScrollSpeed;
	float   									mScrollPositionTarget;
	float   									mScrollPosition;
	float										mAcceleration;
	float										mInitialScrollSpeed;
	std::unique_ptr<SecondOrderDynamics<float>> mDynamics;
	bool										mIsStopped;
};