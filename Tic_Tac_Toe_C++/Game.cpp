#include <iostream>
#include <vector>
#include <string>
#include "GameBoard.hpp"
#include "Piece.hpp"
#include "Game.hpp"
#include <cmath>

Game::Game(){
    this->turnCount = 0;
}

Game::Game(Piece X, Piece O, GameBoard gb){
    this->turnCount = 0;
}

void Game::startGame(Piece X, Piece O, GameBoard gb){
    int position, row;
    std::cout << "GAME BEGIN" << std::endl;
    while(true){
        if(gb.isFull()){
            std::cout << "TIE!\n";
            return;
        }
        if(gb.threeInARow(X, O)){
            break;
        }
        turnCount++;
        if(turnCount % 2 == 1){
            std::cout << X.getName() << "'s turn. Enter a number 0 - 8 to place your piece: " << std::endl;
        }
        else{
            std::cout << O.getName() << "'s turn. Enter a number 0 - 8 to place your piece: " << std::endl;
        }
        std::cin >> position;
        while(position < 0 || position > 8 || X.pos[position] == 1 || O.pos[position] == 1){
            if(position < 0 || position > 8){
                std::cout << "Enter a position within the bounds!" << std::endl;
                std::cin >> position;
            }
            else if(X.pos[position] == 1 || O.pos[position] == 1){
                std::cout << "Slot is taken, enter another number: " << std::endl;
                std::cin >> position;
            }
        }
        if(position <= 2){
               row = 0;
           }
           else if(position <= 5){
               row = 1;
           }
           else{
               row = 2;
           }
        if(turnCount % 2 == 1){
            X.setPos(position);
            gb.boardVect[row][(position % 3) * 2] = X.getName();
            gb.checkFull[position] = 1;
        }
        else{
            O.setPos(position);
            gb.boardVect[row][(position % 3) * 2] = O.getName();
            gb.checkFull[position] = 1;
        }
        gb.printGameBoard(X, O);
    }
    if(turnCount % 2 == 1)
        std::cout << X.getName() << " has WON!";
    else{
        std::cout << O.getName() << " has WON!";
    }
}