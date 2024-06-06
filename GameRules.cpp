#include "GameRules.h"
#include "Generator.h"
#include "ADS/priQueue.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

GameRules::GameRules(EarthArmy& e, AlienArmy& a, Input& i) {
	//myEarth = e;
	//*myAlien = a;
	//*myI = i;
	myEarth = &e;
	myAlien = &a;
	myI = &i;
}

void GameRules::printDeadList() {
	cout << endl;
	cout << "============== Killed / Destructed Units ===========" << endl;
	LinkedQueue<ArmyUnit*> temp(getkilledlist());
	int killedcount=getdeadlistcount();
	cout << killedcount << " Dead Units" << endl;
	temp.print();
}
int GameRules::getdeadlistcount()
{
	LinkedQueue<ArmyUnit*> temp(getkilledlist());
	int count = 0;
	ArmyUnit* trash;
	while (!temp.isEmpty()) {
		temp.dequeue(trash);
		count++;
	}
	return count;
}

Input& GameRules::getInput() {
	return *myI;
}

void GameRules::produceOutput()
{
	int unitTJ; int unitTA; int unitTD;
	int unitDF; int unitDB; int unitDD;
	double TotalalienDF = 0; double totalalienDD = 0; double totalalienDB = 0;
	double TotalhumanDF = 0; double totalhumanDD = 0; double totalhumanDB = 0;
	int totaldeadhumans = 0; int totaldeadaliens = 0;
	int etdead = 0; int esdead = 0; int egdead = 0;
	ArmyUnit* deadunit;
	ofstream outputfile("output.txt");
	if (!outputfile) {
		cout << "Error opening text file" << endl;
	}
	else {
		cout << "Making Output" << endl;
	}
	outputfile << setw(5) << "Td";
	outputfile << setw(5) << "ID";
	outputfile << setw(5) << "Tj";
	outputfile << setw(5) << "Df";
	outputfile << setw(5) << "Db";
	outputfile << setw(5) << "Dd" << endl;
	while (getkilledlist().dequeue(deadunit)) {


		unitTJ = deadunit->getTJ(); unitTD = deadunit->getTD(); unitTA = deadunit->getTA();
		unitDF = deadunit->getDF(); unitDB = deadunit->getDB(); unitDD = deadunit->getDD();
		outputfile << setw(5) << unitTD;
		outputfile << setw(5) << deadunit->getID();
		outputfile << setw(5) << unitTJ;
		outputfile << setw(5) << unitDF;
		outputfile << setw(5) << unitDB;
		outputfile << setw(5) << unitDD << endl;

		if (deadunit->getID() < 2000)
		{
			TotalhumanDF += deadunit->getDF();
			totalhumanDB += deadunit->getDB();
			totalhumanDD += deadunit->getDD();
			totaldeadhumans++;
			if (deadunit->getType() == "Earth Soldier") {
				esdead++;
			}
			else if (deadunit->getType() == "Earth Tank") {
				etdead++;
			}
			else if (deadunit->getType() == "Earth Gunnery") {
				egdead++;
			}

		}
		else
		{
			TotalalienDF += deadunit->getDF();
			totalalienDB += deadunit->getDB();
			totalalienDD += deadunit->getDD();
			totaldeadaliens++;

		}


	}
	int totalaliens = this->myAlien->getTotalCount();
	int totalhumans = this->myEarth->getTotalCount();
	double percenthumandestructed = (totaldeadhumans / totalhumans) * 100; double percentaliendestructed = (totaldeadaliens / totalaliens) * 100;
	double humanavgdf = TotalhumanDF / this->myEarth->getTotalCount(); double humanavgdb = totalhumanDB / totaldeadhumans; double humanavgdd = totalhumanDD / totaldeadhumans;
	double alienavgdf = TotalalienDF / this->myAlien->getTotalCount(); double alienavgdb = totalalienDB / totaldeadaliens; double alienavgdd = totalalienDD / totaldeadaliens;
	double humanDFDBpercent = (TotalhumanDF / totalhumanDB) * 100; double alienDFDBpercent = (TotalalienDF / totalalienDB) * 100;
	double humanDDDBpercent = (totalhumanDD / totalhumanDB) * 100; double alienDDDBpercent = (totalalienDD / totalalienDB) * 100;

	outputfile << "//////////////////////////EARTH ARMY/////////////////////////" << endl;

	if (Victory == true) {
		outputfile << "battle result: WIN" << endl;
		outputfile << "ES UNITS: " << this->myEarth->ES_Count() << endl;
		outputfile << "ET UNITS: " << this->myEarth->ET_Count() << endl;
		outputfile << "EG UNITS: " << this->myEarth->EG_Count() << endl;
		outputfile << "Percentage of destructed units relative to their total= " << endl;
		outputfile << "Percentage of destruced units relative to total units= " << percenthumandestructed << endl;
		outputfile << "Average DF= " << humanavgdf << endl;
		outputfile << "Average DB= " << humanavgdb << endl;
		outputfile << "Average DD= " << humanavgdd << endl;
		outputfile << "DF/DB% = " << humanDFDBpercent << endl;
		outputfile << "DD/DB% = " << humanDDDBpercent << endl;
	}
	else {
		outputfile << "battle result: LOSS" << endl;
		outputfile << "battle result: WIN" << endl;
		outputfile << "ES UNITS: " << this->myEarth->ES_Count() << endl;
		outputfile << "ET UNITS: " << this->myEarth->ET_Count() << endl;
		outputfile << "EG UNITS: " << this->myEarth->EG_Count() << endl;
		outputfile << "Percentage of destructed units relative to their total= " << endl;
		outputfile << "Percentage of destruced units relative to total units= " << percenthumandestructed << endl;
		outputfile << "Average DF = " << humanavgdf << endl;
		outputfile << "Average DB = " << humanavgdb << endl;
		outputfile << "Average DD = " << humanavgdd << endl;
		outputfile << "DF/DB% = " << humanDFDBpercent << endl;
		outputfile << "DD/DB% = " << humanDDDBpercent << endl;
	}
	outputfile << "//////////////////////////ALIEN ARMY/////////////////////////" << endl;

	if (Victory != true) {
		outputfile << "battle result: WIN" << endl;
		outputfile << "battle result: WIN" << endl;
		outputfile << "AS UNITS: " << this->myAlien->AS_Count() << endl;
		outputfile << "AM UNITS: " << this->myAlien->AM_Count() << endl;
		outputfile << "AD UNITS: " << this->myAlien->AD_Count() << endl;
		outputfile << "Percentage of destructed units relative to their total= " << endl;
		outputfile << "Percentage of destruced units relative to total units= " << percentaliendestructed << endl;
		outputfile << "Average DF= " << alienavgdf << endl;
		outputfile << "Average DB= " << alienavgdb << endl;
		outputfile << "Average DD= " << alienavgdd << endl;
		outputfile << "DF/DB% = " << alienDFDBpercent << endl;
		outputfile << "DD/DB% = " << alienDDDBpercent << endl;
	}
	else {
		outputfile << "battle result: LOSS" << endl;
		outputfile << "battle result: WIN" << endl;
		outputfile << "battle result: WIN" << endl;
		outputfile << "AS UNITS: " << this->myAlien->AS_Count() << endl;
		outputfile << "AM UNITS: " << this->myAlien->AM_Count() << endl;
		outputfile << "AD UNITS: " << this->myAlien->AD_Count() << endl;
		outputfile << "Percentage of destructed units relative to their total= " << endl;
		outputfile << "Percentage of destruced units relative to total units= " << percentaliendestructed << endl;
		outputfile << "Average DF= " << alienavgdf << endl;
		outputfile << "Average DB= " << alienavgdb << endl;
		outputfile << "Average DD= " << alienavgdd << endl;
		outputfile << "DF/DB% = " << alienDFDBpercent << endl;
		outputfile << "DD/DB% = " << alienDDDBpercent << endl;
	}


}

