#include <iostream>
#include <cmath>
#include "Game.h"

int NOTE_SIZE = 50;
int WINDOW_SIZE_X = 1920;
int WINDOW_SIZE_Y = 1080;

Game::Game(GlobalSettings settings, Config config):
    m_window(settings.GetValue("title"), sf::Vector2u(WINDOW_SIZE_X, WINDOW_SIZE_Y)),
    m_bar(sf::Vector2f(WINDOW_SIZE_X * 0.35, 450), sf::Vector2f(250, WINDOW_SIZE_Y - 600)),
    m_clip("assets/music/castle_bg.ogg"),
    m_sequencer()
{
    m_elapsed = 0.0f;
    m_clock.restart();

    m_clip.SetVolume(config.GetIntValue("volume"));
    m_clip.Play(true);

    if (!m_backgroundTexture.loadFromFile("assets/images/environment/castle.png")) { /* error */ }
    m_backgroundSprite.setTexture(m_backgroundTexture);

    if (!m_playerTexture.loadFromFile("assets/images/eye.png")) { /* error */ }
    m_playerSprite.setTexture(m_playerTexture);
    m_playerYPo = WINDOW_SIZE_Y * 0.1;
    m_playerSprite.setPosition(WINDOW_SIZE_X * 0.08, m_playerYPo);
    float playerScale = 0.35f;
    m_playerSprite.setScale(playerScale, playerScale);

    if (!m_noteTexture.loadFromFile("assets/images/ui/notes.png")) { /* error */ }

    m_sequencer.GenerateNextSequence();
}

Game::~Game() { }

Window* Game::GetWindow() {
    return &m_window;
}

float Game::GetElapsed() { return m_elapsed; }
void Game::RestartClock() { m_elapsed += m_clock.restart().asSeconds(); }

void Game::Render() {
    m_window.BeginDraw();

    m_window.Draw(m_backgroundSprite);
    m_bar.Render(*m_window.GetRenderWindow());
    m_window.Draw(m_playerSprite);

    m_window.EndDraw();
}

void Game::Tick() {
    sf::Event event = m_window.Tick();

    int y = sin(m_clock.getElapsedTime().asSeconds() * 2) * 25 + 100;
    m_playerSprite.setPosition(m_playerSprite.getPosition().x, m_playerYPo + y);
}