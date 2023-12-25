#pragma once

#include <SFML/Graphics.hpp>
#include <Game.hpp>
#include <Views/PlayerView.hpp>
#include <Views/LaneView.hpp>
#include <Views/TextView.hpp>
#include <LaneViewFactory.hpp>

class PlaygroundAdapter
{
public:
    PlaygroundAdapter(Game& game);
    
    int getBufferRange() const;
    LaneView* getLane(int index);
    PlayerView* getPlayer();
    TextView* getScoreView();
    Game* getGame() const;

private:
    Game*                                   m_game;
    std::vector<std::unique_ptr<LaneView>>  m_lanes;
    std::unique_ptr<PlayerView>             m_player;
    std::unique_ptr<LaneViewFactory>        m_laneViewFactory;
    std::unique_ptr<TextView>               m_scoreView;
};