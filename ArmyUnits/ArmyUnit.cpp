#include "ArmyUnit.h"
ArmyUnit::ArmyUnit(int id, const string& unitType, int tj, int hp, int pow, int attackCap)
    : ID(id),
    type(unitType),
    TJ(tj),
    health(hp),
    power(pow),
    attackCapacity(attackCap)
{ troopCount++; }

// Member function implementations
int ArmyUnit::getID() const {
    return ID;
}
string ArmyUnit::getType() const {
    return type;
}
int ArmyUnit::getJoinTime() const {
    return TJ;
}
int* ArmyUnit::getHealth(){
    return &health;
}
int ArmyUnit::getPower() const {
    return power;
}
int ArmyUnit::getAttackCapacity() const {
    return attackCapacity;
}

int ArmyUnit:: getUML_joinTime() {
    return UML_joinTime;
}
int ArmyUnit::getjoinHealth() {
    return joinHealth;
}

int ArmyUnit::getTJ() const {
    return TJ;
}
int ArmyUnit::getTD() const
{
    return Td;
}

int ArmyUnit::getTA() const
{
    return Ta;
}

int ArmyUnit::getDF() const
{
    return Df;
}

int ArmyUnit::getDB() const
{
    return Db;
}

int ArmyUnit::getDD() const
{
    return Dd;
}


////////////////////////////////////////////SETTERS//////////////////////////////////////////////////
void ArmyUnit::setID(int id) {
    ID = id;
}
void ArmyUnit::setHealth(int h) {
    health = h;
}
void ArmyUnit::setAttackCapacity(int a) {
    attackCapacity = a;
}
void ArmyUnit::setPower(int p) {
    power = p;
}
void ArmyUnit::printID(){
    cout << ID << endl;
}
int ArmyUnit::getTroopCount() {
    return troopCount;
}
void ArmyUnit::setJoinTime(int jointime) {
    TJ = jointime;
}
void ArmyUnit::setTA(int ta) {
    Ta = ta;
}
void ArmyUnit::setTD(int td) {
    Td = td;
}
void ArmyUnit::setDF(int df) {
    Df = df;
}
void ArmyUnit::setDd(int dd) {
    Dd = dd;
}
void ArmyUnit::setDb(int bt) {
    Db = bt;
}

void ArmyUnit::setUML_joinTime(int uml) {
    UML_joinTime = uml;
}
void ArmyUnit::setjoinHealth(int h) {
    joinHealth = h;
}
ostream& operator<<(ostream& os, const ArmyUnit unit)
{
    os << unit.getID();
    return os;
}