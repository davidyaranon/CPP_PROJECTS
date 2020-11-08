#include <iostream>
#include <vector>
#include "Warriors.hpp"
#include "Battle.hpp"
#include <string>

int main(){
    int num_warriors, damage, health;
    std::string name;
    std::vector<Warrior> listOfWarriors;
    std::cout << "Enter how many warriors you want in battle: " << std::endl;
    std::cin >> num_warriors;
    std::cout << "\nEach warrior will have a base damage of 5 and a base health of 100.\nAt the beginning of each game, bonus health will be granted ranging from 0 - 10 (random, so some players might start off with more health).\nEach turn the warriors will be granted bonus damage ranging from 0 - 9 (also random).\nThe game ends when one warrior has 0 health remaining" << std::endl;
    std::cout << "" << std::endl;
    for(int i = 1; i <= num_warriors; i++){
        std::cout << "Enter name for Warrior " << i << ": " << std::endl;
        std::cin >> name;
        damage = 5;
        health = 100;
        Warrior w = Warrior(damage, health, name);
        listOfWarriors.push_back(w);
    }
    Battle battle;
    battle.startFight(listOfWarriors);
}