#include "Generator.h"
#include"GameRules.h"
using namespace std;

Generator::Generator(Input* i1,EarthArmy* e1, AlienArmy* a1, GameRules* g1) {
	I1 = i1;
	E1 = e1;
	A1 = a1;
	G1 = g1;
	srand(time(0));
}

void Generator::generateEarth() {
	int jointime, id, attackcap, power, hp;
	int A = rand() % (100) + 1;
	if (A <= I1->getProb())
	{
		for (int i = 0; i < I1->getN(); i++)
		{
			int B= rand() % (100) + 1;
			if (B > 0 && B < I1->getES())
			{
				jointime=(G1->gettimeStep());
				id=nextEarthid++;
				hp=(rand() % (I1->geteHealth_upper() - I1->geteHealth_lower() + 1) + I1->geteHealth_lower());
				attackcap=(rand() % (I1->geteAttack_upper() - I1->geteAttack_lower() + 1) + I1->geteAttack_lower());
				power=(rand() % (I1->getePower_upper() - I1->getePower_lower() + 1) + I1->getePower_lower());
				EarthSoldier* newSoldier = new EarthSoldier(id, "Earth Soldier", jointime, hp, power, attackcap);
				newSoldier->setjoinHealth(hp);
				E1->AddUnit(newSoldier);
			}
			else if (B > I1->getES() && B < (I1->getES() + I1->getET()))
			{
				jointime=(G1->gettimeStep());
				id=nextEarthid++;
				hp=(rand() % (I1->geteHealth_upper() - I1->geteHealth_lower() + 1) + I1->geteHealth_lower());
				attackcap=(rand() % (I1->geteAttack_upper() - I1->geteAttack_lower() + 1) + I1->geteAttack_lower());
				power=(rand() % (I1->getePower_upper() - I1->getePower_lower() + 1) + I1->getePower_lower());
				EarthTank* newTank= new EarthTank(id, "Earth Tank", jointime, hp, power, attackcap);
				newTank->setjoinHealth(hp);
				E1->AddUnit(newTank);
			}
			else if(B > (I1->getES() + I1->getET()) && B < (I1->getES() + I1->getET() + I1->getEG()))
			{
				jointime=(G1->gettimeStep());
				id=nextEarthid;
				hp=(rand() % (I1->geteHealth_upper() - I1->geteHealth_lower() + 1) + I1->geteHealth_lower());
				attackcap=(rand() % (I1->geteAttack_upper() - I1->geteAttack_lower() + 1) + I1->geteAttack_lower());
				power=(rand() % (I1->getePower_upper() - I1->getePower_lower() + 1) + I1->getePower_lower());
				EarthGunnery* newGunnery = new EarthGunnery(id, "Earth Gunnery", jointime, hp, power, attackcap);
				E1->AddUnit(newGunnery);
			}
			else if (B > (I1->getES() + I1->getET() + I1->getEG()))
			{
				jointime = (G1->gettimeStep());
				id = nextEarthid;
				hp = (rand() % (I1->geteHealth_upper() - I1->geteHealth_lower() + 1) + I1->geteHealth_lower());
				attackcap = (rand() % (I1->geteAttack_upper() - I1->geteAttack_lower() + 1) + I1->geteAttack_lower());
				power = (rand() % (I1->getePower_upper() - I1->getePower_lower() + 1) + I1->getePower_lower());
				Healer* Genie = new Healer(id, "Healer", jointime, hp, power, attackcap);
				E1->AddUnit(Genie);
			}
		}
	}
}

void Generator::generateAlien() {
	
	int A = rand() % (100) + 1;
	int jointime, id, attackcap, power, hp;
	if (A <= I1->getProb())
	{
		for (int i = 0; i < I1->getN(); i++)
		{
			int B = rand() % (100) + 1;
			if (B > 0 && B < I1->getAS())
			{
				jointime = G1->gettimeStep();
				id = nextAlienid++;
				hp=(rand() % (I1->getaHealth_upper() - I1->getaHealth_lower() + 1) + I1->getaHealth_lower());
				attackcap=(rand() % (I1->getaAttack_upper() - I1->getaAttack_lower() + 1) + I1->getaAttack_lower());
				power=(rand() % (I1->getaPower_upper() - I1->getaPower_lower() + 1) + I1->getaPower_lower());
				AlienSoldier* newaSoldier = new AlienSoldier(id,"Alien Soldier",jointime,hp,power,attackcap);
				A1->AddUnit(newaSoldier);
			}
			else if (B > I1->getAS() && B < (I1->getAS() + I1->getAM()))
			{
				jointime=(G1->gettimeStep());
				id = nextAlienid++;
				hp=(rand() % (I1->getaHealth_upper() - I1->getaHealth_lower() + 1) + I1->getaHealth_lower());
				attackcap=(rand() % (I1->getaAttack_upper() - I1->getaAttack_lower() + 1) + I1->getaAttack_lower());
				power=(rand() % (I1->getaPower_upper() - I1->getaPower_lower() + 1) + I1->getaPower_lower());
				AlienMonster* newMonster = new AlienMonster(id,"Alien Monster",jointime,hp,power,attackcap);
				A1->AddUnit(newMonster);
			}
			else
			{
				jointime=(G1->gettimeStep());
				id=nextAlienid++;
				hp=(rand() % (I1->getaHealth_upper() - I1->getaHealth_lower() + 1) + I1->getaHealth_lower());
				attackcap=(rand() % (I1->getaAttack_upper() - I1->getaAttack_lower() + 1) + I1->getaAttack_lower());
				power=(rand() % (I1->getaPower_upper() - I1->getaPower_lower() + 1) + I1->getaPower_lower());
				AlienDrone* newDrone = new AlienDrone(id, "Alien Drone", jointime, hp, power, attackcap);
				A1->AddUnit(newDrone);
			}
		}
	}
}

