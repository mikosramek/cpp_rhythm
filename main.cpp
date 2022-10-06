#include <iostream>
#include <SFML/Window.hpp>

int main() {
    std::cout << "Hello World" << std::endl;

    sf::Window window(sf::VideoMode(800, 600), "Rhythm");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    
    return 0;
}