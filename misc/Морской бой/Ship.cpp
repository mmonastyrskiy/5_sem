#include "Ship.hpp"
#include <iostream>
#include "Game.hpp"


void Ship::place(GameBoard* board)
{
    coords x,y,rotation;
    std::cout << "Введите координаты для " << size << "-х палубного коробляя :";
    std::cin >> x,y;

    if ((x > X_res) || (y > Y_res)){
        std::cout << "Координаты не пренадлежат области поля, попробуйте снова";
        place(board);
    }
    else if (board->is_ship(x,y)){
        std::cout << "В указанных координатах уже находится корабль, попробуйте снова";
        place(board);

    }
    std::cout << "Введите ротацию для " << size << "-х палубного коробляя зная что:\n 1-ВВЕРХ\n2-ВНИЗ\n3-ВЛЕВО\n 4-ВПРАВО:";
    std::cin >> rotation;
    if(rotation > 4 || rotation < 1){
        std::cout << "Неверная ротация, попробуйте снова";
        place(board);
    }

    switch (rotation){

    case 1:

        coords fin = y-size-1;
        while(coords t = y >= fin){
            if(board->is_ship(x,t) || t > Y_res){break;}
            t--;
        }
        while(coords t = y >= fin){
            board->field[t][x] = board->possible_status["SHIP_CELL"];
            t--;
        }
        this->rotation = Rotation::UP;
        return;
        
    case 2:
        coords fin = y+size-1;
        while(coords t = y <= fin){
            if(board->is_ship(x,t) || t > Y_res){break;}
            t++;
        }
        while(coords t = y <= fin){
            board->field[t][x] = board->possible_status["SHIP_CELL"];
            t++;
        }
        this->rotation = Rotation::DOWN;
        return;
    case 3:

        coords fin = x-size-1;
        while(coords t = x >= fin){
            if(board->is_ship(t,y) || t > X_res){break;}
            t--;
        }
        while(coords t = x >= fin){
            board->field[y][t] = board->possible_status["SHIP_CELL"];
            t--;
        }
        this->rotation = Rotation::LEFT;
        return;
    case 4:
    
        coords fin = x+size-1;
        while(coords t = x <= fin){
            if(board->is_ship(t,y) || t > X_res){break;}
            t--;
        }
        while(coords t = x <= fin){
            board->field[y][t] = board->possible_status["SHIP_CELL"];
            t--;
        }
        this->rotation = Rotation::RIGHT;
        return;
    }
        std::cout << "ой, корабль не поместился, попробуйте снова";
        place(board);

}