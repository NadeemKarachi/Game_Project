
#include <iostream>
#include <string>
#include "mage.h"

using namespace std;

// constructor
Mage::Mage(string name , string race, int level, int health, int mana) : Character(name, race, level, health), mana(mana)
{}

// getter
int Mage::getMana() const
{
    return mana;
}

//setter
void Mage::SetMana(int mana_)
{
    mana = mana_;
}

// function to insert spell into spells array
int Mage::AddSpell(string spell_name, int spell_damage, int mana_cost)
{
    if(numOfSpells == 10) // array full
    {
        cout<<"Spell limits reached!"<<endl;
    }else
    {
// add spell at the end
        spells[numOfSpells].name = spell_name;
        spells[numOfSpells].damage = spell_damage;
        spells[numOfSpells].mana_cost = mana_cost;
        numOfSpells++;
    }

    return numOfSpells;
}

// function to set the next spell
void Mage:: nextSpell()
{
    active_Spell++; // increment the active spell
// reached beyond the last spell, reset the active to the first spell
    if(active_Spell == numOfSpells)
        active_Spell = 0;
}

// function to attack the target character
void Mage::Attack(Character *target)
{
    if(numOfSpells == 0) // no spell
        cout<<"This mage has no spells!"<<endl;
    else if(mana < spells[active_Spell].mana_cost) // character's mana < spell's mana cost
        cout<<"Insufficient mana points!"<<endl;
    else
    {
// display the message
        cout<<getName()<<" attacked "<<target->getName()<<" with a spell "<<spells[active_Spell].name<<", dealing "<<spells[active_Spell].damage<<" damage."<<endl;
        target->SetHealth(target->getHealth() - spells[active_Spell].damage); // decrement the health of target by the damage of spell
        nextSpell(); // go to next spell
    }
}

// display the details of mage
void Mage:: Print()
{
    Character::Print();
    cout<<"Spells: "<<endl;
    for(int i=0;i<numOfSpells;i++)
    {
        cout<<spells[i].name<<endl;
    }
}