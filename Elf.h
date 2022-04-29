#ifndef FINAL_PROJ_ELF_H
#define FINAL_PROJ_ELF_H
#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "character.h"

using namespace std;

class Elf : public Character{

public:
    Elf();

    Elf(string name, string race, int level, int health, string weapon);

    void SetWeapon(string weapon_);
    void SetWeaponDamage(int weaponDamage) ;
    void Print();
    void setStrength(int strength_);
    void setIntelligence(int intelligence_);

};

Elf::Elf(): Character(){

}

Elf::Elf(string name, string race, int level, int health, string weapon) : Character( std::move(name), std::move(race), level, health){}

void Elf::SetWeapon(string weapon_){
    Character::setWeapon(weapon_);
}
void Elf::setStrength(int strength_){
    Character::setStrength(int(strength_ * .8));
}

void Elf::setIntelligence(int intelligence_){
    Character::setIntelligence(int(intelligence_*1.2));
}

void Elf::Print(){
    Character::Print();
    cout<<"Weapon: " << getWeapon() << endl;
    cout<<"Attributes: " << Elf::getStrength();
}

void Elf::SetWeaponDamage(int weaponDamage) {
    Character::setWeaponDamage(weaponDamage);
}
#endif //FINAL_PROJ_ELF_H
