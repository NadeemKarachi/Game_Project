#ifndef FINAL_PROJ_RUNGAME_H
#define FINAL_PROJ_RUNGAME_H


#pragma once


#include <iostream>
#include <string>
#include "character.h"
#include "Dwarf.h"
#include "Human.h"
#include "Elf.h"
#include <fstream>
#include <windows.h>
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
    bool calcEnemyAttack();
    void GameMenu();
    void getGame();
    Character MakeChar(int characterChoice, bool isGenerated);
    Character CreateDwarf(bool isGenerated);
    Character CreateHuman(bool isGenerated);
    Character CreateElf(bool isGenerated);
    string GenerateName();
};

RunGame::RunGame(){
    MainMenu();
}

void RunGame::MainMenu(){

    int mainMenuSelection;
    while(true){
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h,1);
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
            getGame();
            GameMenu();
        }
        else if(mainMenuSelection == 3){
            cout << "THANK YOU FOR PLAYING!" << endl;
            cout << "GOODBYE!" << endl;

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
    Character vChar;
    int mainMenuSelection;
    while(true){
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h,3);
        cout << endl;
        cout << "================================================="<< endl;
        cout << "=                   Game Menu                   ="<< endl;
        cout << "================================================="<< endl;
        cout << "1. Fight Next Opponent"<< endl;
        cout << "2. Player Info"<< endl;
        cout << "3. Save Player Data" << endl;
        cout << "4. Exit Game"<< endl;
        cin >> mainMenuSelection;


        if(mainMenuSelection == 1){
            MakeEnemy();
            FightMenu();
            if(player.getHealth() <= 0){
                break;
            }
            cout << endl <<  "After a short rest and healing, you are ready to fight your next opponent."<< endl;
            if(player.getRace() == " "){
                player.SetHealth(150);
            }
            else if(player.getRace() == "Elf"){
                player.SetHealth(200);
            }
            else if(player.getRace() =="Human"){
                player.SetHealth(150);
            }
            else {
                player.SetHealth(100);
            }
        }
        else if(mainMenuSelection == 2){
            player.Print();
        }

        else if(mainMenuSelection == 3){
            ofstream output("Player1.txt");
            output << player.getName() <<endl;
            output << player.getRace() <<endl;
            output << player.getHealth() << endl;
            output << player.getWeapon() << endl;
            output << player.getWeaponDamage() << endl;
            cout <<  "Saved Successfully" << endl;
            output.close();
        }
        else if(mainMenuSelection == 4){
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
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h,4);
        cout << "================================================="<< endl;
        cout << "=                   Fight Menu                  ="<< endl;
        cout << "================================================="<< endl;
        cout << "Player: " << player.getName() << "'s Health:" << player.getHealth() << endl;
        cout << "Enemy: " << enemy.getRace() << " " << enemy.getName() << "'s Health:" << enemy.getHealth() << endl;
        cout << "Player Weapon: " << player.getWeapon() << ", Enemy Weapon: " << enemy.getWeapon() << endl;
        cout << "================================================="<< endl;
        cout << "1. Attack Enemy with your "<< player.getWeapon() << endl;
        cout << "2. Flee"<< endl;
        cin >> fightMenuSelection;
        if(fightMenuSelection == 1){
            bool isDeadEnemy = calcAttack();
            if(isDeadEnemy){
                cout << "Your Opponent has Perished."<< endl;
                break;
            }
            bool isDeadPlayer = calcEnemyAttack();
            if(isDeadPlayer){
                cout << "You have Died"<< endl;
                break;
            }
        }
        else if(fightMenuSelection == 2){
            cout << "You successfully escaped"<< endl;
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
        cout << "You Missed"<< endl;
        cout << endl;
        return false;
    }
    if (attackRoll > 17 && attackRoll < 20){
        int damageOutput = player.getWeaponDamage()+attackRoll+10;
        int enemyHealth = enemy.getHealth()-damageOutput;
        enemy.SetHealth(enemyHealth);
        cout << "CRITICAL HIT! You hit your opponent for " << damageOutput << endl;
        cout << endl;
        if(enemyHealth <= 0){
            return true;
        }
        return false;
    }
    if(attackRoll == 20){
        int damageOutput = (player.getWeaponDamage()+attackRoll+10)*2;
        int enemyHealth = enemy.getHealth()-damageOutput;
        enemy.SetHealth(enemyHealth);
        cout << "DOUBLE HIT! You hit your opponent twice for a total of " << damageOutput << endl;
        cout << endl;
        if(enemyHealth <= 0){
            return true;
        }
        return false;
    }
    int damageOutput = player.getWeaponDamage()+attackRoll;
    int enemyHealth = enemy.getHealth()-damageOutput;
    enemy.SetHealth(enemyHealth);
    cout << "You hit your opponent for " << damageOutput << endl;
    cout << endl;
    if(enemyHealth <= 0){
        return true;
    }
    return false;
}

