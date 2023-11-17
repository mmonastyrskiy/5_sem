/*Игровое поле для игры в морской бой char**? */
#pragma once;
#include "Game.hpp"
#include "Ship.hpp"
#include <map>
#include <string>
class GameBoard final{
public:
char field[10][10];
std::map<std::string, char> possible_status = {
    {"EMPTY_CELL",'.'},
    {"KILLED_CELL",'X'},
    {"SHIP_CELL",'□'}

};
Ship ships[10];

GameBoard();
void display_field();
bool is_ship(int x, int y);
void init_field();
bool is_all_destroyed();

};