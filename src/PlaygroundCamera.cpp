#include <PlaygroundCamera.hpp>
#include <Context.hpp>

PlaygroundCamera::PlaygroundCamera(float scrollPosition)
    : mScrollSpeed(0.f)
    , mScrollPosition(scrollPosition)
    , mScrollPositionTarget(scrollPosition)
    , mDynamics(nullptr)
    , mAcceleration(0.f)
    , mInitialScrollSpeed(0.f)
{
    std::cout << "sizeof(PlaygroundCamera) = " << sizeof(PlaygroundCamera) << std::endl;
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
    mScrollSpeed = mAcceleration * playerPosition;
    if(playerPosition > 0.f)
        mScrollSpeed += mInitialScrollSpeed;
    mScrollPositionTarget += mScrollSpeed * dt.asSeconds();

    if (mScrollPositionTarget < playerPosition)
        mScrollPositionTarget = playerPosition;

    mScrollPosition = mDynamics->update(dt.asSeconds(), mScrollPositionTarget);
}

float PlaygroundCamera::getScrollPosition() const
{
    return mScrollPosition;
}

std::tuple<int, int> PlaygroundCamera::getVisibleRange(int bufferRange) const
{
    auto windowHeight = (*Context::getInstance().getWindow()).getSize().y;
    auto windowWidth = (*Context::getInstance().getWindow()).getSize().x;
    auto laneHeight = 100;
    auto laneWidth = windowWidth;

    auto l = (mScrollPosition - windowHeight / 2.f) / laneHeight;
    auto r = (mScrollPosition + windowHeight / 2.f) / laneHeight;

    return std::make_tuple(l, r + bufferRange);
}