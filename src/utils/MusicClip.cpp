#include "MusicClip.h"

MusicClip::MusicClip(std::string l_clipPath) {
    if (l_clipPath == "") return;
    if (!m_buffer.loadFromFile(l_clipPath)) {
        // error
    }
    m_sound.setBuffer(m_buffer);
}

MusicClip::~MusicClip(){ }

void MusicClip::SetVolume(int l_volume) {
    m_volume = l_volume;
}

void MusicClip::Play(bool l_loop) {
    std::cout << "playing: " << m_sound.Playing << std::endl;
    m_sound.setVolume(m_volume);
    if (m_sound.getStatus() != m_sound.Playing) {
        m_sound.play();
    }
    m_sound.setLoop(l_loop);
}

void MusicClip::Stop() {
    m_sound.stop();
    m_sound.setLoop(false);
}
