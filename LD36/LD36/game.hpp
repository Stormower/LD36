#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <string>
#include "Player.hpp"


class Game {
private:
	sf::RenderWindow m_Window;
	Player m_Player;

public:
	Game();
	void init();
	void run();
	void draw();
	void update();
	void render();
};