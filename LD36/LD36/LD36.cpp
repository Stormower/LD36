// LD36.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main()
{
	using namespace std;
	/*
 
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.display();
	}*/
	string command;
	int nWorkers = 0;
	while (1)
	{
		cin >> command;
		if (command == "w")
		{
			nWorkers++;
		}
		if (command == "displayw")
		{
			cout << "There are " << nWorkers << "Workers \r\n";
		}
	}
	return 0;
}