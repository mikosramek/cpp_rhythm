#include <iostream>
#include <cmath>
#include "Game.h"

int NOTE_SIZE = 50;
int WINDOW_SIZE_X = 1920;

Game::Game(const std::string& l_title):
    m_window(l_title, sf::Vector2u(WINDOW_SIZE_X, 1080)),
    m_dataReader("assets/config.txt")
{
    m_elapsed = 0.0f;
    m_clock.restart();

    if (!m_backgroundTexture.loadFromFile("assets/images/bg.png")) { /* error */ }
    m_backgroundSprite.setTexture(m_backgroundTexture);

    Lines dataLines = m_dataReader.GetLines();
    for (int index = 0; index < dataLines.size(); index += 1) {
        std::string line = dataLines[index];
        if (!line.empty()) {
            std::cout << line << std::endl;
        }
    }

    if (!m_playerTexture.loadFromFile("assets/images/eye.png")) { /* error */ }
    m_playerSprite.setTexture(m_playerTexture);
    m_playerSprite.setPosition(WINDOW_SIZE_X * 0.1, 1080 * 0.06);
    m_playerSprite.setScale(0.5f, 0.5f);

    // for (int i = 0; i < 10; i++) {
    //     m_notes.push_back(Note(
    //         sf::Vector2f(WINDOW_SIZE_X - NOTE_SIZE + i * 75, 108 * i + 50),
    //         NOTE_SIZE,
    //         0.1f,
    //         sf::Color::Red
    //     ));
    // }
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
    m_window.Draw(m_playerSprite);

    m_window.EndDraw();
}

void Game::Tick() {
    sf::Event event = m_window.Tick();

    int y = sin(m_clock.getElapsedTime().asSeconds() * 2) * 25 + 100;
    m_playerSprite.setPosition(m_playerSprite.getPosition().x, m_backgroundSprite.getPosition().y + y);
}