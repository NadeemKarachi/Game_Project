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

    Elf(string name, string race, int level, int health, string weapon, int weaponDamage);

    void setStrength(int strength_);
    void setIntelligence(int intelligence_);
};

Elf::Elf(): Character(){

}

Elf::Elf(string name, string race, int level, int health, string weapon, int weaponDamage) : Character( name, race, level, health, weapon, weaponDamage){}

void Elf::setStrength(int strength_){
    Character::setStrength(int(strength_ * .8));
}

void Elf::setIntelligence(int intelligence_){
    Character::setIntelligence(int(intelligence_*1.2));
}

#endif //FINAL_PROJ_ELF_H
