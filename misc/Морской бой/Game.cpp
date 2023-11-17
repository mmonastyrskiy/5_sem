#pragma once
#include "Game.hpp"
#include <iostream>

bool Game::Game_ended()
{
    if (player1.is_all_destroyed()){
        state = Gamestate::Player2_won;
        return true;
    }
    else if (player2.is_all_destroyed()){
        state = Gamestate::Player1_won;
        return true;
    }
    return false;

}

void Game::Tick(){
    coords x,y;
    active_player->display_field();
    std::cout << "Игрок, стреляйте, введите координаты :";
    std::cin >> x,y;
    if ((x > X_res) || (y > Y_res)){
        std::cout << "Введены неверные координаты" << std::endl;
        return;
    }
    if(Shot(x,y)){
        std::cout << "Попал" << std::endl;
    }
    else{
        std::cout << "не повезло" << std::endl;
    }
    swap_players();

}

Game::Game()
{
    this->player1 = GameBoard();
    this->player2 = GameBoard();
    this->active_player = &this->player1;
    this->state = Gamestate::in_progeress;
    this-> Prepare_Game();
    while (!Game_ended()) {
        Tick();
    }
}

bool Game::Shot(coords x, coords y)
{
    if (active_player->field[y][x]==active_player->possible_status["SHIP_CELL"]){
        active_player->field[y][x] = active_player-> possible_status["KILLED_SHIP"];
        return true;
    }
    return false;
}

void Game::Prepare_Game()
{
    player1.init_field();
    player2.init_field();
}

void Game::swap_players()
{
    if(active_player == &player1){
        active_player = &player2;
        return;
    }
active_player = &player1;
return;

}
