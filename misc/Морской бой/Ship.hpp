#pragma once
#include "Board.hpp"

enum class Rotation {UP,DOWN,LEFT,RIGHT};
class Ship {
    public:
    short size;
    Rotation rotation;
    

    Ship(){};
    void place(GameBoard* GameBoard);

};

class Ship4 final: public Ship {
    const short size=4;

};

class Ship3 final: public Ship {
    const short size=3;

};
class Ship2 final: public Ship {
    const short size=2;

};
class Ship1 final: public Ship {
    const short size=1;
};