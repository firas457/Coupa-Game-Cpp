
#pragma once

#include <iostream>
#include <string>

#include "Game.hpp"

using namespace std;

namespace coup
{
  class Game;

  class Player
  {
  public:
    Game *game;
    Player(Game &game, const string &name, const string &role);
    bool coup_changer;
    int money_recived = 0;
    int money;
    int change;
    bool online;

    string Name;
    string role_ch;
    string last_play;

    void foreign_aid();
    int coins() const;
    string role() const;
    virtual void income();
    void coup(Player &player);
  };
}