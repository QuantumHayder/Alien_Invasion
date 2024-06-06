#pragma once
#include "../ArmyUnit.h"
class AlienArmy;
class GameRules;
class EarthGunnery:public ArmyUnit
{
	public:
		EarthGunnery(int id, const string& unitType, int jointime, int hp, int pow, int attackcap);
		void Attack(GameRules* game, AlienArmy* army);
};
