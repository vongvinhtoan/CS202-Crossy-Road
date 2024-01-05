#pragma once

#include <SFML/Audio.hpp>
#include <map>

namespace Music
{
    enum ID
    {
        BackGroundMusic,
        PlayGroundMusic,
    };
}

class MusicPlayer : private sf::NonCopyable
{
public:
    MusicPlayer();

public:
    void play(Music::ID theme);
    void stop();
    void setPaused(bool paused);
    void setVolume(float volume);

private:
    sf::Music mMusic;
    std::map<Music::ID, std::string> mFilenames;
    float mVolume;
};
