#include "EarthSoldier.h"
#include "../../AlienArmy.h"
#include "../../GameRules.h"

EarthSoldier::EarthSoldier(int id, const string& unitType, int jointime, int hp, int pow, int attackcap):ArmyUnit(id, unitType, jointime, hp, pow, attackcap) {}

void EarthSoldier::Attack(GameRules* game, AlienArmy* army)
{
	int count = 0;
	AlienSoldier* unitattacked;
	while (army->getAS_List().dequeue(unitattacked) && count < attackCapacity && count < army->AS_Count()) {
		int* unitattackedhp = unitattacked->getHealth();
		*unitattackedhp -= (power * health / 100) / sqrt(*unitattackedhp);
		cout << "Earth Soldier with ID " << ID << " is attacking Alien Soldier with ID " << unitattacked->getID() << endl;
		if (*unitattackedhp <= 0) {
			game->getkilledlist().enqueue(unitattacked);
			unitattacked->setTD(game->gettimeStep());
		}
		else
			army->getAS_List().enqueue(unitattacked);
		count++;
	}
}