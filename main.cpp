#include <iostream>
#include <string>
#include <cstdlib>

#include "Dwarf.h"
#include "character.h"
#include "Wizard.h"
#include "game.h"
#include "Elf.h"


using namespace std;

int main(){
    Character vChar;
    Game vGame;
    Dwarf vDwarf;
    Wizard vWiz;
    Elf vElf;


    string characChoice;
    int characterChoice, weaponChoice;
    string charName;

    cout << "******WELCOME TO THE FIGHTING REALM******" << endl;
    cout << "TO START PLAYING PLEASE SELECT A CHARACTER" << endl;

    //Input Validation
    while(true){
        cout << "1. Dwarf" << endl << "2. Wizard" << endl << "3. Elf" << endl;
        cin >> characterChoice;
        if(characterChoice > 3 || characterChoice < 1){
            cout << "Invalid selection! Please Try Again"<<endl;
            //Clears prev input if invalid
            cin.clear();
            cin.ignore(1000000, '\n');
        }
        else
            break;
    }

    if(characterChoice == 1){
        cout << "You have selected Dwarf!" << endl;
        characChoice = "Dwarf";
        cout << "NAME YOUR " << characChoice << "!" << endl;
        cin >> charName;
        vDwarf.SetName(charName);
        vDwarf.SetRace(characChoice);
        vDwarf.SetHealth(100);
        vDwarf.SetLevel(80);


        cout << "Please select a weapon for " << charName << endl;
        cout << "1. Sword" << endl << "2. Axe" << endl << "3. Hammer" << endl;
        cin >> weaponChoice;
        if (weaponChoice == 1){
            vDwarf.SetWeapon("Sword");
        }
        else if(weaponChoice==2) {
            vDwarf.SetWeapon("Axe");
        }
        else if(weaponChoice==3) {
            vDwarf.SetWeapon("Hammer");
        }
        else{ cout << "No weapon has been selected!";}

        vDwarf.Print();
    }
    else if(characterChoice == 2){
        cout << "You have selected Wizard!" << endl;
        characChoice = "Wizard";
        cout << "NAME YOUR " << characChoice << "!" << endl;
        cin >> charName;
        vWiz.SetName(charName);
        vWiz.SetRace(characChoice);
        vWiz.SetHealth(90);
        vWiz.SetLevel(90);

        cout << "Please select a spell for " << charName << endl;
        cout << "1. Fire" << endl << "2. Strength" << endl << "3. Lightning" << endl;
        cin >> weaponChoice;
        if (weaponChoice == 1){
            vDwarf.SetWeapon("Fire");
        }
        else if(weaponChoice==2) {
            vDwarf.SetWeapon("Strength");
        }
        else if(weaponChoice==3) {
            vDwarf.SetWeapon("Lightning");
        }
        else{ cout << "No spell has been selected!";}

        vWiz.Print();
    }
    else if(characterChoice == 3){
        cout << "You have selected Elf!" << endl;
        characChoice = "Elf";
        cout << "NAME YOUR " << characChoice << "!" << endl;
        cin >> charName;
        vElf.SetName(charName);
        vElf.SetRace(characChoice);
        vElf.SetHealth(95);
        vElf.SetLevel(85);


        cout << "Please select a weapon for " << charName << endl;
        cout << "1. Bow&Arrow" << endl << "2. Sword" << endl << "3. Javelin" << endl;
        cin >> weaponChoice;
        if (weaponChoice == 1){
            vElf.SetWeapon("Bow&Arrow");
        }
        else if(weaponChoice==2) {
            vElf.SetWeapon("Sword");
        }
        else if(weaponChoice==3) {
            vElf.SetWeapon("Javelin");
        }
        else{ cout << "No weapon has been selected!";}
        vElf.setStrength(10);
        vElf.Print();
    }



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