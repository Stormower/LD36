#include "stdafx.h"
#include "game.hpp"

Game::Game()
	: m_Window(sf::VideoMode(500, 400), "Stratege") {
	m_Clock.restart();
}

void Game::init() {
}

void Game::run() {
	std::cout << m_NewTime.asMilliseconds() << endl;
	while (m_Window.isOpen())
	{
		sf::Time elapsed = m_Clock.getElapsedTime();
		update(elapsed);
		draw();
		render();
	}
}

void Game::draw() {
	m_Window.clear();
}

void Game::update(sf::Time elapsedTime) {

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
				std::cout << "There are " << m_Player.getnWorkers() << " Workers \r\n";
				break;
			}

		}
	}

	m_NewTime = elapsedTime;

	if ((m_NewTime.asMilliseconds() - m_OldTime.asMilliseconds()) >= 3000)
	{
		std::cout << "You have " << m_Player.getGold() << " gold \r\n";
		m_OldTime = m_NewTime;
		m_Player.earnGolds();
	}	
}

void Game::render() {
	m_Window.display();
}