#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Note.h"

using Notes = std::vector<Note>;

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Rhythm");

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    int shapeX = 0;
    shape.setPosition(shapeX, shape.getPosition().y);

    bool spaceStatus = false;

    float NOTE_SIZE = 50;

    Notes m_notes;
    m_notes.clear();

    for (int i = 0; i < 10; i++) {
        m_notes.push_back(Note(
            sf::Vector2f(1920 - NOTE_SIZE + i * 75, 108 * i + 50),
            NOTE_SIZE,
            0.1f,
            sf::Color::Red
        ));
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
            window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            shapeX -= 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            shapeX += 1;
        }

        bool previousSpace = spaceStatus;
        spaceStatus = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

        if (!previousSpace && spaceStatus) {
            std::cout << "pressed" << std::endl;
        }

        shape.setPosition(shapeX, shape.getPosition().y);

        for (int i = 0; i < m_notes.size(); i += 1) {
            m_notes[i].Tick();
        }

        window.clear();
        window.draw(shape);
        for (int i = 0; i < m_notes.size(); i += 1) {
            m_notes[i].Render(window);
        }
        window.display();
    }
    
    return 0;
}