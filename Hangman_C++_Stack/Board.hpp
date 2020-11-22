#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>

class Board{

public:
    std::vector<std::string> dashes;
    std::string hangman;
    std::string getState();
    void printState(std::string word, int guesses, std::vector<std::string> lettersGuessed, int category);
    void addPart(int guesses);
    Board();
    Board(int wordSize);
};


#endif