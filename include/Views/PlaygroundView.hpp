#pragma once

#include <ViewNode.hpp>
#include <Views/PlayerView.hpp>
#include <Views/LaneView.hpp>
#include <PlaygroundAdapter.hpp>
#include <tuple>
#include <map>
#include <memory>

class PlaygroundView : public ViewNode
{
public:
	PlaygroundView(PlaygroundAdapter& playgroundAdapter);
	virtual ~PlaygroundView() final;

private:
	virtual void update(sf::Time dt) final override;
	virtual void handleEvent(sf::Event& event) final override;
	virtual void handleRealtimeInput() final override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;

private:
	PlaygroundAdapter& m_playgroundAdapter;
};
