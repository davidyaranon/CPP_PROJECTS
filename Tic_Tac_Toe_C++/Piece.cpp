#include <vector>
#include <string>
#include "Piece.hpp"

//Default constructor
Piece::Piece(){
    this->name = "";
    for(int i = 0; i < 9; i++){
        this->pos.push_back(0);
    }
}
//Constructor with parameters
Piece::Piece(std::string name){
    this->name = name;
    for(int i = 0; i < 9; i++){
        this->pos.push_back(0);
    }
}
void Piece::setName(std::string name){
    this->name = name;
}
std::string Piece::getName(){
    return this->name;
}
void Piece::setPos(int spot){
    this->pos[spot] = 1;
}
