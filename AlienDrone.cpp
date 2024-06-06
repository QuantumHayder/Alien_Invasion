#include "AlienDrone.h"
#include "../../EarthArmy.h"
#include "../../GameRules.h"

AlienDrone::AlienDrone(int id, const string& unitType, int jointime, int hp, int pow, int attackcap): ArmyUnit(id, unitType , jointime, hp, pow, attackcap) {}
void AlienDrone::Attack(GameRules* game, AlienArmy* armyA, EarthArmy* armyE)
{
	ArrayStack<EarthTank*> tempTank;
	EarthTank* unitattacked_T;
	EarthGunnery* unitattacked_G; int Gun_pri;

	AlienDrone* attacking_front;
	AlienDrone* attacking_rear;

	if (armyE->getET_List().isEmpty() && armyE->getEG_List().isEmpty()) return; // check first, if there is no ET & EG that exist THEN no need to enter loop
	for (int i = 0; i < attackCapacity; i++)
	{
		if (armyE->getET_List().peek(unitattacked_T) && armyE->getEG_List().peek(unitattacked_G, Gun_pri))
		{
			if (armyA->getAD_List().peek(attacking_front) && armyA->getAD_List().peekRear(attacking_rear))
			{
				armyA->getAD_List().dequeue(attacking_front);
				armyA->getAD_List().dequeueRear(attacking_rear);

				//Drone from front attacks Tanks
				armyE->getET_List().pop(unitattacked_T);
				int* Tank_Hp = unitattacked_T->getHealth();
				int front_power = attacking_front->getPower();
				int* front_health = attacking_front->getHealth();
				cout << "AD: [" << this->getID() << "] shoots ET: [" << unitattacked_T->getID() <<"]" << "\n\n";
				*Tank_Hp -= (front_power * *front_health / 100) / sqrt(*Tank_Hp);
				if (*unitattacked_T->getHealth() <= 0)
					game->getkilledlist().enqueue(unitattacked_T);
				else
					tempTank.push(unitattacked_T);

				//Drone from rear attacks Gunnery
				armyE->getEG_List().dequeue(unitattacked_G, Gun_pri);
				int* Gun_Hp = unitattacked_G->getHealth();
				int rear_power = attacking_rear->getPower();
				int* rear_health = attacking_rear->getHealth();
				cout << "AD: [" << this->getID() << "] shoots ET: [" << unitattacked_T->getID() << "]" << "\n\n";
				*Gun_Hp -= (front_power * *front_health / 100) / sqrt(*Gun_Hp);
				if (*unitattacked_G->getHealth() <= 0)
					game->getkilledlist().enqueue(unitattacked_G);
				else
					armyE->getEG_List().enqueue(unitattacked_G, Gun_pri);

				armyA->getAD_List().enqueue(attacking_front);
				armyA->getAD_List().enqueue(attacking_rear);
			}
		}
		
	}

	while (!tempTank.isEmpty())
	{
		tempTank.pop(unitattacked_T);
		armyE->getET_List().push(unitattacked_T);
	}
}