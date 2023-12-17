#include <PlaygroundCamera.hpp>

PlaygroundCamera::PlaygroundCamera()
    : mScrollSpeed(10.f)
    , mScrollPosition(0.f)
{
}

void PlaygroundCamera::update(sf::Time dt)
{
    mScrollPosition += mScrollSpeed * dt.asSeconds();
}

float PlaygroundCamera::getScrollPosition() const
{
    return mScrollPosition;
}