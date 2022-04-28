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
    int damage;
    int stamina_cost;

public:
    Human();
    Human(string name, string race, int level, int health, int stamina, string weapon_);
    int getStamina() const;
    string getWeapon() const;
    void SetWeapon(string weapon_);
    void SetStamina(int stamina_);
    void EquipWeapon(string name, int damage, int stamina_cost);
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

void Human::EquipWeapon(string name, int damage_, int stamina_cost_) {
    getWeapon() = name;
    damage = damage_;
    stamina_cost = stamina_cost_;

}

void Human::Attack(Character *target)
{
    target->SetHealth(target->getHealth() - damage); // decrement the health of target by weapon damage
// display the message
    cout<<getName()<<" attacked "<<target->getName()<<" with a weapon "<< getWeapon() <<", dealing "<< damage <<" damage."<<endl;
}

void Human::Print(){
    Character::Print();
    cout<<"Weapon: " << getWeapon() << endl;
}



#endif
