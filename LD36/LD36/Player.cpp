#include <string>
#include <map>
#include <vector>

class Player
{
private:
	string m_Name;
	int m_Gold;
	int m_nWorkers;
	map <string, bool> m_Researches;
	//vector m_Units;
	int m_Life = 10000;

public:
	void initResearches();
	void addWorker(int);
	void takeDamage(int);
	void heal(int);
	void earnGolds(int);
	void addResearche(string);
};

voi  Player::initResearches()
{
	m_Researches["r1"] = 0;
	m_Researches["r2"] = 0;
	m_Researches["r3"] = 0;
	m_Researches["r4"] = 0;
	m_Researches["r5"] = 0;

}

void Player::addWorker(int numbWorkers)
{
	m_nWorkers += numbWorkers;
}

void Player::takeDamage(int damage)
{
	m_Life -= damage;
}

void Player::heal(int heal)
{
	m_Life += heal;
}

void Player::earnGolds(int gold)
{
	m_Gold += gold;
}

void Player::addResearche(string researchName)
{
	m_Researches[researchName] = 1;
}