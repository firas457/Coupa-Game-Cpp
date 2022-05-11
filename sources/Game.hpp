
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"
#include <stdexcept>

using namespace std;
namespace coup
{
    class Player;
    class Game
    {
    public:
        Game();
        ~Game();

        vector<Player *> *players_in_game;
        vector<string> players() const;

        Player *stolen_amount;
        Player *last_couped;
        Player *last_forighn;

      
        unsigned int current_palyer_turn;

        bool game_is_on;

      
        void save_player(Player *player) const;

        
        bool player_turn(const Player &player) const;

        void delete_from_game(Player &player) const;

        void game_turn();

        string turn() const;

        void add_to_game(Player *player) const;

        string winner() const;

    };
}
