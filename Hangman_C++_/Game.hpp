#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Board.hpp"

class Game{

public: 
    int guesses, player, numPlayers, category;
    std::vector<std::string> lettersGuessed;
    Board board;
    Game();
    Game(int numPlayers);
    std::string getWord();
    void setWord(std::string word);
    void generateWord();
    int getPlayer();
    void playGame(Board board);
    bool wordFound(Board board);
    bool lettersDuplicate(std::vector<std::string> lettersGuessed, std::string letter);
    std::string fileParse(std::string fileName);
    std::vector<std::string> readWordsFile(std::string fileName);

private:
    std::string word;
};

#endif
