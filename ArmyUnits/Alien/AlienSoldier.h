#pragma once
#include "../ArmyUnit.h"
class EarthArmy;
class GameRules;
class AlienSoldier : public ArmyUnit 
{
	public:
		AlienSoldier(int id, const string& unitType, int jointime, int hp, int pow, int attackcap);
		void Attack(GameRules* game,EarthArmy* army);
};
