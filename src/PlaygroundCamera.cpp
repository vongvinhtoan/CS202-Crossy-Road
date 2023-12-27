#include <PlaygroundCamera.hpp>
#include <Context.hpp>

PlaygroundCamera::PlaygroundCamera(float scrollPosition)
    : mScrollSpeed(0.f)
    , mScrollPosition(scrollPosition)
    , mScrollPositionTarget(scrollPosition)
    , mDynamics(nullptr)
    , mAcceleration(0.f)
    , mInitialScrollSpeed(0.f)
    , mIsStopped(false)
{
    auto &cameraConfig = (*Context::getInstance().getConfigs())["playground"]["camera"];

    auto& dynamic = cameraConfig["dynamic"];
    mDynamics = std::make_unique<SecondOrderDynamics<float>>(dynamic["f"].asFloat(), dynamic["z"].asFloat(), dynamic["r"].asFloat(), scrollPosition);

    mAcceleration = cameraConfig["acceleration"].asFloat();
    mInitialScrollSpeed = cameraConfig["initialScrollSpeed"].asFloat();
}

PlaygroundCamera::~PlaygroundCamera()
{
}

void PlaygroundCamera::update(float playerPosition, sf::Time dt)
{
    if(mIsStopped) return;
        mScrollSpeed = mAcceleration * playerPosition;
    if(playerPosition > 0.f)
        mScrollSpeed += mInitialScrollSpeed;
    mScrollPositionTarget += mScrollSpeed * dt.asSeconds();

    if (mScrollPositionTarget < playerPosition + 100.f)
        mScrollPositionTarget = playerPosition + 100.f;

    mScrollPosition = mDynamics->update(dt.asSeconds(), mScrollPositionTarget);
}

float PlaygroundCamera::getScrollPosition() const
{
    return mScrollPosition;
}

std::tuple<int, int> PlaygroundCamera::getVisibleRange() const
{
    auto windowHeight = (*Context::getInstance().getWindow()).getSize().y;
    auto windowWidth = (*Context::getInstance().getWindow()).getSize().x;
    auto laneHeight = 100;
    auto laneWidth = windowWidth;

    auto l = (mScrollPosition - windowHeight / 2.f) / laneHeight - 2; l = l < 0 ? 0 : l;
    auto r = (mScrollPosition + windowHeight / 2.f) / laneHeight + 2;

    return std::make_tuple(l, r);
}

void PlaygroundCamera::stop()
{
    mIsStopped = true;
}