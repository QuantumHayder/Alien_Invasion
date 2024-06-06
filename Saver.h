#pragma once
#include "../ArmyUnit.h"
class AlienArmy;
class GameRules;
class Saver : public ArmyUnit
{
    public:
        Saver(int id, const string& unitType, int jointime, int hp, int pow, int attackcap);
        void Attack(GameRules* game, AlienArmy* army);
};

