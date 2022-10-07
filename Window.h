#pragma once
#include <SFML/Graphics.hpp>

class Window
{
public:
    Window(const std::string& l_title, const sf::Vector2u& l_size);
    Window();
    ~Window();

    void BeginDraw();
    void EndDraw();

    bool IsDone();
	sf::Vector2u GetWindowSize();

	bool IsFullscreen();
    void ToggleFullscreen();

	sf::Event& Tick();

    void Draw(sf::Drawable& l_drawable);
	sf::RenderWindow* GetRenderWindow();
private:
    void Setup(const std::string& l_title, const sf::Vector2u& l_size);
	void Destroy();
	void Create();

	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isDone;
	bool m_isFullscreen;
};