#pragma once

#include <SFML/Audio.hpp>
#include <ResourceHolder.hpp>
#include <list>

namespace SoundEffect
{
    enum ID
    {
        TrainHorn,
    };
}

typedef ResourceHolder<sf::SoundBuffer, SoundEffect::ID> SoundBufferHolder;

class SoundPlayer : private sf::NonCopyable
{
public:
    SoundPlayer();
    void play(SoundEffect::ID effect);
    void play(SoundEffect::ID effect,
              sf::Vector2f position);
    void removeStoppedSounds();
    void setListenerPosition(sf::Vector2f position);
    sf::Vector2f getListenerPosition() const;

private:
    SoundBufferHolder mSoundBuffers;
    std::list<sf::Sound> mSounds;
};
