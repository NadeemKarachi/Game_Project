#pragma once
#ifndef FINAL_PROJ_HUMAN_H
#define FINAL_PROJ_HUMAN_H

#include <iostream>
#include <string>
#include <utility>
#include "character.h"

using namespace std;

class Human : public Character{

private:
    string weapon;
    int stamina ;

public:
    Human();
    Human(string name, string race, int level, int health, int stamina, string weapon_);
    int getStamina() const;
    string getWeapon() const;
    void SetWeapon(string weapon_);
    void SetStamina(int stamina_);
    //void EquipWeapon(string name, int damage, int stamina_cost);
    void Attack(Character *target);
    void Print();


};

Human::Human(): Character(){
    int stamina = 100;
    int damage = 30;
}

Human::Human(string name, string race, int level, int health, int stamina_, string weapon_) : Character( name, race, level, health),stamina(stamina), weapon(weapon){
    stamina = stamina_;
    weapon = weapon_;
}

// getter
int Human::getStamina() const{
    return stamina;
}
string Human::getWeapon() const{
    return weapon;
}
void Human::SetWeapon(string weapon_){
    weapon = weapon_;
}
// setter
void Human::SetStamina(int stamina_){
    stamina = stamina_;
}


void Human::Print(){
    Character::Print();
    cout<<"Weapon: " << getWeapon() << endl;
}

#endif
