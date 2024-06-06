#include "EarthTank.h"
#include "../../AlienArmy.h"
#include "../../GameRules.h"

EarthTank::EarthTank (int id, const string& unitType, int jointime, int hp, int pow, int attackcap) : ArmyUnit(id, unitType, jointime, hp, pow, attackcap){}
void EarthTank::Attack(GameRules* game, AlienArmy* armyA, EarthArmy* armyE)
{
	ArrayStack<AlienMonster*> tempMons;
	AlienMonster* unitattacked_m;
	AlienSoldier* unitattacked_s;
	//if (armyA->getAM_List().isEmpty() && armyA->getAS_List().isEmpty()) return; // check first, if there is no AM & AS that exist THEN no need to enter loop
	for (int i = 0; i < attackCapacity; i++)
	{
		if (armyE->ES_Count() < 0.3 * armyA->AS_Count()) //Checks Count of ES to AS
		{
			// Tank here should attack both AM & AS, if they both exist
			// If one does not exist it attacks other

			if (!armyA->getAM_List().isEmpty()) //Tank attacks an AM if exists
			{
				armyA->getAM_List().pop(unitattacked_m);
				int* M_Hp = unitattacked_m->getHealth();
				cout << "\n ET: [" << this->getID() << "] shoots AM: [" << unitattacked_m->getID() << "]" << "\n";
				*M_Hp -= (power * health / 100) / sqrt(*M_Hp);
				if (*unitattacked_m->getHealth() <= 0)
					game->getkilledlist().enqueue(unitattacked_m);
				else
					tempMons.push(unitattacked_m);
			}
				
			if (!armyA->getAS_List().isEmpty()) //Tank attacks an AS if exists
			{
				armyA->getAS_List().dequeue(unitattacked_s);
				int* S_Hp = unitattacked_s->getHealth();
				cout << "\n ET: [" << this->getID() << "] shoots AS: [" << unitattacked_s->getID() << "]" << "\n";
				*S_Hp -= (power * health / 100) / sqrt(*S_Hp);
				if (*unitattacked_s->getHealth() <= 0)
					game->getkilledlist().enqueue(unitattacked_s);
				else
					armyA->getAS_List().enqueue(unitattacked_s);
			}		
		}
		else if (armyE->ES_Count() >= 0.8 * armyA->AS_Count()) //Checks Count of ES to AS
		{
			if (!armyA->getAM_List().isEmpty())
			{
				armyA->getAM_List().pop(unitattacked_m);
				int* M_Hp = unitattacked_m->getHealth();
				cout << "\n ET: [" << this->getID() << "] shoots AM: [" << unitattacked_m->getID() << "]" << "\n";
				*M_Hp -= (power * health / 100) / sqrt(*M_Hp);
				if (*unitattacked_m->getHealth() <= 0)
					game->getkilledlist().enqueue(unitattacked_m);
				else
					tempMons.push(unitattacked_m);
			}
		}
		else //for case when count is between 0.3 and 0.8
		{
			if (!armyA->getAM_List().isEmpty())
			{
				armyA->getAM_List().pop(unitattacked_m);
				int* M_Hp = unitattacked_m->getHealth();
				cout << "\n ET: [" << this->getID() << "] shoots AM: [" << unitattacked_m->getID() << "]" << "\n";
				*M_Hp -= (power * health / 100) / sqrt(*M_Hp);
				if (*unitattacked_m->getHealth() <= 0)
					game->getkilledlist().enqueue(unitattacked_m);
				else
					tempMons.push(unitattacked_m);
			}
		}
	}

	while (!tempMons.isEmpty())
	{
		tempMons.pop(unitattacked_m);
		armyA->getAM_List().add(unitattacked_m);
	}
}