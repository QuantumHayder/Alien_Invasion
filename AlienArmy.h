#pragma once
#include "ArmyUnits/Alien/AlienSoldier.h"
#include"ArmyUnits/Alien/AlienDrone.h"
#include "ArmyUnits/Alien/AlienMonster.h"
#include "ADS/Deque.h"
#include "ADS/ArrayBag.h"
#include "ADS/LinkedQueue.h"
class EarthArmy;
class GameRules;
class AlienArmy
{
		private:
			LinkedQueue<AlienSoldier*> AS_List;
			Deque<AlienDrone*> AD_List;
			ArrayBag<AlienMonster*> AM_List;
		public:
			AlienArmy() {};
			bool AddUnit(AlienSoldier* unit);
			bool AddUnit(AlienDrone* unit);
			bool AddUnit(AlienMonster* unit);
			//void Attack(EarthArmy* earth);
			int AS_Count();
			void AS_PrintID();
			int AD_Count();
			void AD_PrintID();
			int AM_Count();
			void AM_PrintID();
			int getTotalCount();
			void print();
			void Attack(GameRules* game,EarthArmy* earth);

			LinkedQueue<AlienSoldier*>& getAS_List();
			Deque<AlienDrone*>& getAD_List();
			ArrayBag<AlienMonster*>& getAM_List();
};