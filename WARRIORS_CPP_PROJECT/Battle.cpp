#include <vector>
#include <random>
#include <iostream>
#include "Warriors.hpp"
#include "Battle.hpp"

Battle::Battle(){
    std::cout << "\nBATTLE HAS BEGUN!\n" << std::endl;
    this->totalTurnCount = 1;
    this->whoseTurn = 0;
    this->amountAlive = 0;
    this->amountOfWarriors = 0;
}

void Battle::startFight(std::vector<Warrior> listOfWarriors){ //static allows us to say Battle::startFightwithout creating a Battle object!
     srand(time(NULL));
     int opponent_tracker;
     this->amountAlive = listOfWarriors.size();
     this->amountOfWarriors = listOfWarriors.size();
     for(int i = 0; i < this->amountOfWarriors; i++){ //Setting all bonus health
            listOfWarriors[i].bonusHealth = rand() % 11; //Set at beginning of game, different for each warrior
            listOfWarriors[i].setHealth(100 + listOfWarriors[i].bonusHealth);
            std::cout << listOfWarriors[i].getName() << " has received " << listOfWarriors[i].bonusHealth << " bonus health. He now has " << listOfWarriors[i].getHealth() << " health" << std::endl;
     }
     while(this->amountAlive > 1){
        opponent_tracker = rand() % this->amountOfWarriors;
        while(opponent_tracker == this->whoseTurn % this->amountOfWarriors || listOfWarriors[opponent_tracker].getHealth() <= 0){
            opponent_tracker = rand() % this->amountOfWarriors;
        }
        listOfWarriors[this->whoseTurn % this->amountOfWarriors].bonusDamage = rand() % 10 ; //Updated every turn
        listOfWarriors[this->whoseTurn % this->amountOfWarriors].setDamage(5 + listOfWarriors[this->whoseTurn % this->amountOfWarriors].bonusDamage);

        std::cout << listOfWarriors[this->whoseTurn % this->amountOfWarriors].getName() << " deals " << listOfWarriors[this->whoseTurn % this->amountOfWarriors ].getDamage() << " damage to " << listOfWarriors[opponent_tracker].getName() << std::endl;

        listOfWarriors[opponent_tracker].tookDamage(listOfWarriors[this->whoseTurn % this->amountOfWarriors].getDamage());
        if(listOfWarriors[opponent_tracker].getHealth() <= 0){
             std::cout << listOfWarriors[opponent_tracker].getName() << " has been killed by " << listOfWarriors[this->whoseTurn %  this->amountOfWarriors].getName() << std::endl;
             this->amountAlive--;
        }
        this->whoseTurn++;
        while(listOfWarriors[this->whoseTurn % this->amountOfWarriors].getHealth() <= 0){
             this->whoseTurn++;
        }
        this->totalTurnCount++;
    }
    while(listOfWarriors[this->whoseTurn % this->amountOfWarriors].getHealth() <= 0){
             this->whoseTurn++;
    }
    std::cout << listOfWarriors[this->whoseTurn % this->amountOfWarriors].getName() << " HAS WON!" << std::endl;
}   