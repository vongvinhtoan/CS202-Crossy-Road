#include <Views/PlaygroundView.hpp>
#include <iostream>
#include <cmath>

PlaygroundView::PlaygroundView()
	: mKeyBinding()
	, mPlayerView(nullptr)
	, mLandViews()
	, mScrollSpeed(0.0f)
	, mScrollPosition(0.0f)
	, mScrollAcceleration(0.0f)
	, mInitialScrollSpeed(0.0f)
	, mCharacterPosition(0, 0)
	, mOldL(0)
	, mOldR(-1)
{
	std::cout << "PlaygroundView::PlaygroundView()" << std::endl;
	initValues();


	mLandViews.resize(mBufferRange);
	for(int i = 0; i < mBufferRange; ++i)
	{
		mLandViews[i] = nullptr;
	}

	updateLands(mScrollPosition);

	mPlayerView = std::make_unique<PlayerView>();
}

void PlaygroundView::initValues()
{
	auto& keyBinding = (*getContext()->getConfigs())["keyBinding"];
	mKeyBinding[sf::Keyboard::Key(keyBinding["moveUp"].asInt())] = MOVE_UP;
	mKeyBinding[sf::Keyboard::Key(keyBinding["moveDown"].asInt())] = MOVE_DOWN;
	mKeyBinding[sf::Keyboard::Key(keyBinding["moveLeft"].asInt())] = MOVE_LEFT;
	mKeyBinding[sf::Keyboard::Key(keyBinding["moveRight"].asInt())] = MOVE_RIGHT;

	mBufferRange = (*getContext()->getConfigs())["playground"]["bufferRange"].asInt();

	mScrollAcceleration = (*getContext()->getConfigs())["playground"]["scrollAcceleration"].asFloat();
	mInitialScrollSpeed = (*getContext()->getConfigs())["playground"]["initialScrollSpeed"].asFloat();
}

PlaygroundView::~PlaygroundView()
{
}

void PlaygroundView::update(sf::Time dt)
{
	std::cout << "PlaygroundView::update()" << std::endl;
	mScrollPosition += mScrollSpeed * dt.asSeconds();
	auto [l, r] = getBufferRange(mScrollPosition, mBufferRange);
	mScrollSpeed = updateScrollSpeed(mCharacterPosition.y);

	std::cout << "mScrollPosition: " << mScrollPosition << std::endl;
	// mOffset = sf::Transform::Identity;
	// mOffset.translate(0.0f, -mScrollPosition);
	std::cout << sizeof(PlaygroundView) << std::endl;
}

void PlaygroundView::handleEvent(sf::Event& event)
{
	if(event.type == sf::Event::KeyPressed)
	{
		auto found = mKeyBinding.find(event.key.code);
		if(found != mKeyBinding.end())
		{
			onCommand(found->second);
		}
	}	
}

void PlaygroundView::handleRealtimeInput()
{
}

void PlaygroundView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	std::cout << "PlaygroundView::draw()" << std::endl;
	// states.transform *= mOffset;
	// std::cout << "mOffset: " << mOffset.transformPoint(sf::Vector2f(0.0f, 0.0f)).y << std::endl;
	for(auto& landView : mLandViews)
	{
		if(landView != nullptr)
			target.draw(*landView, states);
	}
	target.draw(*mPlayerView, states);
}

bool PlaygroundView::contains(sf::Vector2f point) const
{
	return false;
}

void PlaygroundView::onCommand(Command command)
{
	
}

std::tuple<int, int> PlaygroundView::getBufferRange(float scrollPosition, int bufferSize)
{
	float int_scrollPosition = std::floor(scrollPosition);
	return std::make_tuple(int_scrollPosition, int_scrollPosition + bufferSize - 1);
}

float PlaygroundView::updateScrollSpeed(int standingLandIndex)
{
	return mInitialScrollSpeed + mScrollAcceleration * standingLandIndex;
}

void PlaygroundView::updateLands(float scrollPosition)
{
	auto [l, r] = getBufferRange(scrollPosition, mBufferRange);
	
	for(int i = l; i < mOldL; ++i)
	{
		getLand(i) = nullptr;
	}

	for(int i = mOldR + 1; i <= r; ++i)
	{
		getLand(i) = generateNewLand(getLand(i - 1).get());
	}

	std::tie(mOldL, mOldR) = std::make_tuple(l, r);
}

std::unique_ptr<LandView>& PlaygroundView::getLand(int index)
{
	if(index < 0) index = index % mBufferRange + mBufferRange;
	return mLandViews[index % mBufferRange];
}

std::unique_ptr<LandView> PlaygroundView::generateNewLand(LandView* oldLand)
{
	return nullptr;
}