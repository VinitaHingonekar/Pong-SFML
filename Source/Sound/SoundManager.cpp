#include "../../Header/Sound/SoundManager.h"
#include <iostream>

namespace Sound
{
    sf::SoundBuffer SoundManager::ballBounce;
    sf::Sound SoundManager::soundEffect;

    sf::Music SoundManager::backgroundMusic;
    const std::string SoundManager::bgmPath = "Assets/Sounds/Pong_bgm.mp3";
    float SoundManager::backgroundMusicVolume = 50.0f;

    const std::string SoundManager::ballBouncePath = "Assets/Sounds/Ball_Bounce.wav";

    SoundManager::SoundManager()
    {
        Initialize();
    }

    void SoundManager::Initialize()
    {
        LoadSoundFromFile();
    }

    void SoundManager::LoadSoundFromFile()
    {
        if (!backgroundMusic.openFromFile(bgmPath))
        {
            std::cerr << "Error loading background music file: " << bgmPath << std::endl;
            return;
        }
        if (!ballBounce.loadFromFile(ballBouncePath))
            std::cerr << "Error loading sound file: " << ballBouncePath << std::endl;
    }

    void SoundManager::PlaySoundEffect(SoundType soundType)
    {
        switch (soundType)
        {
        case SoundType::BALL_BOUNCE:
            soundEffect.setBuffer(ballBounce);
            break;
        default:
            std::cerr << "Invalid sound type" << std::endl;
            return;
        }

        soundEffect.play();
    }

    void SoundManager::PlayBackgroundMusic()
    {
        backgroundMusic.setVolume(backgroundMusicVolume);
        backgroundMusic.setLoop(true);// Music keeps playing
        backgroundMusic.play();// Start the music
    }
}