
#define X_res 10
#define Y_res 10
#include "Game.hpp"
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
    for(int t=0<Y_res;t++;){std::cout << t <<'\t';}
    std::cout << std::endl;
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
    place(ship);
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
void GameBoard::place(Ship ship)
{
    coords x,y,rotation,fin,t;
    std::cout << "Введите координаты для " << ship.size<< "-х палубного коробляя :";
    std::cin >> x >> y;

    if ((x > X_res) || (y > Y_res)){
        std::cout << "Координаты не пренадлежат области поля, попробуйте снова";
        place(ship);
    }
    else if (is_ship(x,y)){
        std::cout << "В указанных координатах уже находится корабль, попробуйте снова";
        place(ship);

    }
    std::cout << "Введите ротацию для " << ship.size << "-х палубного коробляя зная что:\n 1-ВВЕРХ\n2-ВНИЗ\n3-ВЛЕВО\n 4-ВПРАВО:";
    std::cin >> rotation;
    if(rotation > 4 || rotation < 1){
        std::cout << "Неверная ротация, попробуйте снова";
        place(ship);
    }

    switch (rotation){

    case 1:

        fin = y-ship.size-1;
        t = y;
        while(t >= fin){
            if(is_ship(x,t) || t > Y_res){break;}
            t--;
        }
        t = y;
        while(t >= fin){
            field[t][x] = possible_status["SHIP_CELL"];
            t--;
        }
        ship.rotation = Rotation::UP;
        return;
        
    case 2:
        fin = y+ship.size-1;
        t=y;
        while(t <= fin){
            if(is_ship(x,t) || t > Y_res){break;}
            t++;
        }
        t=y;
        while(t <= fin){
            field[t][x] = possible_status["SHIP_CELL"];
            t++;
        }
        ship.rotation = Rotation::DOWN;
        return;
    case 3:

        fin = x-ship.size-1;
        t=x;
        while(t >= fin){
            if(is_ship(t,y) || t > X_res){break;}
            t--;
        }
        t=x;
        while(t >= fin){
            field[y][t] = possible_status["SHIP_CELL"];
            t--;
        }
        ship.rotation = Rotation::LEFT;
        return;
    case 4:
    
        fin = x+ship.size-1;
        t=x;
        while(t <= fin){
            if(is_ship(t,y) || t > X_res){break;}
            t--;
        }
        t=x;
        while(t <= fin){
            field[y][t] = possible_status["SHIP_CELL"];
            t--;
        }
        ship.rotation = Rotation::RIGHT;
        return;
    }
        std::cout << "ой, корабль не поместился, попробуйте снова";
        place(ship);
}
