
#include <map>
#include <string>
using coords = unsigned short; 
enum class Rotation {UP,DOWN,LEFT,RIGHT};

class Ship {
    public:
    short size;
    Rotation rotation;
    coords x,y;

    

    Ship(){};

};

class Ship4 final: public Ship {
    public:
    Ship4() {
        size = 4;
    }

};

class Ship3 final: public Ship {
    public:
    Ship3() {
        size = 3;
    }

};
class Ship2 final: public Ship {
    public:
    Ship2() {
        size = 2;
    }

};
class Ship1 final: public Ship {
    public:
    Ship1() {
        size = 1;
    }
};




class GameBoard final{
public:
char field[10][10];
std::map<std::string, char> possible_status = {
    {"EMPTY_CELL",'.'},
    {"KILLED_CELL",'X'},
    {"SHIP_CELL",'0'}

};
Ship ships[10];

GameBoard();
void display_field();
bool is_ship(int x, int y);
void init_field();
bool is_all_destroyed();
void place(Ship ship);

};