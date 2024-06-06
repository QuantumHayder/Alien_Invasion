#pragma once
#include"Input.h"
#include"EarthArmy.h"
#include"AlienArmy.h"
#include"AllyArmy.h"
class GameRules;
class Healer;

class Generator
{
private:
	Input* I1;
	EarthArmy* E1;
	AlienArmy* A1;
	GameRules* G1;
	int nextAlienid = 2000;
	int nextEarthid = 1;
public:
	Generator();
	Generator(Input*, EarthArmy*, AlienArmy*, GameRules*);
	void generateEarth();
	void generateAlien();
	void generateAlly();

};

