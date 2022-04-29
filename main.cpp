#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cstdlib>
#include <random>

#include "Dwarf.h"
#include "character.h"
#include "Human.h"
#include "game.h"
#include "Elf.h"
#include "RunGame.h"

Character createDwarf(bool isGenerated);
Character createElf(bool isGenerated);
Character createHuman(bool isGenerated);

using namespace std;

int main() {
    Character vChar;

    string name, occupation, race, weapon;
    int stamina;
    int health;
    int level;
    string characChoice;
    int characterChoice, weaponChoice;
    string charName;

    cout << "******WELCOME TO THE FIGHTING REALM******" << endl;
    RunGame game;
    game.AddPlayer();
}
