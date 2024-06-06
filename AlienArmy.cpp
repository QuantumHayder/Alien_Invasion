#include "AlienArmy.h"
#include "EarthArmy.h"
#include "GameRules.h"
bool AlienArmy::AddUnit(AlienSoldier* unit) 
{
	return AS_List.enqueue(unit);
}

bool AlienArmy::AddUnit(AlienDrone* unit)
{
	return AD_List.enqueue(unit);
}

bool AlienArmy::AddUnit(AlienMonster* unit)
{
	return AM_List.add(unit);
}

void AlienArmy::Attack(GameRules* game,EarthArmy* earth)
{
	AlienSoldier* aliensold;
	AlienDrone* aliendrone;
	AlienMonster* alienmonster;
	for (int i = 0; i < AS_Count(); i++) {
		AS_List.dequeue(aliensold);
		aliensold->Attack(game, earth);
		AS_List.enqueue(aliensold);
	}
	for (int i = 0; i < AD_Count(); i++) {
		AD_List.dequeue(aliendrone);
		aliendrone->Attack(game, this, earth);
		AD_List.enqueue(aliendrone);
	}
	for (int i = 0; i < AM_Count(); i++) {
		AM_List.pop(alienmonster);
		alienmonster->Attack(game, earth,this);
		AM_List.add(alienmonster);
	}
}

int AlienArmy::AS_Count()
{
	LinkedQueue<AlienSoldier*> temp(AS_List);
	int AScount = 0;
	AlienSoldier* temppointer;
	while (!temp.isEmpty()) {
		temp.dequeue(temppointer);
		AScount++;
	}
	return AScount;
}

void AlienArmy::AS_PrintID()
{
	LinkedQueue<AlienSoldier*> temp(AS_List);
	int count = AS_Count();
	cout << count << " Alien Soldiers" << endl;
	temp.print();
}

int AlienArmy::AD_Count()
{
	Deque<AlienDrone*> temp(AD_List);
	int ADcount = 0;
	AlienDrone* temppointer;
	while (!temp.isEmpty()) {
		temp.dequeue(temppointer);
		ADcount++;
	}
	return ADcount;
}

void AlienArmy::AD_PrintID()
{
	Deque<AlienDrone*> temp(AD_List);
	cout << AD_Count() << " Alien Drones " << endl;
	temp.print();
}

int AlienArmy::AM_Count()
{
	return AM_List.getCurrentSize();
}

void AlienArmy::AM_PrintID()
{
	ArrayBag<AlienMonster*> temp(AM_List);
	AlienMonster* temppointer;
	cout << AM_Count() << " Alien Monsters " << endl;
	temp.print();
}

int AlienArmy::getTotalCount()
{
	return (AS_Count() + AD_Count() + AM_Count());
}

void AlienArmy::print()
{
	cout << endl;
	cout << "============== Alien Army Alive Units ==============" << endl;
	AS_PrintID();
	AD_PrintID();
	AM_PrintID();
}

LinkedQueue<AlienSoldier*>& AlienArmy::getAS_List()
{
	return AS_List;
}

Deque<AlienDrone*>& AlienArmy::getAD_List()
{
	return AD_List;
}

ArrayBag<AlienMonster*>& AlienArmy::getAM_List()
{
	return AM_List;
}