#include "Board.hpp"
#include <vector>
#include <iostream>

Board::Board(){
    this->hangman =
    " --------\n"
    " |      |\n"
    " |\n"
    " |\n"
    " |\n"
    " |\n"
   "__|_________\n";
}

Board::Board(int wordSize){
    this->hangman =
    " --------\n"
    " |      |\n"
    " |\n"
    " |\n"
    " |\n"
    " |\n"
    "_|_________\n";
    
    for(int i = 0; i < wordSize; i++)
        this->dashes.push_back("_");
}

std::string Board::getState(){
    return this->hangman;
}

void Board::addPart(int guesses){
    if(guesses == 5){
        this->hangman =
    " --------\n"
    " |      |\n"
    " |      O\n"
    " |\n"
    " |\n"
    " |\n"
    "_|_________\n";
    }
    else if(guesses == 4){
        this->hangman =
    " --------\n"
    " |      |\n"
    " |      O\n"
    " |      |\n"
    " |\n"
    " |\n"
    "_|_________\n";
    }
    else if(guesses == 3){
        this->hangman =
    " --------\n"
    " |      |\n"
    " |      O\n"
    " |     /|\n"
    " |\n"
    " |\n"
    "_|_________\n";
    }
    else if(guesses == 2){
        this->hangman =
    " --------\n"
    " |      |\n"
    " |      O\n"
    " |     /|\\ \n"
    " |\n"
    " |\n"
    "_|_________\n";
    }
    else if(guesses == 1){
        this->hangman =
    " --------\n"
    " |      |\n"
    " |      O\n"
    " |     /|\\ \n"
    " |     / \n"
    " |\n"
    "_|_________\n";
    }
    else if(guesses == 0){
        this->hangman =
    " --------\n"
    " |      |\n"
    " |      O\n"
    " |     /|\\ \n"
    " |     / \\ \n"
    " |\n"
    "_|_________\n";
    }
}

void Board::printState(std::string word, int guesses,  std::vector<std::string> lettersGuessed, int category){
    std::cout << getState() << std::endl;
    std::cout << "Category: ";
    if(category == -1){
        std::cout <<"Custom "<<std::endl;
    }
    else if(category == 1){
        std::cout << "Animals " << std::endl;
    }
    else if(category == 2){
        std::cout << "Kitchen " << std::endl;
    }
    else if(category == 0){
        std::cout << "Random Objects " << std::endl;
    }
    for(int i = 0; i < dashes.size(); i++){
        std::cout << dashes[i] << " ";
    }
    if(lettersGuessed.size() != 0){
        std::cout << "\tGuesses left: " << guesses << "\t\tLetters guessed: ";
        for(int i = 0; i < lettersGuessed.size(); i++){
            std::cout << lettersGuessed[i] << " ";
        }
        std::cout << "" << std::endl;
    }
    else{
        std::cout << "\tGuesses left: " << guesses << std::endl; //No one has guessed incorrectly, no need to print out list of guessed words
    }
}