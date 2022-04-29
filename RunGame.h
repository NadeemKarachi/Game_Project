#ifndef FINAL_PROJ_RUNGAME_H
#define FINAL_PROJ_RUNGAME_H

#endif //FINAL_PROJ_RUNGAME_H

#pragma once
#ifndef FINAL_PROJ_GAME_H
#define FINAL_PROJ_GAME_H

#include <iostream>
#include <string>
#include "character.h"
#include "Dwarf.h"
#include "Human.h"
#include "Elf.h"

using namespace std;

class RunGame{

private:
    Character player;
    Character enemy;
    int current_turn;

public:
    RunGame();
    void RemoveCharacter(int index);
    void AddPlayer();
    Character createDwarf(bool isGenerated);
    Character createHuman(bool isGenerated);
    Character createElf(bool isGenerated);
};

RunGame::RunGame(){}

void AddPlayer(){
    int characterChoice;
    cout << "TO START PLAYING PLEASE SELECT A CHARACTER" << endl;
    //Input Validation
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
    //Why can't I call player from here
    //Why can't I call a createDwarf class
    if (characterChoice == 1) {
        player = createDwarf(false);
    } else if (characterChoice == 2) {
        Character vHum = createHuman(false);
    } else if (characterChoice == 3) {
        Character vElf = createElf(false);
    }
}

Character createDwarf(bool isGenerated){
    Dwarf vDwarf;
    string charName;
    int weaponChoice;

    if (isGenerated)
        charName = "Enemy Dwarf";

    else {
        cout << "You have selected Dwarf!" << endl;
        cout << "GIVE A NAME TO THE DWARF!" << endl;
        cin >> charName;
    }

    vDwarf.SetName(charName);
    vDwarf.SetRace("Dwarf");
    vDwarf.SetHealth(100);
    vDwarf.SetLevel(80);

    while (true) {
        if (isGenerated)
            weaponChoice = rand() % 4;
        else {
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
    return vDwarf;
}

Character createHuman(bool isGenerated) {
    Human vHum;
    string charName;
    int weaponChoice;
    if (isGenerated)
        charName = "Enemy Human";
    else {
        cout << "You have selected Human!" << endl;
        cout << "NAME YOUR HUMAN!" << endl;
        cin >> charName;
    }
    vHum.SetName(charName);
    vHum.SetRace("Human");
    vHum.SetHealth(90);
    vHum.SetLevel(90);

    while (true) {
        if (isGenerated)
            weaponChoice = rand() % 4;
        else {
            cout << "Please select a weapon for " << charName << endl;
            cout << "1. Sword" << endl << "2. Kyoketsu-Shoge" << endl << "3. Flail" << endl;
            cin >> weaponChoice;
        }
        if (weaponChoice == 1) {
            vHum.SetWeapon("Sword");
            break;
        } else if (weaponChoice == 2) {
            vHum.SetWeapon("Kyoketsu-Shoge");
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
    return vHum;
}

Character createElf(bool isGenerated){
    Elf vElf;
    string charName;
    int weaponChoice;
    if(isGenerated)
        charName = "Enemy Elf";
    else{
        cout << "You have selected Elf!" << endl;
        cout << "GIVE A NAME TO THE ELF!" << endl;
        cin >> charName;
    }
    vElf.SetName(charName);
    vElf.SetRace("Elf");
    vElf.SetHealth(95);
    vElf.SetLevel(85);
    while (true) {
        if(isGenerated)
            weaponChoice = rand() % 4;
        else{
            cout << "Please select a weapon for " << charName << endl;
            cout << "1. Bow&Arrow" << endl << "2. Sword" << endl << "3. Javelin" << endl;
            cin >> weaponChoice;
        }
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
    return vElf;
}

#endif
