#include <SoundPlayer.hpp>

SoundPlayer::SoundPlayer()
    : mSoundBuffers(), mSounds()
{
    mSoundBuffers.load(SoundEffect::ID::TrainHorn, "res/sounds/TrainHorn.wav");
}

void SoundPlayer::play(SoundEffect::ID effect)
{
    mSounds.push_back(sf::Sound(mSoundBuffers.get(effect)));
    mSounds.back().play();
}

void SoundPlayer::play(SoundEffect::ID effect,
                       sf::Vector2f position)
{
    mSounds.push_back(sf::Sound(mSoundBuffers.get(effect)));
    mSounds.back().setPosition(position.x, position.y, 0.0f);
    mSounds.back().play();
}

void SoundPlayer::removeStoppedSounds()
{
    mSounds.remove_if([](const sf::Sound &s)
                      { return s.getStatus() == sf::Sound::Stopped; });
}

void SoundPlayer::setListenerPosition(sf::Vector2f position)
{
    sf::Listener::setPosition(position.x, position.y, 0.0f);
}

sf::Vector2f SoundPlayer::getListenerPosition() const
{
    sf::Vector3f position = sf::Listener::getPosition();
    return sf::Vector2f(position.x, position.y);
}

void SoundPlayer::setVolume(float volume)
{
    sf::Listener::setGlobalVolume(volume);
}
