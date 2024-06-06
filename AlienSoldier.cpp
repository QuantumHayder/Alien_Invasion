#include "AlienSoldier.h"
#include "../../EarthArmy.h"
#include "../../GameRules.h"

AlienSoldier::AlienSoldier(int id, const string& unitType, int jointime, int hp, int pow, int attackcap) : ArmyUnit(id, unitType, jointime, hp, pow, attackcap) {}

////////////////////PHASE 2////////////////////
void AlienSoldier::Attack(GameRules* game,EarthArmy* army)
{
	int count = 0;
	EarthSoldier* unitattacked;
	while (army->getES_List().dequeue(unitattacked) && count < attackCapacity) {
		int* unitattackedhp = unitattacked->getHealth();
		*unitattackedhp -= (power * health / 100) / sqrt(*unitattackedhp);
		cout << "Alien Soldier with ID " << ID << " is attacking Earth Soldier with ID " << unitattacked->getID() << endl;
		if (*unitattackedhp <= 0) {
			game->getkilledlist().enqueue(unitattacked);
			unitattacked->setTD(game->gettimeStep());
		}
		else
			army->getES_List().enqueue(unitattacked);
		count++;
	}
}
