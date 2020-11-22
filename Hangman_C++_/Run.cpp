#include <iostream>
#include "Game.hpp"

int main(){
    char mode;
    int numPlayers;
    std::cout << "Single Player or Multiplayer? (M/S)" << std::endl;
    std::cin >> mode;
    while(mode != 'S' ||
          mode != 's' ||
          mode != 'M' ||
          mode != 'm')
    {
        if(mode == 'S' || mode == 's'){
            Game game = Game(1);
            return 0;
        }
        else if(mode == 'M' || mode == 'm'){
            std::cout << "Enter number of players: " << std::endl;
            std:: cin >> numPlayers;
            while(numPlayers <= 0){
                std::cout << "Enter valid number of players: " << std::endl;
                std::cin >> numPlayers;
            }
            Game game = Game(numPlayers);
            return 0;
        }
        std::cout << "Please select M or S to continue" << std::endl;
        std::cin >> mode;
    }      
return 0;   
}
