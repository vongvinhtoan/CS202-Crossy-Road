#pragma once

#include <SFML/Graphics.hpp>

class PlaygroundCamera
{
public:
	PlaygroundCamera();
public:
	void update(sf::Time dt);
	float getScrollPosition() const;
private:
	float   mScrollSpeed;
	float   mScrollPosition;
};