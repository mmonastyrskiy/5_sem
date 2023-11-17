#include "Board.hpp"
#include "Game.hpp"
#include "Ship.hpp"
#include <iostream>
GameBoard::GameBoard()
{

    for(int y=0;y<Y_res;y++){
        for(int x=0;x<X_res;x++){
            field[y][x] = possible_status["EMPTY_CELL"];

        }

    }
}

void GameBoard::display_field()
{
    for(int y=0;y<Y_res;y++){
        for(int x=0;x<X_res;x++){
            std::cout << field[y][x] << '\t';

        }
        std::cout << std::endl;

    }
}

bool GameBoard::is_ship(int x, int y)
{
    return (field[y][x] == possible_status["SHIP_CELL"]) ? true: false;
}

void GameBoard::init_field()
{
    std:: cout << "Заполнение поля игрока" << std:: endl;
    ships[0] = Ship4();
    ships[1] = Ship3();
    ships[2] = Ship3();
    ships[3] = Ship2();
    ships[4] = Ship2();
    ships[5] = Ship2();
    ships[6] = Ship1();
    ships[7] = Ship1();
    ships[8] = Ship1();
    ships[9] = Ship1();

for(auto ship: ships){
    display_field();
    ship.place(this);
}
}

bool GameBoard::is_all_destroyed()
{
       for(int y=0;y<Y_res;y++){
        for(int x=0;x<X_res;x++){
            if (field[y][x] == possible_status["SHIP_CELL"]){
                return true;

            }

        }

    }
    return false;
}
