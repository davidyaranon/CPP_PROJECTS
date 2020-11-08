#include <string>
#include "Warriors.hpp"

//Default constructor
Warrior::Warrior(){
    this->damage = 5;
    this->health = 100;
    this->name = "";
    this->bonusDamage = 0;
    this->bonusHealth = 0;
}
//Constructor with parameters
Warrior::Warrior(int damage, int health, std::string name){
    this->damage = damage;
    this->health = health;
    this->name = name;
    this->bonusDamage = 0;
    this->bonusHealth = 0;
}
int Warrior::getDamage(){
    return this->damage;
}
void Warrior::setDamage(int newDamage){
    this->damage = newDamage;
}
int Warrior::getHealth(){
    return this->health;
}
void Warrior::setHealth(int newHealth){
    this->health = newHealth;
}
void Warrior::tookDamage(int damage){
    this->health -= damage;
}
std::string Warrior::getName(){
    return this->name;
}
void Warrior::setName(std::string name){
    this->name = name;
}
void Warrior::setAllDetails(int damage, int health, std::string name){
    this->damage = damage;
    this->health = health;
    this->name = name;
}
Warrior::~Warrior(){
    
}
