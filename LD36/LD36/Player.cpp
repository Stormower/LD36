#include "stdafx.h"
#include "Player.hpp"

int Player::getGold()
{
	return m_Gold;
}

int Player::getnWorkers()
{
	return m_nWorkers;
}

void  Player::initResearches()
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