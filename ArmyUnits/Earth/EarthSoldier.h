#pragma once
#include "../ArmyUnit.h"
class AlienArmy;
class GameRules;
class EarthSoldier :public ArmyUnit
{
	public:
		EarthSoldier(int id, const string& unitType, int jointime, int hp, int pow, int attackcap);
		void Attack(GameRules* game, AlienArmy* army);
};
