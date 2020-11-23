#include "Game.hpp"
#include "Board.hpp"
#include <iostream>
#include <time.h>
#include <string>
#include <algorithm>
#include <fstream>
#include <random>

//Default constructor
Game::Game(){
    this->guesses = 0;
    this->player = 0;
    this->board = Board();
    std::string word = "";
}

Game::Game(int numPlayers){
    this->guesses = 6;
    this->player = 0;
    this->numPlayers = numPlayers;
    srand(time(NULL));
    this->category = -1;
    playGame(this->board);
}


//READING THESE FILES IN THIS WAY CAUSES THE WORD TO RETURN WITH THE \r AT THE END OF THE STRING!
std::vector<std::string> Game::readWordsFile(std::string fileName){
    std::ifstream file(fileName);
    std::string temp;
    std::vector<std::string> words;
    while(std::getline(file, temp)){
        words.push_back(temp);
    }
    return words;
}

std::string Game::fileParse(std::string fileName){
    std::vector<std::string> listOfWords = readWordsFile(fileName);
    int index = rand() % listOfWords.size();
    std::string word = listOfWords[index];
    return word;
}

void Game::generateWord(){
    std::string word;
    if(this->numPlayers == 1){
        this->category = rand() % 3;
        std::cout << "Generating word..." << std::endl;
        if(this->category == 1){
           word = fileParse("textFiles/Animals.txt");
        }
        else if(this->category == 2){
            word = fileParse("textFiles/Foods.txt");
        }
        else{
            word = fileParse("textFiles/RandomObjects.txt");
        }
        setWord(word);
    }
    else{
        int check = 0;
        std::cout << "Player " << (getPlayer() + 1) << " enter your word: " << std::endl;
        ws(std::cin);
        std::string word;
        std::getline(std::cin, word);
        std::cout <<"\n\n\n\n" << std::endl;
        for(int i = 0; i < word.size(); i++){
            if(word[i] == ' '){
                word[i] = '-';
                check++;
                if(check == 1){
                    std::cout << "THIS WORD CONTAINS SPACE(S). TO REVEAL THEM, TYPE '-' " << std::endl;
                }
            }
        }
        setWord(word);
    }
}

void Game::setWord(std::string word){
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    this->word = word;
}

std::string Game::getWord(){
    return this->word;
}

int Game::getPlayer(){
    return this->player % this->numPlayers;
}

bool Game::wordFound(Board board){
    for(int i = 0; i < board.dashes.size(); i++){
        if(board.dashes[i] == "_"){
            return false;
        }
    }
    return true;
}

bool Game::lettersDuplicate(std::vector<std::string> lettersGuessed, std::string letter){
    transform(letter.begin(), letter.end(), letter.begin(), ::toupper);
    for (int it = 0; it < lettersGuessed.size(); it++){
        if(lettersGuessed[it] == letter){
            return true;
        }
    }
    return false;
}

void Game::playGame(Board board){
    char exit = '\0';
    std::string letter = "";
    int count, win;
    while(true){
        while(this->player != this->numPlayers){
            win = 0;
            generateWord();
            if(numPlayers == 1){
                board = Board(getWord().size() - 1);
            }
            else{
                board = Board(getWord().size());
            }
            board.printState(getWord(), this->guesses, this->lettersGuessed, this->category);
            while(!wordFound(board)){
                if(this->guesses == 0 && this->numPlayers > 1){
                    std::cout << "PLAYER " << getPlayer() + 1 << " HAS WON. THE WORD WAS " << getWord() << std::endl;
                    win = 1;
                    break;
                }
                else if(this->guesses == 0 && this->numPlayers == 1){
                    std::cout << "YOU LOST! THE WORD WAS " << getWord() << std::endl;
                    win = 1;
                    break;
                }
                count = 0;
                std::cout << "Enter your guess: ";
                ws(std::cin);
                std::getline(std::cin, letter);
                while(true){ //While input size > 1 or has been guessed previously...
                    if(letter.size() != 1){
                        std::cout << "Please only enter one letter at a time: " << std::endl;
                        std::getline(std::cin, letter);
                    }
                    if(lettersDuplicate(this->lettersGuessed, letter)){
                        std::cout << "Letter has already been guessed. Guess again: " << std::endl;
                        std::getline(std::cin, letter);
                    }
                    else{
                        break;
                    }
                }
                transform(letter.begin(), letter.end(), letter.begin(), ::toupper);
                std::string temp = letter;
                transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                for(int i = 0; i < getWord().size(); i++){
                    if(getWord()[i] == letter[0] || getWord()[i] == temp[0]){
                        board.dashes[i] = letter;
                        count++;
                    }
                }
                if(count != 0){
                    board.printState(getWord(), this->guesses, this->lettersGuessed, this->category);
                }
                else{
                    this->guesses--;
                    this->lettersGuessed.push_back(letter);
                    board.addPart(this->guesses);
                    board.printState(getWord(), this->guesses, this->lettersGuessed, this->category);
                }
            }
            if(win == 0){
                std::cout << "PLAYER " << getPlayer() + 1 << " HAS LOST!\n";
            }
            this->player++;
            this->guesses = 6;
            this->lettersGuessed.clear();
        }
        this->player = 0;
        std::cout << "Want to keep playing? Press 'e' for no, or any key to continue: " << std::endl;
        std::cin >> exit;
        if(exit == 'e'){
            return;
        }
    }
}
