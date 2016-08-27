#pragma once
#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;
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
	int getnWorkers();
	int getGold();
};