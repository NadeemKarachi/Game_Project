#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "Dwarf.h"
#include "character.h"
#include "Wizard.h"
#include "game.h"


using namespace std;

int main(){
    Character vChar;
    Game vGame;
    Dwarf vDwarf;
    string characChoice;
    int characterChoice;
    string charName;

    cout << "******WELCOME TO THE FIGHTING REALM******" << endl;
    cout << "TO START PLAYING PLEASE SELECT A CHARACTER" << endl;
    cout << "1. Dwarf" << endl << "2. Wizard" << endl << "3. Elf" << endl;
    cin >> characterChoice;

    if(characterChoice > 3 || characterChoice < 1){
        cout << "Invalid selection!"<<endl;
        return -1;
    }
    if(characterChoice ==1){
        cout << "You have selected Dwarf!" << endl;
        characChoice = "Dwarf";
    }
    else if(characterChoice == 2){
        cout << "You have selected Wizard!" << endl;
        characChoice = "Wizard";
    }
    else if(characterChoice == 3){
        cout << "You have selected Elf!" << endl;
        characChoice = "Elf";
    }
    vChar .SetRace(characChoice);
    cout << "NAME YOUR " << characChoice << "!" << endl;
    cin >> charName;
    vChar.SetName(charName);

    /* string filename;
    cin>>filename;

    ifstream input(filename);

    Game game;
    if(!input.is_open()){
        cout<<"file not found!"<<endl;
        return -1;
    }


    string name, occupation, race, level, health;

    for(int i=0;i<2;i++){
        getline(input, occupation);
        getline(input, name);
        getline(input, race);
        getline(input, level);
        getline(input,health);

        if(occupation == "Barbarian"){
            string weapon_name, weapon_damage, weapon_cost, stamina;

            getline(input, stamina);
            getline(input, weapon_name);
            getline(input, weapon_damage);
            getline(input, weapon_cost);

// create a barbarian pointer object
            Barbarian *B = new Barbarian(name, race, stoi(level), stoi(health), stoi(stamina));
// equip the weapon
            B -> EquipWeapon(weapon_name, stoi(weapon_damage), stoi(weapon_cost));
// add the barbarian character to game
            game.AddCharacter(B);

        }
        else if(occupation == "Mage"){
            string mana;
            getline(input, mana);


// create a mage object
            Mage *M = new Mage(name, race, stoi(level), stoi(health), stoi(mana));

            string spell_num;
            getline(input, spell_num);

            for(int i=0;i<stoi(spell_num);i++){
                string spell_name, spell_damage, spell_cost;
                getline(input, spell_name);
                getline(input, spell_damage);
                getline(input, spell_cost);

                M -> AddSpell(spell_name, stoi(spell_damage), stoi(spell_cost));
            }

            game.AddCharacter(M);
        }

        string newline;
        getline(input, newline);
    }

    int option = -1;
    do{
        cout<<"Please choose an option:"<<endl;
        cout<<"1 - Next Turn "<<endl;
        cout<<"2 - Print All Characters"<<endl;
        cout<<"3 - Exit"<<endl;

        cin>>option;
        cout<<endl;


        switch(option){
            case 1:
                game.NextTurn();
                break;

            case 2:
                game.Print();
                break;

            case 3:
                exit(0);

            default:
                cout<<"Invalid Option!"<<endl;
        }

        cout<<endl;
    }
    while(option != 3); //
*/
    return 0;
}