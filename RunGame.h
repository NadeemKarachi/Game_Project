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

public:
    RunGame();
    void AddPlayer();
    void MakeEnemy();
    void MainMenu();
    void FightMenu();
    bool calcAttack();
    void GameMenu();
    Character MakeChar(int characterChoice, bool isGenerated)
;   Character CreateDwarf(bool isGenerated);
    Character CreateHuman(bool isGenerated);
    Character CreateElf(bool isGenerated);
};

RunGame::RunGame(){
    cout << "==========WELCOME TO THE FIGHTING REALM==========" << endl;
    MainMenu();
}

void RunGame::MainMenu(){
    int mainMenuSelection;
    while(true){
        cout << "=================================================" << endl;
        cout << "=                   Main Menu                   =" << endl;
        cout << "=================================================" << endl;
        cout << "1. New Game" << endl;
        cout << "2. Continue" << endl;
        cout << "3. Exit" << endl;
        cin >> mainMenuSelection;
        if(mainMenuSelection == 1){
            AddPlayer();
            GameMenu();
        }
        else if(mainMenuSelection == 2){
            //TODO: Set up save games and continue games
        }
        else if(mainMenuSelection == 3){
            break;
        }
        else{
            cout << "Invalid selection! Please Try Again" << endl;
            cin.clear();
            cin.ignore(1000000, '\n');
        }
    }
}

void RunGame::GameMenu(){
    int mainMenuSelection;
    while(true){
        cout << "================================================="<< endl;
        cout << "=                   Game Menu                   ="<< endl;
        cout << "================================================="<< endl;
        cout << "1. Fight Next Opponent"<< endl;
        cout << "2. Player Info"<< endl;
        cout << "3. Exit Game"<< endl;
        cin >> mainMenuSelection;
        if(mainMenuSelection == 1){
            MakeEnemy();
            FightMenu();
        }
        else if(mainMenuSelection == 2){
            player.Print();
        }
        else if(mainMenuSelection == 3){
            break;
        }
        else{
            cout << "Invalid selection! Please Try Again" << endl;
            cin.clear();
            cin.ignore(1000000, '\n');
        }
    }
}

void RunGame::FightMenu(){
    int fightMenuSelection;
    while(true){
        cout << "================================================="<< endl;
        cout << "=                  Fight Menu                   ="<< endl;
        cout << "================================================="<< endl;
        cout << player.getName() << "'s Health:" << player.getHealth() << endl;
        cout << enemy.getName() << "'s Health:" << enemy.getHealth() << endl;
        cout << "================================================="<< endl;
        cout << "1. Attack Enemy"<< endl;
        cout << "2. Flee"<< endl;
        cin >> fightMenuSelection;
        if(fightMenuSelection == 1){
            bool isDeadEnemy = calcAttack();
            if(isDeadEnemy){
                cout << "Your Opponent has Perished.";
                break;
            }
        }
        else if(fightMenuSelection == 2){
            cout << "You successfully escaped";
            break;
        }
        else{
            cout << "Invalid selection! Please Try Again" << endl;
            cin.clear();
            cin.ignore(1000000, '\n');
        }
    }
}

bool RunGame::calcAttack(){
    srand(time(0));
    int attackRoll = rand() % 20 + 1;
    if (attackRoll < 3){
        cout << "You Missed";
        return false;
    }
    if (attackRoll == 20){
        int damageOutput = player.getWeaponDamage()+attackRoll;
        int enemyHealth = enemy.getHealth()-damageOutput;
        cout << "CRITICAL HIT! You hit your opponent for " << damageOutput << endl;
        if(enemyHealth < 0){
            cout << "Your Opponent has perished"
        }
        cout << "Your opponent flinched and wasn't able to attack.";

        return;
    }


}

void RunGame::AddPlayer(){
    int characterChoice;
    cout << "TO START PLAYING PLEASE SELECT A CHARACTER" << endl;
    //Input Validation
    while (true) {
        cout << "1. Dwarf" << endl << "2. Human" << endl << "3. Elf" << endl;
        cin >> characterChoice;
        if (characterChoice > 3 || characterChoice < 1) {
            cout << "Invalid selection! Please Try Again" << endl;
            cin.clear();
            cin.ignore(1000000, '\n');
        } else
            break;
    }
    player = MakeChar(characterChoice, false);
}

void RunGame::MakeEnemy() {
    srand(time(nullptr)+839);
    int charChoice = rand() % 3 + 1;
    enemy = MakeChar(charChoice, true);
}

