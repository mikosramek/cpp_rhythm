#pragma once
#include <iostream>
#include <SFML/Audio.hpp>

class MusicClip
{
public:
    MusicClip(std::string l_clipPath);
    ~MusicClip();
    void Play(bool l_loop);
    void Stop();
    void SetVolume(int l_volume);
private:
    sf::SoundBuffer m_buffer;
    sf::Sound m_sound;
    int m_volume;
};
