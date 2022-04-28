#pragma once
#ifndef FINAL_PROJ_GAME_H
#define FINAL_PROJ_GAME_H

#include <iostream>
#include <string>
#include "character.h"
#include "Dwarf.h"
#include "Human.h"

using namespace std;

class Game{

private:
    Character *players[2];
    int current_turn;
    int num_of_characters;

public:
    Game();
    void RemoveCharacter(int index);
    void AddCharacter(Character *c);
    void NextTurn();
    void Print();
    int getCharacters(){
        return num_of_characters;
    }
    int getTurn(){
        return current_turn;
    }
};

Game::Game() : current_turn(0), num_of_characters(0){}

// remove a character from the array
void Game:: RemoveCharacter(int index)
{
    if(index < 0 || index >= num_of_characters){
        cout<<"Invalid index!"<<endl;
    }
    else{
 //Character *c = players[index];
// loop to shift the players to left
        for(int i=index;i<num_of_characters-1;i++){
            players[i] = players[i+1];
        }

        num_of_characters--; // decrement the number of characters

    }
}

// add a character to the array
void Game:: AddCharacter(Character *c){
    if(num_of_characters == 2) {
        cout<<"Character limit reached, please wait for the next game!"<<endl;
    }
    else{
        players[num_of_characters] = c;
        num_of_characters++;
    }
}

// simulate a turn
void Game:: NextTurn(){
    if(num_of_characters != 2) // validate number of players
        cout<<"Need more players!"<<endl;
    else{
        current_turn++; // increment the current turn
// player1 attacks player2
      //players[0]->Attack(players[1]);
// check if player1 has lost
        if(players[1]->getHealth() < 0){
            cout<<"Player one wins!"<<endl;
            exit(0);
        }
        else{
// player2 attacks player1
          // players[1]->Attack(players[0]);
// check if player1 has lost
            if(players[0]->getHealth() < 0){
                cout<<"Player two wins!"<<endl;
                exit(0);
            }
        }
    }
}

// display the details of the characters in the game
void Game::Print(){
    for(int i=0;i<num_of_characters;i++){
        players[i]->Print();
        cout<<endl;
    }
}

#endif
