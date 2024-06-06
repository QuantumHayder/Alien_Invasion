#pragma once
#include "ADS/LinkedQueue.h"
#include "ArmyUnits/Earth/Saver.h"
#include"GameRules.h"

class EarthArmy;
class AlienArmy;
class GameRules;
class Saver;
class AllyArmy
{
	LinkedQueue<Saver*> SU_List;

public:
	bool AddUnit(Saver* unit);
	int SU_Count();
	void SU_PrintID();
	void print();
	void Attack(GameRules* game, AlienArmy* alien);
	void Withdraw();
};

