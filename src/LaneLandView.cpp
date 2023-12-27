#include <LaneLandView.hpp>
#include <LaneLand.hpp>
#include <iostream>
#include <Utils.hpp>

LaneLandView::LaneLandView(LaneType laneType)
	: LaneView(laneType)
	, mTiles((*getContext()->getWindow()).getSize().x / 100)
	, mLastLane(nullptr)
{
}

void LaneLandView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(auto tile : mTiles)
	{
		target.draw(tile, states);
	}
	for(int i = 0; i < mObstacles.size(); ++i)
	{
		target.draw(mObstacles[i], states);
	}
}

void LaneLandView::update(sf::Time dt)
{
}

void LaneLandView::handleEvent(sf::Event& event)
{
}

void LaneLandView::handleRealtimeInput()
{
}

bool LaneLandView::contains(sf::Vector2f point) const
{
	return false;
}

void LaneLandView::bind(Lane* _lane, PlaygroundCamera* camera)
{
	LaneLand* lane = dynamic_cast<LaneLand*>(_lane);
	
	auto obstacles = lane->getObstacles();
	mObstacles.resize(obstacles.size());

	if(mLastLane != _lane)
	{
		mLastLane = _lane;
		renew_tiles();
		renew_obstacles();
	}

	auto pos = lane->getIndex() * 100;
	pos -= camera->getScrollPosition() - (*getContext()->getWindow()).getSize().y / 2;
	pos = (*getContext()->getWindow()).getSize().y - pos;

	for(int i = 0; i < mTiles.size(); ++i)
	{
		mTiles[i].setPosition(i * 100, pos);
	}

	for(int i = 0; i < obstacles.size(); ++i)
	{
		auto pos = lane->getIndex() * 100 - 100;
		pos -= camera->getScrollPosition() - (*getContext()->getWindow()).getSize().y / 2;
		pos = (*getContext()->getWindow()).getSize().y - pos;
		mObstacles[i].setPosition(obstacles[i] * 100 + 50, pos);
	}
}

void LaneLandView::renew_tiles()
{
	static const std::vector<TextureID::ID> textures = {
		TextureID::LaneLand_tile_0,
		TextureID::LaneLand_tile_1,
		TextureID::LaneLand_tile_2
	};
	for(int i=0; i<mTiles.size(); ++i)
	{
		mTiles[i].setSize(sf::Vector2f(100.f, 100.f));

		auto texture = textures[utils::random(0, textures.size() - 1)];
		mTiles[i].setTexture(&getContext()->getTextures()->get(texture));
	}
}

void LaneLandView::renew_obstacles()
{
	static const std::vector<TextureID::ID> textures = {
		TextureID::LaneLand_obstacle_0,
		TextureID::LaneLand_obstacle_1
	};
	for(int i=0; i<mObstacles.size(); ++i)
	{
		auto textureId = textures[utils::random(0, textures.size() - 1)];
		sf::Texture& textureRef = getContext()->getTextures()->get(textureId);

		mObstacles[i].setTexture(&textureRef);
		mObstacles[i].setSize(sf::Vector2f(textureRef.getSize().x, textureRef.getSize().y));
		mObstacles[i].setOrigin(sf::Vector2f(textureRef.getSize().x / 2, textureRef.getSize().y));
	}
}

LaneLandView::~LaneLandView()
{
}