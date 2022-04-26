#pragma once
#ifndef FINAL_PROJ_CHARACTER_H
#define FINAL_PROJ_CHARACTER_H

#include <iostream>
#include <string>
using namespace std;

class Character{
private:
    string name;
    string race;
    int level;
    int health;

public:
// constructors
    Character();
    Character(string name_, string race_, int level, int health);

// getter functions
    string getName() const;
    string getRace() const;
    int getLevel() const;
    int getHealth() const;

// setter functions
    void SetName(string name);
    void SetRace(string name);
    void SetLevel(int level);
    void SetHealth(int health);

// other functions
    virtual void Print();
    //virtual void Attack(Character * target) = 0;

};

Character::Character(){
    name = "";
    race = "";
    level = 0;
    health = 0;
}

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

#endif
