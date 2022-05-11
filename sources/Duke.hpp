#pragma once
#include <iostream>
#include <string>

#include "Player.hpp"

using namespace std;

namespace coup{
    class Duke:public Player{
        public:
            Duke(Game &game, const string &name);
            void tax();
            static void block(Player &player);
    };
}