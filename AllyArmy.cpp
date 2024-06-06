#include "AllyArmy.h"

bool AllyArmy::AddUnit(Saver* unit)
{
	return SU_List.enqueue(unit);
}

int AllyArmy::SU_Count()
{
	LinkedQueue<Saver*> temp(SU_List);
	int SUcount = 0;
	Saver* temppointer;
	while (!temp.isEmpty()) {
		temp.dequeue(temppointer);
		SUcount++;
	}
	return SUcount;
}

void AllyArmy::SU_PrintID()
{
	LinkedQueue<Saver*> temp(SU_List);
	int count = SU_Count();
	cout << count << " Saver Units" << endl;
	temp.print();
}

void AllyArmy::print()
{
	SU_PrintID();
}

void AllyArmy::Attack(GameRules* game, AlienArmy* alien)
{
	Saver* saverunit;
	for (int i = 0; i < SU_Count(); i++) {
		SU_List.dequeue(saverunit);
		saverunit->Attack(game, alien);
		SU_List.enqueue(saverunit);
	}
}

void AllyArmy::Withdraw()
{
	Saver* trash;
	for (int i = 0; i < SU_Count(); i++) {
		SU_List.dequeue(trash);
		delete trash;
	}
}
