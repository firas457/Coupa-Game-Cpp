#pragma once
#include <iostream>
#include <string>
#include "Player.hpp"

using namespace std;

namespace coup{
    class Captain:public Player{
        public:
            Captain(Game &game, const string &name);
            void block(Player &player);
            void steal(Player &player);
            
    };
}