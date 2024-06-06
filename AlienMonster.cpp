#include "AlienMonster.h"
#include "../../EarthArmy.h"
#include "../../AlienArmy.h"
#include "../../GameRules.h"

AlienMonster::AlienMonster(int id, const string& unitType, int jointime, int hp, int pow, int attackcap): ArmyUnit(id, unitType, jointime, hp, pow, attackcap) {}
void AlienMonster::Attack(GameRules* game, EarthArmy* army, AlienArmy* armyA)
{
	// Alien Monster should attack both ET & ES, if they both exist
	// If one does not exist it attacks other

	ArrayStack<EarthTank*> tempTank;
	EarthTank* unitattacked_T;
	EarthSoldier* unitattacked_S;

	AlienMonster* attacking;
	if (army->getET_List().isEmpty() && army->getES_List().isEmpty()) return; // check first, if there is no ET & ES that exist THEN no need to enter loop
	for (int i = 0; i < attackCapacity; i++)
	{
		if (armyA->getAM_List().pop(attacking))
		{
			if (army->getET_List().isEmpty() || army->getES_List().isEmpty())
			{
				if (!army->getET_List().isEmpty()) //Attacking Earth Tank
				{
					army->getET_List().pop(unitattacked_T);
					int* Tank_Hp = unitattacked_T->getHealth();
					cout << "AM: [" << this->getID() << "] shoots ET: [" << unitattacked_T->getID() << "]" << "\n\n";
					int M_power = attacking->getPower();
					int *M_health = attacking->getHealth();
					*Tank_Hp -= (M_power * *M_health / 100) / sqrt(*Tank_Hp);
					if (*unitattacked_T->getHealth() <= 0)
						game->getkilledlist().enqueue(unitattacked_T);
					else
						tempTank.push(unitattacked_T);
				}

				if (!army->getES_List().isEmpty()) //Attacking Earth Soldier
				{
					army->getES_List().dequeue(unitattacked_S);
					int* Sold_Hp = unitattacked_S->getHealth();
					cout << "AM: [" << this->getID() << "] shoots ES: [" << unitattacked_S->getID() << "]" << "\n\n";
					int M_power = attacking->getPower();
					int* M_health = attacking->getHealth();
					*Sold_Hp -= (M_power * *M_health / 100) / sqrt(*Sold_Hp);
					if (*unitattacked_S->getHealth() <= 0)
						game->getkilledlist().enqueue(unitattacked_S);
					else
						army->getES_List().enqueue(unitattacked_S);
				}
				armyA->getAM_List().add(attacking);
			}
			else
			{
				if (i % 2 != 0) //Attack is divided between both ET and ES if BOTH lists are not empty
				{
					//Attacking Earth Tank
					army->getET_List().pop(unitattacked_T);
					int* Tank_Hp = unitattacked_T->getHealth();
					cout << "AM: [" << this->getID() << "] shoots ET: [" << unitattacked_T->getID() << "]" << "\n\n";
					int M_power = attacking->getPower();
					int* M_health = attacking->getHealth();
					*Tank_Hp -= (M_power * *M_health / 100) / sqrt(*Tank_Hp);
					if (*unitattacked_T->getHealth() <= 0)
						game->getkilledlist().enqueue(unitattacked_T);
					else
						tempTank.push(unitattacked_T);
				}
				else
				{
					//Attacking Earth Soldier
					army->getES_List().dequeue(unitattacked_S);
					int* Sold_Hp = unitattacked_S->getHealth();
					cout << "AM: [" << this->getID() << "] shoots ES: [" << unitattacked_S->getID() << "]" << "\n\n";
					int M_power = attacking->getPower();
					int* M_health = attacking->getHealth();
					*Sold_Hp -= (M_power * *M_health / 100) / sqrt(*Sold_Hp);
					if (*unitattacked_S->getHealth() <= 0)
						game->getkilledlist().enqueue(unitattacked_S);
					else
						army->getES_List().enqueue(unitattacked_S);
				}
				armyA->getAM_List().add(attacking);
			}
		}
		
	}

	while (!tempTank.isEmpty())
	{
		tempTank.pop(unitattacked_T);
		army->getET_List().push(unitattacked_T);
	}
}