void GameRules::War() {
	Generator myGen(myI, myEarth, myAlien, this);

	while (timeStep <= 500)
	{
		cout << "\n\n\t ============ Time Step " << timeStep << " =============\n\n";
		myGen.generateEarth();
		myGen.generateAlien();
		/* ------- Attacking Logic ------- */
		myEarth->Attack(this, myAlien);
		myAlien->Attack(this, myEarth);
		myEarth->print();
		myAlien->print();
		printDeadList();
		timeStep++;
	}
	//if (timeStep > 100)
	//{
	//	while (timeStep < 100)
	//	{
	//		cout << "\n\n\t ============ Time Step " << timeStep << " =============\n\n";
	//		myGen.generateEarth();
	//		myGen.generateAlien();
	//		//Attack Logic
	//		myEarth->Attack(this, myAlien);
	//		myAlien->Attack(this, myEarth);
	//		myEarth->print();
	//		myAlien->print();
	//		printDeadList();
	//		if (myEarth->getTotalCount() > 0 && myAlien->getTotalCount() == 0)
	//		{
	//			Winner = "Earth Army";
	//			Victory = true;
	//			cout << "Winner Winner Chicken Dinner:: Planet Earth" << endl;
	//		}
	//		else if (myAlien->getTotalCount() > 0 && myEarth->getTotalCount() == 0)
	//		{
	//			Winner = "Alien Army";
	//			Victory = true;
	//			cout << "Winner Winner Chicken Dinner:: Planet ET" << endl;
	//		}
	//		timeStep++;
	//	}
	//}
}



