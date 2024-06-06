#include "EarthGunnery.h"
#include "../../AlienArmy.h"
#include "../../GameRules.h"

EarthGunnery::EarthGunnery(int id, const string& unitType, int jointime, int hp, int pow, int attackcap) :ArmyUnit(id, unitType, jointime, hp, pow, attackcap) {}
void EarthGunnery::Attack(GameRules* game, AlienArmy* army) 
{
    int count = 0;

    AlienMonster* monster;
    AlienDrone* droneFront;
    AlienDrone* droneRear;

    while (count < attackCapacity) {

        if (army->getAD_List().dequeue(droneFront)) {
            int* droneHP = droneFront->getHealth();

            ///To-Do: Add Get First Attacked Time to Unit and check if its -1 then update it to current TS

            *droneHP -= (power * health / 100) / sqrt(*droneHP);

            if (*droneFront->getHealth() <= 0) {
                game->getkilledlist().enqueue(droneFront);
                droneFront->setTD(game->gettimeStep());
            }
            else {
                army->getAD_List().enqueue(droneFront);
            }

            count++;
        }

        if (count < attackCapacity && army->getAD_List().dequeueRear(droneRear)) {
            int* droneHP = droneRear->getHealth();

            ///To-Do: Add Get First Attacked Time to Unit and check if its -1 then update it to current TS

            *droneHP -= (power *health / 100) / sqrt(*droneHP);

            if (*droneRear->getHealth() <= 0) {
                game->getkilledlist().enqueue(droneRear);
                droneRear->setTD(game->gettimeStep());
            }
            else {
                army->getAD_List().enqueue(droneRear);
            }

            count++;
        }

        if (count < attackCapacity && army->getAM_List().pop(monster)) {
            int* monsterHP = monster->getHealth();

            ///To-Do: Add Get First Attacked Time to Unit and check if its -1 then update it to current TS

            *monsterHP -= (power *health / 100) / sqrt(*monsterHP);

            if (*monster->getHealth() <= 0) {
                game->getkilledlist().enqueue(monster);
                monster->setTD(game->gettimeStep());
            }
            else {
                army->getAM_List().add(monster);
            }
            count++;
        }
    }
}