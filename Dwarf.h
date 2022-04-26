#pragma once
#ifndef FINAL_PROJ_DWARF_H
#define FINAL_PROJ_DWARF_H


#include <iostream>
#include <string>
#include "character.h"

using namespace std;

struct weapon{
    string name="";
    int damage=0;
    int stamina_cost = 0;
};

class Dwarf : public Character{

private:
    weapon active_weapon;
    int stamina = 100;
    int damage = 0;

public:
    Dwarf();
    Dwarf(string name, string race, int level, int health, int stamina);
    int getStamina() const;
    void SetStamina(int stamina_);
    void EquipWeapon(string name, int damage, int stamina_cost);
    void Attack(Character * target);
    void Print();
};

Dwarf::Dwarf(): Character(){
    getName() = "";
}

Dwarf::Dwarf(string name, string race, int level, int health, int stamina) : Character(std::move(name), race, level, health), stamina(stamina)
{}

// getter
int Dwarf::getStamina() const
{
    return stamina;
}

// setter
void Dwarf::SetStamina(int stamina_)
{
    stamina = stamina_;
}

// function to set the active weapon details to passed weapon details
void Dwarf::EquipWeapon(string name, int damage, int stamina_cost)
{
    active_weapon.name = name;
    active_weapon.damage = damage;
    active_weapon.stamina_cost = stamina_cost;
}

// function to attach the target
void Dwarf::Attack(Character *target)
{
// check if there is an active weapon
    if(active_weapon.name =="" && active_weapon.damage == 0 && active_weapon.stamina_cost == 0)
        cout<<"Barbarian has no weapon!"<<endl;
    else if(stamina < active_weapon.stamina_cost) // check if character's stamina >= weapon's stamina
        cout<<"Insufficient stamina points!"<<endl;
    else
    {
        target->SetHealth(target->getHealth() - active_weapon.damage); // decrement the health of target by weapon damage
// display the message
        cout<<getName()<<" attacked "<<target->getName()<<" with a weapon "<<active_weapon.name<<", dealing "<<active_weapon.damage<<" damage."<<endl;
    }
}

// display the details of barbarian
void Dwarf::Print()
{
    Character::Print();
    cout<<"Weapon: " << active_weapon.name << endl;
}

#endif