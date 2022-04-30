#pragma once
#ifndef FINAL_PROJ_DWARF_H
#define FINAL_PROJ_DWARF_H


#include <iostream>
#include <string>
#include <utility>
#include "character.h"

using namespace std;

class Dwarf : public Character{
public:
    Dwarf();

    Dwarf(string name, string race, int level, int health, string weapon, int weaponDamage);
    void setHealth(int health_);
    void setStrength(int strength_);
    void setIntelligence(int intelligence_);
};

Dwarf::Dwarf(): Character(){

}

Dwarf::Dwarf(string name, string race, int level, int health, string weapon, int weaponDamage) : Character( name, race, level, health, weapon, weaponDamage){}

void Dwarf::setHealth(int health_){
    Character::SetHealth(health_);
}

void Dwarf::setStrength(int strength_){
    Character::setStrength(int(strength_ * .8));
}

void Dwarf::setIntelligence(int intelligence_){
    Character::setIntelligence(int(intelligence_*1.2));
}

#endif