#pragma once
#include <string>
#include <iostream>
using namespace std;

class ArmyUnit {
    protected:
        int ID;
        string type;
        int TJ; // TJ: join time
        int health;
        int power;
        int attackCapacity; //maximum number of units that could be attacked by this unit at one timestep
        int Ta; //first attacked Time
        int Td; //Destruction Time
        int Df; //first attack delay
        int Dd; //Destruction delay
        int Db; //batle time
        int troopCount=0; //needed for IDs in random generator
        int UML_joinTime;
        int joinHealth;

    public:
        // Constructor
        ArmyUnit(int id, const string& unitType, int jointime, int hp, int pow, int attackcap);
        // Member functions
        //====================Getters====================//
        string getType() const;
        int getID() const;
        int getJoinTime() const;
        int* getHealth();
        int getPower() const;
        int getAttackCapacity() const;
        int getTroopCount();//used in setting ID in generator, counts the number of troops created from each type
        int getUML_joinTime();
        int getjoinHealth();

        int getTJ() const;
        int getTD() const;
        int getTA() const;
        int getDF() const;
        int getDB() const;
        int getDD() const;

        //====================Setters====================//
        void setID(int);
        void setHealth(int);
        void setAttackCapacity(int);
        void setPower(int);
        void setJoinTime(int);
        void setTA(int);
        void setTD(int);
        void setDF(int);
        void setDd(int);
        void setDb(int);
        void setUML_joinTime(int);
        void setjoinHealth(int);
        void printID();
};
ostream& operator<<(ostream& os, const ArmyUnit unit);