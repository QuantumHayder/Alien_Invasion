#include "Healer.h"

Healer::Healer(int id, const string& unitType, int jointime, int hp, int pow, int attackcap) 
	:ArmyUnit(id, unitType, jointime, hp, pow, attackcap) {}

void Healer::attack(priQueue<ArmyUnit*>& UML, GameRules* myGame, EarthArmy* myEarth) {
	if (!UML.isEmpty())
	{
		ArmyUnit* tempptr;
		int pri;
		for (int i = 0; i < attackCapacity; i++)
		{
			UML.dequeue(tempptr, pri);
			if ((myGame->gettimeStep() - tempptr->getUML_joinTime()) > 10)
			{
				myGame->getkilledlist().enqueue(tempptr);
			}
			else
			{
				int redBull = (power * (health / 100)) / sqrt(*tempptr->getHealth());
				tempptr->setHealth(redBull);
			}
			if ((*tempptr->getHealth()) > (0.2 * (tempptr->getjoinHealth())))
			{
				EarthSoldier* revivedSoldier = static_cast<EarthSoldier*>(tempptr);
				EarthTank* revivedTank = static_cast<EarthTank*>(tempptr);
				if (revivedSoldier)
				{
					myEarth->AddUnit(revivedSoldier);
				}
				else if (revivedTank)
				{
					myEarth->AddUnit(revivedTank);
				}
			}
			else
			{
				templist.enqueue_UML(tempptr, pri);
			}

		}
		while (!templist.isEmpty())
		{
			templist.dequeue(tempptr, pri);
			UML.enqueue_UML(tempptr, pri);
		}
	}
}
