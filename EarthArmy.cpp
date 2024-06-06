#include "EarthArmy.h"
#include "AlienArmy.h"
#include "GameRules.h"
class Healer;

bool EarthArmy::AddUnit(EarthSoldier* unit)
{
	return ES_List.enqueue(unit);
}

bool EarthArmy::AddUnit(EarthTank* unit)
{
	return ET_List.push(unit);
}

bool EarthArmy::AddUnit(EarthGunnery* unit)
{
	int highestcombo = (*unit->getHealth() * unit->getPower()); //highest product of health and power of unit is best
	return EG_List.enqueue(unit, highestcombo);
}

bool EarthArmy::AddUnit(Healer* unit) {
	return HU_List.push(unit);
}

int EarthArmy::ES_Count()
{
	LinkedQueue<EarthSoldier*> temp(ES_List);
	int EScount = 0;
	EarthSoldier* temppointer;
	while (!temp.isEmpty()) {
		temp.dequeue(temppointer);
		EScount++;
	}
	return EScount;
}

void EarthArmy::ES_PrintID()
{
	LinkedQueue<EarthSoldier*> temp(ES_List);
	int count=ES_Count();
	cout << count << " Earth Soldiers" << endl;
	temp.print();
}

int EarthArmy::ET_Count()
{
	ArrayStack<EarthTank*> temp(ET_List);
	int ETcount = 0;
	EarthTank* temppointer;
	while (!temp.isEmpty()) {
		temp.pop(temppointer);
		ETcount++;
	}
	return ETcount;
}

void EarthArmy::ET_PrintID()
{
	ArrayStack<EarthTank*> temp(ET_List);
	cout << ET_Count() << " Earth Tanks " << endl;
	temp.print();
}

int EarthArmy::EG_Count()
{
	priQueue<EarthGunnery*> temp;
	int EGcount = 0;
	int trash = 0;
	EarthGunnery* temppointer;
	while (!EG_List.isEmpty()) {
		EG_List.dequeue(temppointer, trash);
		temp.enqueue(temppointer,trash);
		EGcount++;
	}
	while (!temp.isEmpty()) {
		temp.dequeue(temppointer, trash);
		EG_List.enqueue(temppointer, trash);
	}
	return EGcount;
}

void EarthArmy::EG_PrintID()
{
	cout << EG_Count() << " Earth Gunneries " << endl;
	getEG_List().print();
}

int EarthArmy::HU_Count()
{
	ArrayStack<Healer*> temp(HU_List);
	int HUcount = 0;
	Healer* temppointer;
	while (!temp.isEmpty()) {
		temp.pop(temppointer);
		HUcount++;
	}
	return HUcount;
}

void EarthArmy::HU_PrintID()
{
	ArrayStack<Healer*> temp(HU_List);
	cout << HU_Count() << " Healer units " << endl;
	temp.print();
}

int EarthArmy::getTotalCount()
{
	return (ES_Count() + ET_Count() + EG_Count()+ HU_Count());
}

void EarthArmy::print()
{
	cout << "============== Earth Army Alive Units ==============" << endl;
	ES_PrintID();
	ET_PrintID();
	EG_PrintID();
	HU_PrintID();
}

void EarthArmy::Attack(GameRules* game,AlienArmy* alien)
{
	EarthSoldier* earthsold;
	EarthGunnery* earthgunnery;
	EarthTank* earthtank;
	Healer* Alaadin;
	int pri;
	for (int i = 0; i < ES_Count(); i++) {
		ES_List.dequeue(earthsold);
		earthsold->Attack(game,alien);
		ES_List.enqueue(earthsold);
	}
	/*for (int i = 0; i < EG_Count(); i++) {
		int pri;
		EG_List.dequeue(earthgunnery,pri);
		earthgunnery->Attack(game, alien);
		EG_List.enqueue(earthgunnery,pri);
	}*/
	for (int i = 0; i < ET_Count(); i++) {
		ET_List.pop(earthtank);
		earthtank->Attack(game, alien, this);
		ET_List.push(earthtank);
	}
	if (!HU_List.isEmpty())
	{
		HU_List.pop(Alaadin);
		Alaadin->attack(UML, game, this);
		Alaadin->setTD(game->gettimeStep());
		Alaadin->setDb(game->gettimeStep() - Alaadin->getJoinTime());
	    game->getkilledlist().enqueue( Alaadin);
	}

}

LinkedQueue<EarthSoldier*>& EarthArmy::getES_List()
{
	return ES_List;
}

ArrayStack<EarthTank*>& EarthArmy::getET_List()
{
	return ET_List;
}

priQueue<EarthGunnery*>& EarthArmy::getEG_List()
{
	return EG_List;
}

ArrayStack<Healer*>& EarthArmy::getHU_List()
{
	return HU_List;
}

priQueue<ArmyUnit*>& EarthArmy::getUML()
{
	return UML;
}