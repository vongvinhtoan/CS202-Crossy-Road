#pragma once

#include <ViewNode.hpp>
#include <Views/PlayerView.hpp>
#include <Views/LandView.hpp>
#include <tuple>
#include <map>
#include <memory>

class PlaygroundView : public ViewNode
{
public:
	PlaygroundView();
	virtual ~PlaygroundView() final;

private:
	void initValues();

private:
	virtual void update(sf::Time dt) final override;
	virtual void handleEvent(sf::Event& event) final override;
	virtual void handleRealtimeInput() final override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;

public:
	virtual bool contains(sf::Vector2f point) const final override;

private:
	enum Command {
		MOVE_UP,
		MOVE_DOWN,
		MOVE_LEFT,
		MOVE_RIGHT
	};

	void onCommand(Command command);
	std::tuple<int, int> getBufferRange(float scrollPosition, int bufferSize);
	float updateScrollSpeed(int standingLandIndex);
	void updateLands(float scrollPosition);
	std::unique_ptr<LandView>& getLand(int index);
	std::unique_ptr<LandView> generateNewLand(LandView* oldLand);

private:
	std::map<sf::Keyboard::Key, Command> 	mKeyBinding;
	std::unique_ptr<PlayerView>				mPlayerView;
	std::vector<std::unique_ptr<LandView>> 	mLandViews;
	sf::Vector2i 							mCharacterPosition;
	int 									mBufferRange;
	float 									mScrollSpeed;
	float 									mScrollPosition;
	float 									mScrollAcceleration;
	float 									mInitialScrollSpeed;
	int 									mOldL;
	int 									mOldR;
};
