#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <string>
#include "Player.hpp"


class Game {
private:
	sf::RenderWindow m_Window;
	Player m_Player;
	sf::Time m_NewTime, m_OldTime;
	sf::Clock m_Clock;
	sf::Text m_txtGold;
	sf::Text m_txtWorkers;

public:
	Game();
	void init();
	void run();
	void draw();
	void update(sf::Time);
	void render();
};