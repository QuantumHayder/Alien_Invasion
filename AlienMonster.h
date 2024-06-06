#pragma once
#include "../ArmyUnit.h"
class EarthArmy;
class AlienArmy;
class GameRules;
class AlienMonster: public ArmyUnit
{
	public:
		AlienMonster(int id, const string& unitType, int jointime, int hp, int pow, int attackcap);
		void Attack(GameRules* game, EarthArmy* army, AlienArmy* amryA);
};