bool RunGame::calcEnemyAttack(){
    srand(time(0)+32432);
    int attackRoll = rand() % 20 + 1;
    if (attackRoll < 4){
        cout << "Your Enemy Missed"<< endl;
        cout << endl;
        return false;
    }
    if (attackRoll > 18){
        int damageOutput = enemy.getWeaponDamage()+attackRoll+10;
        int enemyHealth = player.getHealth()-damageOutput;
        player.SetHealth(enemyHealth);
        cout << "CRITICAL HIT! You have been hit for " << damageOutput << endl;
        cout << endl;
        if(enemyHealth <= 0){
            return true;
        }
        return false;
    }
    int damageOutput = enemy.getWeaponDamage()+attackRoll;
    int enemyHealth = player.getHealth()-damageOutput;
    player.SetHealth(enemyHealth);
    cout << "You have been hit for " << damageOutput << endl;
    cout << endl;
    if(enemyHealth <= 0){
        return true;
    }
    return false;
    cout << endl;
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
        charName = GenerateName();

    else {
        cout << "\"YOU HAVE BEEN SELECTED ON BEHALF OF THE DWARF NATION TO PARTICIPATE!\"" << endl;
        cout << "GIVE A NAME TO THE DWARF!" << endl;
        cin.ignore();
        getline(cin,charName);
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
            cout << "1. Sword- Outputs 20 damage" << endl << "2. Axe- Outputs 30 damage" << endl << "3. Hammer- Outputs 40 damage" << endl;
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
        charName = GenerateName();
    else {
        cout << "YOU HAVE BEEN SELECTED ON BEHALF OF THE HUMAN NATION TO PARTICIPATE!" << endl;
        cout << "NAME YOUR HUMAN!" << endl;
        cin.ignore();
        getline(cin,charName);
    }
    vHum.SetName(charName);
    vHum.SetRace("Human");
    vHum.SetHealth(150);

    while (true) {
        if (isGenerated)
            weaponChoice = rand() % 3 + 1;
        else {
            cout << "Please select a weapon for " << charName << endl;
            cout << "1. Sword- Outputs 20 damage" << endl << "2. Kyoketsu-Shoge(knife on chain)- Outputs 30 damage" << endl << "3. Flail- Outputs 25 damage" << endl;
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
        charName = GenerateName();
    else{
        cout << "YOU HAVE BEEN SELECTED ON BEHALF OF THE ELF NATION TO PARTICIPATE!" << endl;
        cout << "GIVE A NAME TO THE ELF!" << endl;
        cin.ignore();
        getline(cin,charName);
    }
    vElf.SetName(charName);
    vElf.SetRace("Elf");
    vElf.SetHealth(200);
    while (true) {
        if(isGenerated)
            weaponChoice = rand() % 3 + 1;
        else{
            cout << "Please select a weapon for " << charName << endl;
            cout << "1. Bow&Arrow - Outputs 10 damage" << endl << "2. Sword- Outputs 20 damage" << endl << "3. Javelin- Outputs 15 damage" << endl;
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

string RunGame::GenerateName(){
    string names [150];
    int cnt = 0;
    string line;
    ifstream myfile( "generatableNames.txt" );
    if (myfile){
        while (getline( myfile, line )){
            names[cnt] = line;
            cnt++;
        }
        myfile.close();
    }
    else
        cout << "File coudl not be read";

    srand(time(0)+3214);
    return names[rand() % 150 + 1];
}

void RunGame::getGame(){
    string line;
    ifstream myfile( "Player1.txt" );
    if (myfile){
        getline( myfile, line);
        player.SetName(line);
        getline( myfile, line);
        player.SetRace(line);
        getline( myfile, line);
        player.SetHealth(stoi(line));
        getline( myfile, line);
        player.setWeapon(line);
        getline( myfile, line);
        player.setWeaponDamage(stoi(line));
        myfile.close();
    }
    else
        cout << "NO GAME TO CONTINUE, STARTING NEW GAME!" << endl;

}

#endif
