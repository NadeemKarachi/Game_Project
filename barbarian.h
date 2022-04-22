
#ifndef FINAL_PROJ_BARBARIAN_H
#define FINAL_PROJ_BARBARIAN_H


#include <iostream>
#include <string>
#include "character.h"

using namespace std;

struct weapon{
    string name="";
    int damage=0;
    int stamina_cost = 0;
};

class Barbarian : public Character
{
private:
    weapon active_weapon;
    int stamina = 100;

public:
// constructors
    Barbarian(string name, string race, int level, int health, int stamina);
// getters
    int getStamina() const;
// setters
    void SetStamina(int stamina_);

// other functions
    void EquipWeapon(string name, int damage, int stamina_cost);
    void Attack(Character * target);
    void Print();
};



#endif
