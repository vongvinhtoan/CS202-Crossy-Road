#include <MusicPlayer.hpp>
#include <iostream>

MusicPlayer::MusicPlayer()
    : mMusic(), mFilenames(), mVolume(100.f)
{
    mFilenames[Music::BackGroundMusic] = "res/sounds/BackGroundMusic.ogg";
    mFilenames[Music::PlayGroundMusic] = "res/sounds/PlayGroundMusic.ogg";
}

void MusicPlayer::play(Music::ID theme)
{
    std::string filename = mFilenames[theme];
    if (!mMusic.openFromFile(filename))
        throw std::runtime_error("Music " + filename + " could not be loaded.");
    std::cout << "Music " << filename << " loaded." << std::endl;
    mMusic.setVolume(mVolume);
    mMusic.setLoop(true);
    mMusic.play();
}

void MusicPlayer::stop()
{
    mMusic.stop();
}

void MusicPlayer::setPaused(bool paused)
{
    if (paused)
        mMusic.pause();
    else
        mMusic.play();
}

void MusicPlayer::setVolume(float volume)
{
    mVolume = volume;
    mMusic.setVolume(mVolume);
}
