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
    //Attack Damage
    int strength = 8;
    //Health
    int constitution = 8;
    //Dodge attacks
    int dexterity  = 8;
    //Magic Damage / Resistance
    int intelligence  = 8; //TODO: Add Intelligence functionality
    //Insight
    int wisdom = 8; //TODO: Add wisdom functionality
    //Speech level
    int charisma  = 8; //TODO: Add charisma functionality
    //XP
    double xp; //TODO: Set XP Functionality

public:
// constructors
    Character();
    Character(string name_, string race_, int level, int health);

// getter functions
    string getName() const;
    string getRace() const;
    int getLevel() const;
    int getHealth() const;
    int getStrength() const;
    int getConstitution() const;
    int getDexterity() const;
    int getIntelligence() const;
    int getWisdom() const;
    int getCharisma() const;
    double getXp() const;


    // setter functions
    void SetName(string name);
    void SetRace(string race);
    void SetLevel(int level);
    void SetHealth(int health);
    void setStrength(int strength);
    void setConstitution(int constitution);
    void setDexterity(int dexterity);
    void setIntelligence(int intelligence);
    void setWisdom(int wisdom);
    void setCharisma(int charisma);
    void setXp(double xp);
    void setStrength() const;
    // other functions
    virtual void Print();

    virtual void Attack(Character *target) =0;



};

Character::Character(){
    name = "";
    race = "";
    level = 0;
    health = 0;
}

// constructor
Character::Character(string name, string race, int level_, int health_)
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
    cout<<"Name: "<< getName() <<endl;
    cout<<"Race: "<< getRace() <<endl;
    cout<<"Level: "<< level <<endl;
    cout<<"Health: "<< health <<endl;
}

//Attributes Getters and Setters
int Character::getStrength() const {
    return strength;
}

void Character::setStrength(int strength) {
    Character::strength = strength;
}

int Character::getConstitution() const {
    return constitution;
}

void Character::setConstitution(int constitution) {
    Character::constitution = constitution;
}

int Character::getDexterity() const {
    return dexterity;
}

void Character::setDexterity(int dexterity) {
    Character::dexterity = dexterity;
}

int Character::getIntelligence() const {
    return intelligence;
}

void Character::setIntelligence(int intelligence) {
    Character::intelligence = intelligence;
}

int Character::getWisdom() const {
    return wisdom;
}

void Character::setWisdom(int wisdom) {
    Character::wisdom = wisdom;
}

int Character::getCharisma() const {
    return charisma;
}

void Character::setCharisma(int charisma) {
    Character::charisma = charisma;
}

double Character::getXp() const {
    return xp;
}

void Character::setXp(double xp) {
    Character::xp = xp;
}




#endif
