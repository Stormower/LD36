// LD36.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main()
{
	using namespace std;

 
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	string command;
	int nWorkers = 0;
	int gold = 0;
	sf::Clock clock;
	sf::Time newTime, oldTime;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case (sf::Keyboard::Key::W): 
					nWorkers++;
					cout << "recruited a worker" << endl;
					break;
				case (sf::Keyboard::Key::D):
					cout << "There are " << nWorkers << " Workers \r\n";
					break;
				}

			}
		}
	

		sf::Time elapsed = clock.getElapsedTime();
		newTime = elapsed;
		//cout << (newTime.asMilliseconds() - oldTime.asMilliseconds()) << endl;
		if ((newTime.asMilliseconds() - oldTime.asMilliseconds()) >= 1000)
		{
			cout << "You have " << gold << " gold \r\n";
			oldTime = newTime;
			gold += nWorkers;
		}
		

		window.clear();
		window.display();
	}
	
	while (1)
	{
	
	}
	return 0;
}