#ifndef FINAL_PROJ_ELF_H
#define FINAL_PROJ_ELF_H
#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "character.h"

using namespace std;

class Elf : public Character{

private:
    string weapon;
    int stamina ;

public:
    Elf();
    Elf(string name, string race, int level, int health, int stamina, string weapon_);
    int getStamina() const;
    string getWeapon() const;
    void SetWeapon(string weapon_);
    void SetStamina(int stamina_);
    //void Attack(Character *target);
    void Print();
    void setStrength(int strength_);

    double getStrength() const;
};

Elf::Elf(): Character(){
    int stamina = 100;
    int damage = 30;
}

Elf::Elf(string name, string race, int level, int health, int stamina_, string weapon_) : Character( name, race, level, health),stamina(stamina), weapon(weapon){
    stamina = stamina_;
    weapon = weapon_;
}

// getter
int Elf::getStamina() const{
    return stamina;
}
string Elf::getWeapon() const{
    return weapon;
}
void Elf::SetWeapon(string weapon_){
    weapon = weapon_;
}
// setter
void Elf::SetStamina(int stamina_){
    stamina = stamina_;
}
void Elf::setStrength(int strength_){
    Character::setStrength(strength_);
}

double Elf::getStrength() const {
    return Character::getStrength()*.8;
}

void Elf::Print(){
    Character::Print();
    cout<<"Weapon: " << getWeapon() << endl;
    cout<<"Attributes " << Elf::getStrength();
}
#endif //FINAL_PROJ_ELF_H
