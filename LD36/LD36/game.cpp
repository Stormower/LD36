#include "stdafx.h"
#include "game.hpp"

Game::Game()
	: m_Window(sf::VideoMode(500, 400), "Stratege") {

}

void Game::init() {
}

void Game::run() {
	while (m_Window.isOpen())
	{
		update();
		draw();
		render();
	}
}

void Game::draw() {
	m_Window.clear();
}

void Game::update() {
	std::string command;
	int nWorkers = 0;
	int gold = 0;
	sf::Clock clock;
	sf::Time newTime, oldTime;

	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_Window.close();
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case (sf::Keyboard::Key::W) :
				m_Player.addWorker(1);
				std::cout << "recruited a worker" << std::endl;
				
				break;
			case (sf::Keyboard::Key::D) :
				nWorkers = m_Player.getnWorkers();
				std::cout << "There are " << nWorkers << " Workers \r\n";
				break;
			}

		}
	}


	sf::Time elapsed = clock.getElapsedTime();
	newTime = elapsed;

	if ((newTime.asMilliseconds() - oldTime.asMilliseconds()) >= 1000)
	{
		std::cout << "You have " << gold << " gold \r\n";
		oldTime = newTime;
		gold += nWorkers;
	}	
}

void Game::render() {
	m_Window.display();
}