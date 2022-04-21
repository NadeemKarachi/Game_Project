#include <iostream>
#include <string>
#include "character.h"

using namespace std;

// constructor
Character::Character(string name_, string race_, int level, int health) : name(name_), race(race_), level(level), health(health)
{}

// getter functions
string Character::getName() const
{
    return name;
}

string Character::getRace() const
{
    return race;
}

int Character::getHealth() const
{
    return health;
}

int Character::getLevel() const
{
    return level;
}

// setter functions
void Character::SetHealth(int health_)
{
    health = health_;
}

void Character::SetLevel(int level_)
{
    level = level_;
}

void Character::SetName(string name_)
{
    name = name_;
}

void Character::SetRace(string race_)
{
    race = race_;
}

void Character::Print()
{
    cout<<"Character Status: "<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Race: "<<race<<endl;
    cout<<"Level: "<<level<<endl;
    cout<<"Health: "<<health<<endl;
}