Character RunGame::MakeChar(int characterChoice, bool isGenerated) {
    Character makeChar;
    if (characterChoice == 1) {
        makeChar = CreateDwarf(isGenerated);
    } else if (characterChoice == 2) {
        makeChar = CreateHuman(isGenerated);
    } else if (characterChoice == 3) {
        makeChar = CreateElf(isGenerated);
    }
    return makeChar;
}

Character RunGame::CreateDwarf(bool isGenerated){
    Dwarf vDwarf;
    string charName;
    int weaponChoice;
    srand(time(0));
    if (isGenerated)
        charName = "Enemy Dwarf";

    else {
        cout << "You have selected Dwarf!" << endl;
        cout << "GIVE A NAME TO THE DWARF!" << endl;
        cin >> charName;
    }

    vDwarf.SetName(charName);
    vDwarf.SetRace("Dwarf");
    vDwarf.setHealth(100);
    vDwarf.SetLevel(80);

    while (true) {
        if (isGenerated)
            weaponChoice = rand() % 3 + 1;
        else {
            cout << "Please select a weapon for " << charName << endl;
            cout << "1. Sword" << endl << "2. Axe" << endl << "3. Hammer" << endl;
            cin >> weaponChoice;
        }
        if (weaponChoice == 1) {
            vDwarf.setWeapon("Sword");
            vDwarf.setWeaponDamage(20);
            break;
        } else if (weaponChoice == 2) {
            vDwarf.setWeapon("Axe");
            vDwarf.setWeaponDamage(30);
            break;
        } else if (weaponChoice == 3) {
            vDwarf.setWeapon("Hammer");
            vDwarf.setWeaponDamage(40);
            break;
        } else {
            cout << "INVALID STATEMENT, Try again!";
            cin.clear();
            cin.ignore(1000000, '\n');
        }
    }
    return vDwarf;
}

Character RunGame::CreateHuman(bool isGenerated) {
    Human vHum;
    string charName;
    int weaponChoice;
    srand(time(0));
    if (isGenerated)
        charName = "Enemy Human";
    else {
        cout << "You have selected Human!" << endl;
        cout << "NAME YOUR HUMAN!" << endl;
        cin >> charName;
    }
    vHum.SetName(charName);
    vHum.SetRace("Human");
    vHum.SetHealth(150);

    while (true) {
        if (isGenerated)
            weaponChoice = rand() % 3 + 1;
        else {
            cout << "Please select a weapon for " << charName << endl;
            cout << "1. Sword" << endl << "2. Kyoketsu-Shoge" << endl << "3. Flail" << endl;
            cin >> weaponChoice;
        }
        if (weaponChoice == 1) {
            vHum.setWeapon("Sword");
            vHum.setWeaponDamage(20);
            break;
        } else if (weaponChoice == 2) {
            vHum.setWeapon("Kyoketsu-Shoge");
            vHum.setWeaponDamage(30);
            break;
        } else if (weaponChoice == 3) {
            vHum.setWeapon("Flail");
            vHum.setWeaponDamage(25);
            break;
        } else {
            cout << "No weapon has been selected!";
            cin.clear();
            cin.ignore(1000000, '\n');
        }
    }
    return vHum;
}

Character RunGame::CreateElf(bool isGenerated){
    Elf vElf;
    string charName;
    int weaponChoice;
    srand(time(0));
    if(isGenerated)
        charName = "Enemy Elf";
    else{
        cout << "You have selected Elf!" << endl;
        cout << "GIVE A NAME TO THE ELF!" << endl;
        cin >> charName;
    }
    vElf.SetName(charName);
    vElf.SetRace("Elf");
    vElf.SetHealth(200);
    while (true) {
        if(isGenerated)
            weaponChoice = rand() % 3;
        else{
            cout << "Please select a weapon for " << charName << endl;
            cout << "1. Bow&Arrow" << endl << "2. Sword" << endl << "3. Javelin" << endl;
            cin >> weaponChoice;
        }
        if (weaponChoice == 1) {
            vElf.setWeapon("Bow&Arrow");
            vElf.setWeaponDamage(10);
            break;
        } else if (weaponChoice == 2) {
            vElf.setWeapon("Sword");
            vElf.setWeaponDamage(20);
            break;
        } else if (weaponChoice == 3) {
            vElf.setWeapon("Javelin");
            vElf.setWeaponDamage(15);
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
