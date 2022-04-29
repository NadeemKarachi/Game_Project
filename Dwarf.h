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
    int damage;
    int stamina_cost;

public:
    Dwarf();
    Dwarf(string name, string race, int level, int health, int stamina, string weapon_);
    int getStamina() const;
    string getWeapon() const;
    void SetWeapon(string weapon_);
    void SetStamina(int stamina_);
    void EquipWeapon(string name, int damage, int stamina_cost);
    void Attack(Character *target);
    void Print();


};

Dwarf::Dwarf(): Character(){
    int stamina = 100;
    int damage = 30;
    int stamina_cost = 0;
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
void Dwarf::EquipWeapon(string name, int damage_, int stamina_cost_){
    getWeapon() = name;
    damage = damage_;
    stamina_cost = stamina_cost_;
}

// function to attach the target
void Dwarf::Attack(Character *target)
{
        target->SetHealth(target->getHealth() - damage); // decrement the health of target by weapon damage
// display the message
        cout<<getName()<<" attacked "<<target->getName()<<" with a weapon "<< getWeapon() <<", dealing "<< damage <<" damage."<<endl;
    }


// display the details of barbarian
void Dwarf::Print(){
    Character::Print();
    cout<<"Weapon: " << getWeapon() << endl;
}



#endif