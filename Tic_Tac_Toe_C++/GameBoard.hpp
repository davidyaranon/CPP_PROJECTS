#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include "Piece.hpp"
class GameBoard{

public:
    GameBoard();
    std::vector<std::vector<std::string>> boardVect;
    std::vector<int> checkFull;
    void printGameBoardInit(std::vector<std::vector<std::string>> boardVect);
    void printGameBoard(Piece X, Piece O);
    bool threeInARow(Piece X, Piece O);
    bool isFull();
};

#endif