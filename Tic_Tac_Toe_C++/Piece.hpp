#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <string>

class Piece{

public:
    std::vector<int> pos; //Vector of 0's and 1's
    std::string name;

    Piece();
    Piece(std::string);
    void setName(std::string);
    std::string getName();
    void setPos(int pos);
};

#endif
