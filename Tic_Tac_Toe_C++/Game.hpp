#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include "GameBoard.hpp"
#include "Piece.hpp"

class Game{

public: 
    int turnCount;
    Game();
    Game(Piece X, Piece O, GameBoard gb);
    void startGame(Piece X, Piece O, GameBoard gb);
};

#endif