#include <iostream>
#include <cmath>
#include "Game.h"

int NOTE_SIZE = 50;
int WINDOW_SIZE_X = 1920;
int WINDOW_SIZE_Y = 1080;

Game::Game(const std::string& l_title):
    m_window(l_title, sf::Vector2u(WINDOW_SIZE_X, WINDOW_SIZE_Y)),
    m_bar(sf::Vector2f(WINDOW_SIZE_X * 0.35, 450), sf::Vector2f(250, WINDOW_SIZE_Y - 600))
{
    m_elapsed = 0.0f;
    m_clock.restart();

    if (!m_backgroundTexture.loadFromFile("assets/images/bg.png")) { /* error */ }
    m_backgroundSprite.setTexture(m_backgroundTexture);

    if (!m_playerTexture.loadFromFile("assets/images/eye.png")) { /* error */ }
    m_playerSprite.setTexture(m_playerTexture);
    m_playerYPo = WINDOW_SIZE_Y * 0.1;
    m_playerSprite.setPosition(WINDOW_SIZE_X * 0.08, m_playerYPo);
    float playerScale = 0.35f;
    m_playerSprite.setScale(playerScale, playerScale);

    if (!m_noteTexture.loadFromFile("assets/images/notes.png")) { /* error */ }

    for (int i = 0; i < 10; i++) {
        m_notes.push_back(Note(
            sf::Vector2f(WINDOW_SIZE_X - NOTE_SIZE + i * 75 - 600, 108 * i + 50),
            NOTE_SIZE,
            0,
            sf::Color::Red,
            &m_noteTexture
        ));
    }
}

Game::~Game() {

}

Window* Game::GetWindow() {
    return &m_window;
}

float Game::GetElapsed() { return m_elapsed; }
void Game::RestartClock() { m_elapsed += m_clock.restart().asSeconds(); }

void Game::Render() {
    m_window.BeginDraw();

    m_window.Draw(m_backgroundSprite);

    m_bar.Render(*m_window.GetRenderWindow());

    for (int i = 0; i < m_notes.size(); i++) {
        m_notes[i].Render(*m_window.GetRenderWindow());
    }
    m_window.Draw(m_playerSprite);

    m_window.EndDraw();
}

void Game::Tick() {
    sf::Event event = m_window.Tick();

    int y = sin(m_clock.getElapsedTime().asSeconds() * 2) * 25 + 100;
    m_playerSprite.setPosition(m_playerSprite.getPosition().x, m_playerYPo + y);

    for (int i = 0; i < m_notes.size(); i++) {
        m_notes[i].Tick();
     }
}