#include "Game.hpp"
#include <iostream>
int main(int argc, char* argv){
Game game = Game();
if(game.state == Gamestate::Player1_won){
    std::cout << "Поздравляем игрока #1 с победой" << std::endl;
    return 0;

}
std::cout << "Поздравляем игрока #2 с победой" << std::endl;
    return 0;
}