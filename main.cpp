#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

#include "Dwarf.h"
#include "character.h"
#include "Human.h"
#include "game.h"
#include "Elf.h"
Dwarf createDwarf(bool isGenerated);

using namespace std;

int main(){
    Character vChar;
    Game vGame;
    Human vHum;
    Elf vElf;

    string name, occupation, race, weapon;
    int stamina;
    int health;
    int level;
    string characChoice;
    int characterChoice, weaponChoice;
    string charName;

    cout << "******WELCOME TO THE FIGHTING REALM******" << endl;
    cout << "TO START PLAYING PLEASE SELECT A CHARACTER" << endl;

    //Input Validation
    for(int i = 0; i < 3; i++){
        while (true) {
            cout << "1. Dwarf" << endl << "2. Human" << endl << "3. Elf" << endl;
            cin >> characterChoice;
            if (characterChoice > 3 || characterChoice < 1) {
                cout << "Invalid selection! Please Try Again" << endl;
                //Clears prev input if invalid
                cin.clear();
                cin.ignore(1000000, '\n');
            } else
                break;
        }

        if (characterChoice == 1) {
            Dwarf vDwarf = createDwarf(false);
            /*string weapon_name;
            int weapon_cost;
            int weapon_damage;
            Dwarf *d = new Dwarf(name, race, (level), (health), (stamina), weapon);
            d->EquipWeapon(weapon_name, (weapon_damage), (weapon_cost));
            vGame.AddCharacter(d);
            i++;*/
        }
        else if (characterChoice == 2) {
            cout << "You have selected Human!" << endl;
            characChoice = "Human";
            cout << "NAME YOUR " << characChoice << "!" << endl;
            cin >> charName;
            vHum.SetName(charName);
            vHum.SetRace(characChoice);
            vHum.SetHealth(90);
            vHum.SetLevel(90);

            while (true) {
                cout << "Please select a weapon for " << charName << endl;
                cout << "1. Sword" << endl << "2. kyoketsu-shoge" << endl << "3. Flail" << endl;
                cin >> weaponChoice;
                if (weaponChoice == 1) {
                    vHum.SetWeapon("Sword");
                    break;
                } else if (weaponChoice == 2) {
                    vHum.SetWeapon("kyoketsu-shoge");
                    break;
                } else if (weaponChoice == 3) {
                    vHum.SetWeapon("Flail");
                    break;
                } else {
                    cout << "No weapon has been selected!";
                    cin.clear();
                    cin.ignore(1000000, '\n');
                }
            }
            vHum.Print();
            vChar = vHum;

            /*string weapon_name;
            int weapon_cost;
            int weapon_damage;
            Human *h = new Human(name, race, (level), (health), (stamina), weapon);
            h->EquipWeapon(weapon_name, (weapon_damage), (weapon_cost));
            vGame.AddCharacter(h);
            i++;*/
        }
        else if (characterChoice == 3) {
            cout << "You have selected Elf!" << endl;
            characChoice = "Elf";
            cout << "NAME YOUR " << characChoice << "!" << endl;
            cin >> charName;
            vElf.SetName(charName);
            vElf.SetRace(characChoice);
            vElf.SetHealth(95);
            vElf.SetLevel(85);

            while (true) {
                cout << "Please select a weapon for " << charName << endl;
                cout << "1. Bow&Arrow" << endl << "2. Sword" << endl << "3. Javelin" << endl;
                cin >> weaponChoice;
                if (weaponChoice == 1) {
                    vElf.SetWeapon("Bow&Arrow");
                    break;
                } else if (weaponChoice == 2) {
                    vElf.SetWeapon("Sword");
                    break;
                } else if (weaponChoice == 3) {
                    vElf.SetWeapon("Javelin");
                    break;
                } else {
                    cout << "No weapon has been selected!";
                    cin.clear();
                    cin.ignore(1000000, '\n');
                }
                vElf.setStrength(10);
            }

            vElf.Print();
            i++;
        }
        cout << endl;
        if(i<3){
        cout <<"PLEASE SELECT YOUR OPPONENT: "<<endl;}
    }


    int option = -1;
    int c = 1;
    do{
        cout<<"Please choose an option:"<<endl;

        cout<<"1 - Start Round " << c << endl;
        cout<<"2 - Print All Characters"<<endl;
        cout<<"3 - Exit"<<endl;

        cin>>option;
        cout<<endl;


        switch(option){
            case 1:
                vGame.NextTurn();
                c++;
                break;

            case 2:
                vGame.Print();
                break;

            case 3:
                cout << "THANK YOU FOR PLAYING!" << endl;
                exit(0);

            default:
                cout<<"Invalid Option!"<<endl;
        }

        cout<<endl;
    }
    while(option != 3); //

    return 0;
}

Dwarf createDwarf(bool isGenerated){
    Dwarf vDwarf;
    string charName;
    int weaponChoice;

    if(isGenerated)
        charName = "Enemy Dwarf";

    else{
        cout << "You have selected Dwarf!" << endl;
        cout << "GIVE A NAME TO THE DWARF!" << endl;
        cin >> charName;
    }

    vDwarf.SetName(charName);
    vDwarf.SetRace("Dwarf");
    vDwarf.SetHealth(100);
    vDwarf.SetLevel(80);

    while (true) {
        if(isGenerated)
            weaponChoice = rand() % 100;
        else{
            cout << "Please select a weapon for " << charName << endl;
            cout << "1. Sword" << endl << "2. Axe" << endl << "3. Hammer" << endl;
            cin >> weaponChoice;
        }
        if (weaponChoice == 1) {
            vDwarf.SetWeapon("Sword");
            break;
        } else if (weaponChoice == 2) {
            vDwarf.SetWeapon("Axe");
            break;
        } else if (weaponChoice == 3) {
            vDwarf.SetWeapon("Hammer");
            break;
        } else {
            cout << "INVALID STATEMENT, Try again!";
            cin.clear();
            cin.ignore(1000000, '\n');
        }
    }
    vDwarf.Print();
}