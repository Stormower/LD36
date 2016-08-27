#include <SFML/Graphics.hpp>

class Game {
private:
	sf::RenderWindow m_Window;

public:
	Game();
	void init();
	void run();
	void draw();
	void update();
	void render();
};

Game(): m_Window(sf::VideoMode(500, 400), "Stratege") {

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
	string command;
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
				nWorkers++;
				cout << "recruited a worker" << endl;
				break;
			case (sf::Keyboard::Key::D) :
				cout << "There are " << nWorkers << " Workers \r\n";
				break;
			}

		}
	}


	sf::Time elapsed = clock.getElapsedTime();
	newTime = elapsed;

	if ((newTime.asMilliseconds() - oldTime.asMilliseconds()) >= 1000)
	{
		cout << "You have " << gold << " gold \r\n";
		oldTime = newTime;
		gold += nWorkers;
	}	
}

void Game::render() {
	m_Window.display();
}