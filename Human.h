#pragma once
#ifndef FINAL_PROJ_HUMAN_H
#define FINAL_PROJ_HUMAN_H

#include <iostream>
#include <string>
#include <utility>
#include "character.h"

using namespace std;

class Human : public Character{

public:
    Human();

    Human(string name, string race, int level, int health, string weapon, int weaponDamage);

    void setStrength(int strength_);
    void setIntelligence(int intelligence_);
};

Human::Human(): Character(){

}

Human::Human(string name, string race, int level, int health, string weapon, int weaponDamage) : Character( name, race, level, health, weapon, weaponDamage){}

void Human::setStrength(int strength_){
    Character::setStrength(int(strength_ * .8));
}

void Human::setIntelligence(int intelligence_){
    Character::setIntelligence(int(intelligence_*1.2));
}


#endif
