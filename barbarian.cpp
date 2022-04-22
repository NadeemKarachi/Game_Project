
#include <iostream>
#include <string>
#include <utility>
#include "barbarian.h"

using namespace std;

// constructor
Barbarian::Barbarian(string name, string race, int level, int health, int stamina) : Character(std::move(name), race, level, health), stamina(stamina)
{}

// getter
int Barbarian::getStamina() const
{
    return stamina;
}

// setter
void Barbarian::SetStamina(int stamina_)
{
    stamina = stamina_;
}

// function to set the active weapon details to passed weapon details
void Barbarian::EquipWeapon(string name, int damage, int stamina_cost)
{
    active_weapon.name = name;
    active_weapon.damage = damage;
    active_weapon.stamina_cost = stamina_cost;
}

// function to attach the target
void Barbarian::Attack(Character *target)
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
void Barbarian::Print()
{
    Character::Print();
    cout<<"Weapon: " << active_weapon.name << endl;
}