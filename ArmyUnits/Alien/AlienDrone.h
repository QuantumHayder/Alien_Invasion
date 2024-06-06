#pragma once
#include "../ArmyUnit.h"
#include "../../ADS/ArrayStack.h"
class AlienArmy;
class EarthArmy;
class GameRules;
class AlienDrone : public ArmyUnit
{
	public:
		AlienDrone(int id, const string& unitType, int jointime, int hp, int pow, int attackcap);
		void Attack(GameRules* game, AlienArmy* armyA, EarthArmy* armyE);
};