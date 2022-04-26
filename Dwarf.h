#pragma once
#ifndef FINAL_PROJ_DWARF_H
#define FINAL_PROJ_DWARF_H


#include <iostream>
#include <string>
#include <utility>
#include "character.h"

using namespace std;

/*struct weapon{
    string name= "";
    int damage=0;
    int stamina_cost = 0;
};*/

class Dwarf : public Character{

private:
    string weapon;
    int stamina ;

public:
    Dwarf();
    Dwarf(string name, string race, int level, int health, int stamina, string weapon_);
    int getStamina() const;
    string getWeapon() const;
    void SetWeapon(string weapon_);
    void SetStamina(int stamina_);
    //void EquipWeapon(string name, int damage, int stamina_cost);
    void Attack(Character *target);
    void Print();


};

Dwarf::Dwarf(): Character(){
    int stamina = 100;
    int damage = 30;
}

Dwarf::Dwarf(string name, string race, int level, int health, int stamina_, string weapon_) : Character( name, race, level, health),stamina(stamina), weapon(weapon){
    stamina = stamina_;
    weapon = weapon_;
}

// getter
int Dwarf::getStamina() const{
    return stamina;
}
string Dwarf::getWeapon() const{
    return weapon;
}
void Dwarf::SetWeapon(string weapon_){
    weapon = weapon_;
}
// setter
void Dwarf::SetStamina(int stamina_){
    stamina = stamina_;
}

// function to set the active weapon details to passed weapon details
/*void Dwarf::EquipWeapon(string name, int damage, int stamina_cost){
    active_weapon.name = name;
    active_weapon.damage = damage;
    active_weapon.stamina_cost = stamina_cost;
}*/

// function to attach the target
/*void Dwarf::Attack(Character *target)
{
// check if there is an active weapon
    if(active_weapon.name =="" && active_weapon.damage == 0 && active_weapon.stamina_cost == 0)
        cout<<"Dwarf has no weapon!"<<endl;
    else if(stamina < active_weapon.stamina_cost) // check if character's stamina >= weapon's stamina
        cout<<"Insufficient stamina points!"<<endl;
    else
    {
        target->SetHealth(target->getHealth() - active_weapon.damage); // decrement the health of target by weapon damage
// display the message
        cout<<getName()<<" attacked "<<target->getName()<<" with a weapon "<<active_weapon.name<<", dealing "<<active_weapon.damage<<" damage."<<endl;
    }
}
*/
// display the details of barbarian
void Dwarf::Print(){
    Character::Print();
    cout<<"Weapon: " << getWeapon() << endl;
}



#endif