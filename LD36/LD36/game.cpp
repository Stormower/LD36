#include "stdafx.h"
#include "game.hpp"
#include <stdlib.h>


Game::Game()
	: m_Window(sf::VideoMode(500, 400), "Stratege") {
	m_Clock.restart();
}

void Game::init() {
	char* path;
	_get_pgmptr(&path);
	sf::Font font;
	if (!font.loadFromFile("C://Users/Nicolas/Source/Repos/LD36/LD36/Debug/arial.ttf"))
	{
		std::cout << "Police non chargée" << endl;
	}
	m_txtGold.setFont(font);
	m_txtWorkers.setFont(font);
	m_txtGold.setCharacterSize(18);
	m_txtWorkers.setCharacterSize(18);
	m_txtGold.setColor(sf::Color::Yellow);
	m_txtWorkers.setColor(sf::Color::Blue);
	m_txtWorkers.setPosition(0, 0);
	m_txtGold.setPosition(400, 0);
}

void Game::run() {
	std::cout << m_NewTime.asMilliseconds() << endl;
	init();
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
				if (m_Player.getGold() - 7 >= 0) {
					m_Player.addWorker(1);
					std::cout << "Recruited a worker for 7 Gold" << std::endl;
					m_Player.useGold(7);
					m_txtGold.setString(std::to_string(m_Player.getGold()));
					m_txtWorkers.setString(std::to_string(m_Player.getnWorkers()));
				}
				else {
				std::cout << "Not enough Gold !!" << std::endl;
				}
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
		m_txtGold.setString(std::to_string(m_Player.getGold()));
	}	
}

void Game::render() {
	m_Window.draw(m_txtGold);
	m_Window.draw(m_txtWorkers);
	m_Window.display();
}