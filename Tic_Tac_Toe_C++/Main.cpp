#include <iostream>
#include <vector>
#include <string>
#include "GameBoard.hpp"
#include "Piece.hpp"
#include "Game.hpp"

int main(){
    // GAME: Tic-Tac-Toe (in terminal though)
    Piece X = Piece("X"); //Position vector is initialized to 0 after constructing object
    Piece O = Piece("O"); //Position vector is initialized to 0 after constructing object
    GameBoard gb;

    Game game = Game(X, O, gb);
    game.startGame(X, O, gb);
}
