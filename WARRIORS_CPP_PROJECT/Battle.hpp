#ifndef BATTLE_H
#define BATTLE_H


#include "Warriors.hpp"
#include <vector>

class Battle{

public:
    int totalTurnCount;
    int whoseTurn;
    int amountAlive;
    int amountOfWarriors;
    Battle();
    void startFight(std::vector<Warrior> listOfWariors);
};

#endif