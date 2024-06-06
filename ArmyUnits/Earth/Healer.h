#pragma once
#include "../ArmyUnit.h"
#include"../../ADS/priQueue.h"
#include"../../GameRules.h"
//#include"../../EarthArmy.h"
class EarthArmy;

class Healer :
    public ArmyUnit
{
private:
    priQueue<ArmyUnit*> templist;
public:
    Healer(int id, const string& unitType, int jointime, int hp, int pow, int attackcap);
    void attack(priQueue<ArmyUnit*>&, GameRules*, EarthArmy*);

};