int GameRules::gettimeStep() {
	return timeStep;
}

LinkedQueue<ArmyUnit*>& GameRules::getkilledlist()
{
	return killedlist;
}

//void GameRules::test() 
//{
//	Input* input = new Input();
//	AlienArmy* aliens = new AlienArmy;
//	EarthArmy* human = new EarthArmy;
//	//GameRules* game = new GameRules;
//	Generator* generator = new Generator(*input, *human, *aliens, *this);
//	EarthSoldier* earthtop;
//	EarthTank* tanktop;
//	EarthGunnery* topgunMaverick;
//	int trash=0;
//	AlienSoldier* alientop;
//	AlienMonster* monstertop;
//	AlienDrone* dronetop;
//	AlienDrone* dronerear;
//	LinkedQueue<ArmyUnit*> templist;
//	priQueue<EarthGunnery*> tempGun;
//
//	int time = gettimeStep();
//
//	for (int i = 0;i < 50;i++) 
//	{
//			cout << "                     Time Step: " << i+1 << endl;
//			generator->generateEarth();
//			generator->generateAlien();
//			int A = (rand() % (100)) + 1;
//			if (A > 0 && A < 10) {
//				if(human->getES_List().dequeue(earthtop))
//				human->getES_List().enqueue(earthtop);
//			}
//			else if (A > 10 && A < 20) {
//				if (human->getET_List().pop(tanktop))
//				{
//					getkilledlist().enqueue(tanktop);
//				}
//			}
//			else if (A > 20 && A < 30) {
//				if(!human->getEG_List().isEmpty()) {
//					human->getEG_List().dequeue(topgunMaverick, trash);
//					topgunMaverick->setHealth((*topgunMaverick->getHealth() / 2));
//					int newpri = (*topgunMaverick->getHealth() * topgunMaverick->getPower());
//					tempGun.enqueue(topgunMaverick,newpri);
//				}
//				if (!tempGun.isEmpty()) {
//					tempGun.dequeue(topgunMaverick, trash);
//					int newpri2 = (*topgunMaverick->getHealth() * topgunMaverick->getPower());
//					human->getEG_List().enqueue(topgunMaverick,newpri2);
//				}
//			}
//			else if (A > 30 && A < 40) {
//				for (int j = 0;j < 5;j++) {
//					if (aliens->getAS_List().dequeue(alientop))
//					{
//						alientop->setHealth(*alientop->getHealth() - 1);
//						templist.enqueue(alientop);
//						ArmyUnit* au = alientop;
//						templist.dequeue(au);
//						alientop =(AlienSoldier*) au;
//						aliens->getAS_List().enqueue(alientop);
//					}
//				}
//			}
//			else if (A > 40 && A < 50) {
//				for (int k = 0; k < 5;k++) {
//
//					if (aliens->getAM_List().remove(monstertop))
//						aliens->getAM_List().add(monstertop);
//				}
//			}
//			else if (A > 50 && A < 60) {
//				for (int z = 0;z <3 ;z++) {
//					if(aliens->getAD_List().dequeueRear(dronerear))
//						getkilledlist().enqueue(dronerear);
//				}
//				for (int m = 0;m < 3;m++) {
//					if(aliens->getAD_List().dequeue(dronetop))
//						getkilledlist().enqueue(dronetop);
//				}
//			}
//			human->print();
//			aliens->print();
//			printDeadList();
//			cout << endl;
//			cout << endl;
//			time++;
//		}
//}
//
//
