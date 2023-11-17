#pragma once
#include "Board.hpp"
#define X_res 10
#define Y_res 10



enum class Gamestate {Player1_won, Player2_won, in_progeress};
class Game final{
    public:
    GameBoard player1;
    GameBoard player2;
    Gamestate state;
    GameBoard* active_player;
    bool Game_ended();
    void Tick();
    Game();
    bool Shot(coords x, coords y);
    void Prepare_Game();
    void swap_players();

    
};