#include "Input.h"
#include<iostream>
#include<fstream>

using namespace std;

Input::Input() {
	fstream infile;
	infile.open("scores.txt");
	infile >> N >> ES >> ET >> EG >> HU>> AS >> AM >> AD >> Prob >> eHealth_lower;
	infile.ignore(1);
	infile >> eHealth_upper >> ePower_lower;
	infile.ignore(1);
	infile >> ePower_upper >> eAttack_lower;
	infile.ignore(1);
	infile >> eAttack_upper >> aHealth_lower;
	infile.ignore(1);
	infile >> aHealth_upper >> aPower_lower;
	infile.ignore(1);
	infile >> aPower_upper >> aAttack_lower;
	infile.ignore(1);
	infile >> aAttack_upper;
	infile.close();
}

int Input::getN() {
	return N;
}

int Input::getES() {
	return ES;
}

int Input::getET() {
	return ET;
}

int Input::getEG() {
	return EG;
}

int Input::getHU(){
	return HU;
}

int Input::getAS() {
	return AS;
}

int Input::getAM() {
	return AM;
}

int Input::getAD() {
	return AD;
}

int Input::getProb() {
	return Prob;
}

int Input::geteHealth_lower() {
	return eHealth_lower;
}

int Input::geteHealth_upper() {
	return eHealth_upper;
}

int Input::getePower_lower() {
	return ePower_lower;
}

int Input::getePower_upper() {
	return ePower_upper;
}

int Input::geteAttack_lower() {
	return eAttack_lower;
}

int Input::geteAttack_upper() {
	return eAttack_upper;
}

int Input::getaHealth_lower() {
	return aHealth_lower;
}

int Input::getaHealth_upper() {
	return aHealth_upper;
}

int Input::getaPower_lower() {
	return aPower_lower;
}

int Input::getaPower_upper() {
	return aPower_upper;
}

int Input::getaAttack_lower() {
	return aAttack_lower;
}

int Input::getaAttack_upper() {
	return aAttack_upper;
}